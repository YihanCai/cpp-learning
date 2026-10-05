@echo off
REM 用 MSVC 编译当前目录下所有 .cpp（在 VS 开发者命令提示符中运行）
for %%f in (*.cpp) do (
    echo ===^> 编译 %%f
    cl /nologo /EHsc /utf-8 /std:c++17 "%%f"
)
