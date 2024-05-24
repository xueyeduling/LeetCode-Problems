#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int findMinimumOperations(string s1, string s2, string s3) {
        int res = 0;

        int len = min(s1.length(), min(s2.length(), s3.length()));
        if(s1 == s2 && s2 == s3) return res;

        while(s1.length() != 1 || s2.length() != 1 || s3.length() != 1) {

            res += s1.length() - len;
            s1 = s1.substr(0, len);
            res += s2.length() - len;
            s2 = s2.substr(0, len);
            res += s3.length() - len;
            s3 = s3.substr(0, len);
            
            if(s1 == s2 && s2 == s3) return res;

            len -= 1;
        }

        return -1;
    }

    int main() {
        string s1 = "a";
        string s2 = "aabc";
        string s3 = "a";
        findMinimumOperations(s1, s2, s3);
        return 0;
    }