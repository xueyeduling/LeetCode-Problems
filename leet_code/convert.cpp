#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

string convert(string s, int numRows) {
    if(numRows == 1) return s;
    vector<string> newStr(numRows);
    string result = "";
    int rowIndex = 0, column = 0;
    for(int i = 0; i < s.length(); i++) {
        rowIndex = i % (numRows * 2 - 2);
        if(rowIndex < numRows) newStr[rowIndex] += s[i];
        else newStr[numRows - 1 - (rowIndex - (numRows - 1))] += s[i];
    }

    for(string str : newStr) {
        result += str;
    }

    return result;
}

int main() {
    string s = "PAYPALISHIRING";
    int numRows = 2;
    string newStr = convert(s, numRows);

    cout<< newStr << endl;

    return 0;
}