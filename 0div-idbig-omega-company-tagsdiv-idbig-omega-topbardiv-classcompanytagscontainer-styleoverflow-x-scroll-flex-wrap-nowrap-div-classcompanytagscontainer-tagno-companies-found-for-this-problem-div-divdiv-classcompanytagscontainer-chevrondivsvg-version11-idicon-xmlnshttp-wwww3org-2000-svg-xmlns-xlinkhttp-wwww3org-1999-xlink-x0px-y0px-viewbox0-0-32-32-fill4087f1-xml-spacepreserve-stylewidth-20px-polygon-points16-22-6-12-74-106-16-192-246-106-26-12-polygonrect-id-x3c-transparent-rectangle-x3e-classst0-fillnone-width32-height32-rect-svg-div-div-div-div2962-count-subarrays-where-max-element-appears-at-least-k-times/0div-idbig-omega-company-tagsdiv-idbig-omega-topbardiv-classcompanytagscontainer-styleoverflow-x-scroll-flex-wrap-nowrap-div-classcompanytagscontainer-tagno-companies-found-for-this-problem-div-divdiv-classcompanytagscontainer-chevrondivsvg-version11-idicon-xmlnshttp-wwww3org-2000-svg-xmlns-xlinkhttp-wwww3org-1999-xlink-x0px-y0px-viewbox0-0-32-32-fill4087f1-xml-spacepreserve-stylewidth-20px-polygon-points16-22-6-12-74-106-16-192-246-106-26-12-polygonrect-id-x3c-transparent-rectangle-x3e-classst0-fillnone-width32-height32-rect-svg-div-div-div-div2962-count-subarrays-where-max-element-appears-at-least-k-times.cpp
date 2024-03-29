class Solution {
public:
    long long countSubarrays(vector<int>& arr, int k) {
        int n=arr.size(),maxi=*max_element(arr.begin(),arr.end()),i=0,j=0;
        long long ans=0;
        long long count=0;
        while(i<n&&j<n) 
        {
            if(arr[j]==maxi) count++; 
            while(count==k)
            {
                ans+=n-j;
                if(arr[i]==maxi) count--;
                i++;
            }
            j++;
        }
        return ans;
    }
};