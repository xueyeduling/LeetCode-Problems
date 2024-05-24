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

bool cross(vector<int>& stones, int index, int step) {
        if(index == stones.size() - 1) return true;

        for(int i = -1; i <= 1; ++i) {
            if(step + i <= 0) continue;
            auto it = find(stones.begin() + index + 1, stones.end(), stones[index] + step + i);
            if(it != stones.end() && cross(stones, it - stones.begin(), step + i)) return true;
        }

        return false;
    }

    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
        return cross(stones, 1, 1);
    }

    int main() {
        vector<int> vec = {0,1,3,5,6,8,12,17};
        bool res = canCross(vec);
        return 0;
    }