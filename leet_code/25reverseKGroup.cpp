#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    vector<ListNode*> ListNodeVec;

    while(head != nullptr) {
        ListNodeVec.push_back(head);
        head = head->next;
    }

    int round = ListNodeVec.size() / k;

    for(int i = 1; i <= round; ++i) {
        for(int j = i * k - 1; j > (i - 1) * k; --j)
            ListNodeVec[j]->next = ListNodeVec[j - 1];
            
        if((i + 1) * k - 1 < ListNodeVec.size()) 
            ListNodeVec[(i - 1) * k]->next = ListNodeVec[(i + 1) * k - 1];
        else if(i * k < ListNodeVec.size())
            ListNodeVec[(i - 1) * k]->next = ListNodeVec[i * k];
        else
            ListNodeVec[(i - 1) * k]->next = nullptr;
    }

    return ListNodeVec[k - 1];
}

int f11(int x) {
    int countx = 0;
    while(x) {
        countx++;
        x = x&(x-1);
    }
    return countx;
}


int main() {
    int x = f11(1023);

    x= x+1;

    return 0;
}