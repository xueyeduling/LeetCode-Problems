#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans;
        vector<vector<bool>> isqueen(8, vector<bool>(8, false));
        for(auto vec : queens) isqueen[vec[0]][vec[1]] = true;

        // 下方
        for(int i = king[0] + 1; i < 8; ++i) {
            if(isqueen[i][king[1]]) {
                ans.push_back({i, king[1]});
                break;
            }
        }

        // 上方
        for(int i = king[0] - 1; i > 0; --i) {
            if(isqueen[i][king[1]]) {
                ans.push_back({i, king[1]});
                break;
            }
        }

        // 右方
        for(int i = king[1] + 1; i < 8; ++i) {
            if(isqueen[king[0]][i]) {
                ans.push_back({king[0], i});
                break;
            }
        }

        // 左方
        for(int i = king[1] - 1; i > 0; --i) {
            if(isqueen[king[0]][i]) {
                ans.push_back({king[0], i});
                break;
            }
        }

        // 右下
        for(int i = king[0] + 1, j = king[1] + 1; i < 8 && j < 8; ++i, ++j) {
            if(isqueen[i][j]) {
                ans.push_back({i, j});
                break;
            }
        }

        // 右上
        for(int i = king[0] - 1, j = king[1] + 1; i > 0 && j < 8; --i, ++j) {
            if(isqueen[i][j]) {
                ans.push_back({i, j});
                break;
            }
        }

        // 左下
        for(int i = king[0] + 1, j = king[1] - 1; i < 8 && j > 0; ++i, --j) {
            if(isqueen[i][j]) {
                ans.push_back({i, j});
                break;
            }
        }

        // 左上
        for(int i = king[0] - 1, j = king[1] - 1; i > 0 && j > 0; --i, --j) {
            if(isqueen[i][j]) {
                ans.push_back({i, j});
                break;
            }
        }

        return ans;
    }

int main() {
    vector<vector<int>> queens = {{5,6},{7,7},{2,1},{0,7},{1,6},{5,1},{3,7},{0,3},{4,0},{1,2},{6,3},{5,0},{0,4},{2,2},{1,1},{6,4},{5,4},{0,0},{2,6},{4,5},{5,2},{1,4},{7,5},{2,3},{0,5},{4,2},{1,0},{2,7},{0,1},{4,6},{6,1},{0,6},{4,3},{1,7}};
    vector<int> king({3, 4});

    queensAttacktheKing(queens, king);

    return 0;
}