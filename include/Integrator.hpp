#pragma once
#include "Particle.hpp"
#include "Field.hpp"
class Integrator{
    public:
    virtual ~Integrator() = default;
    virtual void step(const Field& field, Particle& particle, double t, double dt) const = 0;
};