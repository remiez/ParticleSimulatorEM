#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include "Config.hpp"
#include "Vec3.hpp"
Config::Config(const std::string& filename){
    std::ifstream file(filename);
    if(!file) throw std::runtime_error("Nie mogę otworzyć pliku: " + filename);
    std::string line;
    while(std::getline(file,line)){
        if(line.empty() || line[0]=='#') continue;

        auto pos = line.find("=");
        if(pos == std::string::npos) continue;
        std::string key = trim(line.substr(0,pos));
        std::string value = trim(line.substr(pos+1));

        if(key == "dt") dt = std::stod(value);
        else if(key == "steps") steps = std::stoi(value);
        else if(key == "integrator") integrator = value;
        else if(key == "E") E = parseVec3(value);
        else if(key == "B") B = parseVec3(value);
        else if(key == "particles"){
            N = std::stoi(value);
            x.resize(N+1);
            v.resize(N+1);
            q.resize(N+1);
            m.resize(N+1);
            continue;
        }
        for(int i = 1; i <= N; ++i){
            if(key == "particle" + std::to_string(i) + ".x") x[i] = parseVec3(value);
            else if(key == "particle" + std::to_string(i) + ".v") v[i] = parseVec3(value);
            else if(key == "particle" + std::to_string(i) + ".q") q[i] = std::stod(value);
            else if(key == "particle" + std::to_string(i) + ".m") m[i] = std::stod(value);
        }
    }
    for(int i = 1; i <= N; ++i){
        particles.emplace_back(Particle(x[i], v[i], q[i], m[i]));
    }
}

Vec3 Config::parseVec3(const std::string& s){
    std::istringstream iss(s);
    double x,y,z;
    if(!(iss >>x>>y>>z)){
        throw std::runtime_error("Błędny Vec3" + s);
    }
    return Vec3(x,y,z);
}

std::string Config::trim(const std::string& slowo){
    size_t start = 0;
    size_t end = slowo.size();
    while(start < slowo.size() && std::isspace(static_cast<unsigned char>(slowo[start]))){
        ++start;
    }
    
    while(end > start && std::isspace(static_cast<unsigned char>(slowo[end-1]))){
        --end;
    }
    return slowo.substr(start,end-start);
}

double Config::getDt() const{
    return dt;
}

int Config::getSteps() const{
    return steps;
}

std::string Config::getIntegrator() const{
    return integrator;
}

Vec3 Config::getE() const{
    return E;
}

Vec3 Config::getB() const{
    return B;
}

const std::vector<Particle>& Config::getParticles() const{
    return particles;
}

const std::vector<Vec3>& Config::getX() const{
    return x;
}

const std::vector<Vec3>& Config::getV() const{
    return v;
}

const std::vector<double>& Config::getQ() const{
    return q;
}

const std::vector<double>& Config::getM() const{
    return m;
}
