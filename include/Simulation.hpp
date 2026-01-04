#pragma once
#include <vector>
#include <memory>
#include "Field.hpp"
#include "Particle.hpp"
#include "Integrator.hpp"
#include "CSVWriter.hpp"
class Simulation{
    private:
    std::vector<Particle> particles;
    std::unique_ptr<CSVWriter> writer;
    std::shared_ptr<Integrator> integrator;
    std::shared_ptr<Field> field;
    double dt;
    double time;

    public:
    Simulation(std::vector<Particle> p, std::unique_ptr<CSVWriter> wr, std::shared_ptr<Integrator> in, std::shared_ptr<Field> f, double dt);
    Simulation(std::unique_ptr<CSVWriter> wr, std::shared_ptr<Integrator> in, std::shared_ptr<Field> f, double dt);
    void addParticle(const Particle& p);
    void step();
    void run(int steps);

    const std::vector<Particle>& getParticles() const;
    double getTime() const;

};