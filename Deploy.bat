@echo off

set c=%CD%

cd DayZEditor/Scripts/Data

if not exist build.txt >build.txt echo 0
for /f %%x in (build.txt) do (
set /a var=%%x+1
)
>build.txt echo %var%

cd %c%

REM start /W "Build PBO" "%CD%/DayZEditor/Workbench/Batchfiles/ZBinarizeDeploy.bat"

echo Upload to Workshop?
pause
cd "%CD%/DayZEditor/Workbench/Deployment"
start /W "Upload to Workshop" Deployment.exe release