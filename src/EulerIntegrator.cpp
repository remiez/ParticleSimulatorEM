#include "Particle.hpp"
#include "Field.hpp"
#include "Integrator.hpp"
#include "EulerIntegrator.hpp"
void EulerIntegrator::step(const Field& field, Particle& particle, double t, double dt) const{
    Vec3 x = particle.getPosition();
    Vec3 v = particle.getVelocity();

    Vec3 E = field.electric(x, t);
    Vec3 B = field.magnetic(x, t);

    Vec3 a = (particle.getCharge()*(E+v.CrossProduct(B)))/particle.getMass();

    particle.setVelocity(v+a*dt);
    particle.setPosition(x+v*dt);
}