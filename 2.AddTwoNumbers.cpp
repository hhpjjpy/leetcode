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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1,*p2 = l2;
        ListNode *head=NULL,*p_ret = NULL ;
        int flag = 0;
        while(p1 != NULL || p2 != NULL){
            int sum = (p1!=NULL?p1->val:0) + (p2!=NULL?p2->val:0) + flag;
            flag = sum /10;
            if(head == NULL){
                 head = new ListNode(sum%10);
                 p_ret = head;
            }else{
                p_ret->next = new ListNode(sum%10);
                p_ret = p_ret->next;
            }
            p1 = p1!=NULL?p1->next:NULL;
            p2 = p2!=NULL?p2->next:NULL;
        }
        
        if(flag != 0){
             p_ret->next = new ListNode(flag);
             p_ret = p_ret->next; 
        }
        return head;
    }
};
