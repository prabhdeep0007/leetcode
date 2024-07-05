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
    vector<int> findcriticalpoints(ListNode* head){
        ListNode* prev=head,*curr=head->next;
        vector<int> ans;
        int i=1;
        while(curr->next)
        {
            if(prev->val>curr->val && curr->val<curr->next->val)ans.push_back(i);
            else if(prev->val<curr->val && curr->val>curr->next->val)ans.push_back(i);
            i++;
            prev=curr;
            curr=curr->next;
        }
        return ans;
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v=findcriticalpoints(head);
        if(v.size()<2) return {-1,-1};
        int mini=INT_MAX;
        for(int i=0;i<v.size()-1;i++)
        {
           mini=min(mini,v[i+1]-v[i]); 
        }
        return {mini,v[v.size()-1]-v[0]};
    }
};