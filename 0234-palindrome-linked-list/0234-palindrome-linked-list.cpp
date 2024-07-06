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
        ListNode*prev=NULL;
        while(head)
        {
            ListNode*nxt=head->next;
            head->next=prev;
            prev=head;
            head=nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head,*fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* revnode=reversell(slow);
        while(head&&revnode)
        {
            if(head->val!=revnode->val)
            {
                return false;
            }
            head=head->next;
            revnode=revnode->next;
        }
        return true;
    }
};