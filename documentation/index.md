# CMSIS-MLEK Templates Package

This documentation explains the usage of the CMSIS-MLEK Templates Package for developing Machine Learning (ML) and Edge AI applications on Cortex-M processors with Ethos-U NPUs.

## Target Audience

This user's guide assumes basic knowledge about Cortex-M software development and CMSIS-Toolbox workflows. It is written for embedded software developers who work with C/C++ compiler toolchains and develop machine learning applications for microcontroller devices with Cortex-M processors and Ethos-U NPUs.

## Package Overview

The CMSIS-MLEK package provides ready-to-use templates and examples for machine learning applications. It includes three main template categories:

- **Audio Templates** - Keyword spotting and audio processing examples
- **Video Templates** - Object detection and video processing examples  
- **Generic Templates** - General-purpose inference runner for custom ML models

## Manual Chapters

- [**Overview**](overview.md) explains the features and capabilities of the MLEK templates package.
- [**Template Applications**](template.md) describes the available ML templates and how to use them for algorithm development and testing.
- [**Theory of Operation**](theory.md) explains the underlying concepts of data stream recording and playback for ML development.

## Available Templates

The package includes the following example templates:

| Template | Description | Key Features |
|----------|-------------|--------------|
| **Audio/KWS** | Keyword spotting application | Real-time audio processing, wake word detection |
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

## Getting Started

1. Install the CMSIS-MLEK pack in your development environment
2. Choose a template that matches your use case
3. Configure the target platform (Corstone variant)
4. Build and run on AVH or target hardware
5. Customize the ML model and application logic as needed

## Revision History

| Version | Description |
|---------|-------------|
| 0.1.0   | Initial draft release of CMSIS-MLEK templates package |
