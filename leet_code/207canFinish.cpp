#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, unordered_set<int>> preMap;
    unordered_set<int> noPreCourse;
    for(int i = 0; i < numCourses; ++i) noPreCourse.insert(i); 
    for(auto pairs : prerequisites) {
        noPreCourse.erase(pairs[0]);
        preMap[pairs[0]].insert(pairs[1]);
    }
    if(preMap.empty()) return true;

    while(!noPreCourse.empty()) {
        int cour = *noPreCourse.begin();
        for(int i = 0; i < preMap.size(); ++i) {
            auto iter = preMap.begin();
            advance(iter, i);;
            iter->second.erase(cour);
            if(iter->second.empty()) {
                noPreCourse.insert(iter->first);
                preMap.erase(iter->first);
                if(preMap.empty()) return true;
                --i;
            }
        }
        noPreCourse.erase(cour);
    }

    return false;
}



int main() {
    vector<vector<int>> vec = {{1,4},{2,4},{3,1},{3,2}};
    bool finish = canFinish(5, vec);

    return 0;
}