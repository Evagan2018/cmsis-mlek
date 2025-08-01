# CMSIS-MLEK Software Pack

This repository contains **Machine Learning Evaluation Kit (MLEK)** pack which provides [CMSIS Reference Applications](https://open-cmsis-pack.github.io/cmsis-toolbox/ReferenceApplications/) and templates for Edge AI development. These applications implement data preprocessing, memory management, and neural network inference pipelines that are optimized for Cortex-M and Ethos-U platforms.

Refer to [Overview](./overview/README.md) for more details.

## Repository structure

Directory                         | Description
----------------------------------|-------------------------------
[overview](./overview)            | Top-level overview of MLEK reference applications.
[documentation](./documentation/) | [User documentation](https://arm-examples.github.io/cmsis-mlek/main/index.html) of the MLEK reference applications.
[template](./template)            | [MLEK reference applications](https://arm-examples.github.io/cmsis-mlek/main/template.html), a test framework for DSP and ML algorithms.
[.github/workflows](./.github/workflows) | GitHub Actions for validation and publishing.
[.ci](./.ci)                      | Files that relate to CI tests.

## Related

- [MLEK Pack](https://www.keil.arm.com/packs/MLEK) available on [keil.arm.com/packs](https://www.keil.arm.com/packs).
- [MLEK Examples](https://github.com/Arm-Examples/mlek-examples) a repository with MLEK applications that are configured for evaluation boards and use cases.
- [ML Developers Guide for Cortex-M Processors and Ethos-U NPU](https://developer.arm.com/documentation/109267).
- [Arm Virtual Hardware - FVP](https://github.com/arm-software/avh) repository with documentation.

## License

The MLEK references applications are licensed under [![License](https://img.shields.io/github/license/arm-examples/cmsis-mlek?label)](https://github.com/ARM-examples/cmsis-mlek/blob/main/LICENSE).

## Documentation

The [documentation](https://arm-software.github.io/SDS-Framework/main/index.html) is generated using  [MKDocs](https://www.mkdocs.org/) with the following additional plugins:

- [mermaid2](https://mkdocs-mermaid2.readthedocs.io/en/latest/) for sequence diagrams.

Use `mkdocs serve` to generate the documentation on a local computer.

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
