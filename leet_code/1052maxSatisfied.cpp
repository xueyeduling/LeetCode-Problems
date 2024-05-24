#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int res = 0;
    int minstat = 0;
    int n = customers.size();

    vector<int> vecn1(n), vecn2(n);

    vecn1[0] = grumpy[0] ? 0 : customers[0];
    vecn2[n - 1] = grumpy[n - 1] ? 0 : customers[n - 1];

    for(int i = 1; i < n; ++i) vecn1[i] = vecn1[i - 1] + (grumpy[i] ? 0 : customers[i]);
    for(int i = n - 2; i >= 0; --i) vecn2[i] = vecn2[i + 1] + (grumpy[i] ? 0 : customers[i]);

    
    for(int i = 0; i < minutes; ++i) minstat += customers[i];

    res = minstat;
    if(minutes < n) res += vecn2[minutes];

    for(int i = 1; i < n - minutes + 1; ++i) {
        minstat += customers[i + minutes - 1];
        minstat -= customers[i - 1];
        int tmp = minstat + vecn1[i - 1];
        if(i + minutes < n) tmp += vecn2[i + minutes];
        if(tmp > res) res = tmp;
    }
    return res;
}

int main() {
    vector<int> v1 = {10, 1, 7};
    vector<int> v2 = {0, 0, 0};
    maxSatisfied(v1, v2, 2);
    return 0;
}