class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int ans=0,n=people.size(),i=0,j=n-1;
       
        while(i<=j)
        {
            if((people[i]+people[j])>limit) j--;
            else
            {
            i++;
            j--;
            }
            ans++;
        }
        return ans;
    }
};