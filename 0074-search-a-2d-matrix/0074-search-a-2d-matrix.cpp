class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int l=0;
        int h=mat.size()-1;
        int n=mat[0].size();
        int m;
        while(l<=h)
        {
             m=(l+h)/2;
            if(mat[m][n-1]>target)
            {
                h=m-1;
            }
            else if(mat[m][n-1]<target)
            {
                l=m+1;
            }
            else return true;
        }
        if(l==mat.size()) return false;
        return binary_search(mat[l].begin(),mat[l].end(),target);
    }
};