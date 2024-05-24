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

long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size();
    vector<int> ids(n);
    iota(ids.begin(), ids.end(), 0);
    
    sort(ids.begin(), ids.end(), [&](int i, int j) { return nums2[i] > nums2[j]; });

    priority_queue<int, vector<int>, greater<>> pq;
    long long sum = 0;
    for (int i = 0; i < k; i++) {
        sum += nums1[ids[i]];
        pq.push(nums1[ids[i]]);
    }

    long long ans = sum * nums2[ids[k - 1]];
    for (int i = k; i < n; i++) {
        int x = nums1[ids[i]];
        if (x > pq.top()) {
            sum += x - pq.top();
            pq.pop();
            pq.push(x);
            ans = max(ans, sum * nums2[ids[i]]);
        }
    }
    return ans;
}

int main() {
    // nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
    vector<int> vec1 = {1, 3, 3, 2};
    vector<int> vec2 = {2, 1, 3, 4};
    int k = 3;

    int res = maxScore(vec1, vec2, k);

    return res;
}