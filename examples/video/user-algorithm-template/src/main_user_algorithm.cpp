/*
 * SPDX-FileCopyrightText: Copyright 2021-2024 Arm Limited and/or its
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

/**
 * This object detection example is intended to work with the
 * CMSIS pack produced by ml-embedded-eval-kit. The pack consists
 * of platform agnostic end-to-end ML use case API's that can be
 * used to construct ML examples for any target that can support
 * the memory requirements for TensorFlow Lite Micro framework and
 * some heap for the API runtime.
 */
#include "BufAttributes.hpp" /* Buffer attributes to be applied */
#include "Classifier.hpp"    /* Classifier for the result */
#include "DetectionResult.hpp"
#include "DetectorPostProcessing.hpp" /* Post Process */
#include "DetectorPreProcessing.hpp"  /* Pre Process */
#include "VideoSource.hpp"
#include "YoloFastestModel.hpp"       /* Model API */

#include "cmsis_os2.h"                /* ::CMSIS:RTOS2 */
#include <cstdio>                     /* For printf */
#include <cstdint>                    /* For uint32_t, uint8_t */
#include <inttypes.h>                 /* For PRIu32 */

/* Platform dependent files */
#include "main.h"
#include "log_macros.h"      /* Logging macros (optional) */

namespace arm {
namespace app {
    /* Optional getter function for the model pointer and its size. */
    namespace object_detection {
        extern uint8_t* GetModelPointer();
        extern size_t GetModelLen();
    } /* namespace object_detection */
} /* namespace app */
} /* namespace arm */

void app_main_thread(void *arg)
{
    /* For image preprocessing, we need minimal setup */
    uint32_t img_idx = 0;
    size_t img_sz;
    const uint8_t *img_buf;

    printf("Starting image preprocessing only...\n");

    while (open_img_source(img_idx)) {
        img_buf = get_img_array(img_idx);
        img_sz  = get_img_array_size(img_idx);

        /* Basic image preprocessing - convert, resize, normalize as needed */
        printf("Processing image %" PRIu32 " (size: %zu bytes)\n", img_idx, img_sz);
        
        /* Here you can add your custom image preprocessing logic */
        /* For example: format conversion, resizing, normalization, etc. */
        
        printf("Image %" PRIu32 " preprocessed successfully\n", img_idx);

        close_img_source(img_idx++);
    }

    printf("Image preprocessing completed.\n");
}

/* Application initialization */
int app_main (void) {
    const osThreadAttr_t attr = {
        .stack_size = 4096U
    };

    /* Initialize CMSIS-RTOS2, create application thread and start the kernel */
    osKernelInitialize();
    osThreadNew(app_main_thread, NULL, &attr);
    osKernelStart();
    return 0;
}
