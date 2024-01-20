#pragma once
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <scout.h>
using namespace std;

class Local
{
private:
    struct Waypoint {
        double x;
        double y;
        double index;
    };

    double x = 0;
    double y = 0;
    double z = 0;

    std::vector<std::vector<double>> global_map;
public:
    void readCSV();
    void findClosestWaypoint(Scout*);
    vector<vector<double>> getGP();
};