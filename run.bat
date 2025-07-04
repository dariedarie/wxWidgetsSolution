@echo off
echo Running Interactive GL Canvas with Controls...
echo.

if not exist "x64\Release\wxWidgetsTask.exe" (
    echo Error: Application not found!
    echo Please build the project first by running build.bat
    pause
    exit /b 1
)

echo Starting application...
echo.
echo Usage:
echo - Click the red button in the top-right corner to toggle controls
echo - Use the slider to rotate the scene
echo - Check/uncheck to show/hide the triangle
echo - Hover over the red button to see visual feedback
echo.

cd x64\Release
wxWidgetsTask.exe

echo.
echo Application closed.
pause 