#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> canTakeQue(numCourses, -1);
    int takedNum = 0;
    vector<int, vector<int>> preVec(numCourses, {});
    vector<int> preNums(numCourses, 0);

    for(auto vec : prerequisites) {
        preVec[vec[1]].push_back(vec[0]);
        preNums[vec[0]] += 1;
    }

    for(int i = 0; i < numCourses; ++i) {
        if(preNums[i] != 0) continue;
        canTakeQue[takedNum] = i;
        takedNum += 1;
    }

    for(int i = 0; i < takedNum; ++i) {
        for(auto n : preVec[canTakeQue[i]]) {
            preNums[n] -= 1;
            if(preNums[n] != 0) continue;
            canTakeQue[takedNum] = n;
            takedNum += 1;
        }
    }

    vector<int> emptyVec;
    return takedNum == numCourses ? canTakeQue : emptyVec;
}

int main() {
    vector<vector<int>> precourse = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> ans = findOrder(4, precourse);

    return 0;
}