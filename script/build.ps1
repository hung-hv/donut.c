#check if the directory exists
$buildPath = "./build"
if (-Not (Test-Path -Path $buildPath)) {
    Write-Output "build folder did not exist!"
    New-Item -ItemType Directory -Path $buildPath
    Write-Output "build folder has been created"
}

# Navigate to build directory
Set-Location $buildPath

# Define the command
$command_cmake = 'cmake .. -G "MinGW Makefiles"'

# Execute the command
Invoke-Expression $command_cmake

$command_make = 'MinGW32-make'
# Execute the command
Invoke-Expression $command_make