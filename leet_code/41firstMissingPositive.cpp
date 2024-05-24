#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] <= 0) nums[i] = nums.size() + i;
    }

    for(int i = 0; i < nums.size(); ++i) {
        if(abs(nums[i]) <= nums.size()) nums[abs(nums[i]) - 1] = -1 * abs(nums[abs(nums[i]) - 1]);
    }

    for(int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) return i + 1;
    }

    return nums.size() + 1;
}

int main() {
    vector<int> nums = {3,4,-1,1};

    int firstMiss = firstMissingPositive(nums);

    return 0;
}