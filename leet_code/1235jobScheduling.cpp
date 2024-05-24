#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = *max_element(endTime.begin(), endTime.end());
    vector<int> vec(n + 1);
    vec[0] = 0;
    vector<vector<int>> vec2;
    for(int i = 0; i < startTime.size(); ++i) {
        vector<int> tmp;
        tmp.push_back(startTime[i]);
        tmp.push_back(endTime[i]);
        tmp.push_back(profit[i]);
        vec2.push_back(tmp);
    }
    sort(vec2.begin(), vec2.end(), [](auto& v1, auto& v2){return v1[1] < v2[1];});
    for(int i = 1, j = 0; i <= n;) {
        if(j == vec2.size() || vec2[j][1] != i) {
            vec[i] = vec[i - 1];
            ++i;
            continue;
        }
        vec[i] = max(vec2[j][2] + vec[vec2[j][0]], max(vec[i - 1], vec[i]));
        ++j;
        if(j == vec2.size() || vec2[j][1] != i) ++i;
    }

    return vec[n];
}

int main() {
    vector<int> v1 = {43,13,36,31,40,5,47,13,28,16,2,11};
    vector<int> v2 = {44,22,41,41,47,13,48,35,48,26,21,39};
    vector<int> v3 = {8,20,3,19,16,8,11,13,2,15,1,1};

    //int res = jobScheduling(v1, v2, v3);
    short big = 0xff00;
    char litter = big;
    if(litter == 0xff) cout << "大端";
    else cout << "小端";

    return 0;
}