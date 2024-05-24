#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

bool areSimilar(vector<vector<int>>& mat, int k) {
    vector<vector<int>> mat2;
    for(int i = 0; i < mat.size(); ++i) {
        vector<int> nums;
        for(int j = 0; j < mat[i].size(); ++j) {
            if(i % 2 == 0) nums.push_back(mat[i][(j + k) % mat[i].size()]);
            else nums.push_back(mat[i][mat[i].size() - 1 - ( mat[i].size() - 1 - j + k) % mat[i].size()]);
        }
        mat2.push_back(nums);
    }
    return mat == mat2;
}

int main() {
    vector<vector<int>> mat = {{1,2,1,2}, {5,5,5,5}, {6,3,6,3}};

    bool ans = areSimilar(mat, 2);
    
    return 0;
}