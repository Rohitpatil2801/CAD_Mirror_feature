#include"point.h"
#include<vector>
#pragma once
 
std::vector<Point> readFile();
 
std::vector<Point> getPlane(std::vector<Point> readvector);
 
std::vector<Point> reflectPoint(std::vector<Point> point_vector);
 
std::vector<Point> writePlane(std::vector<Point> point_vector);
 
void plotPlane(std::vector<Point> reflect);
 
void plot(std::vector<Point> reflect);