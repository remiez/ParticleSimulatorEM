#include <string>
#include <fstream>
#include "CSVWriter.hpp"

CSVWriter::CSVWriter(const std::string& filename)
    :file(filename)
{
    if(!file.is_open()) throw std::runtime_error("nie mozna otworzyc pliku" + filename);
    WriteHead();
}

CSVWriter::~CSVWriter(){
    file.close();
}

void CSVWriter::WriteHead(){
    file << "time,particle_id,x,y,z,vx,vy,vz,EK\n";
}
void CSVWriter::WriteInhalt(double time, int id, double x, double y, double z, double vx, double vy, double vz, double Ek){
    file <<time<<","<<id<<","<<x<<","<<y<<","<<z<<","<<vx<<","<<vy<<","<<vz<<","<<Ek<<"\n";
}