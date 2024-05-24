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

int minExtraChar(string s, vector<string> &dictionary) {
        unordered_set<string> set(dictionary.begin(), dictionary.end());
        int n = s.size();
        vector<int> f(n + 1);
        for (int i = 0; i < n; i++) {
            f[i + 1] = f[i] + 1; // 不选
            for (int j = 0; j <= i; j++) { // 枚举选哪个
                if (set.count(s.substr(j, i - j + 1))) {
                    f[i + 1] = min(f[i + 1], f[j]);
                }
            }
        }
        return f[n];
    }

int main() {
    vector<string> strs = {"leet","code","leetcode"};

    int ans = minExtraChar("leetscode", strs);
    
    return 0;
}