<<<<<<< HEAD
#include "fraction.h"

void print(const bool& f) {
    if (f)
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;
}

int main() {
    fraction f1, f2;
    std::cin >> f1 >> f2;
    std::cout << f1 + f2 << ' ' << f1 - f2 << ' '
        << f1 * f2 << ' ' << f1 / f2 << std::endl;
    f1 += f2;
    std::cout << f1 << std::endl;
    f1 *= f2;
    std::cout << f1 << std::endl;
    f1 -= f2;
    std::cout << f1 << std::endl;
    f1 /= f2;
    std::cout << f1 << std::endl;
    print(f1 == f2);
    print(f1 != f2);
    print(f1 < f2);
    print(f1 > f2);
    print(f1 <= f2);
    print(f1 >= f2);
    return 0;
}


=======
#include "fraction.h"

void print(const bool& f) {
    if (f)
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;
}

int main() {
    fraction f1, f2;
    std::cin >> f1 >> f2;
    std::cout << f1 + f2 << ' ' << f1 - f2 << ' '
        << f1 * f2 << ' ' << f1 / f2 << std::endl;
    f1 += f2;
    std::cout << f1 << std::endl;
    f1 *= f2;
    std::cout << f1 << std::endl;
    f1 -= f2;
    std::cout << f1 << std::endl;
    f1 /= f2;
    std::cout << f1 << std::endl;
    print(f1 == f2);
    print(f1 != f2);
    print(f1 < f2);
    print(f1 > f2);
    print(f1 <= f2);
    print(f1 >= f2);
    return 0;
}


>>>>>>> cb73fa683f44cfac30efa94f2b3548a5d45d7a6c
