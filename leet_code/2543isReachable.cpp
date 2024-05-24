#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

bool isReachable(int targetX, int targetY) {
    unordered_set<string> pointSet;
    vector<vector<int>> pointVec;
    vector<int> start = {1, 1};
    pointVec.push_back(start);
    pointSet.insert(to_string(1) + ","+ to_string(1));
    string xstr, ystr, ans = to_string(targetX) + "," + to_string(targetY);
    int x, y, temp;

    for(int i = 0; i < pointVec.size(); ++i) {
        x = pointVec[i][0];
        y = pointVec[i][1];
        temp = 0;

        if((x == targetX && y == targetY) || (y == targetX && x == targetY)) return true;

        temp = y - x;
        xstr = to_string(x) + "," + to_string(temp);
        ystr = to_string(temp) + "," + to_string(x);
        if(temp > 1 && pointSet.find(xstr) == pointSet.end() && pointSet.find(ystr) == pointSet.end()) {
            if(xstr == ans || ystr == ans) return true;
            pointSet.insert(to_string(x) + "," + to_string(temp));
            pointVec.push_back({x, temp});
        }

        temp = x - y;
        xstr = to_string(temp) + "," + to_string(y);
        ystr = to_string(y) + "," + to_string(temp);
        if(temp > 1 && pointSet.find(xstr) == pointSet.end() && pointSet.find(ystr) == pointSet.end()) {
            if(xstr == ans || ystr == ans) return true;
            pointSet.insert(to_string(temp) + "," + to_string(y));
            pointVec.push_back({temp, y});
        }

        temp = 2 * y;
        xstr = to_string(x) + "," + to_string(temp);
        ystr = to_string(temp) + "," + to_string(x);
        if(temp > 1 && pointSet.find(xstr) == pointSet.end() && pointSet.find(ystr) == pointSet.end() && (x <= targetX || temp <= targetY) && temp - targetX < targetY) {
            if(xstr == ans || ystr == ans) return true;
            pointSet.insert(to_string(x) + "," + to_string(temp));
            pointVec.push_back({x, temp});
        }

        temp = 2 * x;
        xstr = to_string(temp) + "," + to_string(y);
        ystr = to_string(y) + "," + to_string(temp);
        if(temp > 1 && pointSet.find(xstr) == pointSet.end() && pointSet.find(ystr) == pointSet.end() && (temp <= targetX || y <= targetY) && temp - targetY < targetX) {
            if(xstr == ans || ystr == ans) return true;
            pointSet.insert(to_string(temp) + "," + to_string(y));
            pointVec.push_back({temp, y});
        }
    }

    return false;
}

int main() {
    bool ans = isReachable(4, 7);

    return 0;
}