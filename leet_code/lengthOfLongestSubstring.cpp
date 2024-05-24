#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> exist{};
    int longest = 0, left = 0;
    for(int i = 0; i < s.length(); i++){
        if(exist.find(s[i]) == exist.end()) exist.insert(s[i]);
        else {
            longest = max(longest, (int)exist.size());
            while(exist.find(s[i]) != exist.end()) {
                exist.erase(s[left++]);
            }
            exist.insert(s[i]);
        }
    }
    return max(longest, (int)exist.size());
}

int main() {
    string s = "aab";

    int length = lengthOfLongestSubstring(s);

    cout << length << endl;

    return 0;
}