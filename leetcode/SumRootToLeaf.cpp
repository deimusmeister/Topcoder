// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
//
// Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
// 
// For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.
// 
// Return the sum of these numbers.
// 
//  
// 
// Example 1:
// 
// 
// 
// Input: [1,0,1,0,1,0,1]
// Output: 22
// Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
//  
// 
// Note:
// 
// The number of nodes in the tree is between 1 and 1000.
// node.val is 0 or 1.
// The answer will not exceed 2^31 - 1.

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
private:
    int sum{0};
public:
    int sumRootToLeaf(TreeNode* root) {
        visit(root, 0);
        return sum;
    }
    void visit(TreeNode* root, int digit) {
        digit = (digit << 1) | root->val;
        
        auto left = root->left;
        auto right = root->right;
        
        if(left == nullptr && right == nullptr) {
            sum += digit;
        }
        if(left) {
            visit(left, digit);   
        }
        if(right) {
            visit(right, digit);    
        }
    }
};
