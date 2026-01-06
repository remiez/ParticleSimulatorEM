#pragma once
#include "Particle.hpp"
#include "Field.hpp"
#include "Integrator.hpp"
class RK4Integrator: public Integrator{
    public:
    virtual void step(const Field& field, Particle& particle, double t, double dt) const override;
};