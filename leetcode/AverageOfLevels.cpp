// https://leetcode.com/problems/average-of-levels-in-binary-tree/
// 
// Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
// Example 1:
// Input:
//     3
//    / \
//   9  20
//     /  \
//    15   7
// Output: [3, 14.5, 11]
// Explanation:
// The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
// Note:
// The range of node's value is in the range of 32-bit signed integer.


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
    vector<double> averageOfLevels(TreeNode* root) {
        visit(root, 1);
        std::vector<double> result; 
        for(auto i : this->map) {
            auto sum = static_cast<double>(i.second.first);
            auto count = static_cast<double>(i.second.second);
            std::cout << "level - " << i.first << " : sum - " << sum << " count - " << count << std::endl;  
            result.push_back(sum / count);
        }
        return result;
    }
    void visit(TreeNode* root, int level) {
        if(root == nullptr) {
            return;
        }
        if(map.find(level) == map.end()) {
            map[level].first = root->val;
            map[level].second = 1;
        } else {
            map[level].first += root->val;
            map[level].second += 1;
        }
        visit(root->left, level + 1);
        visit(root->right, level + 1);
    }
private:
    std::map<int, std::pair<long long, int>> map;
};
