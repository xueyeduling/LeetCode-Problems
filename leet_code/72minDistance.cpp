#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int getDistance(int i, int j, string& word1, string& word2) {
    if(i == word1.length() || j == word2.length()) 
        return word1.length() - i + word2.length() - j;
    if(word1[i] == word2[j]) 
        return getDistance(i + 1, j + 1, word1, word2);
    int deletedd = getDistance(i, j + 1, word1, word2);
    int addd = getDistance(i + 1, j, word1, word2);
    int replacedd = getDistance(i + 1, j + 1, word1, word2);
    return min(deletedd, min(addd, replacedd)) + 1;
}

int minDistance(string word1, string word2) {
    return getDistance(0, 0, word1, word2);
}

int main() {
    string word1 = "dinitrophenylhydrazine";
    string word2 = "acetylphenylhydrazine";

    int ans = minDistance(word1, word2);

    return 0;
}