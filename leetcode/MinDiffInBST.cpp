// https://leetcode.com/problems/minimum-distance-between-bst-nodes/
// 
// Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.
// 
// Example :
// 
// Input: root = [4,2,6,1,3,null,null]
// Output: 1
// Explanation:
// Note that root is a TreeNode object, not an array.
// 
// The given tree [4,2,6,1,3,null,null] is represented by the following diagram:
// 
//           4
//         /   \
//       2      6
//      / \    
//     1   3  
// 
// while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
// Note:
// 
// The size of the BST will be between 2 and 100.
// The BST is always valid, each node's value is an integer, and each node's value is different.
// This question is the same as 530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/

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
    int minDiffInBST(TreeNode* root) {
        int result = std::numeric_limits<int>::max();
        visit(root);
        for(int i = 1; i < list.size(); ++i) {
            result = std::min(result, std::abs(list[i] - list[i - 1]));
        }
        return result;
    }
    void visit(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        visit(root->left);
        list.push_back(root->val);
        // std::cout << "val: " << root->val << std::endl;
        visit(root->right);
    }
private:
    std::vector<int> list;
};
