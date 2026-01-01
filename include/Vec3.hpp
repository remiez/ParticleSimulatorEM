#pragma once     //zapobieganie redeklaracją klasy
class Vec3{
    private:
    double x,y,z;
    public:
    Vec3(); //matematyka wektorów
    Vec3(double x, double y, double z);

    double getX() const;
    double getY() const;
    double getZ() const;

    Vec3 operator+(const Vec3& other);
    Vec3 operator-(const Vec3& other);
    Vec3 operator/(double scalar) const;
    Vec3 operator*(double scalar);
    friend Vec3 operator*(double scalar, const Vec3& wektor);
    bool operator==(const Vec3& other);

    double length();
    double length2();
    Vec3 normalize();
    double DotProduct(const Vec3& other);
    Vec3 CrossProduct(const Vec3& other);
    void Wypisz() const;

};