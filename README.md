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
| Day 02 | 04 ~ 05 | 变量和常量 / 标识符和关键字 | [📖 笔记](days/day02.md) | 待学 |

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
└── days/
    └── day02.md                   # Day 02 占位
```

## 怎么编译这些代码

**方式一：VS 开发者命令行（推荐）**

```bat
:: 打开 "Developer Command Prompt for VS 2022"，cd 到代码目录
cl /nologo /EHsc /utf-8 /std:c++17 03_basic_types.cpp
03_basic_types.exe
```

**方式二：直接跑 `build.bat`**

```bat
cd day01_basic_types\code
build.bat
```

> ⚠️ 两个关键参数别漏：
> - `/EHsc` —— 启用标准 C++ 异常处理
> - `/utf-8` —— 源码按 UTF-8 解析（**输出中文乱码就是漏了它**）

## 笔记里记了些什么

不抄课件，只记「我原本不懂、现在懂了」的东西：

- 概念的本质（比如 `std::cout` 里 `std` 是什么、`<<` 为什么能连写）
- **平台差异**（`long` 在 Windows 4 字节、Linux 8 字节）
- **实测数据**（`sizeof` 真实结果、溢出到底变成什么数）
- **踩过的坑**（浮点 `==` 比较、整型静默溢出）

## 参考

- 视频教程：[BV1Y6oVYGE4v](https://www.bilibili.com/video/BV1Y6oVYGE4v/) — 哔哩计算机大学
- 标准参考：[cppreference (中文)](https://zh.cppreference.com/)

---

_持续更新中 🍔_
