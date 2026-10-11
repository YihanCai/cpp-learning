@echo off
REM ============================================================
REM  Build all .cpp files in this folder with MSVC.
REM  Usage: double-click, or run "build.bat" in a terminal.
REM
REM  Why /W3: MSVC defaults to /W1, which silently hides real
REM  problems such as C4554 (suspicious operator precedence) and
REM  C4018 (signed/unsigned mismatch). /W3 catches those.
REM  /W4 is stricter but warns on lots of harmless teaching code,
REM  so we stop at /W3.
REM
REM  Encoding rules (see repo README):
REM    - .cpp must be saved as "UTF-8 with BOM"
REM    - do NOT pass /utf-8, it garbles Chinese console output
REM    - this .bat is ASCII-only WITH CRLF line endings:
REM      cmd.exe parses batch files in the OEM codepage (936),
REM      and LF-only endings can break command parsing.
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
    cl /nologo /EHsc /W3 /std:c++17 "%%f"
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
