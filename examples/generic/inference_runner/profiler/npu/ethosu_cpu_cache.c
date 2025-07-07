/*
 * SPDX-FileCopyrightText: Copyright 2022, 2025 Arm Limited and/or its affiliates <open-source-office@arm.com>
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include "RTE_Components.h"         /* For CPU related defintiions */
#include "ethosu_driver.h"          /* Arm Ethos-U driver header */
#include "log_macros.h"             /* Logging macros */

/** Structure to maintain data cache states. */
typedef struct _cpu_cache_state {
    uint32_t dcache_invalidated : 1;
    uint32_t dcache_cleaned : 1;
} cpu_cache_state;

/** Static CPU cache state object.
 * @note This logic around flipping these states is based on the driver
 *       calling the functions in this sequence:
 *
 *       Cache flush (ethosu_flush_dcache)
 *                  ↓
 *       Start inference (ethosu_inference_begin)
 *                  ↓
 *       Inference (ethosu_dev_run_command_stream)
 *                  ↓
 *       End inference (ethosu_inference_end)
 *                  ↓
 *       Cache invalidate (ethosu_dcache_invalidate)
 **/
static cpu_cache_state s_cache_state = {.dcache_cleaned = 0, .dcache_invalidated = 0};

/**
 * @brief   Gets the current CPU cache state.
 * @return  Pointer to the CPU cache state object.
 */
static cpu_cache_state* ethosu_get_cpu_cache_state(void)
{
    return &s_cache_state;
}

void ethosu_clear_cache_states(void)
{
    cpu_cache_state* const state = ethosu_get_cpu_cache_state();
    trace("Clearing cache state members\n");
    state->dcache_invalidated = 0;
    state->dcache_cleaned     = 0;
}


