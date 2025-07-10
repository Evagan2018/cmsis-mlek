# Overview

The **CMSIS-MLEK (Machine Learning Evaluation Kit) Templates Package** accelerates the development of machine learning applications on Arm Cortex-M processors with Ethos-U NPUs. This package provides ready-to-use reference applications and templates that demonstrate best practices for Edge AI development, enabling rapid prototyping and deployment of ML models on embedded systems.

The MLEK templates cover three main application domains: audio processing (keyword spotting, audio classification), video processing (object detection, image classification), and generic inference (flexible ML model deployment). Each template is built using the modern CMSIS-Toolbox workflow and supports deployment on both physical hardware and Arm Virtual Hardware (AVH) for simulation.

By using the MLEK templates, developers can quickly get started with machine learning on embedded systems without having to build the entire application infrastructure from scratch. The templates include optimized preprocessing, efficient memory management, and neural network inference pipelines specifically tuned for Cortex-M and Ethos-U platforms.

![MLEK Template Architecture](./MLEK-Architecture.png)

The MLEK templates streamline many stages of ML application development:

- **Rapid Prototyping**: Get working ML applications running quickly with minimal setup
- **Algorithm Development**: Use templates as a foundation for custom ML algorithm implementation
- **Model Integration**: Easily swap in custom TensorFlow Lite models with minimal code changes
- **Performance Validation**: Test and optimize ML performance on target hardware or simulation
- **Hardware Evaluation**: Compare performance across different Corstone platforms and configurations

With modern MLOps integration, MLEK templates enable efficient model deployment workflows from training to production.

![MLOps Integration with MLEK](./MLOps.png)

## Features

- **Complete ML Application Templates**: Ready-to-use applications for audio, video, and generic ML inference
- **Multi-Platform Support**: Targets Corstone-300, 310, 315, and 320 platforms with various Ethos-U configurations
- **Optimized Performance**: Leverages CMSIS-NN and Ethos-U driver optimizations for maximum efficiency
- **Flexible Deployment**: Supports both AVH simulation and physical hardware deployment
- **Modern Toolchain**: Built with CMSIS-Toolbox for cross-platform development

## Available Templates

### Audio Processing
- **Keyword Spotting (KWS)**: Wake word detection and voice command recognition
- **Audio User Algorithm**: Template for custom audio ML processing applications

### Video Processing  
- **Object Detection**: Real-time object detection with bounding box visualization
- **User Algorithm Template**: Flexible template for custom computer vision algorithms

### Generic Inference
- **Inference Runner**: General-purpose ML model execution framework for any TensorFlow Lite model

Each template includes:
- Pre-configured project structure with CMSIS-Toolbox
- Optimized preprocessing and inference pipelines
- Support for multiple input/output interfaces
- Built-in performance profiling and benchmarking
- Example models and test data

## Platform Support

The templates support multiple Arm Cortex-M platforms:

| Platform | Processor | NPU Options | Description |
|----------|-----------|-------------|-------------|
| Corstone-300 | Cortex-M55 | Ethos-U55, Ethos-U65 | Arm Virtual Hardware |
| Corstone-310 | Cortex-M85 | Ethos-U55, Ethos-U65 | Arm Virtual Hardware |
| Corstone-315 | Cortex-M85 | Ethos-U65 | Arm Virtual Hardware |
| Corstone-320 | Cortex-M85 | Ethos-U85 | Arm Virtual Hardware|
| Any          | All Cortex-M | Ethos-U or CPU-only | Via CMSIS [Reference Applications](https://open-cmsis-pack.github.io/cmsis-toolbox/ReferenceApplications/) API |

## Links

- [Documentation](../documentation/index.md)
- [Audio Templates](../template/audio/)
- [Video Templates](../template/video/)  
- [Generic Templates](../template/generic/)
- [CMSIS-MLEK Repository](https://github.com/ARM-software/cmsis-mlek)
