#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

bool carPooling(vector<vector<int>>& trips, int capacity) {
    int n[1001] = {0};
    for(int i = 0; i < trips.size(); ++i) {
        for(int j = trips[i][1]; j <= trips[i][2]; ++j) {
            n[j] += trips[i][0];
            if(n[j] > capacity) return false;
        }
    }

    return true;
}

int main() {
    vector<vector<int>> vec = {{2,1,5},{3,3,7}};
    int ans = carPooling(vec, 5);
    
    return 0;
}