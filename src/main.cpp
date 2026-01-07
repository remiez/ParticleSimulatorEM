#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <cctype>
#include "Vec3.hpp"
#include "Particle.hpp"
#include "Field.hpp"
#include "Integrator.hpp"
#include "EulerIntegrator.hpp"
#include "UniformField.hpp"
#include "Simulation.hpp"
#include "CSVWriter.hpp"
#include "RK4Integrator.hpp"
#include "Config.hpp"

int main(){
    Config config("config.txt");
    auto field = std::make_shared<UniformField>(config.getE(), config.getB());
    std::shared_ptr<Integrator> integrator;
    if(config.getIntegrator() == "EulerIntegrator"){
        integrator = std::make_shared<EulerIntegrator>();
        
    }
    else if(config.getIntegrator() == "RK4Integrator"){
        integrator = std::make_shared<RK4Integrator>();
    }
    else{
        std::cout<<"podano zly integrator \n";
    }
    auto writer = std::make_unique<CSVWriter>("data/output.csv");
    Simulation sim(std::move(writer), integrator, field, config.getDt());
    for(const auto& p:config.getParticles()){
        sim.addParticle(p);
    }
    sim.run(config.getSteps());

    std::cout << "Symulator czastek EM\n";
    return 0;
}
