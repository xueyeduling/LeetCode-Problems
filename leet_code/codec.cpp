#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*TreeNode* deserializeByIndex(vector<int>& nums, int& index) {
    if(nums[index] == -1) return nullptr;
    TreeNode* node = new TreeNode(nums[index]);
    node->left = deserializeByIndex(nums, ++index);
    node->right = deserializeByIndex(nums, ++index);
    return node;
}

string serialize(TreeNode* root) {
    return root == nullptr ? "n" : to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data.length() == 0) return nullptr;
    data += ",";
    int index = 0;
    TreeNode* tree;
    vector<int> nodenums;

    for(int i = 0, j = 0; i < data.length(); i++) {
        if(data[i] == ',') {
            string s = data.substr(j, i - j);
            nodenums.push_back(s == "n" ? -1 : stoi(s));
            j = i + 1;
            i++;
        }
    }

    return deserializeByIndex(nodenums, index);
}
*/
// Encodes a tree to a single string.

string serialize(TreeNode* root) {
    if(root == nullptr)
        return "#";

    return to_string(root->val) + ' ' + serialize(root->left) + ' ' + serialize(root->right);
}

// Decodes your encoded data to tree.
TreeNode* rebuildTree(stringstream &ss){
    string tmp;
    ss >> tmp;
    
    if(tmp == "#")
        return nullptr;

    TreeNode* node = new TreeNode(stoi(tmp));
    node->left = rebuildTree(ss);
    node->right = rebuildTree(ss);

    return node;
}

TreeNode* deserialize(string data) {
    stringstream ss(data);
    return rebuildTree(ss);
}

int main() {
    TreeNode node1 = TreeNode(1);
    TreeNode node2 = TreeNode(2);
    TreeNode node3 = TreeNode(3);
    node1.left = nullptr;
    node1.right = &node2;

    string str = serialize(&node1);
    TreeNode* tree = deserialize(str);

    return 0;
}