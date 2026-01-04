#include <iostream>
#include <vector>
#include <memory>
#include "Vec3.hpp"
#include "Particle.hpp"
#include "Field.hpp"
#include "Integrator.hpp"
#include "EulerIntegrator.hpp"
#include "UniformField.hpp"
#include "Simulation.hpp"
#include "CSVWriter.hpp"
int main(){
    auto field = std::make_shared<UniformField>(Vec3(0,0,0), Vec3(0,0,1));
    auto integrator = std::make_shared<EulerIntegrator>();
    auto writer = std::make_unique<CSVWriter>("data/output.csv");
    Simulation sim(std::move(writer), integrator, field, 0.001);
    sim.addParticle(Particle(Vec3(1,0,0), Vec3(0,1,0), 1, 1));
    sim.run(1000);

    std::cout << "Symulator czastek EM\n";
    return 0;
}
