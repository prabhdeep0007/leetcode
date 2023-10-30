class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> m;
        int ans=0;
        for(int ele:time){
            int rem = ele%60;
            ans+=m[(60-rem)%60];
            m[rem]++;
        }
        return ans;
    }
};