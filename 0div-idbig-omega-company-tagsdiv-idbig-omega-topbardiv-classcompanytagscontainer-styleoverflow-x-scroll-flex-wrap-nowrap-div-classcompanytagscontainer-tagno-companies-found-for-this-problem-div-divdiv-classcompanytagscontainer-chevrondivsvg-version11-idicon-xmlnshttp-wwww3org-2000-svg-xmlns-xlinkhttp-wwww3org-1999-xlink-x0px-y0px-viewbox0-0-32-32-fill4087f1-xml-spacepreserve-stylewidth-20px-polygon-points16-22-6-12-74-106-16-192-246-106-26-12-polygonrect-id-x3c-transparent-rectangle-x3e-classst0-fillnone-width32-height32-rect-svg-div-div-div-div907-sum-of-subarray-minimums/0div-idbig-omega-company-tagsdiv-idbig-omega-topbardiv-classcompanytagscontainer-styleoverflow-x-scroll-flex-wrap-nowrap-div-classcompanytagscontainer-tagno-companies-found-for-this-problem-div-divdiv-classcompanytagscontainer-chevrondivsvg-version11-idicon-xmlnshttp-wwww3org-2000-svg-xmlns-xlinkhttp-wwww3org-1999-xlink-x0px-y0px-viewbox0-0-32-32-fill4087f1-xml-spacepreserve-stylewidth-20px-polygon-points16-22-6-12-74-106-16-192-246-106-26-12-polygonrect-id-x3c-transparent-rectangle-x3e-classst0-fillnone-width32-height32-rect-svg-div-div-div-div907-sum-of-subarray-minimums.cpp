class Solution {
public:
    int sumSubarrayMins(vector<int>&v) {
        int n=v.size();
        long long mod=1e9+7;
        stack<pair<long long,long long>>st;
        vector<long long>pse(n,-1),nse(n,n);
        for(int i=0;i<n;i++){
            while(!st.empty() and st.top().first>v[i])st.pop();
            if(!st.empty())pse[i]=st.top().second;
            st.push({v[i],i});
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and st.top().first>=v[i])st.pop();
            if(!st.empty())nse[i]=st.top().second;
            st.push({v[i],i});
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            long long tt=(i-pse[i])*(nse[i]-i)*v[i];
            ans=(ans%mod+(tt)%mod)%mod;
        }
        return ans;
    }
};