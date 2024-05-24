#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int scheduleCourse(vector<vector<int>>& courses) {
    unordered_set<int> taked;
    int maxone, start = 0, oneloop, maxindex;
    while(true){
        maxone = -1, maxindex = -1;
        for(int j = 0; j < courses.size(); ++j) {
            if(taked.find(j) != taked.end()) continue;
            if(start + courses[j][0] > courses[j][1]) continue;
            int startloop = start + courses[j][0];
            oneloop = 1;
            for(int k = 0; k < courses.size(); ++k) {
                if((taked.find(k) != taked.end()) || (k == j)) continue;
                if(startloop + courses[k][0] <= courses[k][1]) ++oneloop;
            }
            if(oneloop <= maxone) continue;
            maxone = oneloop;
            maxindex = j;
        }
        if(maxone == -1) break;
        taked.insert(maxindex);
        start += courses[maxindex][0];
        if(taked.size() == courses.size()) break;
    }

    return taked.size();
}

int main() {
    vector<vector<int>> vec({{7,17},{3,12},{10,20},{9,10},{5,20},{10,19},{4,18}});
    scheduleCourse(vec);

    return 0;
}