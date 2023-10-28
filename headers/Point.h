#pragma once
class Point{
    private:
    double mx,my,mz;
    public:
    Point(double inx,double iny,double inz);
    ~Point();
    double x();
    double y();
    double z();
};