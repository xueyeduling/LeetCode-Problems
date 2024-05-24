#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int longestValidParentheses(string s) {
    int ans = 0;
    stack<int> sta;
    vector<bool> isCancle(s.length(), false);
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == '(') sta.push(i);
        else if(!sta.empty()) {
            int index = sta.top();
            isCancle[i] = true;
            isCancle[index] = true;
            sta.pop();
        }
    }

    int len = 0;
    for(int i = 0; i < s.length(); ++i) {
        if(isCancle[i]) len++;
        else {
            ans = max(ans, len);
            len = 0;
        }
    }
    return max(ans, len);
}

int main() {
    longestValidParentheses("()(())");
    return 0;
}