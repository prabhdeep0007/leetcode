class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> m;
        vector<int> indegree(numCourses,0);
        for(auto v:prerequisites)
        {
            m[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        int count=0;
        while(q.size())
        {
            int temp=q.front();
            q.pop();
            count++;
            for(auto i:m[temp])
            {
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        return count==numCourses;
        
    }
};