class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        int n=arr.size();
        if(k>=n) return *max_element(arr.begin(),arr.end());
        int currmax=arr[0];
        for(int i=1;i<n;i++)
        {
            currmax=max(currmax,arr[i]);
            m[currmax]++;
            if(m[currmax]==k) return currmax;
        }
        return currmax;
    }
};