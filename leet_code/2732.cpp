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

vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
    unordered_map<int, int> mii;
    for(int i = 0; i < grid.size(); ++i) {
        int sign = 0;
        for(int j = 0; j < grid[i].size(); ++j) {
            sign = (sign << 1) + grid[i][j];
        }
        mii[sign] = i;
    }

    for(int i = 0; i < grid.size(); ++i) {
        vector<int> vecSign {0};
        for(int j = 0; j < grid[i].size(); ++j) {
            int n = vecSign.size();
            for(int k = 0; k < n; ++k) {
                if(grid[i][j] == 0) 
                    vecSign.push_back((vecSign[k] << 1) + 1);
                vecSign[k] = (vecSign[k] << 1);
            }
        }
        for(auto sign : vecSign)
            if(mii.count(sign) != 0) 
                if(mii[sign] != i) return vector<int> {min(i, mii[sign]), max(i, mii[sign])};
                else return vector<int> {i};
    }

    return vector<int>{};
}

int main() {
    vector<vector<int>> vec = {{1,1},{0,1},{1,0},{0,0},{1,0},{0,1},{1,1},{0,1},{1,1}};
    vector<int> res = goodSubsetofBinaryMatrix(vec);

    for(auto n : res) cout << n << endl;


    return 0;
}