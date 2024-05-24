#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;



    int getMaximumNumber(vector<vector<int>>& moles) {
        int ans = 0;
        vector<int> maxByTime(moles.size(), 1);
        sort(moles.begin(), moles.end(),[](vector<int> v1, vector<int> v2){return v1[0] < v2[0];});
        for(int i = moles.size() -1; i >= 0; --i) {
            int maxNum = 1;
            for(int j = i + 1; j < moles.size(); ++j) {
                if(abs(moles[j][1] - moles[i][1]) + abs(moles[j][2] - moles[i][2]) <= abs(moles[j][0] - moles[i][0])) {
                    maxNum = max(maxNum, maxByTime[j] + 1);
                }
                maxByTime[i] = maxNum;
            }
            if(abs(moles[i][1] - 1) + abs(moles[i][2] - 1) <= abs(moles[i][0]))
                ans = max(ans, maxNum);
        }
        return ans;
    }


int main() {
    vector<vector<int>> moles = {{2,0,2},{6,2,0},{4,1,0},{2,2,2},{3,0,2}};
    getMaximumNumber(moles);
    return 0;
}