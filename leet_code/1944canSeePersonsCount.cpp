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

vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() < heights[i]) {
                st.pop();
                ans[i]++;
            }
            if (!st.empty()) {
                ans[i]++;
            }
            st.push(heights[i]);
        }
        return ans;
    }

int main() {
    vector<int> vec = {10,6,8,5,11,9};

    vector<int> ans = canSeePersonsCount(vec);
    
    return 0;
}