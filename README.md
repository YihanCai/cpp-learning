# C++ Learning

跟着 B 站 **《【整整300集】这绝对是 B 站最全最细的 C++ 零基础全套教程》**
（[BV1Y6oVYGE4v](https://www.bilibili.com/video/BV1Y6oVYGE4v/)）每天学一点，
代码 + 笔记同步记录在这个仓库里。

## 为什么做这个仓库

- **逼自己写笔记**——看懂 ≠ 会写，能讲清楚才是真的会了
- **留痕**——把每天踩的坑攒起来，以后回头能查
- **代码可运行**——每份代码都在本机编译跑过，输出如实记录

## 环境

| 项目 | 值 |
| --- | --- |
| 操作系统 | Windows |
| IDE | Visual Studio 2022 Community |
| 编译器 | MSVC 14.38 (x64) |
| 验证方式 | 命令行 `cl` 编译 + 实际运行 |

## 学习进度

| 天 | 课程分集 | 主题 | 笔记 | 日期 |
| :---: | --- | --- | --- | --- |
| Day 01 | 01 ~ 03 | C++ 简介 / 编译工具 VS / 基本数据类型 | [📖 笔记](day01_basic_types/README.md) | 2026-10-05 |
| Day 02 | 04 | 变量和常量 | [📖 笔记](day02_variables_constants/README.md) | 2026-10-06 |
| Day 03 | 05 | 标识符和关键字 | 待学 | — |

## 目录结构

```
cpp_learning/
├── README.md                      # 本文件，总目录
├── day01_basic_types/             # Day 01
│   ├── README.md                  #   课程笔记（01~03）
│   └── code/
│       ├── 01_hello.cpp           #   第一个 C++ 程序
│       ├── 03_basic_types.cpp     #   基本类型 + sizeof 实测
│       ├── 03_pitfalls.cpp        #   溢出 & 浮点精度陷阱
│       └── build.bat              #   MSVC 批量编译脚本
├── day02_variables_constants/     # Day 02
│   ├── README.md                  #   课程笔记（04）
│   └── code/
│       ├── 04_variables.cpp       #   变量：定义、初始化、本质
│       ├── 04_constants.cpp       #   常量：三种写法、消灭魔法数字
│       ├── 04_pitfalls.cpp        #   未初始化 / 宏替换 / 作用域陷阱
│       └── build.bat
└── mode01/                        # VS 2022 工程（自己练习用）
    ├── mode01.sln
    └── mode01/main.cpp
```

> 约定：每天一个 `dayNN_主题/` 目录，内含 `README.md`（笔记）+ `code/`（可运行代码）。

## 怎么编译这些代码

**方式一：直接跑 `build.bat`（最省事）**

```bat
cd day02_variables_constants\code
build.bat
```

脚本会自动加载 VS 编译环境，把当前目录所有 `.cpp` 编成 `.exe`。
每个 `dayNN_主题/code/` 目录里都有一份。

**方式二：VS 开发者命令行**

```bat
:: 打开 "Developer Command Prompt for VS 2022"，cd 到代码目录
cl /nologo /EHsc /std:c++17 04_variables.cpp
04_variables.exe
```

**方式三：直接用 VS 打开 `mode01/mode01.sln`，按 `Ctrl + F5`**

## ⚠️ 编码约定（很重要，别踩）

| 文件类型 | 编码 | 原因 |
| --- | --- | --- |
| `.cpp` / `.h` | **UTF-8 带 BOM** | 无 BOM 会被 MSVC 当 GBK 读 → `error C2001`；有 BOM 才不会错位 |
| `.bat` | **纯 ASCII** | `cmd.exe` 按 GBK 读批处理，UTF-8 中文会打乱命令解析 |
| `.md` | UTF-8 | GitHub / 编辑器通吃 |

编译时**不要加 `/utf-8`**。它会让字符串以 UTF-8 字节输出，在中文 `cmd`（代码页 936）里反而乱码。
详细原理和实测对照表见 [Day 01 笔记的 2.5 节](day01_basic_types/README.md#25-中文编码vs-上最大的一个坑实测)。

## 笔记里记了些什么

不抄课件，只记「我原本不懂、现在懂了」的东西：

- 概念的本质（比如 `std::cout` 里 `std` 是什么、`<<` 为什么能连写）
- **平台差异**（`long` 在 Windows 4 字节、Linux 8 字节）
- **实测数据**（`sizeof` 真实结果、溢出到底变成什么数）
- **踩过的坑**（浮点 `==` 比较、整型静默溢出、中文编码连环坑）

## 参考

- 视频教程：[BV1Y6oVYGE4v](https://www.bilibili.com/video/BV1Y6oVYGE4v/) — 哔哩计算机大学
- 标准参考：[cppreference (中文)](https://zh.cppreference.com/)

---

_持续更新中 🍔_
