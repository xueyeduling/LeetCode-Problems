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

int addStr(string& s, int k, int inx = -1) {
    if(inx = -1) inx = s.size() - 1;
    s[inx]++;
    for(int i = inx; i >= 0; --i) {
        if(s[i] - 'a' < k) return i;
        else if(i > 0) {
            s[i] = 'a';
            s[i - 1] = s[i - 1] + 1;
        }
        else return -1;
    }
    return -1;
}

string smallestBeautifulString(string s, int k) {
    int a = 'a', n = 0;
    int len = s.size();
    int m = addStr(s, k);
    while(true) {
        if(m == -1) return "";
        if(len == 2 && s[0] == s[1]) {
            m = addStr(s, k, 1);
            continue;
        } 
        for(int i = max(1, m); i < len; ++i) {
            if(s[i] == s[i - 1] || i > 1 && s[i] == s[i - 2]) {
                m = addStr(s, k, i);
                goto ctn;
            }
        }
        return s;
        ctn: continue;
    }
}

int main() {
    string s = "edg";
    int k = 7;

    string res = smallestBeautifulString(s, k);

    cout << res << endl;

    return 0;
}