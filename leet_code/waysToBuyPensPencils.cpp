#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

long long waysToBuyPensPencils(int total, int cost1, int cost2) {
    long ways = 0;
    for(int i = 0; cost1 * i <= total; i++) {
        ways += (total - cost1 * i) / cost2 + 1;;
    }
    return ways;
}

int main() {
    int total = 20;
    int cost1 = 10;
    int cost2 = 5;

    int ways = waysToBuyPensPencils(total, cost1, cost2);

    cout << ways << endl;

    return 0;
}