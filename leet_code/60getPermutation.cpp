#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int getFactorial(int n) {
        int factorial = 1;
        for(int i = n; i > 1; --i) factorial *= i;
        return factorial;
    }

    string dfs(int k, vector<int> nums) {
        if(nums.size() == 1) return to_string(nums[0]);
        int f = getFactorial(nums.size() - 1);
        int n = k / f;
        int m = k % f;
        if(m == 0 && n > 0) --n;
        if(m == 0) m = f;
        int fir = nums[n];
        nums.erase(remove(nums.begin(), nums.end(), fir), nums.end());
        return to_string(fir) + dfs(m, nums);
    }

    string getPermutation(int n, int k) {
        vector<int> nums(n, 0);
        for(int i = 0; i < n; ++i) nums[i] = i + 1;
        return dfs(k, nums);
    }

int main() {
    string ans = getPermutation(9, 36);

    return 0;
}