#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <numeric>
using namespace std;

int candy(vector<int>& ratings) {
        int min = *min_element(ratings.begin(), ratings.end());
        int n = ratings.size();
        vector<int> candies(n, 0);
        unordered_map<int, vector<int>> ratingsMap;
        for(int i = 0; i < ratings.size(); ++i) {
            ratingsMap[ratings[i]].push_back(i);
            if(ratings[i] != min) continue;
            candies[i] = 1;
            n--;
        }

        vector<int> ratingsVec;
        for(auto r : ratingsMap) {
            ratingsVec.push_back(r.first);
        }

        sort(ratingsVec.begin(), ratingsVec.end());
        for(int j = 1; j < ratingsVec.size(); ++j) {
            for(auto i : ratingsMap[ratingsVec[j]]) {
                int c = 1;
                if(i - 1 >= 0 && candies[i - 1] != 0) {
                    if(ratings[i] > ratings[i - 1]) c = candies[i - 1] + 1;
                }
                if(i + 1 < ratings.size() && candies[i + 1] != 0) {
                    if(ratings[i] > ratings[i + 1]) c = max(c, candies[i + 1] + 1);
                    else c = max(c, 1);
                }
                candies[i] = c;
                n--;
            }
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }

    int main() {
        vector<int> v = {1,3,2,2,1};
        int res = candy(v);

        return 0;
    }