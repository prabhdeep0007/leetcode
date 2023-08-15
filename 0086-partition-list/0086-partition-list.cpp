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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
     ListNode*less=new ListNode();
     ListNode*great=new ListNode();
     ListNode*l1=less,*l2=great;
    while(head)
    {
      if(head->val<x)
      {
          l1->next=new ListNode(head->val);
          l1=l1->next;
      }
      else
      {
          l2->next=new ListNode(head->val);
          l2=l2->next;
      }
        head=head->next;
    }
     l1->next=great->next;
     return  less->next;
    }
};