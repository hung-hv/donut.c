if (Test-Path -Path "../build" -PathType Container) {
  Remove-Item -Recurse -Force "../build/*"
  Write-Output "All files in the build folder have been cleared."
} else {
  Write-Output "The build folder does not exist."
}