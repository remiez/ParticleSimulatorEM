#include <iostream>
#include "Vec3.hpp"
int main() {
    Vec3 wzero;
    Vec3 v1(1,2,3);
    Vec3 v2(4,5,6);
    
    Vec3 norm = v1.normalize();

    norm.Wypisz();

    std::cout << "Symulator czastek EM\n";
    return 0;
}
