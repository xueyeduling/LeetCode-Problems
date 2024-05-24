#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bits/stdc++.h>
using namespace std;


int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int maxProfit = 0;
        int maxProfitRuntimes = 0;
        int wait = 0;
        int profit = 0;

        for(int i = 0; i < customers.size() || wait != 0; ++i) {
            if(i < customers.size()) wait += customers[i];
            if(wait <= 4) {
                profit += wait * boardingCost - runningCost;
                wait = 0;
            }
            else {
                profit += 4 * boardingCost - runningCost;
                wait -= 4;
            }
            if(maxProfit < profit) {
                maxProfit = profit;
                maxProfitRuntimes = i;
            }
        }

        return maxProfit > 0 ? maxProfitRuntimes + 1 : -1;
    }

int main() {
    vector<int> vec = {10, 9, 6};
    int x = 42;
    int ans = minOperationsMaxProfit(vec, 6, 4);
    
    return 0;
}

