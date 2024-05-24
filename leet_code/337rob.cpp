#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

int rob(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr) return root->val;
        queue<TreeNode*> que;
        vector<int> mv;
        vector<int> ans(2, 0);
        que.push(root);

        while(!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            if(node == nullptr) {
                mv.push_back(0);
                continue;
            }
            mv.push_back(node->val);
            que.push(node->left);
            que.push(node->right);
        }

        for(int i = 0; pow(2, i) - 1 <= mv.size(); ++i) {
            int m = 0;
            int rb = pow(2, i + 1) - 1 < mv.size() ? pow(2, i + 1) - 1 : mv.size();
            for(int j = pow(2, i) - 1; j < rb; ++j) m += mv[j];
            if(i % 2 == 0) ans[0] += m;
            else ans[1] += m;
        }

        return max(ans[0], ans[1]);
    }

int main() {
    TreeNode* node1 = new TreeNode(4);
    TreeNode* node2 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(2);
    TreeNode* node4 = new TreeNode(3);

    node1->left = node2;
    node2->left = node3;
    node3->left = node4;

    int ans = rob(node1);

    return 0;
}