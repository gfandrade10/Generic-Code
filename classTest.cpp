#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

#ifndef PFLOAT_ACCURACY
    #define PFLOAT_ACCURACY 3
#endif

template<class T>
class Point 
{
    public:
    Point() 
        : x(0), y(0), z(0) {}

    Point(T X, T Y, T Z) 
        : x(X), y(Y), z(Z) {}

    Point(const Point& p)
        : x(p.x), y(p.y), z(p.z) {}

    ~Point() = default;

    Point& operator=(const Point& p)
    {
        x = p.x; y = p.y; z = p.z;
        return *this;
    }

    Point& operator=(std::initializer_list<T> v)
    {
        if (v.size() == 3)
        {
            auto ptr = v.begin();
            x = *(ptr++); y = *(ptr++); z = *ptr;
        }        
        else
            throw(std::runtime_error("Point operator = for list, invalid input!\n"));
        return *this;
    }

    Point operator+(const Point& p) const
    {
        return Point(x + p.x, y + p.y, z + p.z);
    }

    Point operator-(const Point& p) const
    {
        return Point(x - p.x, y - p.y, z - p.z);
    }

    Point operator*(T scalar) const
    {
        return Point(x*scalar, y*scalar, z*scalar);
    }

    Point operator/(T scalar) const
    {
        if (scalar == 0)
            throw std::runtime_error("Point operator /, division by zero");
        return Point(x/scalar, y/scalar, z/scalar);
    }

    void SetPoint(T X, T Y, T Z)
    {
        x = X; y = Y; z = Z;
    }

    T GetX () const { return x; }
    T GetY () const { return y; }
    T GetZ () const { return z; }

    float Magnitude() const
    {
        return std::sqrt(x*x + y*y + z*z);
    }
    
    static inline float RoundFloat(float value, int decimals)
    {
        int max = std::pow(10,decimals);
        value = value * max;
        value = std::round(value);
        return value / max;
    }

    //point distance with .001 decimal accuracy
    static float PointDistance(const Point& p1, const Point& p2)
    {
        T d1 = p2.x - p1.x;
        T d2 = p2.y - p1.y;
        T d3 = p2.z - p1.z;
        T Squares = d1*d1 + d2*d2 + d3*d3;
        return RoundFloat(std::sqrt(Squares + 0.0), PFLOAT_ACCURACY);
    }

    float DistanceToOrigin() const
    {
        return PointDistance(Point(), *this);
    }

    Point CrossProduct(const Point& p) const
    {
        return Point(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x);
    }

    T DotProduct(const Point& p) const
    {
        return x*p.x + y*p.y + z*p.z;
    }

    //normalized point with .001 decimal accuracy
    template <class U = float>
    Point<U> Normalized() const
    {
        float Mag = Magnitude();
        if (Mag != 0)
        {
            return Point<U>(
                RoundFloat((x + 0.0)/Mag, PFLOAT_ACCURACY), 
                RoundFloat((y + 0.0)/Mag, PFLOAT_ACCURACY), 
                RoundFloat((z + 0.0)/Mag, PFLOAT_ACCURACY)
            );
        }
        else 
            return Point<U>();
    }

    void PrintPoint()
    {
        std::cout << "(X,Y,Z) = (" << x << ", " << y << ", " << z << ")";
        std::cout << "\n";
    }

    protected:
    T x;
    T y;
    T z;
};

int main(int argc, char** argv)
{
    Point<size_t> p1, p2;
    p1.SetPoint(1,2,3);
    p1 = p1 * 2;
    p2 = {5, 4, 7};
    auto p3 = p1.Normalized();
    std::cout << "P1 ";
    p1.PrintPoint();
    std::cout << "P2 ";
    p2.PrintPoint();
    std::cout << "P3 ";
    p3.PrintPoint();
    std::cout << "\nDistance from P1 to P3: " << Point<size_t>::PointDistance(p1, p2);
    std::cout << "\nDistance from P2 to P(O): " << p2.DistanceToOrigin();
    std::cout << "\n\n";
    return 0;
}