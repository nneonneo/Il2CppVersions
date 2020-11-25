@echo off

@if not [%1]==[] goto main
@echo Usage: %0 ^<Version^> [f]
@exit /B 1

:main
@set VERSION=%1
@echo ======================= %VERSION% =======================
@echo %DATE% %TIME%

set OUTDIR=%cd%\output\%VERSION%
set OUT64=%OUTDIR%\libil2cpp-x64.dll
set OUT32=%OUTDIR%\libil2cpp-x86.dll

if /i not "%2"=="f" if exist "%OUT64%" if exist "%OUT32%" exit /B 0

rd /s /q "%OUTDIR%" 2>nul
mkdir "%OUTDIR%"
mkdir "%OUTDIR%\lib"
mkdir "%OUTDIR%\stripped"
mkdir "%OUTDIR%\il2cpp"

call "%~dp0\MonoBleedingEdge\bin\mcs.bat" -t:library -out:"%OUTDIR%\lib\Test.dll" Test.cs
copy "%~dp0\MonoBleedingEdge\lib\mono\unityaot\mscorlib.dll" "%OUTDIR%\lib"

"%~dp0\il2cpp-%VERSION%\build\deploy\netcoreapp3.1\UnityLinker.exe" --out="%OUTDIR%\stripped" --i18n=none --core-action=link --search-directory="%OUTDIR%\lib" --include-assembly="%OUTDIR%\lib\Test.dll" --dotnetruntime=il2cpp --dotnetprofile=unityaot --use-editor-options --platform=WindowsDesktop
@IF %ERRORLEVEL% NEQ 0 GOTO fail

"%~dp0\il2cpp-%VERSION%\build\deploy\netcoreapp3.1\il2cpp.exe" --generatedcppdir "%OUTDIR%\il2cpp" --convert-to-cpp --emit-null-checks --enable-array-bounds-check --dotnetprofile=unityaot --assembly "%OUTDIR%\stripped\Test.dll"
@IF %ERRORLEVEL% NEQ 0 GOTO fail

mkdir "%OUTDIR%\cache"
"%~dp0\il2cpp-%VERSION%\build\deploy\netcoreapp3.1\il2cpp.exe" --generatedcppdir "%OUTDIR%\il2cpp" --compile-cpp --platform=WindowsDesktop --architecture=x64 --outputpath "%OUT64%" --dotnetprofile=unityaot --configuration=Release --cachedirectory="%OUTDIR%\cache" --libil2cpp-static --baselib-directory="%~dp0\PlaybackEngines\windowsstandalonesupport\Variations\win64_nondevelopment_il2cpp" --avoid-dynamic-library-copy
@IF %ERRORLEVEL% NEQ 0 GOTO fail
rd /s /q "%OUTDIR%\cache"

mkdir "%OUTDIR%\cache"
"%~dp0\il2cpp-%VERSION%\build\deploy\netcoreapp3.1\il2cpp.exe" --generatedcppdir "%OUTDIR%\il2cpp" --compile-cpp --platform=WindowsDesktop --architecture=x86 --outputpath "%OUT32%" --dotnetprofile=unityaot --configuration=Release --cachedirectory="%OUTDIR%\cache" --libil2cpp-static --baselib-directory="%~dp0\PlaybackEngines\windowsstandalonesupport\Variations\win32_nondevelopment_il2cpp" --avoid-dynamic-library-copy
@IF %ERRORLEVEL% NEQ 0 GOTO fail
rd /s /q "%OUTDIR%\cache"

exit /B 0

:fail
@echo ======================= FAILED =======================
exit /B 1
