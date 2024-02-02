@echo off
set url=%1
set sha512=%2
set dst=%3
set "_dst=%dst:/=\%"
set "_sha512=%sha512:~0,90%"

cd /d %~dp3
nuget install %sha512:~0,90% -Source https://nuget.pkg.github.com/van-off-the-ovvo/index.json
echo.
if exist %_sha512%.1.0.0 (
    echo "Pull from the NuGet feed"
    cd %_sha512%.1.0.0

    REM Assume both are files not directories
    echo "F" | xcopy /f *.part %_dst%
) else (
    echo "Fetch from the url"
    curl.exe -L %url% --create-dirs --output %dst%
    REM Replace with the correct path
    nuget pack ./asset-source.nuspec -BasePath %~dp3 -Properties "sha=%_sha512%;file=%dst%" -OutputDirectory %TEMP%
    nuget push -SkipDuplicate %TEMP%\%_sha512%.1.0.0.nupkg -Source https://nuget.pkg.github.com/van-off-the-ovvo/index.json
)