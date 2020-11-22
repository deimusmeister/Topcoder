// https://leetcode.com/problems/maximum-binary-tree/
// 
// Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
// 
// The root is the maximum number in the array.
// The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
// The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
// Construct the maximum tree by the given array and output the root node of this tree.
// 
// Example 1:
// Input: [3,2,1,6,0,5]
// Output: return the tree root node representing the following tree:
// 
//       6
//     /   \
//    3     5
//     \    / 
//      2  0   
//        \
//         1
// Note:
// The size of the given array will be in the range [1,1000].

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        TreeNode* root = nullptr;
        visit(nums, root, 0, n);
        return root;
    }
    void visit(vector<int>& nums, TreeNode*& root, int start, int end) {
        if(start >= end) {
            return;
        };
        int max = nums[start];
        int maxIndex = start;
        for(int i = start; i < end; ++i) {
            if(nums[i] > max) {
                maxIndex = i;
                max = nums[i];
            }
        }
        root = new TreeNode;
        root->val = max;
        visit(nums, root->left, start, maxIndex);
        visit(nums, root->right, maxIndex + 1, end);
    }
};
