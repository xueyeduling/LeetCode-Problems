#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;
vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    for(int i = 1; i < nums.size(); ++i) {
        for(int j = 0; j < i; ++j) {
            if(nums[j] > nums[i] && abs(nums[j] - nums[i]) <= limit) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i = j;
            }
        }
    }

    return nums;
}

int main() {
    vector<int> vec = {5,100,44,45,16,30,14,65,83,64};
    vector<int> ans = lexicographicallySmallestArray(vec,15);
    
    return 0;
}