#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;

vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int summ = accumulate(rolls.begin(), rolls.end(), 0);
    int m = rolls.size();
    int sumTotal = mean * (m + n);
    int diff = sumTotal - summ;
    if(diff > n * 6 || diff < n) return vector<int>();

    int diff2 = diff - n;
    int add5 = diff2 / 5;
    int addMode = diff2 % 5;

    vector<int> res(n, 1);
    for(int i = 0; i < add5; ++i) {
        res[i] = 6;
    }
    if(addMode > 0) res[add5] += addMode;

    return res;
}

int main() {
    vector<int> vec = {1,2,3,4};
    int mean = 6;
    int n = 4;

    missingRolls(vec, mean, n);

    return 0;
}