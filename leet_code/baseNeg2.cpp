#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

string baseNeg2(int n) {
    if(!n) return "0";
    int digit = 0, sum = 1;
    string neg2Num = "1";
    for(; n > sum;) {
        digit += 2;
        sum += pow(2, digit);
        neg2Num += "01";
    }
    digit -= 1;
    while(digit >= 0) {
        sum -= abs(pow(-2, digit));
        if(sum >= n) {
            if(digit % 2 != 0) neg2Num[neg2Num.length() - digit - 1] = '1';
            else neg2Num[neg2Num.length() - digit - 1] = '0';
        }
        else {
            sum += abs(pow(-2, digit));
        }
        digit--;
    }

    return neg2Num;
}

int main() {
    int num = 6;
    string newStr = baseNeg2(num);

    cout<< newStr << endl;

    return 0;
}