#include <vector>
#include <memory>
#include "Field.hpp"
#include "Particle.hpp"
#include "Integrator.hpp"
#include "Simulation.hpp"
Simulation::Simulation(std::vector<Particle> p, std::shared_ptr<Integrator> in, std::shared_ptr<Field> f, double dt)
    :particles(p), integrator(in), field(f), dt(dt), time(0.0)
{}
Simulation::Simulation(std::shared_ptr<Integrator> in, std::shared_ptr<Field> f, double dt)
    :particles(), integrator(in), field(f), dt(dt), time(0.0)
{}
void Simulation::addParticle(const Particle& p){
    particles.push_back(p);
}

void Simulation::step(){
    for(auto& p:particles){
        integrator->step(*field, p, time, dt);
    }
    time+=dt;
}

void Simulation::run(int steps){
    for(int i=0; i<steps; ++i){
        step();
    }
}

const std::vector<Particle>& Simulation::getParticles() const{
    return particles;
}

double Simulation::getTime() const{
    return time;
}
