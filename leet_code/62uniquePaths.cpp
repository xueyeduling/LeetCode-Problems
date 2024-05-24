#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;


    int uniquePaths(int m, int n) {
        vector<vector<int>> vec(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) 
            vec[i][0] = 1;
        for(int i = 0; i < n; ++i) vec[0][i] = 1;

        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                vec[i][j] = vec[i - 1][j] + vec[i][j - 1];
            }
        }

        return vec[m - 1][n - 1];
    }

int main() {
    int ans = uniquePaths(3, 3);

    return ans;
}