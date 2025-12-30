#include "Vec3.hpp"
#include "Field.hpp"
#include "UniformField.hpp"
UniformField::UniformField(const Vec3& E, const Vec3& B)
    :elektryczne(E), magnetyczne(B)
{}

Vec3 UniformField::electric(const Vec3&, double) const{
    return elektryczne;
}

Vec3 UniformField::magnetic(const Vec3&, double) const{
    return magnetyczne;
}