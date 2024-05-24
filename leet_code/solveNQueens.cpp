#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

    vector<vector<string>> ans;
    // n is row, m is column
    bool canPlace(int n, int m, vector<vector<bool>>& isQueens) {
        for(int i = n - 1; i >= 0; --i) {
            if(isQueens[i][m]) return false;
        }
        for(int i = n - 1, j = 1; i >= 0 && m - j >= 0; --i, ++j) {
            if(isQueens[i][m - j]) return false;
        }
        for(int i = n - 1, j = 1; i >= 0 && m + j < isQueens.size(); --i, ++j) {
            if(isQueens[i][m + j]) return false;
        }

        return true;
    }

    bool nQueens(int n, vector<vector<bool>>& isQueens) {
        if(n == isQueens.size()) {
            vector<string> vecStr;
            for(int i = 0; i < isQueens.size(); ++i) {
                string s = "";
                for(int j = 0; j < isQueens.size(); ++j) {
                    if(isQueens[i][j]) s.append("Q");
                    else s.append(".");
                }
                vecStr.emplace_back(s);
            }
            ans.emplace_back(vecStr);
        }
        for(int i = 0; i < isQueens.size(); ++i) {
            if(!canPlace(n, i, isQueens)) continue;
            isQueens[n][i] = true;
            nQueens(n + 1, isQueens);
            isQueens[n][i] = false;
        }
        return false;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<bool> boolVec(n, false);
        vector<vector<bool>> isQueens(n , boolVec);
        nQueens(0, isQueens);

        return ans;
    }


int main() {
    solveNQueens(4);

    return 0;
}