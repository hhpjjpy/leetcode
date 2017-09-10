/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverList(ListNode *head){
        if(head==NULL||head->next == NULL)
            return head;
        ListNode *newHead = reverList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *p_left = head;
        int count = 1;
        while(p_left!=NULL&&count<k){
            p_left = p_left->next;
            count++;
        }
        if(p_left==NULL)
            return head;
        
        ListNode *p_right = p_left->next;
        p_left->next = NULL;
        
        ListNode *newHead = reverList(head);
        head->next = reverseKGroup(p_right,k);
        
        return newHead;
    }
};
