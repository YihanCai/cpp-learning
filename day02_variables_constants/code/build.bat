@echo off
REM ============================================================
REM  Build all .cpp files in this folder with MSVC.
REM  Usage: double-click, or run "build.bat" in a terminal.
REM
REM  IMPORTANT (encoding):
REM    Source files must be saved as "UTF-8 with BOM".
REM    - UTF-8 without BOM  -> MSVC reads them as GBK, error C2001
REM    - adding /utf-8      -> Chinese output garbled in console
REM  This .bat itself is ASCII-only on purpose: cmd.exe reads
REM  batch files using the OEM codepage (936 on Chinese Windows),
REM  so non-ASCII bytes here would break command parsing.
REM ============================================================
setlocal enabledelayedexpansion

REM ---- Load VS environment if cl is not already available ----
where cl >nul 2>&1
if errorlevel 1 (
    if exist "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" (
        echo [i] Loading Visual Studio build environment...
        call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" >nul 2>&1
    ) else (
        echo [x] vcvars64.bat not found.
        echo     Please run this script inside "Developer Command Prompt for VS 2022".
        pause
        exit /b 1
    )
)

set OK=0
set FAIL=0

for %%f in (*.cpp) do (
    echo.
    echo ===^> Compiling %%f
    cl /nologo /EHsc /std:c++17 "%%f"
    if errorlevel 1 (
        echo     [FAIL] %%f
        set /a FAIL+=1
    ) else (
        echo     [OK]   %%~nf.exe
        set /a OK+=1
    )
)

echo.
echo ============================================
echo  Done. Success: !OK!   Failed: !FAIL!
echo ============================================
endlocal
