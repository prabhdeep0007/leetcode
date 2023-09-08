class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        prev={1};
        if(rowIndex==0) return prev;
        for(int i=1;i<=rowIndex+1;i++)
        {
            vector<int> curr;
            for(int j=0;j<i;j++)
            {
                if(j==0||j==i-1)curr.push_back(1);
                else{
                    curr.push_back(prev[j]+prev[j-1]);
                }
            }
            prev=curr;
        }
        return prev;
    }
};