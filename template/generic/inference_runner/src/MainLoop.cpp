/*
 * SPDX-FileCopyrightText: Copyright 2021, 2024 Arm Limited and/or its
 * affiliates <open-source-office@arm.com>
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

#include "TestModel.hpp"            /* Model class for running inference. */
#include "UseCaseHandler.hpp"       /* Handlers for different user options. */
#include "UseCaseCommonUtils.hpp"   /* Utils functions. */
#include "main.h"
#include "log_macros.h"             /* Logging functions */
#include "BufAttributes.hpp"        /* Buffer attributes to be applied */

#include "cmsis_os2.h"                /* ::CMSIS:RTOS2 */

namespace arm {
namespace app {
    static uint8_t tensorArena[ACTIVATION_BUF_SZ] ACTIVATION_BUF_ATTRIBUTE;
    namespace inference_runner {
#if defined(DYNAMIC_MODEL_BASE) && defined(DYNAMIC_MODEL_SIZE)

static uint8_t* GetModelPointer()
{
    info("Model pointer: 0x%08x\n", DYNAMIC_MODEL_BASE);
    return reinterpret_cast<uint8_t*>(DYNAMIC_MODEL_BASE);
}

static size_t GetModelLen()
{
    /* TODO: Can we get the actual model size here somehow?
     * Currently we return the reserved space. It is possible to do
     * so by reading the memory pattern but it will not be reliable. */
    return static_cast<size_t>(DYNAMIC_MODEL_SIZE);
}

#else /* defined(DYNAMIC_MODEL_BASE) && defined(DYNAMIC_MODEL_SIZE) */

extern uint8_t* GetModelPointer();
extern size_t GetModelLen();

#endif /* defined(DYNAMIC_MODEL_BASE) && defined(DYNAMIC_MODEL_SIZE) */
    }  /* namespace inference_runner */
} /* namespace app */
} /* namespace arm */

void app_main_thread(void *arg)
{
    arm::app::TestModel model;  /* Model wrapper object. */

    /* Load the model. */
    if (!model.Init(arm::app::tensorArena,
                    sizeof(arm::app::tensorArena),
                    arm::app::inference_runner::GetModelPointer(),
                    arm::app::inference_runner::GetModelLen())) {
        printf_err("Failed to initialise model\n");
        while(1) {
            /* Wait forever */
        }
    }

    /* Instantiate application context. */
    arm::app::ApplicationContext caseContext;

    arm::app::Profiler profiler{"inference_runner"};
    caseContext.Set<arm::app::Profiler&>("profiler", profiler);
    caseContext.Set<arm::app::Model&>("model", model);

    /* Loop. */
    if (RunInferenceHandler(caseContext)) {
        info("Inference completed.\n");
    } else {
        printf_err("Inference failed.\n");
    }
}

/* Application initialization */
int app_main (void) {
    const osThreadAttr_t attr = {
        .stack_size = 10000U
    };

    /* Initialize CMSIS-RTOS2, create application thread and start the kernel */
    osKernelInitialize();
    osThreadNew(app_main_thread, NULL, &attr);
    osKernelStart();
    return 0;
}

