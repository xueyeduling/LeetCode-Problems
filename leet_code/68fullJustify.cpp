#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> str_vec;
        for(int i = 0; i < words.size(); ) {
            string s = "";

            int len = words[i].length() + 1, j = i + 1;

            while(j != words.size() && len + words[j].length() <= maxWidth) len += words[j++].length() + 1;

            if(j - i - 1 == 0) {
                s += words[i];
                int maxWidthTemp = maxWidth;
                while(maxWidthTemp-- >= len) s += " ";
            }
            else if(j == words.size()) {
                for(int k = i; k < j; ++k) {
                    s += words[k];
                    if(s.length() < maxWidth) s += " ";
                }
                int maxWidthTemp = maxWidth;
                while(maxWidthTemp-- > len) s += " ";
            }
            else {
                int spaces1 = (maxWidth - len + 1) / (j - i - 1);
                string spaces = " ";
                while(spaces1-- > 0) spaces += " ";
                int spaces2 = (maxWidth - len + 1) % (j - i - 1);

                for(int k = i; k < j; ++k) {
                    s += words[k];
                    if(k + 1 < j) s += spaces;
                    if(spaces2-- > 0) s += " ";
                }
            }

            str_vec.push_back(s);

            i = j;
        }

        return str_vec;
    }

int main() {
    vector<string> words = {"ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"};

    vector<string> ans = fullJustify(words, 16);

    return 0;
}