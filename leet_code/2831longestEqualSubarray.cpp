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


int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> pos_lists(n + 1);
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            pos_lists[x].push_back(i - pos_lists[x].size());
        }

        int ans = 0;
        for (auto& pos : pos_lists) {
            int left = 0;
            for (int right = 0; right < pos.size(); right++) {
                while (pos[right] - pos[left] > k) {
                    left++;
                }
                ans = max(ans, right - left + 1);
            }
        }
        return ans;
    }

int main() {
    vector<int> vec = {1,3,2,3,1,3};
    int k = 3;
    int ans = longestEqualSubarray(vec, k);
    
    return 0;
}

