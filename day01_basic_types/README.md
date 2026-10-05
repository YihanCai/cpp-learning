# Day 01 — 01. C++ 简介 / 02. 编译工具 VS / 03. 基本数据类型

> 课程视频：[【整整300集】C++ 零基础全套教程 — BV1Y6oVYGE4v](https://www.bilibili.com/video/BV1Y6oVYGE4v/)
> 对应分集：**P2 01.C++简介**（4:02）、**P3 02.编译工具VS**（11:37）、**P4 03.基本数据类型**（9:11）
> 学习日期：2026-10-05

---

## 一、C++ 简介

### 1.1 C++ 是什么

C++ 是 **Bjarne Stroustrup** 在 1983 年（贝尔实验室）推出的语言，最初叫 _"C with Classes"_（带类的 C）。它是在 C 语言基础上扩展而来，所以：

- **兼容 C 的绝大部分语法**——C 的代码基本能直接当 C++ 编译
- **增加了面向对象**（类、继承、多态）、**泛型编程**（模板）、**STL 标准库**
- 是**编译型**、**静态类型**、**运行效率极高**的语言

### 1.2 为什么还要学 C++

| 场景 | 说明 |
| --- | --- |
| 游戏引擎 | Unreal Engine、Unity 底层、自研引擎 |
| 嵌入式 / 单片机 | 与宝宝在做的 ESP32 是同一片战场 |
| 桌面软件 | 浏览器内核、Office、Photoshop、QQ/微信部分模块 |
| 高频交易 / 量化 | 纳秒级延迟，只有 C++ 扛得住 |
| 基础软件 | 数据库（MySQL、MongoDB）、编译器、操作系统 |

> 一句话：**凡是"要求快"或"直接贴着硬件"的地方，都有 C++。**

### 1.3 一个 C++ 程序长什么样

```cpp
#include <iostream>   // ① 预处理：把 iostream 头文件的内容"贴"进来

int main() {          // ② 主函数：程序唯一入口
    std::cout << "Hello, C++!" << std::endl;  // ③ 向屏幕输出
    return 0;         // ④ 返回 0 表示正常结束
}
```

**逐行拆解：**

- `#include <iostream>`
  `i` = input，`o` = output，`stream` = 流 → 输入输出流。尖括号 `<>` 表示去**系统目录**找头文件；双引号 `""` 表示先在**当前目录**找。
- `int main()`
  有且只有一个。操作系统启动程序后第一件事就是找到并调用它。`int` 是返回值类型。
- `std::cout`
  `std` 是**命名空间**（namespace），`cout` 全名 `std::cout`，意思是"character output"——把内容输出到控制台。`::` 叫**作用域解析运算符**。
- `<<`
  **插入运算符**（也叫输出运算符）。可以理解成把右边的数据"喂"给左边的流，因此可以链式连写：
  `cout << "a" << "b" << "c";`
- `std::endl`
  换行 **并刷新缓冲区**。等价于 `'\n' + 强制刷盘`，频繁使用会拖慢速度，日常用 `"\n"` 更轻量。
- `return 0;`
  返回给操作系统。**0 = 成功**，非 0 = 出错。main 函数可以省略不写，编译器默认补 `return 0`。

---

## 二、编译工具：Visual Studio

### 2.1 为什么需要"编译"
C++ 是编译型语言，源码不能被机器直接执行：

```
源代码 .cpp ──[编译器]──> 目标文件 .obj ──[链接器]──> 可执行文件 .exe
```

- **编译（Compile）**：把 `.cpp` 翻译成机器码 `.obj`，并做语法检查
- **链接（Link）**：把 `.obj` 和你用到的库（如 `iostream` 的实现）拼在一起，产出 `.exe`

### 2.2 本机环境（已确认）

| 项目 | 值 |
| --- | --- |
| IDE | **Visual Studio 2022 Community** |
| 编译器 | MSVC **14.38.33130**（x64） |
| 安装路径 | `C:\Program Files\Microsoft Visual Studio\2022\Community` |
| vcvars 脚本 | `...\VC\Auxiliary\Build\vcvars64.bat` |

### 2.3 命令行编译（不依赖 IDE 的验证方式）

在 **"Developer Command Prompt for VS 2022"** 里执行：

```bat
cl /nologo /EHsc /utf-8 /std:c++17 03_basic_types.cpp
```

**参数解释：**

| 参数 | 作用 |
| --- | --- |
| `cl` | MSVC 编译器命令（Compile and Link） |
| `/nologo` | 不打印版本横幅 |
| `/EHsc` | 启用标准 C++ 异常处理，**写 C++ 必须加** |
| `/utf-8` | 源码和执行字符集都按 UTF-8 处理（**输出中文必须加，否则乱码**） |
| `/std:c++17` | 指定 C++17 标准 |

> 本目录下的 `build.bat` 就是批量编译脚本，双击或命令行运行即可。
> 如果不在 VS 开发者命令行里，可以先执行 `vcvars64.bat` 把环境变量加载进来。

### 2.4 VS 工程里常用的快捷键

| 快捷键 | 作用 |
| --- | --- |
| `Ctrl + F5` | 编译并运行（**不调试**，运行完窗口不会闪退） |
| `F5` | 调试运行（会停在断点） |
| `F9` | 在光标行打断点 |
| `F10` / `F11` | 单步跳过 / 单步进入 |
| `Ctrl + K, Ctrl + F` | 格式化选中代码 |

> **初学者建议一律用 `Ctrl + F5`**——用 `F5` 的话程序跑完窗口瞬间关闭，看不到输出，会误以为"程序没运行"。

---

## 三、基本数据类型

### 3.1 总览表

| 类型 | 关键字 | 本机 sizeof | 范围 / 说明 |
| --- | --- | :---: | --- |
| 字符型 | `char` | **1** | -128 ~ 127，本质是 1 字节整数 |
| 短整型 | `short` / `short int` | **2** | -32768 ~ 32767 |
| 整型 | `int` | **4** | -2147483648 ~ 2147483647（最常用） |
| 长整型 | `long` / `long int` | **4** | Windows 4 字节；Linux 64 位下是 8 字节 |
| 长长整型 | `long long` | **8** | ±9.2×10¹⁸ |
| 单精度浮点 | `float` | **4** | 有效数字约 7 位，字面量要带 `f` |
| 双精度浮点 | `double` | **8** | 有效数字约 15~16 位（最常用） |
| 长双精度浮点 | `long double` | **8** | Windows/MSVC 下与 double 相同 |
| 布尔型 | `bool` | **1** | 只有 `true` / `false`，输出为 `1` / `0` |

> ⚠️ **上表是本机 MSVC x64 的实测结果**（代码见 `03_basic_types.cpp`）。
> 标准只规定了「`sizeof(char) == 1`、`short ≤ int ≤ long ≤ long long`」这些**相对关系**，
> 具体字节数由**平台和编译器**决定，跨平台时要特别小心 `long`。

### 3.2 有符号 / 无符号

```cpp
int           a = -100;         // 有符号（signed），默认
unsigned int  b = 4000000000u;  // 无符号，只能表示 ≥ 0
```

- `unsigned` 把"负数那一半"挪到正数区间：`unsigned int` 范围变成 **0 ~ 4294967295**
- `signed` / `unsigned` 可以写在类型前后：`unsigned int`、`int unsigned` 等价
- ⚠️ **有符号和无符号混用运算时，有符号会被悄悄转成无符号**，这是经典 bug 来源：
  ```cpp
  int a = -1;
  unsigned int b = 1;
  if (a > b) { /* 竟然会进来！因为 a 变成了 4294967295 */ }
  ```

### 3.3 字面量后缀（告诉编译器"我是什么类型"）

| 后缀 | 含义 | 例子 |
| --- | --- | --- |
| `u` / `U` | unsigned | `42u` |
| `l` / `L` | long | `100000L` |
| `ll` / `LL` | long long | `10000000000LL` |
| `f` / `F` | float | `3.14f` |
| `l` / `L` | long double | `3.1415L` |

> 浮点字面量不加后缀时**默认是 `double`**。写 `float f = 3.14;` 会有精度截断警告，
> 正确写法是 `float f = 3.14f;`

### 3.4 `sizeof` 运算符

`sizeof` 不是函数，是**运算符**，编译期就能算出结果：

```cpp
sizeof(int)   // 4      类型
sizeof(x)     // 变量也能用
```

用途：查类型大小、算数组长度 `sizeof(arr) / sizeof(arr[0])`。

### 3.5 两个必须记住的坑（实测验证）

#### 坑 1：整型溢出不会报错，会"绕回去"

```cpp
int maxInt = INT_MAX;         // 2147483647
cout << maxInt + 1;           // 输出 -2147483648 ⚠️
```

有符号整型溢出在 C++ 标准里是**未定义行为（UB）**——编译器可能警告，但绝不报错，运行时静默给出错误结果。

无符号整型溢出的行为则是**明确定义**的：直接回绕。

```cpp
unsigned int u = 0;
cout << u - 1;                // 输出 4294967295
```

#### 坑 2：浮点数不能用 `==` 比较

```cpp
double a = 0.1, b = 0.2;
cout << setprecision(17) << a + b;   // 0.30000000000000004 ⚠️
cout << (a + b == 0.3);              // 0（false）
```

因为你写的 `0.1` 是**十进制**，而计算机存的是**二进制浮点**，十进制小数转二进制大多除不尽，只能存近似值。

**正确写法**——判断差值是否小于一个极小阈值：

```cpp
const double EPS = 1e-9;
bool ok = std::abs((a + b) - 0.3) < EPS;   // true
```

> 顺带一条实用建议：**涉及金额、精度要求高的计算，别用 float/double**，
> 用整数（以"分"为单位）或专门的十进制库。

### 3.6 类型转换速查

```cpp
double d = 3.99;
int i = d;              // 隐式转换：直接截断小数 → 3（不是四舍五入！）
int j = (int)3.99;      // C 风格强制转换
int k = static_cast<int>(3.99);   // C++ 推荐写法，意图清晰、编译器能检查
```

---

## 四、今天动手写的代码

| 文件 | 内容 |
| --- | --- |
| [`code/01_hello.cpp`](../code/01_hello.cpp) | 第一个程序：`cout`、`endl`、`return 0` |
| [`code/03_basic_types.cpp`](../code/03_basic_types.cpp) | 全部基本类型的声明、`sizeof` 实测、`INT_MIN/MAX` |
| [`code/03_pitfalls.cpp`](../code/03_pitfalls.cpp) | 整型溢出 + 浮点精度陷阱的实测复现 |
| [`code/build.bat`](../code/build.bat) | MSVC 批量编译脚本 |

**本机实测输出节选：**

```
INT_MAX     = 2147483647
INT_MAX + 1 = -2147483648          ← 溢出，静默出错
unsigned 0 - 1 = 4294967295        ← 无符号回绕
0.1 + 0.2      = 0.30000000000000004
0.1 + 0.2 == 0.3 ? 0               ← 经典的 false
sizeof(long)        = 4   (Windows)
sizeof(long double) = 8   (MSVC 与 double 同宽)
```

---

## 五、今日小结

**记住了什么**
1. C++ 是编译型 + 静态类型语言，`.cpp → .obj → .exe` 两步走
2. `main()` 是唯一入口；`std::cout <<` 链式输出；`endl` 换行并刷新
3. 基本类型：`char/short/int/long/long long` + `float/double/long double` + `bool`
4. `sizeof` 是运算符，本机 `int` = 4、`double` = 8
5. 溢出和浮点精度是两个"不报错但结果错"的坑

**待办 / 疑问**
- [ ] 试试把 `03_pitfalls.cpp` 里的 `INT_MAX + 1` 换成 `long long`，验证是否还有问题
- [ ] `long` 在 Windows 和 Linux 上宽度不同——写跨平台代码时怎么选类型？（下游 `int32_t` / `int64_t` 有答案）

**下一课预告**：04. 变量和常量

---

[← 返回总目录](../README.md) | [下一天：Day 02 →](../days/day02.md)
