// 06.运算符 —— 陷阱合集
// Day 03 / 课程 06 补充
//
// 这一节是视频之外自己踩/查出来的，五个坑：
//   1. 整数除以 0 → 程序直接崩溃（浮点除以 0 反而没事）
//   2. 运算符优先级的反直觉案例
//   3. 同一个表达式里混用 ++ / -- → 未定义行为
//   4. 无符号数和有符号数混合比较 → 结果反直觉
//   5. 位运算和比较运算的优先级陷阱

#include <iostream>
#include <climits>
using namespace std;

int main() {
    // ============================================================
    // 坑 1：除零
    // ============================================================
    cout << "---- 坑 1：除以 0 ----" << endl;

    // 浮点除零：有明确定义，得到 inf
    double zero = 0.0;
    double one = 1.0;
    cout << "1.0 / 0.0  = " << one / zero << "   ← 浮点是 inf（无穷大），程序不崩" << endl;
    cout << "-1.0 / 0.0 = " << -one / zero << "  ← -inf" << endl;
    cout << "0.0 / 0.0  = " << zero / zero << "   ← nan（not a number）" << endl;

    // 整数除零：未定义行为，程序会直接崩
    int izero = 0;
    int ione = 1;
    cout << "\n整数除零不能在这里演示 —— 它会【直接让程序崩溃】。" << endl;
    cout << "如果取消下面两行的注释，你会看到：" << endl;
    cout << "    Runtime Error: Integer division by zero" << endl;
    cout << "    然后程序带着非 0 退出码终止，后面的代码一行都不会执行" << endl;
    // cout << ione / izero << endl;   // ← 取消注释 = 立刻崩溃

    // 所以整数除法前一定要判断
    int divisor = 0;
    int dividend = 100;
    if (divisor != 0) {
        cout << "\n安全写法：divisor != 0 才做除法。当前 divisor = " << divisor << "，跳过。" << endl;
    }

    // ============================================================
    // 坑 2：运算符优先级
    // ============================================================
    cout << "\n---- 坑 2：优先级的反直觉案例 ----" << endl;

    // 乘法优先于加法，这个大家知道
    cout << "2 + 3 * 4       = " << 2 + 3 * 4 << "      ← 乘先算，不是 20" << endl;

    // 但比较运算符优先于位运算符！这个是重灾区
    // 1 << 2 + 3   实际是   1 << (2 + 3) = 32
    cout << "\n1 << 2 + 3      = " << (1 << 2 + 3) << "     ← 竟然是 32，不是 7！" << endl;
    cout << "        因为 + 的优先级【高于】<<，" << endl;
    cout << "        实际是 1 << (2+3) = 1 << 5 = 32" << endl;
    cout << "        想得到 7 要写 (1 << 2) + 3 = " << ((1 << 2) + 3) << endl;

    // == 优先于 &，也非常反直觉
    int flags = 6;      // 二进制 110
    int mask  = 4;      // 二进制 100
    cout << "\nflags & mask == 4  = " << (flags & mask == 4) << endl;
    cout << "        你以为在算 (flags & mask) == 4" << endl;
    cout << "        实际是 flags & (mask == 4) —— == 优先级更高！" << endl;
    cout << "        mask == 4 得 true(1)，再和 6 做 & → 6 & 1 = " << (6 & 1) << endl;
    cout << "        正确写法 ((flags & mask) == 4) = " << ((flags & mask) == 4) << endl;

    // 逻辑运算符之间
    cout << "\n逻辑运算符优先级：!  >  &&  >  ||" << endl;
    cout << "true || false && false = " << (true || false && false) << endl;
    cout << "        实际是 true || (false && false) = true" << endl;
    cout << "        而不是 (true || false) && false = false" << endl;

    cout << "\n结论：优先级记不住就别硬记，【拿不准就加括号】。加括号不丢人，出 bug 才丢人。" << endl;

    // ============================================================
    // 坑 3：同一表达式里混用 ++ / -- → 未定义行为
    // ============================================================
    cout << "\n---- 坑 3：同一表达式混用自增 ----" << endl;

    int i = 5;
    int bad = i++ + ++i;      // ⚠️ 未定义行为！不同编译器结果不同
    cout << "i = 5 时执行  bad = i++ + ++i;" << endl;
    cout << "  本机（MSVC）算出来 bad = " << bad << "，i = " << i << endl;
    cout << "  但这个结果【没有任何保证】，换编译器/换优化等级可能就变了。" << endl;
    cout << "  这是未定义行为（UB），正确答案是：不要把 ++ 和别的运算写在同一行。" << endl;

    // 拆开写就完全没问题
    int j = 5;
    int good = j;
    j++;
    good += j;
    cout << "\n拆开写的版本（安全）：good = " << good << "，j = " << j << endl;

    // 同一个变量在一个表达式里被改两次，也属于 UB
    // int k = 1;
    // k = k++ + 1;      // ⚠️ UB，别写

    // ============================================================
    // 坑 4：有符号 / 无符号混合比较
    // ============================================================
    cout << "\n---- 坑 4：有符号和无符号比较 ----" << endl;

    int          si = -1;
    unsigned int ui = 1;

    cout << "int si = -1;  unsigned int ui = 1;" << endl;
    cout << "si > ui ?  " << (si > ui) << "   ← 竟然是 true！" << endl;
    cout << "\n原因：int 和 unsigned int 比较时，int 会被【隐式转成无符号】。" << endl;
    cout << "      -1 转成 unsigned 就是 " << (unsigned int)(-1) << "（32 位全 1）" << endl;
    cout << "      拿这个巨大数和 1 比，当然更大。" << endl;
    cout << "\n避免办法：别让有符号和无符号混着算；非要有符号，显式转换一下。" << endl;

    // 经典翻车场景：倒序遍历
    cout << "\n经典翻车场景（用无符号做倒序循环）：" << endl;
    cout << "  for (unsigned i = 5; i >= 0; i--) { ... }   ← 死循环！" << endl;
    cout << "  i 减到 0 后再减就回绕成 " << (unsigned int)(-1) << "，永远 >= 0" << endl;
    cout << "  正确做法：用 int，或者写成 for (unsigned i = 5; i-- > 0; )" << endl;

    // ============================================================
    // 坑 5：sizeof 和算术混用
    // ============================================================
    cout << "\n---- 坑 5：sizeof 返回的是无符号类型 ----" << endl;

    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;
    cout << "arr 的长度用 sizeof 算：" << endl;
    cout << "  sizeof(arr) / sizeof(arr[0]) = " << sizeof(arr) / sizeof(arr[0]) << "   ← 正确" << endl;
    cout << "\n但 sizeof 的结果类型是 size_t（无符号），拿去和有符号数相减要小心：" << endl;
    cout << "  sizeof(arr) - sizeof(int) = " << sizeof(arr) - sizeof(int) << "  ← 正常" << endl;
    cout << "  如果结果本该是负数，会回绕成一个巨大值（见坑 4）" << endl;

    return 0;
}
