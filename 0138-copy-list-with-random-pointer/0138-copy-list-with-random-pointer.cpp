/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node*temp=head,*nxt;
        while(temp)
        {
            nxt=temp->next;
            temp->next=new Node(temp->val);
            temp->next->next=nxt;
            temp=nxt;
        }
        temp=head;
        Node*ans=head->next;
        while(temp)
        {
            if(temp->random)temp->next->random=temp->random->next;
            temp=temp->next->next;
        }
        Node*prev=head;
        temp=head->next;
        while(temp->next)
        {
            prev->next=temp->next;
            nxt=temp->next->next;
            prev=temp->next;
            temp->next=nxt;
            temp=nxt;
        }
        prev->next=NULL;
        return ans;
    }
};