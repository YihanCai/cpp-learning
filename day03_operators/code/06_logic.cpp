// 06.运算符 —— 逻辑运算符、短路求值、三目运算符
// Day 03 / 课程 06
//
// 知识点：
//   1. 三个逻辑运算符：&&（与） ||（或） !（非）
//   2. 【重点】短路求值：&& 左边为假就不再算右边，|| 左边为真就不再算右边
//   3. 短路求值的实战用途：防止数组越界 / 防止除零
//   4. 三目运算符 条件 ? 值1 : 值2
//   5. 【C++ 特色】三目运算符的结果是引用，可以当左值

#include <iostream>
using namespace std;

int main() {
    // ============================================================
    // 1. 三个逻辑运算符
    // ============================================================
    cout << "---- 逻辑运算符 ----" << endl;
    cout << boolalpha;   // 让 bool 显示成 true/false

    bool t = true, f = false;

    cout << "true  && true  = " << (t && t) << endl;
    cout << "true  && false = " << (t && f) << endl;
    cout << "false && true  = " << (f && t) << "   ← 有一个假，就整体假" << endl;
    cout << "false && false = " << (f && f) << endl;

    cout << endl;
    cout << "true  || true  = " << (t || t) << endl;
    cout << "true  || false = " << (t || f) << "   ← 有一个真，就整体真" << endl;
    cout << "false || true  = " << (f || t) << endl;
    cout << "false || false = " << (f || f) << endl;

    cout << endl;
    cout << "!true  = " << !t << endl;
    cout << "!false = " << !f << endl;

    // 用整数当条件：非 0 即真
    cout << "\n---- 非 0 即真 ----" << endl;
    cout << "5  && 1  = " << (5 && 1) << endl;
    cout << "5  && 0  = " << (5 && 0) << "   ← 0 当假处理" << endl;
    cout << "-1 && 1  = " << (-1 && 1) << "   ← 负数也是真" << endl;
    cout << "!!5      = " << (!!5) << "   ← 双非：把任意值压成 bool" << endl;

    // ============================================================
    // 2. 【重点】短路求值
    // ============================================================
    cout << "\n---- 短路求值 ----" << endl;
    cout << "规则：&& 左边已经为假，右边【根本不执行】" << endl;
    cout << "      || 左边已经为真，右边【根本不执行】" << endl;

    int count = 0;
    // 写了一个带副作用的函数，看它到底有没有被调用
    // （这里用 lambda 模拟，后面学到函数就懂了）
    auto sideEffect = [&count]() -> bool {
        count++;
        return true;
    };

    count = 0;
    bool r1 = false && sideEffect();
    cout << "\nfalse && sideEffect()   结果 = " << r1
         << "，右侧被调用了 " << count << " 次  ← 没执行" << endl;

    count = 0;
    bool r2 = true || sideEffect();
    cout << "true  || sideEffect()   结果 = " << r2
         << "，右侧被调用了 " << count << " 次  ← 没执行" << endl;

    count = 0;
    bool r3 = true && sideEffect();
    cout << "true  && sideEffect()   结果 = " << r3
         << "，右侧被调用了 " << count << " 次  ← 执行了" << endl;

    count = 0;
    bool r4 = false || sideEffect();
    cout << "false || sideEffect()   结果 = " << r4
         << "，右侧被调用了 " << count << " 次  ← 执行了" << endl;

    // ============================================================
    // 3. 短路求值的实战用途
    // ============================================================
    cout << "\n---- 短路的实战用途：用顺序保护后面的操作 ----" << endl;

    int arr[5] = {10, 20, 30, 40, 50};
    int index = 10;      // 故意越界

    // ❌ 危险写法：先访问再判断，越界就完了
    // if (arr[index] > 0 && index < 5) { }
    //
    // ✅ 正确写法：把范围判断放前面，越界时右边根本不执行
    if (index < 5 && arr[index] > 0) {
        cout << "index 合法，arr[index] = " << arr[index] << endl;
    } else {
        cout << "index = " << index << " 越界了，但因为短路，arr[10] 从未被访问 → 安全" << endl;
    }

    // 同理可以防除零
    int divisor = 0;
    if (divisor != 0 && 100 / divisor > 5) {
        cout << "能整除" << endl;
    } else {
        cout << "divisor = 0，短路跳过了除法 → 避免了崩溃" << endl;
    }

    // ============================================================
    // 4. 三目运算符
    // ============================================================
    cout << "\n---- 三目运算符 条件 ? 值1 : 值2 ----" << endl;

    int a = 10, b = 20;
    int maxVal = (a > b) ? a : b;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "(a > b) ? a : b  = " << maxVal << "   ← 取较大的那个" << endl;

    string result = (a % 2 == 0) ? "偶数" : "奇数";
    cout << "a 是 " << result << endl;

    // 可读性提醒
    cout << "\n提醒：三目不要嵌套太多层，三层以上就该改成 if-else 了。" << endl;

    // ============================================================
    // 5. 【C++ 特色】三目运算符的结果是"引用"，可以当左值
    // ============================================================
    cout << "\n---- C++ 特色：三目可以当左值 ----" << endl;

    int p = 1, q = 2;
    cout << "初始 p = " << p << ", q = " << q << endl;

    // 这一行在 C 语言里是【错误】的，但在 C++ 里合法！
    (p > q ? p : q) = 100;

    cout << "(p > q ? p : q) = 100;  之后" << endl;
    cout << "  p = " << p << "（没变）" << endl;
    cout << "  q = " << q << "（被改了，因为 q 比较大，选中的是它）" << endl;
    cout << "\n原理：C++ 的三目运算符返回的是【引用】而非值，所以能被赋值。" << endl;
    cout << "C 语言里这么写会编译报错，这是 C++ 和 C 的一个区别。" << endl;
    cout << "（实际写代码别这么用，可读性太差，面试题里见得多）" << endl;

    return 0;
}
