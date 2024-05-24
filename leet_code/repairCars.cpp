#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

long long repairCars(vector<int>& ranks, int cars) {
    sort(ranks.begin(), ranks.end());
    vector<long long> timesVec;
    long double time = 0;
    int timeMax = 0;
    for(int r : ranks) time += sqrt(ranks[0]) / sqrt(r);
    time = floor((cars / time) * sqrt(ranks[0]));
    for(int totalCar = 0; ; ++time) {
        totalCar = 0;
        for(int r : ranks) totalCar += time / sqrt(r);
        if(cars - totalCar <= 0) {
            if(cars - totalCar < 0) time--;
            break;
        }
    }
    for(int r : ranks) {
        int car = time / sqrt(r);
        cars -= car;
        timesVec.push_back(r * pow(car + 1, 2));
        timeMax = max(r * (int)pow(car, 2), timeMax);
    }
    if(!cars) return timeMax;
    sort(timesVec.begin(), timesVec.end());
    return timesVec[cars - 1];
}

int main() {
    vector<int> ranks({31,31,5,19,19,10,31,18,19,3,16,20,4,16,2,25,10,16,23,18,21,23,28,6,7,29,11,11,19,20,24,19,26,12,29,29,1,14,17,26,24,7,11,28,22,14,31,12,3,19,16,26,11});//5,3,1,2,6,5,3,1,5,7,1,4,5,1,6});//4,2,3,1});
    int ans = repairCars(ranks, 736185);

    return 0;
}