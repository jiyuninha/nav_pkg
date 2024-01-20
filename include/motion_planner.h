#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <scout.h>
using namespace std;

class MotionPlanner {
public:
    vector < vector <double> > self_path;
    vector < vector <double> > find_local_path(vector<vector<double>> global_map, Scout* scout);
};