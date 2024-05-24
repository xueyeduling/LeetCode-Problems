#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;

    ListNode* next;

    ListNode(int x): val(x), next(nullptr) {}
};

void printList(ListNode* node){
    while(node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}

ListNode* sortList(ListNode* node, int len) {
    if(len == 1) return node;
    ListNode* head = new ListNode(0);
    ListNode* cur = head;
    ListNode* left = node;
    ListNode* right = node;
    for(int i = 0; i < (len / 2) - 1; right = right->next, ++i) {}

    ListNode* tmp = right->next;
    right->next = nullptr;
    right = tmp;

    int leftLen = len / 2;
    int rightLen = len - len / 2;
    ListNode* sortedLeft = sortList(left, leftLen);
    ListNode* sortedRight = sortList(right, rightLen);

    int i = 0, j = 0;
    for(; i < leftLen && j < rightLen;) {
        if(sortedLeft->val <= sortedRight->val) {
            cur->next = sortedLeft;
            cur = cur->next;
            sortedLeft = sortedLeft->next;
            ++i;
        }
        else {
            cur->next = sortedRight;
            cur = cur->next;
            sortedRight = sortedRight->next;
            ++j;
        }
    }
    if(i < leftLen) cur->next = sortedLeft;
    else cur->next = sortedRight;

    return head->next;
}

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(3);
    ListNode* n3 = new ListNode(5);
    ListNode* n4 = new ListNode(6);
    ListNode* n5 = new ListNode(4);
    ListNode* n6 = new ListNode(2);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    printList(n1);

    int len = 0;
    ListNode* tmp = n1;
    for(; tmp != nullptr; len++, tmp = tmp->next) {}
    ListNode* sortedList = sortList(n1, len);

    printList(n1);
}