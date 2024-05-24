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

int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int zerorows = 0;
        vector<int> notzerorowvec;
        unordered_map<int, int> map;
        vector<int> colvec;

        for(int i = 0; i < matrix.size(); ++i) {
            int zero = 0;
            for(int j = 0; j < matrix[i].size(); ++j) {
                if(matrix[i][j] == 0) zero++;
            }
            if(zero == matrix[i].size()) zerorows++;
            else if(numSelect + zero >= matrix[i].size()) notzerorowvec.push_back(i);
        }

        for(int i = 0; i < notzerorowvec.size(); ++i) {
            int n = 0;
            for(int j = 0; j < matrix[notzerorowvec[i]].size(); ++j) {
                if(matrix[notzerorowvec[i]][j] == 0)  continue;
                n = n * 10;
                n += (j + 1);
            }
            map[n] += 1;
        }

        for(auto m : map) {
            colvec.push_back(m.second);
        }

        for()

        return zerorows;
    }

int main() {
    vector<vector<int>> martix = {{1,0,1,0},{1,0,1,0},{0,1,1,1},{0,1,0,0}};

    int ans = maximumRows(martix, 3);
    
    return 0;
}