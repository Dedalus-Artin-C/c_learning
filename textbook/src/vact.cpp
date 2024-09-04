// vact.cpp --methods for the Vector class
#include <cmath>
#include "vect.hpp" //includes Vector class definition

using std::atan;
using std::atan2;
using std::cos;
using std::cout;
using std::end;
using std::sin;
using std::sqrt;

namespace VECTOR
{
    const double Rad_to_deg = 45.0 / atan(1.0); // r = 180L/pi

    void Vector::set_mag()
    {
        mag = sqrt(x * x + y * y); //magnitude
    }

    void Vector::set_ang()
    {
        if (x == 0.0 && y == 0.0){
            ang = 0.0;
        }
        else 
            ang = atan2(y, x);
    }

    void Vector::set_x()
    {
        x = mag * cos(ang);
    }

    void Vector::set_y()
    {
        y = mag * sin(ang);
    }

    Vector::Vector()
    {
        x = y = mag = ang = 0.0;
        mode = RECT;//pol是极坐标
    }

    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (form == POL)
        {
            mag = n1;
            ang = n2;
            set_x();
            set_y();
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() --";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }

    } 

    Vector::~Vector()
    {
        // nothing to do
    }
    void Vector::polar_mode()
    {
        mode = POL;
    }

    void Vector::rect_mode()
    {
        mode = RECT;
    }

    Vector Vector::operator+(const Vector & b) const 
    {
        return Vector(x + b.x, y + b.y);
    }

    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    Vector Vector::operator-(const Vector & b) const
    {
        return Vector(x - b.x, y - b.y);
    }

    Vector Vector::operator*(double n) const
    {
        return Vector(x * n, y * n);
    }

    //friends 
    Vector operator*(double n, const Vector & a)
    {
        return a * n;
    }

    std::ostream & operator<<(std::ostream & os, const Vector & v)
    {
        if (v.mode == Vector::RECT)
            os << "(" << v.x << ", " << v.y << ")";
        else if (v.mode == Vector::POL){
            os << "(" << v.mag << ", " << v.ang * Rad_to_deg << ")";
        }
    }


}
