#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

template <typename t> void move(std::vector<t>& v, size_t oldIndex, size_t newIndex)
{
    if (oldIndex > newIndex)
        std::rotate(v.rend() - oldIndex - 1, v.rend() - oldIndex, v.rend() - newIndex);
    else        
        std::rotate(v.begin() + oldIndex, v.begin() + oldIndex + 1, v.begin() + newIndex + 1);
}

int getNewIndex(vector<int>& vec, int val) {
    for(int i = 0; i < vec.size(); ++i)
        if(val < vec[i]) return i;
    return vec.size() - 1;
}

    bool check(vector<int> &nums, int k, int mx) {
        int cnt = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= mx) {
                cnt++; // 偷 nums[i]
                i++; // 跳过下一间房子
            }
        }
        return cnt >= k;
    }

    int minCapability(vector<int> &nums, int k) {
        vector<int> nums2(nums.begin(), nums.end());
        sort(nums2.begin(), nums2.end());
        int left = 0, right = nums2.size() - 1;
        while (left + 1 < right) { // 开区间写法
            int mid = left + (right - left) / 2;
            (check(nums, k, nums2[mid]) ? right : left) = mid;
        }
        return nums2[right];
    }

    int minCapability2(vector<int> &nums, int k) {
        vector<vector<int>> nums_index(nums.size(), vector<int>(2, 0));
        for(int i = 0; i < nums.size(); ++i) nums_index[i] = {nums[i], i};
        sort(nums_index.begin(), nums_index.end(), [](vector<int> v1, vector<int> v2){return v1[0] < v2[0];});
        vector<int> nums_index2(2 * k - 1, 0);
        for(int i = 0; i < 2 * k - 1; ++i) nums_index2[i] = nums_index[i][1];
        sort(nums_index2.begin(), nums_index2.begin() + k);
        int i = 0, j = 1, n = k;
        while(true) {
            if(j == k ) break;
            if(nums_index2[i] + 1 != nums_index2[i + 1]) i += 1;
            else i += 2;
            j += 1;
            if(i >= n) {
                int index = getNewIndex(nums_index2, nums_index2[n]);
                move(nums_index2, n, index);
                i = 0;
                j = 1;
                n++;
            }
        }
        return nums_index[n - 1][0];
    }

int main() {
    vector<int> nums = {1,4,5};

    int ans = minCapability(nums, 1);

    return 0;
}