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
    ListNode* reverseLL(ListNode* head)
    {
        if(head==NULL) return NULL;
        ListNode* prev=NULL;
        while(head)
        {
            ListNode*nxt =head->next;
            head->next=prev;
            prev=head;
            head=nxt;
        }
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int idx=1;
        ListNode* dummy=new ListNode(0,head);
        ListNode *prev=dummy;
        while(idx<left){
            prev=prev->next;
            idx++;
        }
          ListNode* start=prev->next,*end=prev->next;
        while(idx<right){
            end=end->next;
            idx++;
        }
        ListNode *rev_end=NULL;
        if(end->next){
            rev_end=end->next;
        }
        end->next=NULL;
        ListNode *nh=reverseLL(start);
        if(prev)
            prev->next=nh;
        else
            head=nh;
        start->next=rev_end;
        return dummy->next;
    }
};