// 04.变量和常量 —— 变量
// Day 02 / 课程 04
//
// 知识点：
//   1. 变量是什么：一块内存空间起了个名字
//   2. 定义语法：数据类型 变量名 = 初始值;
//   3. 三种初始化写法：赋值 / 括号 / 列表（C++11）
//   4. 「初始化」和「赋值」是两回事
//   5. 用 & 取地址，亲眼看到变量在内存里

#include <iostream>
#include <string>
using namespace std;

int main() {
    // ---------- 1. 最基本的定义 ----------
    // 语法：数据类型 变量名 = 初始值;
    //        ↑ 三要素缺一不可（初值可以后补）
    int age = 18;
    cout << "age = " << age << endl;

    // 变量的值可以改（这就是"变"量）
    age = 19;
    cout << "改了之后 age = " << age << endl;

    // ---------- 2. 三种初始化写法 ----------
    int a = 10;      // ① 赋值初始化，最常用、最直观
    int b(20);       // ② 括号初始化，从 C 语言继承来的
    int c{30};       // ③ 列表初始化，C++11 新增，推荐

    int d{};         // 不写值 = 初始化成 0（注意：这是"初始化"，不是"没管"）
    cout << "a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;

    // 列表初始化有个好处：编译器会拦住"窄化转换"
    // int e{3.14};   // ← 取消注释会编译报错，因为 3.14 是 double，塞进 int 会丢小数
    int e = 3.14;     //    而赋值初始化只给你一个警告，照样编过
    cout << "e = " << e << "（3.14 被截断，且只是警告，不报错）" << endl;

    // ---------- 3. 初始化 ≠ 赋值 ----------
    // 初始化：变量"出生"时就带上值
    int init = 100;
    // 赋值：变量已经存在，再把新值"覆盖"上去
    init = 200;
    cout << "init = " << init << endl;
    // 现阶段看结果一样，但概念要分清：初始化只发生一次，赋值可以无数次。

    // ---------- 4. 变量的本质：内存里的一个格子 ----------
    // 变量名只是给人看的，CPU 只认地址。
    // &变量名 就是取这个变量在内存中的地址。
    int value = 42;
    cout << "\n---- 变量的本质 ----" << endl;
    cout << "value 的值   = " << value << endl;
    cout << "value 的地址 = " << &value << "（这是 16 进制的内存地址）" << endl;
    cout << "sizeof(value) = " << sizeof(value) << " 字节" << endl;

    // ---------- 5. 不同数据类型各占各的格子 ----------
    char        vChar   = 'A';
    short       vShort  = 100;
    int         vInt    = 10000;
    long long   vLong   = 10000000000LL;
    float       vFloat  = 3.14f;
    double      vDouble = 3.14159;
    bool        vBool   = true;
    string      vStr    = "字符串";

    cout << "\n---- 各类型的变量 ----" << endl;
    cout << "char   " << sizeof(vChar)   << " 字节  " << vChar << endl;
    cout << "short  " << sizeof(vShort)  << " 字节  " << vShort << endl;
    cout << "int    " << sizeof(vInt)    << " 字节  " << vInt << endl;
    cout << "long long " << sizeof(vLong) << " 字节  " << vLong << endl;
    cout << "float  " << sizeof(vFloat)  << " 字节  " << vFloat << endl;
    cout << "double " << sizeof(vDouble) << " 字节  " << vDouble << endl;
    cout << "bool   " << sizeof(vBool)   << " 字节  " << vBool << endl;
    cout << "string " << sizeof(vStr)    << " 字节  " << vStr << "（string 是类，sizeof 只是对象自身大小）" << endl;

    // ---------- 6. 局部变量和全局变量的作用域 ----------
    // 这里的 x 只在 main 的 {} 里活着
    int x = 1;
    {
        // 这里又定义了一个 x，它和外层的 x 不是同一个变量
        int x = 2;
        cout << "\n内层 x = " << x << "（内层的，暂时盖住了外层）" << endl;
    }
    cout << "外层 x = " << x << "（内层那个已经没了）" << endl;

    return 0;
}
