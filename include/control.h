#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <scout.h>
#include <math.h>
#define _USE_MATH_DEFINES

using namespace std;

class Control {
private:
    Scout scout;
    // double pi = 3.14159265358979323846;
    double lookahead = 0;
    double alpha = 0;
    int target_index = 0;
    double angle = 0;
    double target_velocity = 1;

public:
    void PurePursuit(vector < vector <double> > local_path, Scout* scout);
    //void Stanley();
    double LongitudinalController();
    double LateralController(Scout*);
    //Scout* getCtrl();
    //void run();
};