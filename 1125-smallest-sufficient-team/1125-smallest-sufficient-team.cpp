class Solution {
public:
    vector<int> ans;
    void solve(vector<int> &p,int i,int& n,vector<int>& temp,int cm, unordered_map<int,bool>& banned)
    {
        if(i==p.size()) 
        {
            if(cm==((1<<n)-1))
            {
            if(ans.size()>temp.size()|| ans.size()==0) ans=temp;
            }
            return;
        }
        solve(p,i+1,n,temp,cm,banned);
        if(!banned[i])
        {
         temp.push_back(i);
         solve(p,i+1,n,temp,cm|p[i],banned);
         temp.pop_back();        
        }
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string,int> m;
        int n=req_skills.size();
        vector<int> p(people.size(),0);
        for(int i=0;i<n;i++)
        {
           m[req_skills[i]]=i;
        }
        vector<int> temp;
        for(int i=0;i<people.size();i++)
        {
            for(auto s:people[i])
            {
             p[i]|=1<<m[s];   
            }
        }
        unordered_map<int,bool> banned;
        int a=people.size();
       for(int i=0;i<a;i++)
       {
           for(int j=i+1;j<a;j++)
           {
               int b=p[i]|p[j];
               if(p[i]==b) banned[j]=true;
               else if(p[j]==b) banned[i]=true;
           }
       }
        solve(p,0,n,temp,0,banned);
        return ans;
    }
};