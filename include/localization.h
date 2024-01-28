#pragma once
#include <master.h>
#include <fstream>
#include <sstream>

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

    vector<vector<double>> global_map;
    vector < vector <double> > self_path;
public:
    void readCSV();
    void findClosestWaypoint(Scout*);
    vector<vector<double>> getGP();
    vector < vector <double> > find_local_path(vector<vector<double>>, Scout*);
    vector <vector <double>> run(Scout*);
};