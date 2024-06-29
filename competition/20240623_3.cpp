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
    int n = nums.size();
    const long long INF = 1e18;
    long long f[n][2];
    for (int i = 0; i < n; i++) f[i][0] = f[i][1] = -INF;
    f[0][0] = nums[0];
    for (int i = 1; i < n; i++) {
        f[i][0] = max(f[i - 1][0], f[i - 1][1]) + nums[i];
        f[i][1] = f[i - 1][0] - nums[i];
    }
    return max(f[n - 1][0], f[n - 1][1]);
}

int main() {
    vector<int> vec = {-100};
    double res = maximumTotalCost(vec);

    cout << res << endl;

    return 0;
}