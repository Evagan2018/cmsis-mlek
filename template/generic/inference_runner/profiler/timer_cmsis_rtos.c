/*
 * SPDX-FileCopyrightText: Copyright 2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
 * SPDX-License-Identifier: Apache-2.0
 *
 * Implementation of the PMU/CPU profiling module.
 * This module uses the CMSIS-RTOS2 API for timing.
 */

#include "timer_cmsis_rtos.h"  // Module's public header
#include "cmsis_os2.h"     // For osKernelGetSysTimer...

#if defined (ARM_NPU)
 #include "ethosu_profiler.h" // NPU PMU API, if available
#endif

// Assumption: A header for logging macros exists, otherwise use <stdio.h>
#if defined(USE_LOG_MACROS)
    #include "log_macros.h"
#else
    #include <stdio.h>
    #define printf_err(...) printf("ERROR: " __VA_ARGS__)
#endif

// Private, static strings for units
static const char* unit_cycles = "cycles";
static const char* unit_ms = "milliseconds";

/* --- Private Function Prototypes --- */

static bool add_pmu_counter(
        uint64_t value,
        const char* name,
        const char* unit,
        pmu_counters* counters);

static uint32_t get_tstamp_milliseconds(uint64_t total_cycles);

/* --- Public API Implementations --- */

void platform_reset_counters(void) {
    // Since we use the RTOS timer, there are no platform-specific
    // hardware timers to reset.
    // Only NPU-specific PMUs are initialized, if available.
#if defined (ARM_NPU)
    ethosu_pmu_init();
#endif
}

void platform_get_counters(pmu_counters* counters)
{
    counters->num_counters = 0;
    counters->initialised = true;
    uint32_t i = 0;

#if defined (ARM_NPU)
    ethosu_pmu_counters npu_counters = ethosu_get_pmu_counters();
    for (i = 0; i < ETHOSU_USED_PMU_NCOUNTERS; ++i) {
        add_pmu_counter(
                npu_counters.npu_evt_counters[i].counter_value,
                npu_counters.npu_evt_counters[i].name,
                npu_counters.npu_evt_counters[i].unit,
                counters);
    }
    for (i = 0; i < ETHOSU_DERIVED_NCOUNTERS; ++i) {
        add_pmu_counter(
                npu_counters.npu_derived_counters[i].counter_value,
                npu_counters.npu_derived_counters[i].name,
                npu_counters.npu_derived_counters[i].unit,
                counters);
    }
    add_pmu_counter(
            npu_counters.npu_total_ccnt,
            "NPU TOTAL",
            "cycles",
            counters);
#else  /* defined (ARM_NPU) */
    UNUSED(i);
#endif /* defined (ARM_NPU) */

#if defined(CPU_PROFILE_ENABLED)
    add_pmu_counter(
            Get_SysTick_Cycle_Count(),
            "CPU TOTAL",
            "cycles",
            counters);
#endif /* defined(CPU_PROFILE_ENABLED) */

#if !defined(CPU_PROFILE_ENABLED)
#if !defined(ARM_NPU)
    UNUSED(add_pmu_counter);
#endif /* !defined(ARM_NPU) */
#endif /* !defined(CPU_PROFILE_ENABLED) */
}


/* --- Private Helper Functions --- */

static uint32_t get_tstamp_milliseconds(uint64_t total_cycles) {
    const uint32_t timer_freq_hz = osKernelGetSysTimerFreq();
    if (timer_freq_hz == 0) {
        return 0; // Frequency not available, avoid division by zero
    }
    // Conversion using 64-bit arithmetic to prevent overflow/precision loss
    uint64_t milliseconds = (total_cycles * 1000U) / timer_freq_hz;
    return (uint32_t)milliseconds;
}

static bool add_pmu_counter(uint64_t value, const char* name, const char* unit, pmu_counters* counters) {
    const uint32_t idx = counters->num_counters;
    if (idx < NUM_PMU_COUNTERS) {
        counters->counters[idx].value = value;
        counters->counters[idx].name = name;
        counters->counters[idx].unit = unit;
        ++counters->num_counters;
        return true;
    }
    printf_err("Could not add PMU counter! Array is full.\n");
    return false;
}
