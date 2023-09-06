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
    int count(ListNode*head)
    {
        int c=0;
        while(head)
        {
            c++;
            head=head->next;
        }
        return c;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int c=count(head);
        vector<ListNode*> ans;
        if(k>=c)
        {
            for(int i=0;i<c;i++)
            {
                ListNode *nxt=head->next;
                head->next=NULL;
                ans.push_back(head);
                head=nxt;
            }
            for(int i=0;i<k-c;i++)
            {
                ans.push_back(NULL);
            }
            return ans;
        }
        int nodesperlist=c/k;
        int extranode=c%k;
        for(int i=0;i<k;i++)
        {
             ans.push_back(head);
            for(int j=0;j<nodesperlist-1;j++)
            {
             head=head->next;
            }
            if(extranode) 
            {
                head=head->next;
                extranode--;
            }
                ListNode *nxt=head->next;
                head->next=NULL;   
                head=nxt;
        }
        return ans;
    }
};