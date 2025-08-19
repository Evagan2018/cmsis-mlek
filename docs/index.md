# Machine Learning Evaluation Kit (MLEK) for CMSIS Workflows

This documentation explains the usage of the CMSIS-MLEK Reference Application Package for developing Machine Learning (ML) and Edge AI applications on Cortex-M processors optional with Ethos-U NPUs.

## Target Audience

This user's guide assumes basic knowledge about Cortex-M software development and CMSIS-Toolbox workflows. It is written for embedded software developers who work with C/C++ compiler toolchains and develop machine learning applications for microcontroller devices with Cortex-M processors and Ethos-U NPUs.

## Manual Chapters

- [**Overview**](overview.md) explains the features and capabilities of the MLEK templates package.
- [**MLEK Audio Applications**](templates_audio.md) describes the available ML templates for audio use-cases.
- [**MLEK Video Applications**](templates_video.md) describes the available ML templates for video and image use-cases.
- [**Targeting Hardware Boards**](target_configuration_refapp.md) gives step-by-step guidance for deploying the reference applications to a hardware platform in VS Code.
- [**Targeting Arm Virtual Hardware**](target_configuration_avh.md) shows how to select a virtual target in Visual Studio code.  

<!--  Duplicate of Overview.md
## Package Overview

The CMSIS-MLEK package provides ready-to-use templates and examples for machine learning applications. It includes three main template categories:

- **Audio Reference Applications** - Keyword spotting and audio processing examples
- **Video Reference Applications** - Object detection and video processing examples  
- **Generic Reference Applications** - General-purpose inference runner for custom ML models (available from version 1.0+)

## Available Templates

The package includes the following example templates:

| Template | Description | Key Features |
|----------|-------------|--------------|
| **Audio/KWS** | Keyword spotting application | Real-time audio processing, wake word detection |
| **Audio/User Algorithm** | Customizable audio processing template | Template for implementing custom audio ML algorithms |
| **Video/Object Detection** | Object detection using camera input | Real-time object detection, bounding box visualization |
| **Video/User Algorithm** | Customizable video processing template | Template for implementing custom video ML algorithms |
| **Generic/Inference Runner** | General-purpose ML inference | Support for custom TensorFlow Lite models |

## Supported Platforms

The templates support multiple Arm Cortex-M platforms:

- **Corstone-300** (Cortex-M55 + Ethos-U55/U65)
- **Corstone-310** (Cortex-M85 + Ethos-U55/U65) 
- **Corstone-315** (Cortex-M85 + Ethos-U65)
- **Corstone-320** (Cortex-M85 + Ethos-U85)

Each template can be built for both Arm Virtual Hardware (AVH) simulation and physical evaluation boards.
-->

## Revision History

| Version | Description |
|---------|-------------|
| 0.5.0   | First published release.                              |
