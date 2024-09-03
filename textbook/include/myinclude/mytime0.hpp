// mytime0.hpp --time class before operator overloading

#ifndef MYTIME0_HPP_
#define MYTIME0_HPP_

class Time {
    private :
        int hours;
        int minutes;
    public :
        Time();
        Time(int h, int m = 0);
        void AddMin(int m);
        void AddHr(int h);
        void Reset(int h = 0, int m = 0);
        Time Sum(const Time & t) const;
        void Show() const;
        Time operator+(const Time & t) const;

};

#endif