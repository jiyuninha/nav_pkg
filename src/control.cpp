#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include "control.h"
#include "scout.h"
using namespace std;

void Control::PurePursuit(vector < vector <double> > local_path, Scout* scout) {
    lookahead = 7.5; 
    target_index = lookahead * 10;
    //Scout vehicle = this->scout; // 현재 스카우트 상태
    Scout vehicle;
    auto target = vehicle.newPosition();
    //cout << "getAngVel: " << scout->getAngVel() << endl;
    if (target->idx < local_path.size()) { 
        while (true) {
            target->x = local_path[0][target_index];
            target->y = local_path[1][target_index];
            if (lookahead - lookahead * 1 / 3 < sqrt(pow(target->x - scout->getPosition_x(), 2) + pow(target->y - scout->getPosition_y(), 2)) && sqrt(pow(target->x - scout->getPosition_x(), 2) + pow(target->y - scout->getPosition_y(), 2)) < lookahead + lookahead * 1 / 3) break;
            else if (sqrt(pow(target->x - scout->getPosition_x(), 2) + pow(target->y - scout->getPosition_y(), 2)) < lookahead) {
                target_index++;
            }
            else if (sqrt(pow(target->x - scout->getPosition_x(), 2) + pow(target->y - scout->getPosition_y(), 2)) > lookahead) {
                target_index--;
            }
            else break;
        }
            //        cout << "target_index : " << target_index << endl;
    }
    else {
        int last = local_path.size() - 1;
        target->x = local_path[0][last];
        target->y = local_path[1][last];
    }

    double tmp = fmod(atan2(target->y - scout->getPosition_y() , target->x - scout->getPosition_x()) * (180.0 / M_PI), 360.0);
    double alpha = scout->getHeading() - tmp;
    //cout << this->angle << endl;
    this->angle = atan2(2.0 * 2.7 * sin(alpha * (M_PI / 180.0)) / lookahead, 1.0);
}
double Control::LateralController(Scout* scout) { // 계산된 현재 각속도를 반환해 저장
    double sampling_time = 0.1; // need to be determined(considering hz of ros msg)
    //cout << scout->getAngVel() << endl;
    double angVel = scout->getAngVel() + (this->angle / sampling_time - scout->getAngVel());
    return angVel;
}
double Control::LongitudinalController() {
    double linVel = target_velocity / 3.6; // 종방향 제어
    return linVel;
}