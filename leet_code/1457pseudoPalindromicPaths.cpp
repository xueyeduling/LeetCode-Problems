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
int occurs[10];
int res = 0;
void dfs(TreeNode* root) {
        occurs[root->val] += 1;
        if(root->left != nullptr) dfs(root->left);
        if(root->right != nullptr) dfs(root->right);
        if(root->left == nullptr && root->right == nullptr) {
            int odd = 0;
            for(int i = 1; i < 9; ++i) {
                if(occurs[i] % 2 != 0) odd++;
            }
            if(odd <= 1) res += 1;
        }
        occurs[root->val] -= 1;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return res;
    }

    int main() {
        //[8,6,9,null,null,null,4,4,1,5,4,null,null,null,null,8]
        TreeNode n1 = TreeNode(8);
        TreeNode n2 = TreeNode(6);
        TreeNode n3 = TreeNode(9);
        TreeNode n4 = TreeNode(4);
        TreeNode n5 = TreeNode(4);
        TreeNode n6 = TreeNode(1);
        TreeNode n7 = TreeNode(5);
        TreeNode n8 = TreeNode(4);
        TreeNode n9 = TreeNode(8);

        n1.left = &n2;
        n1.right = &n3;
        n3.right = &n4;
        n4.left = &n5;
        n4.right = &n6;
        n5.left = &n7;
        n5.right = &n8;
        n8.left = &n9;
        pseudoPalindromicPaths(&n1);
        return 0;
    }