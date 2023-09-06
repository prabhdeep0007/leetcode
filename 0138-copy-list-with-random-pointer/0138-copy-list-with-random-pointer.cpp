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
        Node *temp=head;
        while(temp)
        {
            Node* nxt=temp->next;
            temp->next=new Node(temp->val);
           temp->next->next=nxt;
            temp=nxt;
        }
        Node *ans=head->next;
        temp=head;
        while(temp)
        {
            if(temp->random)temp->next->random=temp->random->next;
            temp=temp->next->next;
        }
        temp=head;
        while(temp)
        {
            Node*nxt=temp->next->next;
            if(nxt) 
            {
            temp->next->next=nxt->next;
            temp->next=nxt;
            temp=nxt;
            }
            else{
                temp->next=NULL;
                break;
            }
        }
        return ans;
    }
};