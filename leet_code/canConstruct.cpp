#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    for(char c : ransomNote) {
        auto iter = magazine.find(c);
        if(iter == std::string::npos) return false;
        else magazine.erase(iter, 1);
    }
    return true;
}

int main() {
    string ransomNote = "aa";
    string magazin = "ab";

    cout<< canConstruct(ransomNote, magazin) << endl;

    return 0;
}