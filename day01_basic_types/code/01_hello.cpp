// 01.C++ 简介 —— 第一个 C++ 程序
// Day 01 / 课程 01
//
// 知识点：
//   1. #include <iostream> 引入标准输入输出流库
//   2. main() 是程序唯一入口，整个程序从它开始执行
//   3. std::cout 是"标准输出流"对象，配合 << 把内容送到屏幕
//   4. std::endl 换行并刷新缓冲区
//   5. return 0 表示程序正常结束

#include <iostream> // i=input o=output stream=流

int main() {
    // std:: 是命名空间前缀。cout 全名是 std::cout
    std::cout << "Hello, C++!" << std::endl;

    // 不用 endl 也可以，"\n" 更轻量（endl 会额外刷新缓冲区）
    std::cout << "Hello, 音乐汉堡!\n";

    // 一行里连续使用多个 <<
    std::cout << "我" << "在" << "学 C++" << std::endl;

    return 0; // 返回 0 告诉操作系统：程序正常退出
}
