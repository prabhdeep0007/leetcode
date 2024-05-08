class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string> ans(n);
        priority_queue<int> p;
        map<int,int>m;
        for(int i=0;i<n;i++)
        {
            p.push(score[i]);
            m[score[i]]=i;
        }
       int i=1;
        while(!p.empty())
        {
            int t=p.top(); p.pop();
            int it=m[t];
            if(i==1)
            {
            ans[it]="Gold Medal";
            }
            else if(i==2)
            {
            ans[it]="Silver Medal";
            }
            else if(i==3)
            {
            ans[it]="Bronze Medal";
            }
            else {
                ans[it]=to_string(i);
            }
                i++;
        }
        return ans;
    }
};