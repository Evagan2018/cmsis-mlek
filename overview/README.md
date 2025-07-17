# Overview

The **Machine Learning Evaluation Kit (MLEK)** pack contains [CMSIS Reference Applications](https://open-cmsis-pack.github.io/cmsis-toolbox/ReferenceApplications/) and templates for Edge AI development with embedded systems.
MLEK covers three main application domains:

- [Audio](todo-link-to-docu) processing with audio classification and keyword spotting.
- [Video](todo-link-to-docu) processing with image classification and object detection.
- [Generic](todo-link-to-docu) inference for flexible ML model deployment.

Each reference applications is a *csolution project* which supports deployment to physical hardware or Arm Virtual Hardware (AVH-FVP) for simulation.
It implements data preprocessing, memory management, and neural network inference pipelines that are optimized for Cortex-M and Ethos-U platforms.

![MLEK Reference Application Architecture](./MLEK-Architecture.png)

The MLEK reference applications templates streamline many stages of ML application development:

- **Rapid Prototyping**: Get working ML applications running quickly with minimal setup
- **Algorithm Development**: Use templates as a foundation for custom ML algorithm implementation
- **Model Integration**: Easily swap in custom TensorFlow Lite models with minimal code changes
- **Performance Validation**: Test and optimize ML performance on target hardware or simulation
- **Hardware Evaluation**: Compare performance across different Corstone platforms and configurations

## Platform Support

The templates support via _target names_ multiple [Arm Cortex-M IP Subsystems](https://www.arm.com/products/silicon-ip-subsystems#Products). 

IP Subsystem | Description
:------------|:------------
Corstone-300 | Cortex-M55 optional with Ethos-U55 or Ethos-U65
Corstone-310 | Cortex-M85 optional with Ethos-U55
Corstone-315 | Cortex-M85 optional with Ethos-U65
Corstone-320 | Cortex-M85 optional with Ethos-U85

The postfix in the selected _target name_ of the `*.csolution.yml` project file configures Ethos-U NPU that is used in the system.

Postfix      | Description
:------------|:------------
_none_       | Cortex-M system only, no Ethos-U NPU
`-U55`       | Cortex-M + Ethos-U55 NPU
`-U65`       | Cortex-M + Ethos-U65 NPU
`-U85`       | Cortex-M + Ethos-U85 NPU

![System Topology](./System-Topology.png)

## Links

- [Documentation](../documentation/index.md)
- [Audio Templates](../template/audio/)
- [Video Templates](../template/video/)  
- [Generic Templates](../template/generic/)
- [CMSIS-MLEK Repository](https://github.com/ARM-software/cmsis-mlek)
