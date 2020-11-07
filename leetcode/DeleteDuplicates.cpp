// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// 
// Given a sorted linked list, delete all duplicates such that each element appear only once.
// 
// Example 1:
// 
// Input: 1->1->2
// Output: 1->2
// Example 2:
// 
// Input: 1->1->2->3->3
// Output: 1->2->3

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* root = head;
        while(head != nullptr) {
            auto val = head->val;
            auto child = head->next;
            while(child != nullptr && val == child->val) {
                child = child->next;
            }
            head->next = child;
            head = head->next;
        }
        return root;
    }
};
