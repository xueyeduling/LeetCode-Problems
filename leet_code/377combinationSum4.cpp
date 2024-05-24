#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int res = 0;

int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1);
    dp[0] = 1;
    for (int i = 1; i <= target; i++) {
        for (int& num : nums) {
            if (num <= i && dp[i - num] < INT_MAX - dp[i]) {
                dp[i] += dp[i - num];
            }
        }
    }
    return dp[target];
}

int main()
{
    vector<int> v = {2, 1, 3};
    int target = 35;
    int res = combinationSum4(v, target);

    return 0;
}