class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> A;
        vector<string> ret;
        for(int i=0; i<tickets.size(); i++)
            A[tickets[i][0]].insert(tickets[i][1]);
        stack<string> S;
        S.push("JFK");
        while(!S.empty())
        {
            string src = S.top();
            if(A[src].size()==0)
            {
                ret.push_back(src);
                S.pop();
            }
            else
            {
                auto dest = A[src].begin();
                S.push(*dest);       
                A[src].erase(A[src].begin());
            }
        }
        reverse(ret.begin(), ret.end());
        return ret; 
            
    }
};