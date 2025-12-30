#include "Vec3.hpp"
#include "Particle.hpp"
//konstruktory
Particle::Particle()
    :position(Vec3(0,0,0)), velocity(Vec3(0,0,0)), charge(0), mass(1)
{}

Particle::Particle(Vec3 p, Vec3 v , double ch, double m)
    :position(p), velocity(v), charge(ch), mass(m)
{}

Particle::Particle(const Particle& other)
    :position(other.position), velocity(other.velocity), charge(other.charge), mass(other.mass)
{}

//settery
void Particle::setPosition(const Vec3& p){
    position = p;
}

void Particle::setVelocity(const Vec3& v){
    velocity = v;
}

//gettery
const Vec3& Particle::getPosition() const{
    return position;
}

const Vec3& Particle::getVelocity() const{
    return velocity;
}

double Particle::getMass(){
    return mass;
}

double Particle::getCharge(){
    return charge;
}

double Particle::getKineticEnergy(){
    return 0.5*mass*velocity.length2();
}

