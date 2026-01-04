#pragma once
#include <fstream>
#include <string>
class CSVWriter{
    private:
    std::ofstream file;
    public:
    CSVWriter(const std::string& filename);
    ~CSVWriter();

    void WriteHead();
    void WriteInhalt(double time, int id, double x, double y, double z, double vx, double vy, double vz, double Ek);
};