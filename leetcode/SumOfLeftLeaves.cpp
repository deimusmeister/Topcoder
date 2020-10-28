// https://leetcode.com/problems/sum-of-left-leaves/
// 
// Find the sum of all left leaves in a given binary tree.
// 
// Example:
// 
//     3
//    / \
//   9  20
//     /  \
//    15   7
// 
// There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

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
    int sumOfLeftLeaves(TreeNode* root) {
        visit(root, false);
        return sum;
    }
    void visit(TreeNode* root, bool left) {
        if(root == nullptr) {
            return;
        }
        if(left && root->left == nullptr && root->right == nullptr) {
            sum += root->val;
        }
        visit(root->left, true);
        visit(root->right, false);
    }
private:
    int sum{0};
};
