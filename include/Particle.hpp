#pragma once
#include "Vec3.hpp"
class Particle{
    private:
    Vec3 position;
    Vec3 velocity;
    double charge;
    double mass;

    public:
    Particle();
    Particle(Vec3 p, Vec3 v , double ch, double m);
    Particle(const Particle& other);

    void setPosition(const Vec3& p);
    void setVelocity(const Vec3& v);

    const Vec3& getPosition() const;
    const Vec3& getVelocity() const;
    double getMass();
    double getCharge();
    double getKineticEnergy();



};