#include"../headers/reflection.h"
using namespace std;
int main()
{
    vector<Point> one = readFile();
    vector<Point> second = getPlane(one);
    writePlane(second);
    vector<Point> third = reflectPoint(second);
    plot(third);
    return 0;
}
