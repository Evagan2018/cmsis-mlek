/*
 * SPDX-FileCopyrightText: Copyright 2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
 * SPDX-License-Identifier: Apache-2.0
 *
 * Public interface for the PMU/CPU profiling module.
 * This module requires a running CMSIS-RTOS2 environment.
 */

#ifndef PMU_PROFILER_H
#define PMU_PROFILER_H

#include <stdint.h>
#include <stdbool.h>

// Configurable maximum number of counters that can be captured.
#define NUM_PMU_COUNTERS 16

/**
 * @brief Structure for a single performance counter.
 */
typedef struct pmu_counter_t {
    uint64_t    value;      // The captured counter value
    const char* name;       // Name of the counter (e.g., "CPU TOTAL")
    const char* unit;       // Unit of the counter (e.g., "cycles")
} pmu_counter_t;

/**
 * @brief Structure to hold a collection of performance counters.
 */
typedef struct pmu_counters {
    bool          initialised;                // Flag indicating if the structure is valid
    uint32_t      num_counters;               // Number of valid counters in the array
    pmu_counter_t counters[NUM_PMU_COUNTERS]; // Array of counters
} pmu_counters;

/**
 * @brief Resets the relevant PMU counters.
 * @note  Should be called before starting a measurement.
 *        This function does NOT reset the RTOS system timer.
 */
void platform_reset_counters(void);

/**
 * @brief Captures the current values of all configured counters.
 * @param[out] counters Pointer to a pmu_counters structure that will be
 *                      filled with the current counter values.
 */
void platform_get_counters(pmu_counters* counters);

#endif // PMU_PROFILER_H
