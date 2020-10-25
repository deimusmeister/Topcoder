// https://leetcode.com/problems/minimum-absolute-difference-in-bst/
// 
// Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
// 
// Example:
// 
// Input:
// 
//    1
//     \
//      3
//     /
//    2
// 
// Output:
// 1
// 
// Explanation:
// The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
//  
// 
// Note:
// 
// There are at least two nodes in this BST.
// This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

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
    int getMinimumDifference(TreeNode* root) {
        visit(root);
        int min = std::numeric_limits<int>::max();
        for(int i = 1; i < list.size(); ++i) {
            min = std::min(min, std::abs(list[i] - list[i - 1]));
        }
        return min;
    }
    void visit(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        visit(root->left);
        list.push_back(root->val);
        visit(root->right);
    }
    
private:
    std::vector<int> list;
};
