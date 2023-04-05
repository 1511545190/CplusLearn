/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * }; 两个链表，个位为头，相加后返回新链表
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode prev; // pre head 
        //to avoid head node missing 
        
        int carry = 0;
        ListNode* cur = &prev;
        
        while(l1||l2){
            int val1,val2;
            if(l1)val1 =l1->val;
            else val1 = 0; 
            
            if(l2)val2 =l2->val;
            else val2 = 0;

            int sum = val1 + val2 + carry;
            carry = sum/10;
            sum %=10;

            cur->next = new ListNode(sum);
            cur = cur->next;
            
            if(l1)l1 = l1 = l1->next;
            if(l2)l2 = l2 = l2->next;
            
        }
       if(carry == 1) 
            cur->next = new ListNode(carry);

        return prev.next;
    }
};
