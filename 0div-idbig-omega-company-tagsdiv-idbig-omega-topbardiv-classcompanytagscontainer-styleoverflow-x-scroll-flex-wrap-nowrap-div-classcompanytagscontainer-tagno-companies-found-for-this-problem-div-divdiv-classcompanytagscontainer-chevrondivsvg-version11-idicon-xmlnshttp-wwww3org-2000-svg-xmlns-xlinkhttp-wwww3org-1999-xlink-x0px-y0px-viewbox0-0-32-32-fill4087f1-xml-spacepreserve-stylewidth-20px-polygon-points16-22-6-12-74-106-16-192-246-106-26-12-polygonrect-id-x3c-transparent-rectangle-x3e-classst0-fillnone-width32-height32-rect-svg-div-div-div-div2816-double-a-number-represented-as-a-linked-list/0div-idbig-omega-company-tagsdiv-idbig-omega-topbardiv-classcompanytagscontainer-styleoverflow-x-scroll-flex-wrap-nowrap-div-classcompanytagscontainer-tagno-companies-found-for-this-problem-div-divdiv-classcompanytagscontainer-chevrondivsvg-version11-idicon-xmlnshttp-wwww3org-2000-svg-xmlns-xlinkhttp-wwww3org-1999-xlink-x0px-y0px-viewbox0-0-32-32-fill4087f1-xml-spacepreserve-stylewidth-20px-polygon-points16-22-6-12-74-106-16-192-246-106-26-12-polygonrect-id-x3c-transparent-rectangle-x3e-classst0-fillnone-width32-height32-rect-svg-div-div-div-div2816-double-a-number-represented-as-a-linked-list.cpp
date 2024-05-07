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
    ListNode* reversell(ListNode* h)
    {
        ListNode* prev=NULL;
        while(h)
        {
            ListNode* nxt=h->next;
            h->next=prev;
            prev=h;
            h=nxt;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        head=reversell(head);
        ListNode* t=head,*prev;
        int c=0;
        while(t)
        {
            int v=t->val*2+c;
            t->val=v%10;
            c=v/10;
            prev=t;
            t=t->next;
        }
        if(c) prev->next=new ListNode(c);
        return reversell(head);
    }
};