https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// 
// Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.
// 
//  
// 
// Example 1:
// 
// 
// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true
// Example 2:
// 
// 
// Input: root = [5,3,6,2,4,null,7], k = 28
// Output: false
// Example 3:
// 
// Input: root = [2,1,3], k = 4
// Output: true
// Example 4:
// 
// Input: root = [2,1,3], k = 1
// Output: false
// Example 5:
// 
// Input: root = [2,1,3], k = 3
// Output: true


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
   bool findTarget(TreeNode* root, int k) {
       if(root == nullptr) {
           return false;
       }
       auto val = root->val;
       if(mp.find(k - val) != mp.end()) {
           return true;
       } else if(mp.find(val) == mp.end()) {
           mp[val] = 1;
       } else {
           mp[val]++;
       }
       return findTarget(root->right, k) || findTarget(root->left, k);
   }
private:
   std::unordered_map<int, int> mp;
};
