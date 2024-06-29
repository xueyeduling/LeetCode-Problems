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

int paintWalls(vector<int>& cost, vector<int>& time) {
    int n = cost.size();
    vector<int> f(n + 1, INT_MAX / 2); // 防止加法溢出
    f[0] = 0;
    for (int i = 0; i < n; i++) {
        int c = cost[i], t = time[i] + 1; // 注意这里加一了
        for (int j = n; j; j--) {
            f[j] = min(f[j], f[max(j - t, 0)] + c);
        }
    }
    return f[n];
}

int main() {
    vector<int> cost = {1,2,3,2};
    vector<int> time = {1,1,1,1};

    int res = paintWalls(cost, time);

    cout << res << endl;

    return 0;
}