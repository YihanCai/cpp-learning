// 03.基本数据类型 —— 最常用的几个类型
// Day 01 / 课程 03
//
// 知识点：
//   1. C++ 是"静态类型"语言：变量必须先声明类型，之后不能随便变
//   2. 整型 family：short / int / long / long long（有符号、无符号两套）
//   3. 浮点 family：float / double / long double
//   4. 字符型：char（本质是 1 字节的整数）
//   5. 布尔型：bool（true / false，底层存 1 / 0）
//   6. 关键工具：sizeof 运算符，查看类型占几个字节

#include <iostream>
#include <climits> // 存放整型极值常量，如 INT_MAX

int main() {
    // ---------- 1. 整型 ----------
    short s = 10;                // 短整型，一般 2 字节
    int i = 100;                 // 整型，一般 4 字节（最常用）
    long l = 100000L;            // 长整型，Windows 上是 4 字节，Linux 上是 8 字节
    long long ll = 10000000000LL; // 长长整型，保证 8 字节

    std::cout << "s   = " << s << std::endl;
    std::cout << "i   = " << i << std::endl;
    std::cout << "l   = " << l << std::endl;
    std::cout << "ll  = " << ll << std::endl;

    // 无符号：只能表示非负数，范围整体往正方向平移
    unsigned int ui = 4000000000u;

    std::cout << "ui  = " << ui << std::endl;

    // ---------- 2. 浮点型 ----------
    float f = 3.14f;      // 单精度，一般 4 字节；字面量必须带 f，否则默认是 double
    double d = 3.1415926; // 双精度，一般 8 字节（最常用）
    long double ld = 3.1415926535L;

    std::cout << "f   = " << f << std::endl;
    std::cout << "d   = " << d << std::endl;
    std::cout << "ld  = " << ld << std::endl;

    // ---------- 3. 字符型 ----------
    char c = 'A';       // 单引号，只能放一个字符
    char c2 = 66;       // 也可以用整数赋值，66 就是 'B' 的 ASCII 码

    std::cout << "c   = " << c << "  (ASCII " << (int)c << ")" << std::endl;
    std::cout << "c2  = " << c2 << std::endl;

    // ---------- 4. 布尔型 ----------
    bool b1 = true;
    bool b2 = false;

    std::cout << "b1  = " << b1 << "  (输出 1)" << std::endl;
    std::cout << "b2  = " << b2 << "  (输出 0)" << std::endl;
    std::cout << "1 == 1 : " << (1 == 1) << std::endl;
    std::cout << "1 >  2 : " << (1 > 2) << std::endl;

    // ---------- 5. sizeof：看类型占多少字节 ----------
    std::cout << "---- sizeof ----" << std::endl;
    std::cout << "sizeof(bool)        = " << sizeof(bool) << std::endl;
    std::cout << "sizeof(char)        = " << sizeof(char) << std::endl;
    std::cout << "sizeof(short)       = " << sizeof(short) << std::endl;
    std::cout << "sizeof(int)         = " << sizeof(int) << std::endl;
    std::cout << "sizeof(long)        = " << sizeof(long) << "  (Windows 平台)" << std::endl;
    std::cout << "sizeof(long long)   = " << sizeof(long long) << std::endl;
    std::cout << "sizeof(float)       = " << sizeof(float) << std::endl;
    std::cout << "sizeof(double)      = " << sizeof(double) << std::endl;
    std::cout << "sizeof(long double) = " << sizeof(long double) << std::endl;

    // ---------- 6. 取值范围 ----------
    std::cout << "---- int 的取值范围 ----" << std::endl;
    std::cout << "INT_MIN = " << INT_MIN << std::endl;
    std::cout << "INT_MAX = " << INT_MAX << std::endl;

    return 0;
}
