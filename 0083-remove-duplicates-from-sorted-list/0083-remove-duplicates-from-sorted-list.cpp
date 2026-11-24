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
        unordered_set<int> st;
    
        ListNode* curr = head;
        ListNode* prev = NULL;
            
        while(curr != NULL){
            if(st.find(curr->val) != st.end()){
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else{
                st.insert(curr->val);
                prev = curr;
                curr = curr->next;
            }
        }
        
        return head;
    }
};