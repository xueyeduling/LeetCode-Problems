#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int sumSubarrayMins(vector<int>& arr) {
        int res = 0;
        int n = arr.size();
        int arr2[n][2];
        for(int i = 0; i < n; ++i) {
            int j;
            for(j = i - 1; j >= 0; --j) {
                if(arr[j] <= arr[i]) break;
            }
            arr2[i][0] = j;

            for(j = i + 1; j < n; ++j) {
                if(arr[j] < arr[i]) break;
            }
            arr2[i][1] = j;
        }

        for(int i = 0; i < n; ++i) {
            res = (res + arr[i] * (i - arr2[i][1]) * (arr2[i][0] - i)) % 1;
        }

        return res;
    }


int main() {
    vector<int> vec = {71,55,82,55};
    int ans = sumSubarrayMins(vec);
    
    return 0;
}