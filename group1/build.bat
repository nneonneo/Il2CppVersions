@if not [%1]==[] goto main
@echo Usage: %0 ^<Version^>
@exit /B 1

:main
@set VERSION=%1
@echo ======================= %VERSION% =======================
@echo %DATE% %TIME%

set OUTDIR=%cd%\output\%VERSION%
rd /s /q "%OUTDIR%" 2>nul
mkdir "%OUTDIR%"
mkdir "%OUTDIR%\lib"
mkdir "%OUTDIR%\stripped"
mkdir "%OUTDIR%\il2cpp"

call "%~dp0\Mono\bin\smcs.bat" -t:library -out:"%OUTDIR%\lib\Test.dll" Test.cs
copy "%~dp0\Mono\lib\mono\2.0\mscorlib.dll" "%OUTDIR%\lib"

@REM could use -d "%~dp0\Mono\lib\mono\2.0" - but then we might compile a lot of DLLs
@REM so instead, just try to avoid using certain features
"%~dp0\UnusedByteCodeStripper2\UnusedBytecodeStripper2.exe" -out "%OUTDIR%\stripped" -l none -c link -b False -f "%~dp0/il2cpp-%VERSION%/LinkerDescriptors/" -d "%OUTDIR%\lib" -a "%OUTDIR%\lib\Test.dll"
@IF %ERRORLEVEL% NEQ 0 GOTO fail

"%~dp0\MonoBleedingEdge\bin\mono.exe" "%~dp0\il2cpp-%VERSION%\build\il2cpp.exe" --generatedcppdir "%OUTDIR%\il2cpp" --convert-to-cpp --copy-level=None --emit-null-checks --enable-array-bounds-check --assembly "%OUTDIR%\stripped\Test.dll"
@IF %ERRORLEVEL% NEQ 0 GOTO fail

@REM mono, for whatever reason, causes link.exe's printf to block forever. so, don't use mono to run il2cpp for compilation...
mkdir "%OUTDIR%\cache"
"%~dp0\il2cpp-%VERSION%\build\il2cpp.exe" --generatedcppdir "%OUTDIR%\il2cpp" --compile-cpp --platform=WindowsDesktop --architecture=x64 --outputpath "%OUTDIR%\libil2cpp-x64.dll" --configuration=Release --cachedirectory="%OUTDIR%\cache"
@IF %ERRORLEVEL% NEQ 0 GOTO fail
rd /s /q "%OUTDIR%\cache"

mkdir "%OUTDIR%\cache"
"%~dp0\il2cpp-%VERSION%\build\il2cpp.exe" --generatedcppdir "%OUTDIR%\il2cpp" --compile-cpp --platform=WindowsDesktop --architecture=x86 --outputpath "%OUTDIR%\libil2cpp-x86.dll" --configuration=Release --cachedirectory="%OUTDIR%\cache"
@IF %ERRORLEVEL% NEQ 0 GOTO fail
rd /s /q "%OUTDIR%\cache"

exit /B 0

:fail
@echo ======================= FAILED =======================
exit /B 1
