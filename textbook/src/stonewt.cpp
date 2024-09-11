// stonewt.cpp

#include "stonewt.hpp"
#include <iostream>

using namespace std;
Stonewt::Stonewt(double lbs)
{
    stone = int (lbs) / Lbs_per_stn;
    pds_left = int (lbs) % Lbs_per_stn;
    pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}//数值转化填入private

Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
}//构造

Stonewt::~Stonewt()
{
    //noting to do
}

void Stonewt::show_stn() const
{
    cout << stone << " stone " << pds_left << " pounds" << endl;
}

void Stonewt::show_lbs() const
{
    cout << pounds << " pounds" << endl;
}


