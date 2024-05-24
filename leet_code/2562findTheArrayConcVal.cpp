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

long long findTheArrayConcVal(vector<int>& nums) {
        long long n = 0;
        for(int i = 0, j = nums.size() - 1; i <= j; ++i, --j) {
            if(i == j) return n + nums[i];
            n += nums[i] * pow(10, to_string(nums[j]).size()) + nums[j];
        }
        return n;
    }

    int main() {
        vector<int> v = {5,14,13,8,12};
        long long n = findTheArrayConcVal(v);
        return 0;
    }