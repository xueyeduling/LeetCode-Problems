#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

bool primeSubOperation(vector<int>& nums) {
        vector<int> primes;
        
        for(int i = 2, j; i <= 1000; ++i) {
            for (j = 2; j <= i / 2; j++) if (i % j == 0) break;
            if(j > i / 2) primes.push_back(i);
        }

        for(int i = nums.size() - 2; i >= 0; --i) {
            if(nums[i] < nums[i + 1]) continue;
            else {
                auto p = upper_bound(primes.begin(), primes.end(), nums[i] - nums[i + 1]);
                if(p != primes.end() && *p < nums[i]) nums[i] = nums[i] - *p;
                else return false;
            }
        }

        return true;
    }

    int main() {
        vector<int> vec = {5, 8, 3};
        primeSubOperation(vec);
        return 0;
    }