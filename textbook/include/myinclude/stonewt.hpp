#ifndef STONEWT_HPP_
#define STONEWT_HPP_

class Stonewt {
    private :
        enum {Lbs_per_stn = 14};
        int stone;
        double pds_left, pounds;  //fractional part  entir weight in pounds
    public :
        Stonewt(double lbs);
        Stonewt(int stn, double lbs);
        Stonewt();
        ~Stonewt();
        void show_stn() const;
        void show_lbs() const;
};

#endif
