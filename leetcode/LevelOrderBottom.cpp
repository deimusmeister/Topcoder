// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
// 
// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
// 
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]


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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        visit(root, 0);
        std::vector<std::vector<int>> result;
        for(auto i = mp.rbegin(); i != mp.rend(); ++i) {
            auto vec = i->second;
            result.push_back(vec);
        }
        return result;
    }
    void visit(TreeNode* root, int level){
        if(root == nullptr) {
            return;
        }
        mp[level].push_back(root->val);
        visit(root->left, level + 1);
        visit(root->right, level + 1);
    }
private:
    std::map<int, std::vector<int>> mp;
};
