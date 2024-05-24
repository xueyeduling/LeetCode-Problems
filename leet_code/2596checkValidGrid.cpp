#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;


bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return false;
        vector<pair<int, int>> stepVec(pow(grid.size(), 2), pair<int, int>());

        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                stepVec[grid[i][j]] = {i, j};
            }
        }

        for(int i = 1; i < stepVec.size(); ++i) {
            if(pow(stepVec[i - 1].first - stepVec[i].first, 2) + pow(stepVec[i - 1].second - stepVec[i].second, 2) != 5)
                return false;
        }

        return true;
    }

int main() {
    vector<vector<int >> vec = {{0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22}};
    checkValidGrid(vec);

    return 0;
}