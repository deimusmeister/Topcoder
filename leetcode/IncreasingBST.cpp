// https://leetcode.com/problems/increasing-order-search-tree/
// 
// Given a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.
// 
// Example 1:
// Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]
// 
//        5
//       / \
//     3    6
//    / \    \
//   2   4    8
//  /        / \ 
// 1        7   9
// 
// Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
// 
//  1
//   \
//    2
//     \
//      3
//       \
//        4
//         \
//          5
//           \
//            6
//             \
//              7
//               \
//                8
//                 \
//                  9  
//  
// 
// Constraints:
// 
// The number of nodes in the given tree will be between 1 and 100.
// Each node will have a unique integer value from 0 to 1000.


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
    std::queue<TreeNode*> queue;
public:
    TreeNode* increasingBST(TreeNode* root) {
        visit(root);
        auto top = queue.front();
        auto first = top;
        queue.pop();
        while(!queue.empty()) {
            top->left = nullptr;
            top->right = queue.front();
            top = queue.front();
            queue.pop();
        }
        return first;
    }
    
    void visit(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        auto left = root->left;
        auto right = root->right;
        if(left != nullptr) {
            visit(left);
        }
        this->queue.push(root);
        if(right != nullptr) {
            visit(right);
        }
    }
};
