// https://leetcode.com/problems/binary-tree-paths/
// 
// Given a binary tree, return all root-to-leaf paths.
// 
// Note: A leaf is a node with no children.
// 
// Example:
// 
// Input:
// 
//    1
//  /   \
// 2     3
//  \
//   5
// 
// Output: ["1->2->5", "1->3"]
// 
// Explanation: All root-to-leaf paths are: 1->2->5, 1->3


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr) {
            return result;
        }
        std::string val = std::to_string(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            result.push_back(val);
        } else {
            visit(root->left, val);
            visit(root->right, val);  
        }
        return result;
    }
    void visit(TreeNode* root, std::string str) {
        if(root == nullptr) {
            return;
        }
        str += "->" + std::to_string(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            result.push_back(str);
        } else {
            visit(root->left, str);
            visit(root->right, str);   
        }
    }
private:
    std::vector<std::string> result;
};
