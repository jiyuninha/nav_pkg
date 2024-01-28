#include <control.h>

void Control::PurePursuit(vector < vector <double> > local_path, Scout* scout) {
    lookahead = 3.5; 
    target_index = lookahead * 10;
    Scout vehicle;
    auto target = vehicle.newPosition();
    if (target_index < local_path.size()) { 
        target->x = local_path[target_index][0];
        target->y = local_path[target_index][1];
    }
    else {
        int last = local_path.size() - 1;
        target->x = local_path[last][0];
        target->y = local_path[last][1];
    }
    targetHeading = fmod(atan2(target->y - scout->getPosition_y() , target->x - scout->getPosition_x()) * (180.0 / M_PI), 360.0);
    if(targetHeading < 0)targetHeading += 360;
    double alpha = targetHeading - scout->getHeading();
    this->angle = fmod(atan2(2.0 * 0.5 * sin(alpha * (M_PI / 180.0)) / lookahead, 1.0), 2*M_PI);
}
double Control::LateralController(Scout* scout) { 
    double angVel = this->angle/0.02;
    return angVel;
}

double Control::PID(Scout* scout){
    double targetAngVel = this->angle; // (rad/s) -> targetAngVel;
    double angVel = scout->getAngVel(); // current scout's angvel
    double error = targetAngVel - angVel;
    integral += error * 0.02;
    double derivative = (error - previous_error) / 0.02;
    double output = Kp*error + Ki*integral + Kd*derivative;
    previous_error = error;
    return output;
}
double Control::run(vector < vector <double> > local_path, Scout* scout){
    this->PurePursuit(local_path, scout);
    this->LateralController(scout);
    double resultAngVel;
    if(abs(targetHeading - scout->getHeading()) < 0.001){
        return resultAngVel;
    }
    else{
        resultAngVel = this->PID(scout); //***
        return resultAngVel;
    }
}