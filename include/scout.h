#pragma once
using namespace std;

class Scout {
private:
    double angVel = 0.0;
    double linVel = 0.0;
    double cur_angVel = 0.0;
    double cur_linVel = 0.0;
    double heading = 0.0;

    class Position {
    public:
        double x;
        double y;
        int idx;
        Position(){
            this->x = 0.0;
            this->y = 0.0;
            this->idx = -1;
        }
        // double get_x() {
        //     return this->x;
        // }
        // double get_y() {
        //     return this->y;
        // }
        // int get_idx() {
        //     return this->idx;
        // }
    };

    Position ego;

public:
    Scout() { 
        // Scout 객체 생성 시 초기화 작업
    }
    void getCtrl() {
        // 현재

    }
    void setAngVel(double vel) {
        this->angVel = vel;
    }
    void setHeading(double heading){
        this->heading = heading;
    }
    void setLinVel(double vel){
        this->cur_linVel = vel;
    }
    void setPosition_idx(int idx){
        this->ego.idx = idx;
    }
    void setPosition_x(double xn){
        this->ego.x = xn;
    }
    void setPosition_y(double yn){
        this->ego.y = yn;
    }
    double getHeading() {
        return this->heading;
    }
    double getAngVel(){
        return this->cur_angVel;
    }
    double getLinVel(){
        return this->cur_linVel;
    }
    Position* newPosition(){
        Position* pose = new Position();
        return pose;
    }
    double getPosition_x() {
        return this->ego.x; // get 함수를 써야하는지?
    }
    double getPosition_y() {
        return this->ego.y;
    }
    int getPosition_idx() {
        return this->ego.idx;
    }
};
