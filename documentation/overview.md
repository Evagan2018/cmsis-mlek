# Overview

<!-- markdownlint-disable MD013 -->
<!-- markdownlint-disable MD036 -->

The CMSIS-MLEK (Machine Learning Evaluation Kit) Templates Package provides ready-to-use reference applications and templates for developing machine learning applications on Arm Cortex-M processors with Ethos-U NPUs. These templates accelerate the development of Edge AI applications by providing complete, working examples that demonstrate best practices for ML inference on embedded systems.

![MLEK Templates Architecture](images/MLEK-Architecture.png)

The MLEK templates are designed to support the complete machine learning development workflow on embedded systems:

- **Rapid Prototyping**: Get started quickly with pre-configured ML applications for common use cases
- **Algorithm Development**: Use templates as a foundation for developing custom ML algorithms
- **Performance Optimization**: Leverage optimized implementations for Cortex-M and Ethos-U platforms
- **Hardware Validation**: Test and validate ML models on both simulation and physical hardware
- **MLOps Integration**: Connect to modern ML development pipelines and workflows

## Template Categories

The MLEK package includes three main categories of templates, each targeting different ML application domains:

### Audio Processing Templates

![Audio Processing Workflow](images/Audio-Workflow.png)

The audio templates focus on real-time audio processing and analysis:

- **Keyword Spotting (KWS)**: Wake word detection and voice command recognition
- **Custom Audio Algorithms**: Template for implementing custom audio ML processing

These templates include optimized audio preprocessing, feature extraction, and neural network inference specifically tuned for low-power audio applications.

### Video Processing Templates

![Video Processing Workflow](images/Video-Workflow.png)

The video templates provide computer vision capabilities:

- **Object Detection**: Real-time object detection with bounding box visualization
- **User Algorithm Template**: Flexible template for custom computer vision algorithms

Video templates include efficient image preprocessing, memory management for video frames, and optimized inference pipelines for vision models.

### Generic Inference Templates

![Generic Inference Architecture](images/Generic-Inference.png)

The generic templates provide a flexible foundation for any ML model:

- **Inference Runner**: General-purpose ML model execution framework
- **Model Deployment**: Tools and utilities for deploying custom TensorFlow Lite models
- **Performance Profiling**: Built-in profiling and benchmarking capabilities

## Target Platform Support

The MLEK templates support multiple Arm Cortex-M platforms with Ethos-U NPU acceleration:

| Platform | Processor | NPU | 
|----------|-----------|-----|
| **Corstone-300** | Cortex-M55 | Ethos-U55 |
| **Corstone-310** | Cortex-M85 | Ethos-U55 or U65 | 
| **Corstone-315** | Cortex-M85 | Ethos-U65 | 
| **Corstone-320** | Cortex-M85 | Ethos-U85 | 

Each template can be configured to run on:

- **Arm Virtual Hardware (AVH)**: For simulation, CI/CD, and early development
- **Physical Evaluation Boards**: For hardware validation and real-world testing
- **Custom Hardware**: By implementing the required interfaces 

## Virtual Interfaces

VIO / VStream etc... 