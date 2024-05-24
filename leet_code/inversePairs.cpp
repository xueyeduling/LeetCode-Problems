#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

    static long ans;
    static bool compare(int num1, int num2) {
        if(num1 <= num2) return true;
        ans++;
        return false;
    }
    int InversePairs(vector<int>& nums) {
        ans = 0;
        vector<int> numsSort = nums;
        sort(numsSort.begin(), numsSort.end(), compare);
        for(int i = 0; i < nums.size(); ++i) {
            if(numsSort[i] > nums[i]) ans += i;
        }
        return ans % 1000000007;
    }

    
int main() {
    std::vector<int> v{1,2,42,42,63};
    InversePairs(v);

    return 0;
}