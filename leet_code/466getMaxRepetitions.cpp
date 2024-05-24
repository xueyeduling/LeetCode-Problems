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

int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    double m = 0, n = 0;
    for(; m < n1 * s1.size(); ++m) {
        if(s1[(int)m % s1.size()] == s2[(int)n % s2.size()]) n++;
        if((int)(m + 1) % s1.size() == 0 && (int)n % s2.size() == 0) break;
    }

    if(m >= n1 * s1.size()) return n / ((1.0 * s2.size()) * n2);
    return (n / (1.0 * s2.size())) * n1 / (n2 * ((m + 1) / (1.0 * s1.size())));
}

int main() {
    string s1 = "niconiconi";
    string s2 = "nico";

    int ans = getMaxRepetitions(s1, 99981, s2, 81);
    
    return 0;
}
