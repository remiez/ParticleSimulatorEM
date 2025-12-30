#pragma once
#include "Vec3.hpp"
#include "Field.hpp"
class UniformField: public Field{
    private:
    Vec3 elektryczne;
    Vec3 magnetyczne;

    public:
    UniformField(const Vec3& E, const Vec3& B);

    Vec3 electric(const Vec3& x, double t) const override;
    Vec3 magnetic(const Vec3& x, double t) const override;
};