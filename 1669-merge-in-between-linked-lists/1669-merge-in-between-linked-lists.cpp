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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode*tail2=list2;
        while(tail2->next)
        {
            tail2=tail2->next;
        }
        ListNode*preva=list1,*nextb;
        for(int i=0;i<a-1;i++)
        {
            preva=preva->next;
        }
        nextb=preva;
        for(int i=0;i<(b-a+2);i++)
        {
            nextb=nextb->next;
        }
        preva->next=list2;
        tail2->next=nextb;
        return list1;
    }
};