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
    ListNode* reversell(ListNode*head)
    {
     ListNode* prev=NULL;
     while(head)
     {
      ListNode* nxt=head->next;
      head->next=prev;
      prev=head;
      head=nxt;
     }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr=head;
        int t=k-1;
        while(t--&&curr)
        {
            curr=curr->next;
        }
        if(!curr) return head;
        ListNode* nxt=curr->next;
        curr->next=NULL;
        curr=reversell(head);
        head->next=reverseKGroup(nxt,k);
        return curr;
        
    }
};