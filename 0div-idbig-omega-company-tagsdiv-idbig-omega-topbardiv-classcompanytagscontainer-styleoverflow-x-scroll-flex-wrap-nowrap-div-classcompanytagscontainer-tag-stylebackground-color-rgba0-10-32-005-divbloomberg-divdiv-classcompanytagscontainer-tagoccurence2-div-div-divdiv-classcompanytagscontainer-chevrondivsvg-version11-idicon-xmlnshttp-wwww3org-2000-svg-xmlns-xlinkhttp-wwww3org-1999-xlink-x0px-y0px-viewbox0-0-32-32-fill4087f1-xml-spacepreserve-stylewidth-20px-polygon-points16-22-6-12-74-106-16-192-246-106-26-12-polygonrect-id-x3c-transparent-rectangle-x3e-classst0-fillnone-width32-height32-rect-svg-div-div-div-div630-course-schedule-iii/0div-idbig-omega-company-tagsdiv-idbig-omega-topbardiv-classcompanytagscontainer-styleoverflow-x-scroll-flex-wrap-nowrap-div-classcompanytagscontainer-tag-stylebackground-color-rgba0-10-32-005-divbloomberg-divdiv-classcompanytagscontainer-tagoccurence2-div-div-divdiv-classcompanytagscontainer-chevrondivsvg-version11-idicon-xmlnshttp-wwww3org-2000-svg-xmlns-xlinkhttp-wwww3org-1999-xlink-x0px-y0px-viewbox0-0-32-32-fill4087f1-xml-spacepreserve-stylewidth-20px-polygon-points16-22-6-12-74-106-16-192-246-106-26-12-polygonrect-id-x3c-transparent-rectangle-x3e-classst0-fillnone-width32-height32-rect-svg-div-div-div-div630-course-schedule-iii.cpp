class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(begin(courses),end(courses),cmp);
        long long sum=0;
        priority_queue<int> pq;
        for(auto i:courses)
        {
            sum+=i[0];
            pq.push(i[0]);
            if(sum>i[1])
            {
                sum-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};