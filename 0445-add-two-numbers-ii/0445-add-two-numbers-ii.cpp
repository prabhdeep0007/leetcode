class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2,s3;
        while(l1)
        {
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2)
        {
            s2.push(l2->val);
            l2=l2->next;
        }
        int sum,carry=0;
        while(s1.size()&&s2.size())
        {
            sum=carry+s1.top()+s2.top();
            s1.pop();
            s2.pop();
            s3.push(sum%10);
            carry=sum/10;
        }
        while(s1.size())
        {
            sum=carry+s1.top();
            s1.pop();
            s3.push(sum%10);
            carry=sum/10;
        }
        while(s2.size())
        {
            sum=(carry+s2.top());
            s2.pop();
            s3.push(sum%10);
            carry=sum/10;
        }
        if(carry)
        {
            s3.push(carry);
        }
        ListNode*head=new ListNode(s3.top());
        ListNode *temp=head;
        s3.pop();
        while(s3.size())
        {
            head->next=new ListNode(s3.top());
            head=head->next;
            s3.pop();
        }
        return temp;
    }
};