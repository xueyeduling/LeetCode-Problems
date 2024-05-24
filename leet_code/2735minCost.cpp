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


long long minCost(vector<int>& nums, int x) {
    int n = nums.size();
    vector<int> nums2 = nums;
    int mcost = accumulate(nums2.begin(), nums2.end(), 0);;

    for(int i = 1; i < n; ++i) {
        int cost = 0;
        for(int j = 0; j < n; ++j) {
            int k = j - i;
            if(k < 0) k += n;
            nums2[j] = min(nums2[j], nums[k]);
            cost += nums2[j];
        }
        cost += i * x;
        mcost = min(cost, mcost);
    }

    return mcost;
}

int main() {
    vector<int> vec = {15, 150, 56, 69, 214, 203};
    int x = 42;
    int ans = minCost(vec, x);
    
    return 0;
}

