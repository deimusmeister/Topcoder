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
        if(head == nullptr) {
            return nullptr;
        }
        auto parent = head;
        auto child = parent->next;
        parent->next = nullptr;
        if(child == nullptr) {
            child = parent;
        } else {
            while(child != nullptr) {
                auto tmp = child->next;
                child->next = parent;
                parent = child;
                if(tmp == nullptr) {
                    break;
                } else {
                    child = tmp;                
                }
            }   
        }
        return child;
    }
    
    // ListNode* reverseList(ListNode* head) {
    //     std::stack<ListNode*, std::vector<ListNode*>> st;
    //     while(head != nullptr) {
    //         st.push(head);
    //         head = head->next;
    //     }
    //     if(st.empty()) {
    //         head = nullptr;
    //     } else {
    //         head = st.top();            
    //     }
    //     while(!st.empty()) {
    //         auto top = st.top();
    //         st.pop();
    //         if(st.empty()) {
    //             top->next = nullptr;
    //             break;
    //         } else {
    //             top->next = st.top();    
    //         }
    //     }
    //     return head;
    // }
};
