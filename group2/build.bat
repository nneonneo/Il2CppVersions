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

call "%~dp0\Mono\bin\smcs.bat" -t:library -out:"%OUTDIR%\lib\Test.dll" Test.cs
copy "%~dp0\Mono\lib\mono\2.0\mscorlib.dll" "%OUTDIR%\lib"

"%~dp0\il2cpp-%VERSION%\build\UnityLinker.exe" --out="%OUTDIR%\stripped" --i18n=none --core-action=link --descriptor-directory="%~dp0/il2cpp-%VERSION%/LinkerDescriptors/" --search-directory="%OUTDIR%\lib" --include-assembly="%OUTDIR%\lib\Test.dll"
@IF %ERRORLEVEL% NEQ 0 GOTO fail

"%~dp0\il2cpp-%VERSION%\build\il2cpp.exe" --generatedcppdir "%OUTDIR%\il2cpp" --convert-to-cpp --copy-level=None --emit-null-checks --enable-array-bounds-check --assembly "%OUTDIR%\stripped\Test.dll"
@IF %ERRORLEVEL% NEQ 0 GOTO fail

mkdir "%OUTDIR%\cache"
"%~dp0\il2cpp-%VERSION%\build\il2cpp.exe" --generatedcppdir "%OUTDIR%\il2cpp" --compile-cpp --platform=WindowsDesktop --architecture=x64 --outputpath "%OUT64%" --configuration=Release --cachedirectory="%OUTDIR%\cache" --libil2cpp-static
@IF %ERRORLEVEL% NEQ 0 GOTO fail
rd /s /q "%OUTDIR%\cache"

mkdir "%OUTDIR%\cache"
"%~dp0\il2cpp-%VERSION%\build\il2cpp.exe" --generatedcppdir "%OUTDIR%\il2cpp" --compile-cpp --platform=WindowsDesktop --architecture=x86 --outputpath "%OUT32%" --configuration=Release --cachedirectory="%OUTDIR%\cache" --libil2cpp-static
@IF %ERRORLEVEL% NEQ 0 GOTO fail
rd /s /q "%OUTDIR%\cache"

exit /B 0

:fail
@echo ======================= FAILED =======================
exit /B 1
