#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include "..\headers\Point.h"
using namespace std;
void plotPlane(vector<Point>);

vector<Point> readFile()
{
    ifstream in("../STL_files/flowerpot.STL");
    ofstream out("../Text_files/original.txt");
    vector<Point> readvector;
    string s;
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
            out << x << " " << y << " " << z << endl;
            vertexPoints.push_back({x, y, z});
        }
    }
    in.close();
    out.close();

    return vertexPoints;
}

vector<Point> get_plane(vector<Point> readvector)
{

    double vx, vy, vz, px, py, pz;
    cout << "Enter points on plane";

    cout << "px" << endl;
    cin >> px;

    cout << "py" << endl;
    cin >> py;

    cout << "pz" << endl;
    cin >> pz;

    cout << "Enter the vector points" << endl;
    cout << "vx" << endl;
    cin >> vx;

    cout << "vy" << endl;
    cin >> vy;

    cout << "vz" << endl;
    cin >> vz;

    Point Plane_points(px, py, pz);
    Point Vector_points(vx, vy, vz);

    readvector.insert(readvector.begin(), Vector_points);
    readvector.insert(readvector.begin() + 1, Plane_points);

    return readvector;
}

vector<Point> reflect_point(vector<Point> point_vector)
{

    const double a = point_vector[0].x();
    const double b = point_vector[0].y();
    const double c = point_vector[0].z();

    const double div = sqrt(pow(a, 2.0) + pow(b, 2.0) + pow(c, 2.0));

    Point normalised_vector(a / div, b / div, c / div);

    double x1 = point_vector[1].x(), y1 = point_vector[1].y(), z1 = point_vector[1].z();

    vector<Point> reflected_shape;

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

// ------------------------------Planer point vector---------------------------------------
std::vector<Point> writePlane(std::vector<Point> point_vector)
{

    const double a = point_vector[0].x();
    const double b = point_vector[0].y();
    const double c = point_vector[0].z();

    const double div = sqrt(pow(a, 2.0) + pow(b, 2.0) + pow(c, 2.0));

    Point normalised_vector(a / div, b / div, c / div);

    double x1 = point_vector[1].x(), y1 = point_vector[1].y(), z1 = point_vector[1].z();

    vector<Point> planar_shape;

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

// ------------------------------Plot plane.txt-----------------------
void plotPlane(vector<Point> reflect)
{
    ofstream out("../Text_files/plane.txt");
    for (auto i : reflect)
    {
        out << i.x() << " " << i.y() << " " << i.z() << endl;
    }
    out.close();
}

//-----------------------------Plot in reflection.txt---------------
void plot(vector<Point> reflect)
{
    ofstream out("../Text_files/reflection.txt");
    for (auto i : reflect)
    {

        out << i.x() << " " << i.y() << " " << i.z() << endl;
    }
    out.close();
}
//------------------------------Main-----------------------------------------------
int main()
{
    // readStl("flowerpot.stl");
    vector<Point> one = readFile();
    vector<Point> second = get_plane(one);
    writePlane(second);
    vector<Point> third = reflect_point(second);
    plot(third);
    return 0;
}
//----------------------------------------------------------------------------------
