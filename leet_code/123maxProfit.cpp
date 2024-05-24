#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int maxProfit1(vector<int>& prices, int beg, int end) {
        int profit = 0;
        int min = prices[beg];
        for(int i = beg + 1; i < end; ++i) {
            if(prices[i] - min > profit) profit = prices[i] - min;
            else if(prices[i] < min) min = prices[i];
        }

        return profit;
    }

    int maxProfit(vector<int>& prices) {
        int pro = 0;
        for(int i = 0; i < prices.size(); ++i) {
            int pro1 = maxProfit1(prices, 0, i);
            int pro2 = maxProfit1(prices, i, prices.size());
            if(pro1 + pro2 > pro) pro = pro1 +  pro2;
        }
        return pro;
    }

    int main() {
        //cout << (long long)pow(2, 23) % 13 << endl;

        vector<int> prices = {1,2,3,4,5};
        
        int i = maxProfit(prices);
        

        return 0;
    }