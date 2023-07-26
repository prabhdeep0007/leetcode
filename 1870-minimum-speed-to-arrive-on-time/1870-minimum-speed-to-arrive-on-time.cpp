class Solution {
public:
    int minSpeedOnTime(vector<int>& arr, double hour) {
        int ans=INT_MAX,maxi=arr[0],n=arr.size();
        for(int i=1;i<arr.size();i++)
        {
            maxi=max(arr[i],maxi);
        }
        int l=1,h=1e7;
        while(l<=h)
        {
            double temp=0;
            int m=(l+h)/2;
            for(int i=0;i<n-1;i++)
            {
                temp+=ceil((double)arr[i]/m);
            }
            temp+=(double)arr[n-1]/m;
            if(temp>hour)
            {
                l=m+1;
            }
            else 
            {
                h=m-1;
                ans=m;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};