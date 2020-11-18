// https://leetcode.com/problems/balanced-binary-tree/
// 
// Given a binary tree, determine if it is height-balanced.
// 
// For this problem, a height-balanced binary tree is defined as:
// 
// a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
// 
//  
// 
// Example 1:
// 
// 
// Input: root = [3,9,20,null,null,15,7]
// Output: true
// Example 2:
// 
// 
// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false
// Example 3:
// 
// Input: root = []
// Output: true
//  
// 
// Constraints:
// 
// The number of nodes in the tree is in the range [0, 5000].
// -104 <= Node.val <= 104

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
    bool isBalanced(TreeNode* root) {
        visit(root, 0);
        return balanced;
    }
    int visit(TreeNode* root, int level) {
        if(!balanced) {
            return 0;
        }
        if(root == nullptr) {
            return 0;
        }
        int left = 1 + visit(root->left, level + 1);
        int right = 1 + visit(root->right, level + 1);
        if(std::abs(left - right) > 1) {
            balanced = false;
            return 0;
        } else {
            return std::max(left, right);
        }
    }
private:
    bool balanced{true};
};
