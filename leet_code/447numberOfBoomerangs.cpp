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

int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        
        sort(points.begin(), points.end(), [](const vector<int>& p1, const vector<int>& p2)
        {
            return sqrt(pow(p1[0], 2) + pow(p1[1], 2)) < sqrt(pow(p2[0], 2) + pow(p2[1], 2));
        });

        for(int i = 0; i < points.size(); ++i) {
            for(int j = i + 1; j < points.size(); ++j) {
                int d = pow(points[j][0] - points[i][0], 2) + pow(points[j][1] - points[i][1], 2);
                for(int k = j + 1; k < points.size(); ++k) {
                    int d2 = pow(points[k][0] - points[j][0], 2) + pow(points[k][1] - points[j][1], 2);
                    if(d2 < d) continue;
                    if(d2 == d) res += 2;
                    break;
                }
            }
        }

        return res;
    }

int main() {
    vector<vector<int>> points = {{0,0},{1,0},{-1,0},{0,1},{0,-1}};

    int ans = numberOfBoomerangs(points);
    
    return 0;
}