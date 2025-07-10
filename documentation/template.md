# MLEK Reference Application Templates

<!-- markdownlint-disable MD013 -->
<!-- markdownlint-disable MD036 -->

The CMSIS-MLEK Templates Package provides ready-to-use reference applications for developing machine learning applications on Arm Cortex-M processors with Ethos-U NPUs. These templates serve as complete, working examples that demonstrate best practices for ML inference on embedded systems and can be used as starting points for custom ML applications.

The MLEK templates are designed to accelerate ML development by providing:

- **Complete Application Framework**: Ready-to-run ML applications with optimized preprocessing and inference pipelines
- **Model Integration Support**: Easy integration of custom TensorFlow Lite models with minimal code changes
- **Performance Optimization**: Leveraging CMSIS-NN and Ethos-U optimizations for maximum efficiency
- **Cross-Platform Deployment**: Support for both Arm Virtual Hardware (AVH) simulation and physical hardware

Each template is implemented as a [CMSIS-Toolbox Reference Application](https://open-cmsis-pack.github.io/cmsis-toolbox/ReferenceApplications/) and is hardware agnostic, requiring only a compatible `Board-Layer` with drivers for the specific target hardware.

## Template Categories

The MLEK package includes three main categories of templates:

### Audio Processing Templates

Located in `template/audio/`, these templates focus on real-time audio processing:

- **Keyword Spotting (KWS)**: Demonstrates wake word detection and voice command recognition
- **Audio User Algorithm Template**: Provides a foundation for custom audio ML processing applications

### Video Processing Templates  

Located in `template/video/`, these templates provide computer vision capabilities:

- **Object Detection**: Real-time object detection with bounding box visualization
- **User Algorithm Template**: Flexible template for implementing custom computer vision algorithms

### Generic Inference Templates

Located in `template/generic/`, these templates provide flexible ML model deployment:

- **Inference Runner**: General-purpose ML model execution framework that can run any TensorFlow Lite model

## Template Structure

Each MLEK template follows a consistent structure designed for ease of use and customization:

![MLEK Template Structure](images/MLEK_Template_Structure.png)

### Key Components

- **CMSIS-Toolbox Project**: Modern project structure with `.csolution.yml` and `.cproject.yml` files
- **Board Layer**: Hardware abstraction layer providing drivers for specific target platforms
- **Model Integration**: Optimized integration for TensorFlow Lite models with CMSIS-NN acceleration
- **Input/Output Handling**: Configurable interfaces for sensors, cameras, microphones, and displays
- **Performance Profiling**: Built-in timing and resource usage measurements

### Build Configurations

Each template supports multiple build configurations:

- **Debug**: Full debugging symbols and verbose logging for development
- **Release**: Optimized builds for performance measurement and deployment
- **AVH Target**: Configuration for Arm Virtual Hardware simulation
- **Hardware Target**: Configuration for physical evaluation boards

![MLEK Build Configurations](images/MLEK_Build_Config.png)

## Supported Platforms

The MLEK templates support multiple Arm Cortex-M platforms with Ethos-U NPU acceleration:

| Platform | Processor | NPU Options | Template Support |
|----------|-----------|-------------|------------------|
| **Corstone-300** | Cortex-M55 | Ethos-U55, Ethos-U65 | All templates |
| **Corstone-310** | Cortex-M85 | Ethos-U55, Ethos-U65 | All templates |
| **Corstone-315** | Cortex-M85 | Ethos-U65 | All templates |
| **Corstone-320** | Cortex-M85 | Ethos-U85 | All templates |

Each platform configuration includes:
- Optimized memory layouts and linker scripts
- Platform-specific driver configurations  
- Ethos-U NPU driver integration
- Performance-tuned compiler settings

## Working with MLEK Templates

The MLEK templates are part of the CMSIS-MLEK pack and can be used with various development environments.

### Required API Interfaces

For hardware deployment, the Board-Layer should provide the following API interfaces:

| Required API Interface | Description |
|:----------------------|:------------|
| **CMSIS_VIO** | Virtual I/O interface for LEDs, buttons, and basic I/O |
| **STDOUT, STDERR** | Standard output for printf debugging and logging |
| **Platform-Specific** | Additional interfaces depending on template type: |
| - Audio Templates | I2S/SAI for microphone input |
| - Video Templates | Camera interface (DCMI/CSI) |
| - Generic Templates | Flexible I/O for custom sensors |

### Using VS Code

This section explains how to use MLEK templates with the [Arm CMSIS Solution](https://marketplace.visualstudio.com/items?itemName=Arm.cmsis-csolution) extension for VS Code.

#### Install Required Packs

Install the CMSIS-MLEK pack and any required board support packs:

```shell
cpackget add ARM::cmsis-mlek
cpackget add ARM::CMSIS
cpackget add ARM::CMSIS-NN
```

#### Create New Solution

1. Open VS Code and use the **Create a new solution** dialog
2. Select one of the MLEK reference applications:
   - **MLEK Audio KWS Template**
   - **MLEK Video Object Detection Template** 
   - **MLEK Generic Inference Template**

![Select MLEK Template](images/SelectMLEKTemplate.png)

3. Configure the target platform and toolchain:

![Configure MLEK Solution](images/ConfigureMLEKSolution.png)

#### Build and Run

1. Select your target configuration (AVH or hardware board)
2. Choose build type (Debug or Release)
3. Build the project using the CMSIS-Toolbox
4. Deploy to target hardware or run on AVH simulation

### Compile for Custom Hardware

To add support for custom hardware:

1. Open the `*.csolution.yml` file and add a new `target-type`:

```yml
target-types:
  - type: MyCustomBoard
    device: STM32U585AIIx  # Your target MCU
    variables:
      - Board-Layer: $SolutionDir()$/board/MyCustomBoard/Board.clayer.yml
```

2. Create a board layer (`Board.clayer.yml`) that implements the required API interfaces
3. Add board-specific drivers and configuration files

## Template Usage Examples

### Audio Template: Keyword Spotting

The KWS template demonstrates real-time wake word detection:

**Key Features:**
- Real-time audio preprocessing (MFCC feature extraction)
- Optimized neural network inference using CMSIS-NN
- Configurable wake word models
- Performance profiling and benchmarking

**Getting Started:**
1. Build and run the template on your target platform
2. Speak the wake word ("Yes" by default)
3. Observe detection results via UART output or LEDs
4. Replace the model with your custom wake word model

**Customization Points:**
- `kws/src/kws_model.cpp`: Replace with your TensorFlow Lite model
- `kws/src/audio_preprocessing.cpp`: Modify audio preprocessing pipeline  
- `kws/config/kws_config.h`: Adjust detection thresholds and parameters

### Video Template: Object Detection

The object detection template provides real-time computer vision:

**Key Features:**
- Camera input processing and frame buffering
- Object detection using MobileNet-based models
- Bounding box visualization
- Multi-object detection and classification

**Getting Started:**
1. Build and run the template with camera input
2. Point camera at objects for detection
3. View detection results on display or via debug output
4. Integrate your custom object detection model

**Customization Points:**
- `object-detection/src/detection_model.cpp`: Replace with your model
- `object-detection/src/image_preprocessing.cpp`: Modify image preprocessing
- `object-detection/config/detection_config.h`: Adjust detection parameters

### Generic Template: Inference Runner

The generic inference template provides maximum flexibility:

**Key Features:**
- Framework for any TensorFlow Lite model
- Configurable input/output tensors
- Performance benchmarking utilities
- Extensible architecture for custom applications

**Getting Started:**
1. Replace the example model with your TensorFlow Lite model
2. Configure input/output tensor specifications
3. Implement custom preprocessing/postprocessing
4. Build and test your custom ML application

**Customization Points:**
- `inference_runner/Model/`: Replace with your TensorFlow Lite model files
- `inference_runner/src/inference_runner.cpp`: Modify inference pipeline
- `inference_runner/config/`: Adjust model and application configuration

## Performance Optimization

All MLEK templates include built-in performance optimization features:

- **CMSIS-NN Integration**: Optimized neural network kernels for Cortex-M
- **Ethos-U Acceleration**: NPU acceleration for supported layers
- **Memory Optimization**: Efficient memory management and tensor allocation
- **Profiling Tools**: Built-in timing and resource usage measurements

### Performance Measurement

Each template includes performance profiling capabilities:

```c
// Example performance measurement in templates
uint32_t inference_start = DWT->CYCCNT;
model_inference();
uint32_t inference_cycles = DWT->CYCCNT - inference_start;
printf("Inference time: %d cycles\n", inference_cycles);
```

## Next Steps

After successfully running an MLEK template:

1. **Model Integration**: Replace the example model with your trained TensorFlow Lite model
2. **Application Customization**: Modify the application logic for your specific use case  
3. **Performance Tuning**: Optimize for your target constraints (memory, power, latency)
4. **Hardware Deployment**: Test on your target hardware platform
5. **Production Deployment**: Integrate into your final product design

For detailed examples and additional resources, refer to the individual template README files and the MLEK documentation.


