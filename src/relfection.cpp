#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include "..\headers\reflection.h"
 
std::vector<Point> readFile()
{
    std::ifstream in("../STL_files/flowerpot.STL");
    std::ofstream out("../Text_files/original.txt");
    std::vector<Point> readvector;
    std::string s;
    std::vector<Point> vertexPoints;
    std::string line;
    while (std::getline(in, line))
    {
        if (line.find("vertex") != std::string::npos)
        {
            std::istringstream iss(line);
            std::string token;
            double x, y, z;
            iss >> token >> x >> y >> z;
            out << x << " " << y << " " << z << std::endl;
            vertexPoints.push_back({x, y, z});
        }
    }
    in.close();
    out.close();
 
    return vertexPoints;
}
 
std::vector<Point> getPlane(std::vector<Point> readvector)
{
 
    double vx, vy, vz, px, py, pz;
    std::cout << "Enter points on plane";
 
    std::cout << "px" << std::endl;
    std::cin >> px;
 
    std::cout << "py" << std::endl;
    std::cin >> py;
 
    std::cout << "pz" << std::endl;
    std::cin >> pz;
 
    std::cout << "Enter the vector points" << std::endl;
    std::cout << "vx" << std::endl;
    std::cin >> vx;
 
    std::cout << "vy" << std::endl;
    std::cin >> vy;
 
    std::cout << "vz" << std::endl;
    std::cin >> vz;
 
    Point Plane_points(px, py, pz);
    Point Vector_points(vx, vy, vz);
 
    readvector.insert(readvector.begin(), Vector_points);
    readvector.insert(readvector.begin() + 1, Plane_points);
 
    return readvector;
}
 
std::vector<Point> reflectPoint(std::vector<Point> point_vector)
{
 
    const double a = point_vector[0].x();
    const double b = point_vector[0].y();
    const double c = point_vector[0].z();
 
    const double div = sqrt(pow(a, 2.0) + pow(b, 2.0) + pow(c, 2.0));
 
    Point normalised_vector(a / div, b / div, c / div);
 
    double x1 = point_vector[1].x(), y1 = point_vector[1].y(), z1 = point_vector[1].z();
 
    std::vector<Point> reflected_shape;
 
    for (int i = 2; i < point_vector.size(); i++)
    {
        double tx = point_vector[i].x();
        double ty = point_vector[i].y();
        double tz = point_vector[i].z();
        double dist = abs(((a * tx) + (b * ty) + (c * tz) - (a * x1) - (b * y1) - (c * z1)) / (div));
        reflected_shape.push_back(Point(point_vector[i].x() + (2 * dist * normalised_vector.x()), point_vector[i].y() + (2 * dist * normalised_vector.y()), point_vector[i].z() + (2 * dist * normalised_vector.z())));
    }
    return reflected_shape;
}
 
void plotPlane(std::vector<Point> reflect)
{
    std::ofstream out("../Text_files/plane.txt");
    for (auto i : reflect)
    {
        out << i.x() << " " << i.y() << " " << i.z() << std::endl;
    }
    out.close();
}
 
std::vector<Point> writePlane(std::vector<Point> point_vector)
{
 
    const double a = point_vector[0].x();
    const double b = point_vector[0].y();
    const double c = point_vector[0].z();
 
    const double div = sqrt(pow(a, 2.0) + pow(b, 2.0) + pow(c, 2.0));
 
    Point normalised_vector(a / div, b / div, c / div);
 
    double x1 = point_vector[1].x(), y1 = point_vector[1].y(), z1 = point_vector[1].z();
 
    std::vector<Point> planar_shape;
 
    for (int i = 2; i < point_vector.size(); i++)
    {
        double tx = point_vector[i].x();
        double ty = point_vector[i].y();
        double tz = point_vector[i].z();
        double dist = abs(((a * tx) + (b * ty) + (c * tz) - (a * x1) - (b * y1) - (c * z1)) / (div));
        planar_shape.push_back(Point(point_vector[i].x() + (dist * normalised_vector.x()), point_vector[i].y() + (dist * normalised_vector.y()), point_vector[i].z() + (dist * normalised_vector.z())));
    }
    plotPlane(planar_shape);
    return planar_shape;
}
 
void plot(std::vector<Point> reflect)
{
    std::ofstream out("../Text_files/reflection.txt");
    for (auto i : reflect)
    {
 
        out << i.x() << " " << i.y() << " " << i.z() << std::endl;
    }
    out.close();
}