// https://leetcode.com/problems/symmetric-tree/
// 
// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
// 
// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
// 
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
//  
// 
// But the following [1,2,2,null,3,null,3] is not:
// 
//     1
//    / \
//   2   2
//    \   \
//    3    3
//  
// 
// Follow up: Solve it both recursively and iteratively.

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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }
        if(root->left == nullptr && root->right == nullptr) {
            return true;
        }
        bool result = true;
        q.push_back(root);
        while(!q.empty()) {
            int val = std::numeric_limits<int>::min();
            if(!st.empty()) {
                val = st.top();   
            }
            TreeNode* f = q.front();
            if(f->left == nullptr && f->right == nullptr) {
                if(val == std::numeric_limits<int>::max()) {
                    st.pop();
                } else {
                    st.push(std::numeric_limits<int>::max());
                }
            } else {
                if(f->left != nullptr) {
                    q.push_back(f->left);
                    if(val == f->left->val) {
                        st.pop();
                    } else {
                        st.push(f->left->val);
                    }
                } else {
                    if(val == std::numeric_limits<int>::max()) {
                        st.pop();
                    } else {
                        st.push(std::numeric_limits<int>::max());
                    }
                }
                if(!st.empty()) {
                    val = st.top();   
                } else {
                    val = std::numeric_limits<int>::min();
                }
                if(f->right != nullptr) {
                    q.push_back(f->right);
                    if(val == f->right->val) {
                        st.pop();
                    } else {
                        st.push(f->right->val);
                    }
                } else {
                    if(val == std::numeric_limits<int>::max()) {
                        st.pop();
                    } else {
                        st.push(std::numeric_limits<int>::max());
                    }
                }   
            }
            q.pop_front();
        }
        result = (st.size() == 0);
        return result;
    }
private:
    std::deque<TreeNode*> q;
    std::stack<int> st;
};
