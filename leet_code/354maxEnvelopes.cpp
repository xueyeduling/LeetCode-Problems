#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int maxEnvelopes(vector<vector<int>>& envelopes) {
    if (envelopes.empty()) return 0;
    
    int n = envelopes.size();
    
    sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
        return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
    });

    vector<int> f = {envelopes[0][1]};
    for (int i = 1; i < n; ++i) {
        if (int num = envelopes[i][1]; num > f.back()) {
            f.push_back(num);
        }
        else {
            auto it = lower_bound(f.begin(), f.end(), num);
            *it = num;
        }
    }
    return f.size();
}


int main() {
    vector<vector<int>> envelopes = {{3, 10}, {12, 25}, {12, 4}, {33, 5}, {33, 1}};

    int ans = maxEnvelopes(envelopes);

    return 0;
}