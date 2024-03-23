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
    ListNode* reverse(ListNode* head)
    {
      ListNode* prev=NULL,*next;
      while(head)
      {
          next=head->next;
          head->next=prev;
          prev=head;
          head=next;
      }
    return prev;
        
    }
    void reorderList(ListNode* head) {
        ListNode*slow=head,*fast=head;
        while(fast->next&&fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
         ListNode*next,*snext,*temp=head;
        snext=slow->next;
        slow->next=NULL;
        slow=snext;   
        while(temp&&slow)
        {
            snext=slow->next;
            next=temp->next;
            temp->next=slow;
            slow->next=next;
            temp=next;
            slow=snext; 
        }
            
    }
};