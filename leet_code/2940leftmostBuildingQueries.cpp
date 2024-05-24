#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int> res;
        for(int i = 0; i < queries.size(); ++i) {
            int a = queries[i][0], b = queries[i][1];
            if(a > b) swap(a, b);
            int c = heights[a];
            if(a == b) res.push_back(a);
            else if(c >= *max_element(heights.begin() + b, heights.end())) res.push_back(-1);
            else if(c < heights[b]) res.push_back(b);
            else {
                for(int j = b + 1; j < heights.size(); ++j) {
                    if(c >= heights[j]) continue;
                    res.push_back(j);
                    break;
                }
            }
        }

        return res;
    }

    int main() {
        vector<int> vec = {2,3,1};
        vector<vector<int>> vec2 = {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
        leftmostBuildingQueries(vec, vec2);
        return 0;
    }