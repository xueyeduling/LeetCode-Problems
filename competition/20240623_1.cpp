#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        double res = nums[nums.size() - 1];
        for(int i = 0, j = nums.size() - 1; i < j; ++i, --j) {
            res = min(res, (nums[i] + nums[j]) / 2.0 );
        }
        
        return res;
    }

int main() {
    vector<int> vec = {7,8,3,4,15,13,4,1};
    double res = minimumAverage(vec);

    sort(vec.begin(), vec.end());

    cout << res << endl;

    return 0;
}