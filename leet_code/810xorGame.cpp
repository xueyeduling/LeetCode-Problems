#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

bool step(vector<int>& nums, int& val) {
    for(int i = 0; i < nums.size(); ++i) {
        if((val ^ nums[i]) == 0){
            val = 0;
            nums.erase(nums.begin() + i);
            return false;
        }
    }
    val ^= nums[0];
    nums.erase(nums.begin());
    return true;
}

bool xorGame(vector<int>& nums) {
    if(nums.size() == 1) return true;
    int val = 0;
    bool alice;
    while(nums.size() > 1) {
        bool b = step(nums, val);
        alice = nums.size() % 2 == 0 ?  !b : b;
    }
    return alice;
}

int main() {
    vector<int> nums = {1,2,3};
    string word2 = "acetylphenylhydrazine";

    bool win = xorGame(nums);

    return 0;
}