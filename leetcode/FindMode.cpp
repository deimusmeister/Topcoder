// https://leetcode.com/problems/find-mode-in-binary-search-tree/
// 
// Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.
// 
// Assume a BST is defined as follows:
// 
// The left subtree of a node contains only nodes with keys less than or equal to the node's key.
// The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
// Both the left and right subtrees must also be binary search trees.
//  
// 
// For example:
// Given BST [1,null,2,2],
// 
//    1
//     \
//      2
//     /
//    2
//  
// 
// return [2].
// 
// Note: If a tree has more than one mode, you can return them in any order.
// 
// Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

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
    vector<int> findMode(TreeNode* root) {
        visit(root);
        int max = std::numeric_limits<int>::min();
        std::vector<int> result;
        for(auto i : mp) {
            if(i.second > max) {
                max = i.second;
                result.clear();
            }
            if(i.second == max) {
                result.push_back(i.first);
            }
        }
        return result;
    }
    
    void visit(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        mp[root->val]++;
        visit(root->left);
        visit(root->right);
    }
private:
    std::unordered_map<int, int> mp;
};
