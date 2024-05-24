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

 vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        map<int, queue<int>> m;
        int index = 0;
        int i = 0;
        for(; i <= nums.size() - k; ++i) {
            m[nums[i]].push(i);
        }
        while(i <= nums.size()) {
            res.push_back(m.begin()->first);
            int endi = m.begin()->second.front();
            for(; index <= endi; ++index) {
                m[nums[index]].pop();
                if(m[nums[index]].empty()) m.erase(nums[index]);
            }
            if(i == nums.size()) return res;
            m[nums[i]].push(i);
            i += 1;
        }

        return res;
    }

int main() {
    vector<int> vec = {2,4,3,3,5,4,9,6};
    vector<int> res = mostCompetitive(vec, 4);

    return 0;
}