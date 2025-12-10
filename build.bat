@echo off
REM Build script for donut project
REM Usage: build.bat [clean|build|rebuild]

set PROJECT_DIR=%~dp0
set BUILD_DIR=%PROJECT_DIR%build

if "%1"=="" goto :HELP
if "%1"=="clean" goto :CLEAN
if "%1"=="build" goto :BUILD
if "%1"=="rebuild" goto :REBUILD
goto :HELP

:CLEAN
echo Cleaning build directory...
if exist "%BUILD_DIR%" (
    rmdir /s /q "%BUILD_DIR%"
    echo Build directory cleaned.
) else (
    echo Build directory does not exist.
)
goto :END

:BUILD
echo Building project...
REM Create build directory if it doesn't exist
if not exist "%BUILD_DIR%" (
    mkdir "%BUILD_DIR%"
    echo Created build directory.
)

REM Navigate to build directory
cd /d "%BUILD_DIR%"

REM Run cmake to generate makefiles
echo Running cmake...
cmake .. -G "MinGW Makefiles"
if errorlevel 1 (
    echo CMake failed!
    goto :END
)

REM Build the project
echo Building with make...
mingw32-make
if errorlevel 1 (
    echo Build failed!
    goto :END
)

echo Build completed successfully!
goto :END

:REBUILD
echo Rebuilding project (clean + build)...
call :CLEAN
call :BUILD
goto :END

:HELP
echo Usage: build.bat [command]
echo.
echo Commands:
echo   clean    - Remove build directory and all generated files
echo   build    - Build the project (create build dir if needed)
echo   rebuild  - Clean and then build the project
echo.
echo Examples:
echo   build.bat clean
echo   build.bat build
echo   build.bat rebuild

:END
