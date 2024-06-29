#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <numeric>
#include <unordered_set>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {

        vector<int> res(nums.size(), -1);
        vector<int> stack = {0};
        for(int i = 1; stack.back() != i; i = ++i % nums.size()) {
            while(stack.size() > 0 && nums[stack.back()] < nums[i]) {
                res[stack.back()] = nums[i];
                stack.pop_back();
            }
            if(res[i] == -1) stack.push_back(i);
        }

        return res;
    }

int main()
{
    vector<int> nums = {1,1,1,1,1};

    nextGreaterElements(nums);

    return 0;
}