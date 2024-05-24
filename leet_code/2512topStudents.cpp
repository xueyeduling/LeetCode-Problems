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

vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
    vector<vector<int>> si;
    vector<int> result;
    unordered_map <string, int> wordScordMap;

    for(auto& s : positive_feedback) wordScordMap[s] = 3;
    for(auto& s : negative_feedback) wordScordMap[s] = -1;

    for(int i = 0; i < report.size(); ++i) {
        int score = 0;
        stringstream ss(report[i]);
        string word;
        while(ss >> word) if(wordScordMap.count(word) != 0) score += wordScordMap[word];
        si.push_back({-score, student_id[i]});
    }
    
    sort(si.begin(), si.end());

    for(int i = 0; i < k; ++i) result.push_back(si[i][1]);

    return result;
}

int main() {
    vector<string> positive_feedback = {"smart","brilliant","studious"};
    vector<string> negative_feedback = {"not"};
    vector<string> reports = {"this student is not studious","the student is smart"};
    vector<int> ids = {1, 2};
    int k = 2;

    topStudents(positive_feedback, negative_feedback, reports, ids, k);

    return 0;
}