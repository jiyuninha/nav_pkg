#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <motion_planner.h>
#include <control.h>
using namespace std;

vector<vector<double>> MotionPlanner::find_local_path(vector<vector<double>> global_map, Scout* scout) {
    self_path.clear();
    int end_local_index = 0;
    if (scout->getPosition_idx() + 100 > global_map.size()) {
        end_local_index = global_map.size();
    }
    else {
        end_local_index = scout->getPosition_idx() + 100;
    }
    for (int i = scout->getPosition_idx(); i < end_local_index; ++i) {
        self_path.push_back( { global_map[i][0], global_map[i][1] });
    }
    return self_path;
}