class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        unordered_map<char,int>m;
        for(auto i:tasks)
        {
            m[i]++;           
        }
        for(auto&i:m)
        {
            pq.push(i.second);
        }
        int time=0;
        while(pq.size())
        {
            vector<int> remain;
            int count=n+1;
            while(count&& pq.size())
            {
                int t=pq.top();
                pq.pop();
                if(t>1) remain.push_back(t-1);
                time++;
                count--;
            }
            for(auto i:remain)
            {
                pq.push(i);
            }
            if(pq.size()==0) break;
            time+=count;
        }
        return time;
    }
};