#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <sstream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

long long findMaximumElegance(vector<vector<int>>& items, int k) {
    long long res = 0, temp = 0;
    unordered_set<int> s_types;
    sort(items.begin(), items.end(), [](auto& v1, auto& v2){return v1[0] > v2[0];});

    vector<vector<int>> mulvec;

    for(int i = 0; i < k; ++i) {
        res += items[i][0];
        if(s_types.count(items[i][1]) > 0) mulvec.push_back(items[i]);
        else s_types.insert(items[i][1]);
    }

    res += pow(s_types.size(), 2);
    temp = res;
    int j = k;
    while(mulvec.size() != 0) {
        vector<int> vec = mulvec.back();
        mulvec.pop_back();
        temp -= vec[0];

        for(; j < items.size(); ++j) {
            int type = items[j][1];
            if(s_types.count(type) != 0) continue;
            s_types.insert(items[j][1]);
            temp += items[j][0];
            temp += (s_types.size() * 2 - 1);
            break;
        }
        res = max(res, temp);
        if(j == items.size()) break;
    }

    return res;
}

int main() {
    vector<vector<int>> items = {{9, 3}, {3, 2}, {6, 1}, {5, 1}};
    int k = 3;

    int ans = findMaximumElegance(items, k);

    cout << ans << endl;

    return 1;
}