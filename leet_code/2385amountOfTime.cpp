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

int ans;
int res;
int start;
int depth2(TreeNode* rt){
    if (rt == NULL) {
        return 0; // 访问到空节点了，返回0
    }
    int L = depth2(rt->left); // 左儿子为根的子树的深度
    int R = depth2(rt->right); // 右儿子为根的子树的深度
    res = max(res, max(L, R));
    return max(L, R) + 1; // 返回该节点为根的子树的深度
}
int depth(TreeNode* rt){
    if (rt == NULL) {
        return 0; // 访问到空节点了，返回0
    }
    if(rt->val == start) {
        depth2(rt);
        return 1;
    }
    int L = depth(rt->left); // 左儿子为根的子树的深度
    int R = depth(rt->right); // 右儿子为根的子树的深度
    ans = max(ans, L + R + 1); // 计算d_node即L+R+1 并更新ans
    return max(L, R) + 1; // 返回该节点为根的子树的深度
}


int amountOfTime(TreeNode* root, int starts) {
    ans = 1;
    start = starts;
    res = 1;
    depth(root);

    return max(ans - 1, res);
}

int main() {
    TreeNode* n1 = new TreeNode(5);
    TreeNode* n2 = new TreeNode(4);
    TreeNode* n3 = new TreeNode(3);

    n1->left = n2;
    n1->right = n3;

    int res = amountOfTime(n1, 5);

    return 0;
}