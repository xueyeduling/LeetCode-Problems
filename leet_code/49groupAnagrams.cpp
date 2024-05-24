#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<unordered_map<char, int>> chatMapVec;
        vector<unordered_set<int>> indexSetVec;

        for(int i = 0; i < strs.size(); ++i) {
            unordered_map<char, int> chatMap;
            for(auto& c : strs[i]) chatMap[c]++;

            auto findIter = find(chatMapVec.begin(), chatMapVec.end(), chatMap);
            if(findIter == chatMapVec.end()){
                chatMapVec.push_back(chatMap);
                indexSetVec.push_back({i});
            }
            else indexSetVec[findIter - chatMapVec.begin()].insert(i);
        }
        
        vector<vector<string>> ans(chatMapVec.size(), vector<string>());
        for(int i = 0; i < indexSetVec.size(); ++i) {
            for(auto& index : indexSetVec[i])
                ans[i].push_back(strs[index]);
        }

        return ans;
    }

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    groupAnagrams(strs);

    return 0;
}