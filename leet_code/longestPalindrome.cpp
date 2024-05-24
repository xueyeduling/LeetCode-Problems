#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

pair<int, int> expandFromCenter(string s, int left, int right) {
    for(;left >=0 && right < s.length(); left--, right++) {
        if(s[left] != s[right]) return {left + 1, right - 1};
    }
    return {left + 1, right - 1};
}

string longestPalindrome(string s) {
    if(s.length() < 2) return s;
    int start = 0, end = 0;
    int left, right;
    for(int i = 0; i < s.length(); i++) {
        auto [left1, right1] = expandFromCenter(s, i, i);
        auto [left2, right2] = expandFromCenter(s, i, i + 1);
        if(right1 - left1 > end - start) {
            start = left1;
            end = right1;
        }
        if(right2 - left2 > end - start) {
            start = left2;
            end = right2;
        }
    }

    return s.substr(start, end - start + 1);
}

int main() {
    string s = "bb";
    string palindrome = longestPalindrome(s);

    cout<< palindrome << endl;

    return 0;
}