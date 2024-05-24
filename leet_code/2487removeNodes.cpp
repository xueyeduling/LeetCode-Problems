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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNodes(ListNode* head) {
        int maxval = 0;
        vector<int> vec;
        vector<int> vec2;
        ListNode* node = head;

        while(node != nullptr) {
            vec.push_back(node->val);
            node = node->next;
        }

        for(int i = vec.size() - 1; i >= 0; --i) {
            if(vec[i] < maxval) continue;
            maxval = max(vec[i], maxval);
            vec2.push_back(vec[i]);
        }

        ListNode* prenode = new ListNode();
        node = head;
        prenode->next = node;
        ListNode* newhead = prenode;
        for(int i = vec2.size() - 1; i >= 0; --i) {
            while(node->val < vec2[i]) {
                node = node->next;
                prenode->next = node;
            }
            prenode = node;
            node = node->next;
        }

        return newhead->next;
    }

int main() {
    ListNode* n1 = new ListNode(5);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(13);
    ListNode* n4 = new ListNode(3);
    ListNode* n5 = new ListNode(8);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    ListNode* ans = removeNodes(n1);
    
    return 0;
}
