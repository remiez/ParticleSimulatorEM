#include "Particle.hpp"
#include "Field.hpp"
#include "Integrator.hpp"
#include "RK4Integrator.hpp"
void RK4Integrator::step(const Field& field, Particle& particle, double t, double dt) const{
    Vec3 x = particle.getPosition();
    Vec3 v = particle.getVelocity();

    auto acceleration = [&](const Vec3& pos, const Vec3& vel, double time){
        Vec3 E = field.electric(pos, time);
        Vec3 B = field.magnetic(pos, time);

       return (particle.getCharge()*(E+vel.CrossProduct(B)))/particle.getMass();
    };

    Vec3 k1x = v;
    Vec3 k1v = acceleration(x, v, t);

    Vec3 k2x = v + 0.5*dt*k1x;
    Vec3 k2v = acceleration(x + dt*k1x*0.5, v + dt*k1v*0.5, t+0.5*dt);

    Vec3 k3x = v + 0.5*dt*k2x;
    Vec3 k3v = acceleration(x + dt*k2x*0.5, v + dt*k2v*0.5, t+0.5*dt);

    Vec3 k4x = v + 0.5*dt*k3x;
    Vec3 k4v = acceleration(x + 0.5*dt*k3x, v + 0.5*dt*k3v, t + dt);

    particle.setPosition(x + (dt/6)*(k1x + 2*k2x + 2*k3x + k4x));
    particle.setVelocity(v + (dt/6)*(k1v + 2*k2v + 2*k3v + k4v));

}