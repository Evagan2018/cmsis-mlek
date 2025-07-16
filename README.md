# Overview

The **CMSIS Machine Learning Evaluation Kit (MLEK)** provides a comprehensive framework for developing and deploying machine learning applications on Arm Cortex-M processors with Ethos-U Neural Processing Units. MLEK enables developers to build sophisticated edge AI applications using familiar CMSIS development tools and flows.

MLEK is designed to integrate seamlessly with the CMSIS ecosystem, including the CMSIS-Toolbox and CMSIS-compliant Hardware Abstraction Layers and software components. This integration ensures that developers can leverage existing CMSIS knowledge and workflows while accessing advanced ML capabilities optimized for embedded systems.

The framework automatically detects NPU-enabled targets through naming conventions and configures appropriate optimizations for each Ethos-U variant. This automatic configuration simplifies development and ensures optimal performance across different hardware platforms.


## Reference Applications

The CMSIS-MLEK Pack includes ready-to-use reference applications organized into three categories:

| Audio Applications    | |
| -|-
| **Keyword Spotting (KWS)** | Real-time wake word detection with MFCC feature extraction and configurable keywords |
| **User Algorithm Template** | Customizable audio processing template for developing custom audio ML applications |

| Video Applications  | |
| -|-
| **Object Detection** | Real-time object detection using YOLO models with camera integration and bounding box visualization |
| **User Algorithm Template** | Flexible computer vision template for custom image processing and ML inference | 

| Generic Applications | |
| - | -
| **Generic Inference Runner** | Performance analysis tool for evaluating ML models during initial porting to Cortex-M/Ethos-U platforms, providing detailed metrics and optimization insights|

Each reference application includes complete source code, configuration examples, and optimization strategies for different hardware targets and NPU configurations.

## Features

- **Automatic NPU / CPU Detection** — Intelligent target recognition based on naming conventions with automatic optimization
- **Multi-Platform Support** — Compatible with various evaluation boards, and Fixed Virtual Platforms (FVPs)
- **CMSIS Integration** — Full compatibility with CMSIS-Toolbox, csolution project format, and standard CMSIS components
- **CMSIS Layer Design** - Simplifies integration into user application. 
- **Real-Time Processing** — Optimized for low-latency inference with deterministic performance characteristics
- **Energy Efficiency** — Advanced power management and workload optimization for battery-powered applications

The framework supports comprehensive development workflows including automated testing, continuous integration, and performance analysis across multiple hardware configurations.

## Links

- **[Documentation](../documentation/)** — Complete developer guides and API reference
- **[Getting Started](../documentation/getting-started.md)** — Quick setup and first project tutorial  
- **[Application Examples](../template/)** — Ready-to-use audio, video, and generic ML applications
- **[Target Configuration](../documentation/targets/)** — Platform-specific setup and optimization guides
- **[MLEK Learning Path](https://learn.arm.com/learning-paths/embedded-and-microcontrollers/mlek/)** — Comprehensive MLEK concepts and tutorials
- **[CMSIS-Toolbox](https://github.com/Open-CMSIS-Pack/cmsis-toolbox)** — Modern CMSIS development tools and workflows

