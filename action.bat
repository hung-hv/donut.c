@echo off
REM define the path
set dirPath=script\

REM Check if the first argument is "build"
if "%1" == "build" (
    set fileName=build.ps1
    powershell -ExecutionPolicy Bypass -File "%~dp0%dirPath%%fileName%"
) else if "%1" == "clean" (
    set fileName=clean.ps1
    powershell -ExecutionPolicy Bypass -File "%~dp0%dirPath%%fileName%"
) else (
    echo Invalid command.
    echo Usage:
    echo    action build   - Runs the build script
    echo    action clean   - Runs the clean script
)