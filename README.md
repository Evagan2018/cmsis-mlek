[![License](https://img.shields.io/github/license/arm-examples/cmsis-mlek?label)](https://github.com/ARM-examples/cmsis-mlek/blob/main/LICENSE)
[![Build documentation](https://img.shields.io/github/actions/workflow/status/Arm-Examples/cmsis-mlek/mkdocs.yml?logo=arm&logoColor=0091bd&label=Build%20documentation)](https://github.com/Arm-Examples/cmsis-mlek/tree/main/.github/workflows/mkdocs.yml)
[![Build documentation and pack](https://img.shields.io/github/actions/workflow/status/Arm-Examples/cmsis-mlek/pack.yaml?logo=arm&logoColor=0091bd&label=Build%20documentation%20and%20pack)](https://github.com/Arm-Examples/cmsis-mlek/tree/main/.github/workflows/pack.yaml)
[![AC6 Audio build and run tests](https://img.shields.io/github/actions/workflow/status/Arm-Examples/cmsis-mlek/test_audio.yaml?logo=arm&logoColor=0091bd&label=AC6%20Audio%20build%20and%20run%20tests)](https://github.com/Arm-Examples/cmsis-mlek/tree/main/.github/workflows/test_audio.yaml)
[![AC6 Video build tests](https://img.shields.io/github/actions/workflow/status/Arm-Examples/cmsis-mlek/test_video.yaml?logo=arm&logoColor=0091bd&label=AC6%20Video%20build%20tests)](https://github.com/Arm-Examples/cmsis-mlek/tree/main/.github/workflows/test_video.yaml)
[![AC6 Inference build tests](https://img.shields.io/github/actions/workflow/status/Arm-Examples/cmsis-mlek/test_generic.yaml?logo=arm&logoColor=0091bd&label=AC6%20Inference%20build%20tests)](https://github.com/Arm-Examples/cmsis-mlek/tree/main/.github/workflows/test_generic.yaml)


# CMSIS-MLEK Software Pack

This repository contains **Machine Learning Evaluation Kit (MLEK)** pack which provides [CMSIS Reference Applications](https://open-cmsis-pack.github.io/cmsis-toolbox/ReferenceApplications/) and templates for Edge AI development. 


## Quick Start

1. Install [Keil Studio for VS Code](https://marketplace.visualstudio.com/items?itemName=Arm.keil-studio-pack) from the
   VS Code marketplace.
2. Clone this Git repository into a VS Code workspace.
3. Open the [CMSIS View](https://mdk-packs.github.io/vscode-cmsis-solution-docs/userinterface.html#2-main-area-of-the-cmsis-view)
   in VS Code and use the ... menu to choose an example via *Select Active Solution from workspace*.
4. The related tools and software packs are downloaded and installed. Review progress with *View - Output - CMSIS Solution*.
5. In the CMSIS view, use the
   [Action buttons](https://github.com/ARM-software/vscode-cmsis-csolution?tab=readme-ov-file#action-buttons) to build,
   load and debug the example on the hardware.


## Examples description

The provided applications implement data preprocessing, memory management, and neural network inference pipelines that are optimized for Cortex-M and Ethos-U platforms. The examples are prepared to run with [Keil Studio for VS Code](https://www.keil.arm.com/).

The CMSIS-MLEK software pack is derived from the [Arm® ML embedded evaluation kit](https://git.gitlab.arm.com/artificial-intelligence/ethos-u/ml-embedded-evaluation-kit) and makes the examples easier to access. It also contains interfaces to physical hardware and simplifies porting to target hardware. It contains the following ML applications and uses currently Neural Network Models currently in [TensorFlow Lite](https://www.keil.arm.com/packs/tensorflow-lite-micro-tensorflow) format.


| ML application                                 | Description             | Neural Network Model |
|---                                             |---                      |---                   |
| [Keyword spotting (KWS)](./template/audio)     | Recognize the presence of a key word in verbal speech | [MicroNet](https://github.com/ARM-software/ML-zoo/tree/9f506fe52b39df545f0e6c5ff9223f671bc5ae00/models/keyword_spotting/micronet_medium/tflite_int8) |
| [Object detection](./template/video)           | Detects and draws face bounding box in a given image  | [Yolo Fastest](https://github.com/emza-vs/ModelZoo/blob/master/object_detection/yolo-fastest_192_face_v4.tflite) |
| [Generic inference runner](./template/generic) | Code block allowing you to develop your own use case  | Your custom model |

Refer to [Overview](./overview/README.md) for more details.


## Repository structure

| Directory                                | Description |
|---                                       |--- |
| [.ci](./.ci)                             | Files that relate to CI tests. |
| [.github/workflows](./.github/workflows) | GitHub Actions for validation and publishing. |
| [overview](./overview)                   | Top-level overview of MLEK reference applications. |
| [docs](./docs/)                          | Source of the [user documentation](https://arm-examples.github.io/cmsis-mlek) of the MLEK reference applications. |
| [template](./template)                   | MLEK reference applications source code. |


## Continuous Integration (CI)

| <div style="width:150px"> CI Workflow </div>          | Description |
|---                                                    |---  |
| [mkdocs](./.github/workflows/mkdocs.yml)              | Builds the pack documentation on a GitHub hosted runner.      |
| [pack](./.github/workflows/pack.yaml)                 | Builds the pack on a GitHub hosted runner. |
| [test_audio](./.github/workflows/test_audio.yaml)     | Builds the Keyword spotting application (audio) for different contexts by using the Arm Compiler for Embedded (AC6), execute each of them by using [FVP simulation models](https://arm-software.github.io/AVH/main/simulation/html/index.html), capture the FVP UART output and upload them as artifact. |
| [test_video](./.github/workflows/test_video.yaml)     | Builds the Object detection application (video) for different contexts by using the Arm Compiler for Embedded (AC6). |
| [test_generic](./.github/workflows/test_generic.yaml) | Builds the a Generic inference application for different contexts by using the Arm Compiler for Embedded (AC6). |


## Related

- [CMSIS-MLEK Pack](https://www.keil.arm.com/packs/cmsis-mlek-arm) available on [www.keil.arm.com/packs](https://www.keil.arm.com/packs).
- [tensorflow-lite-micro Pack](https://www.keil.arm.com/packs/tensorflow-lite-micro-tensorflow) available on [www.keil.arm.com/packs](https://www.keil.arm.com/packs).
- [CMSIS-MLEK Examples](https://github.com/Arm-Examples/cmsis-mlek-examples) a repository with MLEK applications that are configured for evaluation boards and use cases.
- [ML Developers Guide for Cortex-M Processors and Ethos-U NPU](https://developer.arm.com/documentation/109267).
- [Arm Virtual Hardware - FVP](https://github.com/arm-software/avh) repository with documentation.


## Documentation

The [documentation](https://arm-examples.github.io/cmsis-mlek/index.html) is generated using [MKDocs](https://www.mkdocs.org/). Use `mkdocs serve` to generate the documentation on a local computer.


## Contributions and Pull Requests

Contributions are accepted under [![License](https://img.shields.io/github/license/arm-examples/cmsis-mlek?label)](https://github.com/ARM-examples/cmsis-mlek/blob/main/LICENSE). Only submit contributions where you have authored all of the code.

### Issues and Labels

Please feel free to raise an [issue on GitHub](https://github.com/ARM-examples/cmsis-mlek/issues)
to report misbehavior (i.e. bugs) or start discussions about enhancements. This
is your best way to interact directly with the maintenance team and the community.
We encourage you to append implementation suggestions as this helps to decrease the
workload of the very limited maintenance team.

We will be monitoring and responding to issues as best we can.
Please attempt to avoid filing duplicates of open or closed items when possible.
In the spirit of openness we will be tagging issues with the following:

- **bug** – We consider this issue to be a bug that will be investigated.
- **wontfix** - We appreciate this issue but decided not to change the current behavior.
- **enhancement** – Denotes something that will be implemented soon.
- **future** - Denotes something not yet schedule for implementation.
- **out-of-scope** - We consider this issue loosely related to CMSIS. It might by implemented outside of CMSIS. Let us know about your work.
- **question** – We have further questions to this issue. Please review and provide feedback.
- **documentation** - This issue is a documentation flaw that will be improved in future.
- **review** - This issue is under review. Please be patient.
- **DONE** - We consider this issue as resolved - please review and close it. In case of no further activity this issues will be closed after a week.
- **duplicate** - This issue is already addressed elsewhere, see comment with provided references.
- **Important Information** - We provide essential information regarding planned or resolved major enhancements.
