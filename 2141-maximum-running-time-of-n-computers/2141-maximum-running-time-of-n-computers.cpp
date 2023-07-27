class Solution {
public:
    long long maxRunTime(int n, vector<int>& arr) {
        long long total_time = 0; 
        for(auto i : arr) total_time += i; 
        sort(arr.rbegin(),arr.rend());
        int m=arr.size();
        for(int i = 0; i < m; i++, n--) {
            if(arr[i] <= (total_time / n)) break;
            total_time -= arr[i];
        }
        
        return total_time / n; 
    }
};