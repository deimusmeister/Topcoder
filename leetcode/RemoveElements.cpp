// https://leetcode.com/problems/remove-linked-list-elements/
// 
// Remove all elements from a linked list of integers that have value val.
// 
// Example:
// 
// Input:  1->2->6->3->4->5->6, val = 6
// Output: 1->2->3->4->5

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newHead = nullptr;
        ListNode* parent = nullptr;
        while(head != nullptr) {
            if(head->val != val && newHead == nullptr) {
                newHead = head;
            }
            if(head->val != val) {
                if(parent != nullptr) {
                    parent->next = head;
                }
                parent = head;
            }
            head = head->next;
        }
        if(parent != nullptr) {
            parent->next = nullptr;   
        }
        return newHead;
    }
};
