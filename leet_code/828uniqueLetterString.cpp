#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int uniqueLetterString(string s) {
    int ans = s.length();

    for(int i = 2; i <= s.size(); ++i) {
        unordered_map<char, int> m;
        for(int k = 0; k < i; ++k) {
            m[s[k]] += 1;
        }

        for(auto& p : m) {
            if(p.second == 1) {
                ans++;
            }
        }

        for(int j = 0; j + i < s.size(); ++j) {
            m[s[j]] -= 1;
            m[s[j + i]] += 1;
            for(auto& p : m) {
                if(p.second == 1) {
                    ans++;
                }
            }
        }
    }

    return ans;
}

int main() {
    int ans =  uniqueLetterString("ABC");
    
    return 0;
}