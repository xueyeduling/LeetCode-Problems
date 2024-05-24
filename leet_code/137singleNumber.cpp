#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <numeric>
using namespace std;

int singleNumber(vector<int>& nums) {
        int n = 0;
        for (auto e: nums) n ^= e;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        n ^= sum;
        return (sum - n / 4 * 3);
    }

int main() {
    vector<int> vec = {2,1,2,1,2,1,99};
    int n = singleNumber(vec);
    return 0;
}