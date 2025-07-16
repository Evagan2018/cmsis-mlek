# MLEK Reference Application Templates

<!-- markdownlint-disable MD013 -->
<!-- markdownlint-disable MD036 -->


### Video Processing Templates

These templates focus on real-time audio processing:

- **Keyword Spotting (KWS)**: Demonstrates wake word detection and voice command recognition
- **Audio User Algorithm Template**: Provides a foundation for custom audio ML processing applications

### Keyword Spotting Application

Explain

## Working with MLEK Templates


### Required API Interfaces

For hardware deployment, the Board-Layer should provide the following API interfaces:

| Required API Interface | Description |
|:----------------------|:------------|
| **CMSIS_VIO** | Virtual I/O interface for LEDs, buttons, and basic I/O |
| **CMSIS_VSTREAM_VIDEO_IN** | Virtual Video Input / Camera Interface |
| **CMSIS_VSTREAM_VIDEO_OUT** | Virtual Video Output / Display |
| **STDOUT, STDERR** | Standard output for printf debugging and logging |

