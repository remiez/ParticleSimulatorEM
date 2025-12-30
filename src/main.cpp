#include <iostream>
#include "Vec3.hpp"
#include "Particle.hpp"
int main() {
    Vec3 pos(0,0,0);
    Vec3 vel(1,0,0);
    Particle p0;
    Particle p1(pos, vel, 1, 1);
    
    (p1.getPosition()).Wypisz();
    (p1.getVelocity()).Wypisz();
    std::cout<<p1.getMass()<<"\n";
    std::cout<<p1.getCharge()<<"\n";
    std::cout<<p1.getKineticEnergy()<<"\n";
    std::cout<<"\n";

    p1.setPosition(Vec3(1,1,1));
    p1.setVelocity(Vec3(2,0,0));

    p1.getPosition().Wypisz();
    p1.getVelocity().Wypisz();
    std::cout<<p1.getKineticEnergy()<<"\n";

    std::cout << "Symulator czastek EM\n";
    return 0;
}
