#include"..\headers\Point.h"
Point::Point(double inx,double iny,double inz):mx(inx),my(iny),mz(inz){}

Point::~Point(){};

double Point::x(){
    return this->mx;
}

double Point::y(){
    return this->my;
}

double Point::z(){
    return this->mz;
}
