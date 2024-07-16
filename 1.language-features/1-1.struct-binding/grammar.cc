#include <iostream>

struct A {
    int a{0};
    double b{0.0};
    A() = default;
    A(const int a, const double b) : a(a), b(b) {
        std::cout << "copy A" << std::endl;
    }
};

int main() {
    A a{1, 1.0};
    auto [u1, v1] {a};
    std::cout << "initial value: " << u1 << " " << v1 << std::endl;
    u1 = 10;
    std::cout <<  "after modified: "<< a.a << " " << a.b << std::endl;

    auto &[u2, v2] {a};
    std::cout << "initial value: " << u2 << " " << v2 << std::endl;
    u2 = 20;
    std::cout <<  "after modified: "<< a.a << " " << a.b << std::endl;

    return 0;
}
