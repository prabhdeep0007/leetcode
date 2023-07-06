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
   ListNode* reverselinkedlist(ListNode* head)
    {
        ListNode* prev=NULL;
       while(head)
       {
           ListNode*temp=head->next;
           head->next=prev;
           prev=head;
           head=temp;
       }
       return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            {
                    return 1;
            }
     ListNode* fast=head,*slow=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow=reverselinkedlist(slow);
       while(slow)
       {
           if(head->val!=slow->val) return false;
           slow=slow->next;
           head=head->next;
       }
        return true;
    }
};