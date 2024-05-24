#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int trap(vector<int>& height) {
    stack<int> leftIndexs;
    int sum = 0;
    for(int i = 0; i < height.size(); ++i) {
        int left = leftIndexs.empty() ? -1 : leftIndexs.top();
        if(height[i] == 0) continue;
        else if(leftIndexs.empty()) leftIndexs.push(i);
        else if(i - left == 1 && (height[left] >= height[i])) {
            if(height[left] == height[i]) leftIndexs.pop();
            leftIndexs.push(i);
        }
        else if(leftIndexs.size() == 1) {
            sum += (i - left -1) * min(height[i], height[left]);
            if(height[left] <= height[i]) leftIndexs.pop();
            leftIndexs.push(i);
        }
        else {
            int previousHeight = 0;
            while(!leftIndexs.empty()) {
                left = leftIndexs.top();
                if(i - left > 1) sum += (i - left -1) * (min(height[i], height[left]) - previousHeight);
                previousHeight = height[left];
                if(height[left] <= height[i]) leftIndexs.pop();
                if(height[left] >= height[i]) {
                    leftIndexs.push(i);
                    break;
                }
            }
            if(leftIndexs.empty()) leftIndexs.push(i);
        }
    }

    return sum;
}

int main() {
    vector<int> height({0,1,2,0,3,0,1,2,0,0,4,2,1,2,5,0,1,2,0,2});
    int sum = trap(height);

    return sum;
}