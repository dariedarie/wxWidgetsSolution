@echo off
echo Building Interactive GL Canvas with Controls...
echo.

REM Try to find Visual Studio installation
set "VS_PATH="
if exist "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat" (
    set "VS_PATH=C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat"
) else if exist "C:\Program Files\Microsoft Visual Studio\2022\Professional\Common7\Tools\VsDevCmd.bat" (
    set "VS_PATH=C:\Program Files\Microsoft Visual Studio\2022\Professional\Common7\Tools\VsDevCmd.bat"
) else if exist "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\Tools\VsDevCmd.bat" (
    set "VS_PATH=C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\Tools\VsDevCmd.bat"
)

if "%VS_PATH%"=="" (
    echo Error: Visual Studio 2022 not found!
    echo Please install Visual Studio 2022 or update the path in this script.
    pause
    exit /b 1
)

echo Using Visual Studio at: %VS_PATH%
echo.

REM Set up Visual Studio environment and build
call "%VS_PATH%"
msbuild SolutionProject.sln /p:Configuration=Release /p:Platform=x64

if %ERRORLEVEL% EQU 0 (
    echo.
    echo Build successful!
    echo Executable location: x64\Release\wxWidgetsTask.exe
    echo.
    echo To run the application:
    echo 1. Navigate to x64\Release\
    echo 2. Run wxWidgetsTask.exe
    echo.
) else (
    echo.
    echo Build failed! Please check the error messages above.
    echo.
    echo Common issues:
    echo - wxWidgets not installed or not built
    echo - Visual Studio platform toolset not found
    echo - Missing dependencies
    echo.
)

pause 