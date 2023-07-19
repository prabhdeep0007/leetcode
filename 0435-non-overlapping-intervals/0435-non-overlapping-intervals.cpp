class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int n=intervals.size(),count=0,idx=0;
         for(int i=1;i<n;i++)
        {
         if(intervals[idx][1]>intervals[i][0])
         {
            count++;
         }else
         {
             idx=i;
         }
       
        }
        return count;
    }
};