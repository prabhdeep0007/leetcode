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
    int findsize(ListNode* head)
    {
        int cnt=0;
        while(head)
        {
         head=head->next;
         cnt++;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=findsize(head);
        size=size-n;
        if(size==0) return head->next;
        ListNode* temp=head;
        while(size>1)
        {
            temp=temp->next;
            size--;
        }
        temp->next=temp->next->next;
        return head;
        
    }
};