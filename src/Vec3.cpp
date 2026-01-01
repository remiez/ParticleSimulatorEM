#include "Vec3.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
Vec3::Vec3()          //Zaprogramowanie tego jak działa konstruktor domyślny
    :x(0), y(0), z(0)
{}

Vec3::Vec3(double xx, double yy, double zz)
    :x(xx), y(yy), z(zz)        //Zaprogramowanie konstruktora głównego
{}

double Vec3::getX() const{
    return x;
}

double Vec3::getY() const{
    return y;
}

double Vec3::getZ() const{
    return z;
}

//Matematyka wektorów konkretnie to programowanie jak ma ona działać

Vec3 Vec3::operator+(const Vec3& other){
    return Vec3(x+other.x, y+other.y, z+other.z);
}

Vec3 Vec3::operator-(const Vec3& other){
    return Vec3(x-other.x, y-other.y, z-other.z);
}

Vec3 Vec3::operator/(double scalar) const{
    if(scalar != 0){
        return Vec3(x/scalar, y/scalar, z/scalar);
    }
    else{
        throw std::runtime_error("Nie można dzielić przez zero");
    }
}

Vec3 operator*(double scalar, const Vec3& wektor){
    return Vec3(wektor.x*scalar, wektor.y*scalar, wektor.z*scalar);
}

Vec3 Vec3::operator*(double scalar){
    return Vec3(x * scalar, y * scalar, z * scalar);
}

bool Vec3::operator==(const Vec3& other){
    if(x==other.x && y==other.y && z==other.z){
        return true;
    }
    else{
        return false;
    }
}

double Vec3::length2(){
    return x*x+y*y+z*z;
}

double Vec3::length(){
    return sqrt(x*x+y*y+z*z);
}

Vec3 Vec3::normalize(){
    return Vec3(x/length(), y/length(), z/length());
}

double Vec3::DotProduct(const Vec3& other){
    return x*other.x+y*other.y+z*other.z;
}

Vec3 Vec3::CrossProduct(const Vec3& other){
    return Vec3(y*other.z-z*other.y, z*other.x-x*other.z, x*other.y-y*other.x);
}

void Vec3::Wypisz() const{
    std::cout<<"współrzędna x to:"<<x<<"\n";
    std::cout<<"współrzędna y to:"<<y<<"\n";
    std::cout<<"współrzędna z to:"<<z<<"\n";
}