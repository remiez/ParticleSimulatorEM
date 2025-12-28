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

Vec3::Vec3(const Vec3& other)
    :x(other.x), y(other.y), z(other.z)
{}

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

Vec3 Vec3::normalize(){
    return Vec3(x/sqrt(x*x+y*y+z*z), y/sqrt(x*x+y*y+z*z), z/sqrt(x*x+y*y+z*z));
}
double Vec3::DotProduct(const Vec3& wektor1, const Vec3& wektor2){
    return wektor1.x*wektor2.x+wektor1.y*wektor2.y+wektor1.z*wektor2.z;
}

Vec3 Vec3::CrossProduct(const Vec3& wektor1, const Vec3& wektor2){
    return Vec3(wektor1.y*wektor2.z-wektor1.z*wektor2.y, wektor1.z*wektor2.x-wektor1.x*wektor2.z, wektor1.x*wektor2.y-wektor1.y*wektor2.x);
}

void Vec3::Wypisz(){
    std::cout<<"współrzędna x to:"<<x<<"\n";
    std::cout<<"współrzędna y to:"<<y<<"\n";
    std::cout<<"współrzędna z to:"<<z<<"\n";
}