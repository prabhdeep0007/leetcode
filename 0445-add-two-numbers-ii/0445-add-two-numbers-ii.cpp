class Solution {
public:
    ListNode * reverse(ListNode* n)
    {
        ListNode*prev=NULL;
        while(n)
        {
            ListNode*nxt=n->next;
            n->next=prev;
            prev=n;
            n=nxt;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        int sum,carry=0;
        ListNode*dummy=new ListNode();
        ListNode*temp=dummy;
        while(l1&&l2)
        {
            sum=(carry+l1->val+l2->val)%10;
            temp->next=new ListNode(sum);
            carry=(carry+l1->val+l2->val)/10;
            l1=l1->next;
            l2=l2->next;
            temp=temp->next;
        }
        while(l1)
        {
            sum=(carry+l1->val)%10;
            temp->next=new ListNode(sum);
            carry=(carry+l1->val)/10;
            l1=l1->next;
            temp=temp->next;
        }
        while(l2)
        {
            sum=(carry+l2->val)%10;
            temp->next=new ListNode(sum);
            carry=(carry+l2->val)/10;
            l2=l2->next;
            temp=temp->next;
        }
        if(carry)
        {
            temp->next=new ListNode(carry);
        }
        return reverse(dummy->next);
    }
};