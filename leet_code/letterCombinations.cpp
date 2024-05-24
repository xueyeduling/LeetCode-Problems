#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
using namespace std;

string combination(string str, string digits){
    if(digits.length() == 0) return str;
    int i = int(digits[0]);
    int num = i + (i - 50) * 2 + 47;
    string newStr = "";
    if(i > 55) num += 1;
    newStr += combination(str + char(num), digits.substr(1)) 
        + " " + combination(str + char(num + 1), digits.substr(1)) 
        + " " + combination(str + char(num + 2), digits.substr(1))
        + (i != 55 ? "" : " " + combination(str + char(num + 3), digits.substr(1)))
        + (i != 57 ? "" : " " + combination(str + char(num + 4), digits.substr(1)));

    return newStr;
}

vector<string> letterCombinations(string digits) {
    vector<string> strs;
    string strCombinated = combination("", digits);
    stringstream ss(strCombinated);
    string str;
    while(ss >> str) {
        strs.emplace_back(str);
    }
    return strs;
}

int main() {
    string s = "273457";
    letterCombinations(s);
    return 0;
}