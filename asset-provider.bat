@echo off
set url=%1
set sha512=%2
set dst=%3
set "_dst=%dst:/=\%"
set "_sha512=%sha512:~0,90%"
set "nuget_name=vcpkg_cached_assets"

cd /d %~dp3


echo %NUGET%
%NUGET% install %vcpkg_name% -Version %sha512:~0,90% -Source %PACKAGE_STORAGE_URL%
echo.
if exist %nuget_name%.%_sha512% (
    echo "Pull from the NuGet feed"
    echo url: %url%
    echo dst: %dst%
    cd %nuget_name%.%_sha512%

    REM Assume both are files not directories
    echo "F" | xcopy /f *.part %_dst%
) else (
    echo "Fetch from the url"
    echo url: %url%
    echo dst: %dst%
    curl.exe -L %url% --create-dirs --output %dst%
    REM Replace with the correct path
    %NUGET% pack %~dp0/asset-source.nuspec -BasePath %~dp3 -Properties "sha=%_sha512%;file=%dst%" -OutputDirectory %TEMP%
    %NUGET% push -SkipDuplicate %TEMP%\%_sha512%.1.0.0.nupkg -Source %PACKAGE_STORAGE_URL%
)