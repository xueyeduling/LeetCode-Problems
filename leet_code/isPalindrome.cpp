#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) return false;
        int reverser = 0;
        for(; x > reverser; x /= 10) {
            reverser = reverser * 10 + x % 10;
        }
        return x == reverser || x == reverser / 10;
    }

int main() {
    cout << isPalindrome(121) << endl;

    return 0;
}