#include <vector>
#include <memory>
#include "Field.hpp"
#include "Particle.hpp"
#include "Integrator.hpp"
#include "Simulation.hpp"
#include "CSVWriter.hpp"
Simulation::Simulation(std::vector<Particle> p, std::unique_ptr<CSVWriter> wr, std::shared_ptr<Integrator> in, std::shared_ptr<Field> f, double dt)
    :particles(p), writer(std::move(wr)), integrator(in), field(f), dt(dt), time(0.0)
{}
Simulation::Simulation(std::unique_ptr<CSVWriter> wr, std::shared_ptr<Integrator> in, std::shared_ptr<Field> f, double dt)
    :particles(), writer(std::move(wr)), integrator(in), field(f), dt(dt), time(0.0)
{}
void Simulation::addParticle(const Particle& p){
    particles.push_back(p);
}

void Simulation::step(){
    int k = 1;
    for(auto& p:particles){
        integrator->step(*field, p, time, dt);
        writer->WriteInhalt(time, k, p.getPosition().getX(), p.getPosition().getY(), p.getPosition().getZ(), p.getVelocity().getX(), p.getVelocity().getY(), p.getVelocity().getZ(), p.getKineticEnergy());
        k+=1;
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
