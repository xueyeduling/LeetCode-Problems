#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxPathVal = INT_MIN;
void dfs(TreeNode* root) {
    if(root == nullptr) return;
    dfs(root->left);
    dfs(root->right);
    if(root->left == nullptr && root->right == nullptr) {
        maxPathVal = max(root->val, maxPathVal);
    }
    else if(root->left != nullptr && root->right == nullptr) {
        root->val = max(root->val, root->val + root->left->val);
        maxPathVal = max(root->val, maxPathVal);
    }
    else if(root->left == nullptr && root->right != nullptr) {
        root->val = max(root->val, root->val + root->right->val);
        maxPathVal = max(root->val, maxPathVal);
    }
    else {
        int addLeft = root->val + root->left->val;
        int addRight = root->val + root->right->val;
        int addAll = root->val + root->left->val + root->right->val;
        int maxVal = max(addLeft, max(addRight, max(root->val, addAll)));
        root->val = maxVal;
        maxPathVal = max(maxVal, maxPathVal);
    }
}

int maxPathSum(TreeNode* root) {
    dfs(root);
    return maxPathVal;
}

int main() {
    // 5,4,8,11,null,13,4,7,2,null,null,null,1
    TreeNode* node1 = new TreeNode(4);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(2);

    
    TreeNode* node2 = new TreeNode(2);

    node1->left = node2;

    int sum = maxPathSum(node1);
    return 0;
}