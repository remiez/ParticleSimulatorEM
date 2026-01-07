#pragma once
#include <vector>
#include "Particle.hpp"
#include "Vec3.hpp"
class Config{
    private:
    std::vector<Particle> particles;
    int N;
    double dt;
    int steps;
    std::string integrator;
    Vec3 E;
    Vec3 B;
    std::vector<Vec3> x;
    std::vector<Vec3> v;
    std::vector<double> q;
    std::vector<double> m;

    public:
    Config(const std::string& filename);
    Vec3 parseVec3(const std::string& s);
    std::string trim(const std::string& slowo);

    double getDt() const;
    int getSteps() const;
    std::string getIntegrator() const;
    Vec3 getE() const;
    Vec3 getB() const;
    const std::vector<Particle>& getParticles() const;
    const std::vector<Vec3>& getX() const;
    const std::vector<Vec3>& getV() const;
    const std::vector<double>& getQ() const;
    const std::vector<double>& getM() const;
    
};