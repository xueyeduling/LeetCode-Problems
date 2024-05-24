#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int maximumXorProduct(long long a, long long b, int n) {
        long long res = 0;
        int m = pow(10, 9) + 7;

        int x = 2;

        /*for(long long i = 0; i < pow(2, n); ++i) {
            long long l1 = a ^ i;
            long long l2 = b ^ i;
            res = max(res, l1 * l2);
        }*/

        long long l1 = a ^ x;
        long long l2 = b ^ x;
        res = l1 * l2;

        return res % m;
    }

    int main() {
        vector<int> vec = {5, 8, 3};
        maximumXorProduct(1,6,3);
        return 0;
    }