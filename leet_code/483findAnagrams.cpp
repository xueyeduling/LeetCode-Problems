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

vector<int> findAnagrams(string s, string p) {
    vector<int> res;

    if(s.size() < p.size()) return res;

    unordered_map<char, int> charIntMap;
    for(int i = 0; i < p.size(); ++i) {
        charIntMap[s[i]] += 1;
        charIntMap[p[i]] -= 1;
        if(charIntMap[s[i]] == 0) charIntMap.erase(s[i]);
        if(charIntMap[p[i]] == 0) charIntMap.erase(p[i]);
    }
    if(charIntMap.size() == 0) res.push_back(0);

    for(int i = 0; i < s.size() - p.size(); ++i) {
        int index = i + p.size();
        charIntMap[s[i]] -= 1;
        charIntMap[s[index]] += 1;
        if(charIntMap[s[i]] == 0) charIntMap.erase(s[i]);
        if(charIntMap[s[index]] == 0) charIntMap.erase(s[index]);
        if(charIntMap.size() == 0) res.push_back(i + 1);
    }

    return res;
}

int main() {
    string s = "baa";
    string p = "aa";

    vector<int> ans = findAnagrams(s, p);
    
    return 0;
}
