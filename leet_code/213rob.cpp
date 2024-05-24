#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int rob(vector<int>& nums) {
        if(nums.size() < 3) return *max_element(nums.begin(), nums.end());
        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());
        for(int i = 1; i < nums1.size(); ++i) nums1[i] = max(nums1[i - 1], (i == 1 ? 0 : nums1[i - 2]) + nums1[i]);
        for(int i = 1; i < nums2.size(); ++i) nums2[i] = max(nums2[i - 1], (i == 1 ? 0 : nums2[i - 2]) + nums2[i]);
        int max1 = *max_element(nums1.begin(), nums1.end());
        int max2 = *max_element(nums2.begin(), nums2.end());
        return max(max1, max2);
    }

int main() {
    vector<int> house = {4,1,2,7,5,3,1};
    int ans = rob(house);

    return ans;
}