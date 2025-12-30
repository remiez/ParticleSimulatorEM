#pragma once
#include "Vec3.hpp"
class Field{
    public:
    virtual ~Field() = default;
    virtual Vec3 electric(const Vec3& x, double t) const = 0;
    virtual Vec3 magnetic(const Vec3& x, double t) const = 0;
};