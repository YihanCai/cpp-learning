// 03.基本数据类型 —— 拓展：整型溢出与精度陷阱
// Day 01 / 课程 03 补充
//
// 这两个坑是初学者最容易踩、也最容易被面试问到的：
//   1. 整型溢出（overflow）：超出范围会"绕回去"，不会报错
//   2. 浮点精度：float/double 存的是近似值，不能直接用 == 比较

#include <iostream>
#include <climits>
#include <iomanip> // setprecision

int main() {
    // ---------- 1. 整型溢出：最大 int 再加 1 ----------
    int maxInt = INT_MAX;
    std::cout << "INT_MAX     = " << maxInt << std::endl;
    std::cout << "INT_MAX + 1 = " << maxInt + 1 << std::endl; // 变成最小值（有符号溢出）
    std::cout << "这行代码编译器通常会警告，但不会报错——运行起来是'静默出错'。" << std::endl;

    // 无符号整型溢出是明确定义的行为：回绕到 0
    unsigned int u = 0;
    std::cout << "unsigned 0 - 1 = " << u - 1 << std::endl; // 4294967295

    // ---------- 2. 浮点精度 ----------
    // 0.1 + 0.2 在二进制浮点里不精确等于 0.3
    double a = 0.1;
    double b = 0.2;
    std::cout << std::setprecision(17); // 打印 17 位有效数字，暴露真相
    std::cout << "0.1 + 0.2      = " << a + b << std::endl;
    std::cout << "0.1 + 0.2 == 0.3 ? " << ((a + b) == 0.3) << std::endl;

    // 正确做法：判断差值是否小于一个很小的阈值（epsilon）
    const double EPS = 1e-9;
    std::cout << "正确比较方式   = " << (std::abs((a + b) - 0.3) < EPS) << std::endl;

    // float 的有效位数只有 7 位左右，超出就丢精度
    float fpi = 3.14159265358979323846f;
    std::cout << std::setprecision(10);
    std::cout << "float  pi = " << fpi << std::endl;
    std::cout << "double pi = " << (double)3.14159265358979323846 << std::endl;

    return 0;
}
