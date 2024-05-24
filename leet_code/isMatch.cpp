#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;


bool isMatch(string s, string p) {
    bool matched = true;
    int i = 0, j = 0;
    while(true) {
        if(i >= s.length()) {
            char lastChar = p[j - 1];
            while(j < p.length()) {
                if(p[j] != '*') {
                    if(p[j] == '.') j++;
                    else if(j + 1 == p.length()) return false;
                    else if(p[j + 1] != '*') return false;
                }
                else {
                    if(j + 1 == p.length()) return true;
                    if(p[j + 1] != lastChar) {
                        if(j + 2 == p.length()) return false;
                        else if(p[j + 2] != '*') return false;
                    }
                }
                j += 2;
            }
            return true;
        }
        if(j >= p.length()) {
            if(p.length() < 2) 
                return false;
            if(p[p.length() - 1] != '*') 
                return false;
            if(p[p.length() - 2] == s[i] && s[i] == s[i - 1]) 
                return true;
            if(p[p.length() - 2] == '.') 
                return true;
            return false;
        };
        if(s[i] == p[j]) {
            i++;
            j++;
        }
        else if(p[j] == '.') {
            i++;
            j++;
        }
        else if(j + 1 < p.length() - 1 && p[j + 1] == '*') {
            j += 2;
        }
        else if(p[j] == '*') {
            if(j == 0) return false;
            if(p[j - 1] == s[i] || (p[j - 1] == '.' && s[i] == s[i - 1])) {
                i++;
            }
            else {
                j++;
            }
        }
        else {
            return false;
        }
    }

    return true;
}

int main() {
    string s = "ab";
    string p = ".*..";
 
    cout << isMatch(s, p) << endl;

    return 0;
}

/*
    if(i >= s.length()) {
        char lastChar = p[j - 1];
        while(j < p.length()) {
            if(p[j] != '*') {
                if(j + 1 == p.length()) return false;
                if(p[j + 1] != '*') return false;
            }
            else {
                if(j + 1 == p.length()) return true;
                if(p[j + 1] != lastChar) {
                    if(j + 2 == p.length()) return false;
                    else if(p[j + 2] != '*') return false;
                }
            }
            j += 2;
        }
        return true;
    }

    if(j >= p.length()) {
        if(p.length() < 2) 
            return false;
        if(p[p.length() - 1] != '*') 
            return false;
        if(p[p.length() - 2] == s[i] && s[i] == s[i - 1]) 
            return true;
        if(p[p.length() - 2] == '.') 
            return true;
        return false;
    };
*/