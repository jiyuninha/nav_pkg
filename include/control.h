#pragma once
#include <master.h>
#define _USE_MATH_DEFINES

class Control {
private:
    double lookahead = 0;
    double alpha = 0;
    int target_index = 0;
    double angle = 0;
    double targetHeading = 0;
    double resultAngVel;
    double integral;
    double previous_error;
    double Kp, Kd, Ki;
    struct Position{
        double x;
        double y;
        int idx;
    };
public:
    Control() : Kp(0.01), Ki(0.1), Kd(0.02), integral(0), previous_error(0) {};
    void PurePursuit(vector < vector <double> >, Scout*);
    double LateralController(Scout*);
    double PID(Scout*);
    double run(vector < vector <double> >, Scout*);
};