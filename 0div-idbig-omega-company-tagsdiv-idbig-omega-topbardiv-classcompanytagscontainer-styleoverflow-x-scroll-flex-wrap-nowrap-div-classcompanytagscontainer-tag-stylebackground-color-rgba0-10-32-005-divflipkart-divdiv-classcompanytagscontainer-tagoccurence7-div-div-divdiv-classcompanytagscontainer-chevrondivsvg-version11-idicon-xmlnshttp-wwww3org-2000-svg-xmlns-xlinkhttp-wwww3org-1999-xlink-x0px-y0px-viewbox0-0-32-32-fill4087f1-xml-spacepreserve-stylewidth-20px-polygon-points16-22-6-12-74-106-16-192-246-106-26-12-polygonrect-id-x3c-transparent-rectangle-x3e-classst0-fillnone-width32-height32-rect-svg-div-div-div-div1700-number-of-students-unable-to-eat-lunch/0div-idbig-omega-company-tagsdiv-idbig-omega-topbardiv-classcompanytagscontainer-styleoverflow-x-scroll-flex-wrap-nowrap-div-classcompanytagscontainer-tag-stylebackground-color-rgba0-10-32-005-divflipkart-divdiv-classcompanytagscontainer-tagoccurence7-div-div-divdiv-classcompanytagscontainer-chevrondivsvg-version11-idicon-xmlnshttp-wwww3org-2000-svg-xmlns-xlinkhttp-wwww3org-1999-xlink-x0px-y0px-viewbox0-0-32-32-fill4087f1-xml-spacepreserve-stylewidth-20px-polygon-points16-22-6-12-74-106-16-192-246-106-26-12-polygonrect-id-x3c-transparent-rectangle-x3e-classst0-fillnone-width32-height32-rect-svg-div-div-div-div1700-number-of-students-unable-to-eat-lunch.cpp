class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(int i=0;i<students.size();i++)
        {
            q.push(students[i]);
        }
        int j=0,n=students.size();
        bool flag=false;
        while(true)
        {
          if(j==n || flag) break;
          flag=true;
          for(int i=0;i<n && j<n;i++)
          {
            int t=q.front();
              q.pop();
          if(t==sandwiches[j])
          {
             flag=false;
             j++;
          }else q.push(t);
         }
        
        }
        return n-j;
    }
};