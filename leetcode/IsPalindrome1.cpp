// https://leetcode.com/problems/palindrome-linked-list/
// 
// Given a singly linked list, determine if it is a palindrome.
// 
// Example 1:
// 
// Input: 1->2
// Output: false
// Example 2:
// 
// Input: 1->2->2->1
// Output: true
// Follow up:
// Could you do it in O(n) time and O(1) space?

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
    bool isPalindrome(ListNode* head) {
        bool result = true;
        int n = 0;
        auto h = head;
        while(h != nullptr) {
            ++n;
            h = h->next;
        }
        if(n == 1) {
            return true;
        }
        
        h = head;
        int count = 0;
        ListNode* parent = nullptr;
        while(count < n / 2 && h != nullptr) {
            auto t = h;
            h = h->next;
            t->next = parent;
            parent = t;
            ++count;
        }
        if(n % 2 != 0) {
            h = h->next;
        }
        while(h != nullptr && parent != nullptr) {
            if(h->val != parent->val) {
                return false;
            }
            parent = parent->next;
            h = h->next;
        }
        return true;
    }
};
