#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <numeric>
#include <set>
using namespace std;

int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> grid2 = grid;
        for(int i = 0; i < m - 1; ++i) {
            for(int j = 0; j < n; ++j) {
                for(int k = 0; k < n; ++k) {
                    grid2[i + 1][k] =  min(j == 0 ? INT_MAX : grid2[i + 1][k], grid[i + 1][k] + grid2[i][j] + moveCost[grid[i][j]][k]);
                } 
            }
        }

        return *min_element(grid2[m - 1].begin(), grid2[m - 1].end());
    }

int main() {
    vector<vector<int>> vec = {{5,3},{4,0},{2,1}};
    vector<vector<int>> vec2 = {{9,8},{1,5},{10,12},{18,6},{2,4},{14,3}};
    int i = minPathCost(vec, vec2);
    return 0;
}