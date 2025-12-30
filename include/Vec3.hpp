#pragma once     //zapobieganie redeklaracją klasy
class Vec3{
    private:
    double x,y,z;
    public:
    Vec3(); //matematyka wektorów
    Vec3(double x, double y, double z);
    Vec3 operator+(const Vec3& other);
    Vec3 operator-(const Vec3& other);
    Vec3 operator/(double scalar) const;
    Vec3 operator*(double scalar);
    friend Vec3 operator*(double scalar, const Vec3& wektor);
    bool operator==(const Vec3& other);

    double length();
    double length2();
    Vec3 normalize();
    static double DotProduct(const Vec3& wektor1, const Vec3& wektor2);
    static Vec3 CrossProduct(const Vec3& wektor1, const Vec3& wektor2);
    void Wypisz() const;

};