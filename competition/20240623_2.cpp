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

int minimumArea(vector<vector<int>>& grid) {
        vector<vector<int>> onevec;
        int minr = grid.size(), maxr = 0, minc = grid[0].size(), maxc = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == 0) continue;
                minr = min(minr, i);
                maxr = max(maxr, i);
                minc = min(minc, j);
                maxc = max(maxc, j);
            }
        }
        
        return (maxr - minr + 1) * (maxc - minc + 1);
    }

int main() {
    vector<vector<int>> vec = {{0,1,0},{1,0,1}};
    int res = minimumArea(vec);

    cout << res << endl;

    return 0;
}