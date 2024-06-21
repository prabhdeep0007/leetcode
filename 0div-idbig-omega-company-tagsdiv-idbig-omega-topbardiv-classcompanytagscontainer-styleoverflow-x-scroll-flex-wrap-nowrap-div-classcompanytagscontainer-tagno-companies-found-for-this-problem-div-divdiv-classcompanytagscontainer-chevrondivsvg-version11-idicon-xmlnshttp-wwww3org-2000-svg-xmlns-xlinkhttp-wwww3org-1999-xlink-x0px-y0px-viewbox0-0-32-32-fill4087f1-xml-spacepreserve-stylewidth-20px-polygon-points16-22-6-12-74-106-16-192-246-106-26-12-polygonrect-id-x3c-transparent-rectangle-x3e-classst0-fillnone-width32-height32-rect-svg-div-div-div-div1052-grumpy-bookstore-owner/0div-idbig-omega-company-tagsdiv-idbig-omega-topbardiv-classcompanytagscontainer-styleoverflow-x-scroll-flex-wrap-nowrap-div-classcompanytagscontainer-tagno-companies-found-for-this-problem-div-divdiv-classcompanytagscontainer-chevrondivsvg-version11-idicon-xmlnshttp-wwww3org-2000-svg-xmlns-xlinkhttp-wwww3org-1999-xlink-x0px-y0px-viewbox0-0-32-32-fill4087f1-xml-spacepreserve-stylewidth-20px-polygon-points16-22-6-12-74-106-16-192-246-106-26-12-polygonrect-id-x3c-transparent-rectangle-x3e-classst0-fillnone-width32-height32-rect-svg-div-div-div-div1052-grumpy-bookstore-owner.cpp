class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int i=0,j=minutes;
        int temp=0,ans=0,n=customers.size();
        for(int i=0;i<customers.size();i++)
        {
            if(i<minutes ||grumpy[i]==0) temp+=customers[i];
        }
        ans=max(ans,temp);
        while(i<n&&j<n)
        {
            
            if(grumpy[j]==1) temp+=customers[j];
            j++;
            if(grumpy[i]==1) temp-=customers[i];
            i++;
            ans=max(ans,temp);
        }
        return ans;
    }
};