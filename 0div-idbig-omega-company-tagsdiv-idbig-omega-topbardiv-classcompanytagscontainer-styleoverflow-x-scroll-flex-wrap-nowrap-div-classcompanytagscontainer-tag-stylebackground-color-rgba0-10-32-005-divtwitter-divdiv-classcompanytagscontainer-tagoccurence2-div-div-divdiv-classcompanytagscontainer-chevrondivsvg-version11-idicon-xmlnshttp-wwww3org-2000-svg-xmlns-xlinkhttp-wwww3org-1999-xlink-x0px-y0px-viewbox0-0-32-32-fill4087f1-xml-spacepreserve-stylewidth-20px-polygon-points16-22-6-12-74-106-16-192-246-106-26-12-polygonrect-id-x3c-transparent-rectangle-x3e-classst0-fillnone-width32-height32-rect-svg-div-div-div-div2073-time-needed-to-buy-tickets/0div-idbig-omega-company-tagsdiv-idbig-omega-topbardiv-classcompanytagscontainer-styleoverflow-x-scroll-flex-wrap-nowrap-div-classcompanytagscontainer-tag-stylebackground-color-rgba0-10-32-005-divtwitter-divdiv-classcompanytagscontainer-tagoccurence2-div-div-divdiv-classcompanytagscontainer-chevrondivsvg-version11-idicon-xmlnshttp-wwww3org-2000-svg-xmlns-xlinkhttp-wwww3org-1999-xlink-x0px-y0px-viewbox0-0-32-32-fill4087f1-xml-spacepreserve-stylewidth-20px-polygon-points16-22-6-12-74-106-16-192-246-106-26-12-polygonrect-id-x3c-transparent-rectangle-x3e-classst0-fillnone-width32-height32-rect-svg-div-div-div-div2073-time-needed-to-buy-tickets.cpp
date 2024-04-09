class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans=0;
        while(true)
        {
            bool f=false;
        for(int i=0;i<tickets.size();i++)
        {
            tickets[i]--;
            if(tickets[i]>=0)ans++;
            if(tickets[k]==0)
            {
                f=true;
                break;
            }
        }
        if(f) break;
        }
        return ans;
    }
};