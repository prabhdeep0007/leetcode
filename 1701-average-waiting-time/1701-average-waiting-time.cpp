class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        int t=customers[0][0];
        double ans=0;
        for(int i=0;i<n;i++){
            if(t>customers[i][0])t+=customers[i][1];
            else t=customers[i][0]+customers[i][1];
            ans+=t-customers[i][0];
        }
        return ans/n;
    }
};