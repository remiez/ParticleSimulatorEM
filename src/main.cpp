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
void printHelp() {
    std::cout <<
R"(Symulator cząstek naładowanych w polu elektromagnetycznym

Użycie:
  ./symulator <plik_konfiguracyjny>

Opis:
  Program symuluje ruch wielu cząstek naładowanych w 3D
  w zewnętrznym polu elektromagnetycznym zgodnie z
  klasycznym równaniem siły Lorentza.

Opcje:
  --help        Wyświetla tę pomoc
)";
}

int main(int argc, char* argv[]){
    std::string configPath;
    if(argc!=2){
        std::cerr<<"Błąd: podano złą liczbe argumentów zostanie użyty plik konfigurujący config.txt\n";
        std::cout<<"jak nie wiadomo jak uruchomić wpisz --help\n";
        configPath = "config.txt";
    }
    else if(std::string(argv[1]) == "--help"){
        printHelp();
        return 0;
    }
    else{
        configPath = argv[1];
    }
    try{
    Config config(configPath);
    auto writer = std::make_unique<CSVWriter>("data/output.csv");
    Simulation sim(std::move(writer), config.getIntegrator(), config.getField(), config.getDt());
    for(const auto& p:config.getParticles()){
        sim.addParticle(p);
    }
    sim.run(config.getSteps());
    }
    catch(const std::exception& e){
        std::cerr<<"Błąd: "<<e.what()<<"\n";
        return 1;
    }
    std::cout << "Symulator czastek EM\n";
    return 0;
}
