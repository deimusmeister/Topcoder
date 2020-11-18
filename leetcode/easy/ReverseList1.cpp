// https://leetcode.com/problems/reverse-linked-list/
// 
// Reverse a singly linked list.
// 
// Example:
// 
// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL
// Follow up:
// 
// A linked list can be reversed either iteratively or recursively. Could you implement both?

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
    ListNode* reverseList(ListNode* head) {
        std::stack<ListNode*, std::vector<ListNode*>> st;
        while(head != nullptr) {
            st.push(head);
            head = head->next;
        }
        head = st.top();
        while(!st.empty()) {
            auto top = st.top();
            st.pop();
            if(st.empty()) {
                top->next = nullptr;
            } else {
                top->next = st.top();    
            }
        }
        return head;
    }
};
