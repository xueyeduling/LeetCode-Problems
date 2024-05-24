#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <numeric>
#include <set>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int, greater<int> > pq;
        for(int i = 0; i < k; ++i) pq.insert(nums[i]);
        for(int i = k; i < nums.size(); ++i) {
            int n = *pq.begin();
            res.push_back(n);
            pq.erase(nums[i - k]);
            pq.insert(nums[i]);
        }
        int n = *pq.begin();
        res.push_back(n);

        return res;
    }

int main() {
    vector<int> vec = {-7,-8,7,5,7,1,6,0};
    maxSlidingWindow(vec, 4);
    return 0;
}