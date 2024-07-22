#include <iostream>
#include <typeinfo>
#include <cxxabi.h>

struct A {
    const char a[6];
    const char b[3];
};
int main() {
    A a{};
    // 使用auto进行结构体绑定时不会发生类型退化
    const auto &[u, v] = a;
    // abi::cxa_demangle()，用来将类型名还原，包含于头文件<cxxabi.h>
    std::cout << abi::__cxa_demangle(typeid(decltype(u)).name(), nullptr, nullptr, nullptr) << std::endl;
    // 使用auto进行普通变量推导时会发生类型退化 const char[] -> const char*
    auto u2 = u;
    std::cout << abi::__cxa_demangle(typeid(decltype(u2)).name(), nullptr, nullptr, nullptr) << std::endl;

    return 0;
}