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
    
int maxDeep = 0;
int leftIndex = 0;
int rightIndex = 0;

void dfs(TreeNode* root, int index) {
    if(root->left != nullptr) dfs(root->left, index * 2 + 1);
    if(root->right != nullptr) dfs(root->right, index * 2 + 2);
    if(root->left == nullptr && root->right == nullptr) {
        int deep = floor(log2(index + 1));
        if(deep < maxDeep) return;
        if(deep > maxDeep) leftIndex = index;
        maxDeep = deep;
        rightIndex = index; 
    }
}

TreeNode* getTree(TreeNode* root, int curIndex, int index) {
    if(root == nullptr) return nullptr;
    int lIndex = curIndex * 2 + 1;
    int rIndex = curIndex * 2 + 2;
    if(index == lIndex) return root->left;
    if(index == rIndex) return root->right;
    TreeNode* tree = getTree(root->left, lIndex, index);
    if(tree != nullptr) return tree;
    return getTree(root->right, rIndex, index);
}

TreeNode* lcaDeepestLeaves(TreeNode* root) {
    dfs(root, 0);
    if(leftIndex >= rightIndex) return leftIndex == 0 ? root : getTree(root, 0, leftIndex);
    while(leftIndex != rightIndex) {
        leftIndex = (leftIndex - 1) / 2;
        rightIndex = (rightIndex - 1) / 2;
    }
    return leftIndex == 0 ? root : getTree(root, 0, leftIndex);
}
pair<int, TreeNode *> dfs(TreeNode *cur) {  
        if (!cur)  
            return make_pair(0, nullptr);  
        auto [dep_l, res_l] = dfs(cur->left);  
        auto [dep_r, res_r] = dfs(cur->right);  
        if (dep_l == dep_r)  
            return make_pair(dep_l + 1, cur);  
        else if (dep_l < dep_r)  
            return make_pair(dep_r + 1, res_r);  
        else  
            return make_pair(dep_l + 1, res_l);  
    }  
  
TreeNode *subtreeWithAllDeepest(TreeNode *root) {  
    return dfs(root).second;  
} 
int main() {
    //[3,5,1,6,2,0,8,null,null,7,4]
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(5);
    TreeNode* node3 = new TreeNode(1);
    TreeNode* node4 = new TreeNode(6);
    TreeNode* node5 = new TreeNode(2);
    TreeNode* node6 = new TreeNode(0);
    TreeNode* node7 = new TreeNode(8);
    TreeNode* node8 = new TreeNode(7);
    TreeNode* node9 = new TreeNode(4);

    TreeNode* node10 = new TreeNode(10);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node5->left = node8;
    node5->right = node9;

    TreeNode* tree = subtreeWithAllDeepest(node1);
    return 0;
}