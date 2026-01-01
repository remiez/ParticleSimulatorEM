#include <iostream>
#include "Vec3.hpp"
#include "Particle.hpp"
#include "Field.hpp"
#include "Integrator.hpp"
#include "EulerIntegrator.hpp"
#include "UniformField.hpp"
int main() {
    double t=0;
    double dt=0.001;
    int steps = 1000;
    Vec3 predkosc(1,1,0);
    Vec3 polozenie(0,0,0);
    Vec3 E(0,0,0);
    Vec3 B(0,0,1);
    Particle czastka(polozenie, predkosc, 1, 1);
    UniformField pole(E, B);
    EulerIntegrator integrator;
    for(int i = 0; i < steps; ++i){
        if(i%100==0){
            Vec3 x = czastka.getPosition();
            Vec3 v = czastka.getVelocity();
            std::cout<<"polozenie to: ("<<x.getX()<<", "<<x.getY()<<", "<<x.getZ()<<")  ";
            std::cout<<"predkosc to: ("<<v.getX()<<", "<<v.getY()<<", "<<v.getZ()<<")\n";
        }
        integrator.step(pole, czastka, dt, t);
        t += dt;
    } 

    std::cout << "Symulator czastek EM\n";
    return 0;
}
