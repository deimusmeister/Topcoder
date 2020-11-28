// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
// 
// Given two binary search trees root1 and root2.
// 
// Return a list containing all the integers from both trees sorted in ascending order.
// 
//  
// 
// Example 1:
// 
// 
// Input: root1 = [2,1,4], root2 = [1,0,3]
// Output: [0,1,1,2,3,4]
// Example 2:
// 
// Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
// Output: [-10,0,0,1,2,5,7,10]
// Example 3:
// 
// Input: root1 = [], root2 = [5,1,7,0,2]
// Output: [0,1,2,5,7]
// Example 4:
// 
// Input: root1 = [0,-10,10], root2 = []
// Output: [-10,0,10]
// Example 5:
// 
// 
// Input: root1 = [1,null,8], root2 = [8,1]
// Output: [1,1,8,8]
//  
// 
// Constraints:
// 
// Each tree has at most 5000 nodes.
// Each node's value is between [-10^5, 10^5].

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        std::vector<int> result;
        std::vector<int> v1;
        std::vector<int> v2;
        visit(root1, v1);
        visit(root2, v2);
        int pos1 = 0;
        int pos2 = 0;
        while(pos1 < v1.size() && pos2 < v2.size()) {
            if(v1[pos1] <= v2[pos2]) {
                result.push_back(v1[pos1]);
                ++pos1;
            } else {
                result.push_back(v2[pos2]);
                ++pos2;
            }
        }
        if(pos1 < v1.size()) {
            for(int i = pos1; i < v1.size(); ++i) {
                result.push_back(v1[i]);
            }
        }
        if(pos2 < v2.size()) {
            for(int i = pos2; i < v2.size(); ++i) {
                result.push_back(v2[i]);
            }
        }
        return result;
    }
    void visit(TreeNode* root, std::vector<int>& v) {
        if(root == nullptr) {
            return;
        }
        visit(root->left, v);
        v.push_back(root->val);
        visit(root->right, v);
    }
};
