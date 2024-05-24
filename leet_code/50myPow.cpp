#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

double myPow(double x, int n) {
        if(n == 0) return x < 0 ? -1 : 1;
        if(x == 1) return 1;
        if(x == -1) return n % 2 == 0 ? 1 : -1;
        double res = 1;
        long long absn = n;
        if(n < 0) absn = 0 - absn;
        for(int i = 1; i <= absn; ++i) {
            if(n > 0) res *= x;
            else res /= x;
            if(res == 0) return res;
        }
        return res;
    }

    int main() {
        return myPow(2.0, -2147483648);
    }