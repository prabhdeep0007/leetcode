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
        unordered_map<Node *,Node*>m;
        Node *dummy=new Node(-1);
        Node* temp=dummy,*head2=head;
        while(head)
        {
        temp->next=new Node(head->val);
        m[head]=temp->next;
        head=head->next;
        temp=temp->next;
        }
        temp=dummy;
        temp=temp->next;
        while(head2)
        {
            temp->random=m[head2->random];
            head2=head2->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};