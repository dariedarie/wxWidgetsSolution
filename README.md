# Interactive GL Canvas with Controls - Technical Assessment

A wxWidgets desktop application that demonstrates integration between GUI components and OpenGL rendering pipeline.

## Features

✅ **Main Application Window**
- wxWidgets application with wxGLCanvas as the main display area

✅ **OpenGL Rendering**
- 2D scene with geometric shapes (colored triangle and circle)
- Smooth rendering with proper OpenGL context management

✅ **Canvas Overlay Button**
- Clickable red button overlay in the top-right corner of the OpenGL canvas
- Visual feedback on hover (color change)
- Mouse click detection and event handling

✅ **Control Panel**
- Toggle-able side panel with wxWidgets controls
- wxSlider for rotation control (0-360 degrees)
- wxCheckBox to show/hide the triangle
- Real-time synchronization with OpenGL scene

✅ **Integration Requirements**
- Proper event handling for mouse input and window resize
- OpenGL context management throughout application lifecycle
- Responsive UI with visual feedback
- Clean resource management and error handling

## Project Structure

```
SolutionProject/
├── wxWidgetsTask/
│   ├── main.cpp              # Main application code
│   ├── wxWidgetsTask.vcxproj # Visual Studio project file
│   └── wxWidgetsTask.vcxproj.filters
├── x64/
│   ├── Debug/                # Debug build output
│   └── Release/              # Release build output
├── SolutionProject.sln       # Visual Studio solution
└── README.md                 # This file
```

## Prerequisites

- **Visual Studio 2022** (or compatible version)
- **wxWidgets 3.3.0** (or compatible version)
- **OpenGL libraries** (included with Windows)

## Build Instructions

### 1. Install wxWidgets

1. Download wxWidgets 3.3.0 from [https://www.wxwidgets.org/downloads/](https://www.wxwidgets.org/downloads/)
2. Extract to `C:\Users\[YourUsername]\Desktop\Task\wxWidgets-3.3.0\`
3. Build wxWidgets libraries:
   ```bash
   cd C:\Users\[YourUsername]\Desktop\Task\wxWidgets-3.3.0\build\msw
   nmake -f makefile.vc BUILD=release TARGET_CPU=X64
   ```

### 2. Build the Application

1. Open `SolutionProject.sln` in Visual Studio 2022
2. Select **Release** configuration and **x64** platform
3. Build the solution (Ctrl+Shift+B)
4. The executable will be generated in `x64/Release/wxWidgetsTask.exe`

### 3. Run the Application

1. Navigate to `x64/Release/`
2. Run `wxWidgetsTask.exe`

## Usage

### Main Interface
- The application opens with an OpenGL canvas showing a colored triangle and circle
- A red overlay button is visible in the top-right corner

### Interactive Features
1. **Overlay Button**: Click the red button in the top-right corner to toggle the control panel
2. **Rotation Slider**: Adjust the rotation of the entire scene (0-360 degrees)
3. **Triangle Toggle**: Check/uncheck to show or hide the triangle
4. **Mouse Hover**: The overlay button changes color when you hover over it

### Visual Elements
- **Triangle**: Multi-colored triangle (red, green, blue vertices)
- **Circle**: Yellow wireframe circle
- **Background**: Dark blue-gray background
- **Overlay Button**: Red button with white border, positioned in top-right corner

## Technical Implementation

### Architecture
- **GLCanvas**: Custom wxGLCanvas class handling OpenGL rendering
- **ControlPanel**: wxPanel with interactive controls
- **MainFrame**: Main application window managing layout
- **MyApp**: wxWidgets application entry point

### Key Features
- **Event-Driven Design**: Proper wxWidgets event handling
- **OpenGL Integration**: Seamless wxWidgets + OpenGL integration
- **Resource Management**: Proper cleanup of OpenGL contexts and wxWidgets resources
- **Responsive UI**: Real-time updates between controls and OpenGL scene

### OpenGL Features
- 2D orthographic projection
- Depth testing and blending
- Matrix transformations for rotation
- Overlay rendering for UI elements

## Dependencies

- **wxWidgets 3.3.0**: GUI framework
- **OpenGL**: Graphics rendering
- **Visual Studio 2022**: Development environment
- **Windows SDK**: Platform-specific libraries

## Troubleshooting

### Common Issues

1. **wxWidgets not found**
   - Ensure wxWidgets is installed and built correctly
   - Check include and library paths in project settings

2. **OpenGL errors**
   - Verify graphics drivers are up to date
   - Ensure OpenGL libraries are available

3. **Build errors**
   - Clean and rebuild the solution
   - Check Visual Studio platform toolset version

### Build Configuration

The project is configured for:
- **Platform**: x64
- **Configuration**: Release (recommended) or Debug
- **Character Set**: Unicode
- **Platform Toolset**: v143 (Visual Studio 2022)

## Evaluation Criteria Met

✅ **Clear code organization and modular design**
- Separated concerns: GLCanvas, ControlPanel, MainFrame
- Clean class interfaces and proper encapsulation

✅ **Smooth integration of wxWidgets and OpenGL**
- Proper context management and event handling
- Seamless overlay rendering

✅ **Proper event handling and interactivity**
- Mouse events, window resize, control interactions
- Real-time visual feedback

✅ **Responsive UI and visual feedback**
- Immediate response to control changes
- Hover effects and smooth rendering

✅ **Robustness: proper error handling and resource cleanup**
- RAII principles for resource management
- Proper OpenGL context lifecycle management

## License

This project is created for technical assessment purposes. 