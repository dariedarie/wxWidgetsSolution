## Features

- **OpenGL Rendering**: 2D scene with colored triangle and circle
- **Interactive Controls**: Rotation slider and triangle visibility toggle
- **Overlay Button**: Clickable red button in top-right corner
- **Responsive UI**: Real-time synchronization between controls and OpenGL scene

## Project Structure

```
[ProjectName]/
├── [SourceDirectory]/
│   ├── GLCanvas.h          # OpenGL canvas header
│   ├── GLCanvas.cpp        # OpenGL canvas implementation
│   ├── ControlPanel.h      # Control panel header
│   ├── ControlPanel.cpp    # Control panel implementation
│   ├── MainFrame.h         # Main window header
│   ├── MainFrame.cpp       # Main window implementation
│   ├── MyApp.h            # Application class header
│   ├── MyApp.cpp          # Application class + entry point
│   └── [ProjectName].vcxproj
├── [BuildOutput]/
│   ├── Debug/              # Debug build output
│   └── Release/            # Release build output
├── [ProjectName].sln       # Visual Studio solution
├── build.bat              # Automated build script
├── run.bat                # Application launcher
└── README.md              # This file
```

## Prerequisites

- **Visual Studio 2022** (Community, Professional, or Enterprise)
- **wxWidgets** (latest stable version recommended)
- **Windows 10/11** (x64 architecture)

## Build Steps

### 1. Install wxWidgets

1. **Download wxWidgets**
   ```bash
   https://www.wxwidgets.org/downloads/
   ```

2. **Extract to your development directory**
   ```bash
   C:\Development\wxWidgets-3.3.0\
   ```

3. **Build wxWidgets libraries**
   ```bash
   cd C:\Development\wxWidgets-3.3.0\build\msw
   nmake -f makefile.vc BUILD=release TARGET_CPU=X64
   ```

### 2. Build the Application

#### Option A: Using Build Script
```bash
cd [YourProjectPath]
.\build.bat
```

#### Option B: Manual Build
1. Open the `.sln` file in Visual Studio 2022
2. Select **Release** configuration and **x64** platform
3. Build the solution (`Ctrl+Shift+B`)

### 3. Run the Application

#### Option A: Using Run Script
```bash
.\run.bat
```

#### Option B: Manual Execution
```bash
cd [OutputDirectory]
.\[ApplicationName].exe
```

## Usage

- **Overlay Button**: Click the red button in top-right corner to toggle controls
- **Rotation Slider**: Adjust scene rotation (0-360 degrees)
- **Triangle Toggle**: Show/hide the colored triangle
- **Hover Effects**: Overlay button changes color on hover
