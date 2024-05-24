#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
using namespace std;

int minNumber(vector<int> &nums1, vector<int> &nums2) {
    int mask1 = 0, mask2 = 0;
    for (int x: nums1) mask1 |= 1 << x;
    for (int x: nums2) mask2 |= 1 << x;
    int x = __builtin_ctz(mask1), y = __builtin_ctz(mask2);
    return mask1 & mask2 ? __builtin_ctz(mask1 & mask2) : min(x * 10 + y, y * 10 + x);
}

int main() {
    vector<int> vec1 = {1,2,3,4,5};
    vector<int> vec2 = {6,7,8,9};
    minNumber(vec1, vec2);
    return 0;
}