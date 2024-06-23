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


long long totalcost(vector<int>& nums, int index, bool b) {
    if(index == nums.size()) return 0;
    long long res = nums[index] + totalcost(nums, index + 1, false); // 分组，不分组一样
    if(!b) {
        res = max(res, -nums[index] + totalcost(nums, index + 1, true)); // 不分组
    }
    return res;
}

long long maximumTotalCost(vector<int>& nums) {
    long long res = nums[0];
    for(int i = 1; i < nums.size(); ++i) {
        if(nums[i] > 0) res += nums[i];
        else if(nums[i - 1] < 0 && nums[i - 1] > nums[i]) {
            res -= nums[i];
            res -= nums[i - 1];
        }
        else res -= nums[i];
    }
    
    return res;
}

int main() {
    vector<int> vec = {-100};
    double res = maximumTotalCost(vec);

    cout << res << endl;

    return 0;
}