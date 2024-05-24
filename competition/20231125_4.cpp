#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int minimumCoins(vector<int>& prices) {
    vector<int> vec;
    vec.push(prices[0]);
    vec.push(prices[1]);
    for(int i = 2; i < prices.size(); ++i) {
        vec.push(vec[i - 1] + *min_element(i/2, i));
    }
    
    return vec.back();
}

int main() {
    vector<int> vec = {26,18,6,12,49,7,45,45};

    int ans =  minimumCoins(vec);
    
    return 0;
}