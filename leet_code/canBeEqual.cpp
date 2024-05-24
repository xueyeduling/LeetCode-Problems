#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

bool isEqual(string s1, string s2, int index) {
    if(s1 == s2) return true;
    if(index > 1) return false;
    string tempS1 = s1;
    tempS1[index] = s1[index + 2];
    tempS1[index + 2] = s1[index];
    index += 1;
    return (isEqual(tempS1, s2, index) || isEqual(s1, s2, index));
}

bool canBeEqual(string s1, string s2) {
    int i = 0;
    return isEqual(s1, s2, i);
}

int main() {
    string s1 = "abcd";
    string s2 = "dacb";

    cout << canBeEqual(s1, s2) << endl;
    return 0;
}