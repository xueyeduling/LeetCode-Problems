#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
    for(auto& oper : operations) {
        gem[oper[1]] += gem[oper[0]] / 2;
        gem[oper[0]] -= gem[oper[0]] / 2;
    }

    sort(gem.begin(), gem.end());

    return gem.back() - gem.front();
}

int main() {
    vector<int> gem = {3,1,2};
    vector<vector<int>> operations = {{0,2},{2,1},{2,0}};

    int ans = giveGem(gem, operations);

    return ans;
}