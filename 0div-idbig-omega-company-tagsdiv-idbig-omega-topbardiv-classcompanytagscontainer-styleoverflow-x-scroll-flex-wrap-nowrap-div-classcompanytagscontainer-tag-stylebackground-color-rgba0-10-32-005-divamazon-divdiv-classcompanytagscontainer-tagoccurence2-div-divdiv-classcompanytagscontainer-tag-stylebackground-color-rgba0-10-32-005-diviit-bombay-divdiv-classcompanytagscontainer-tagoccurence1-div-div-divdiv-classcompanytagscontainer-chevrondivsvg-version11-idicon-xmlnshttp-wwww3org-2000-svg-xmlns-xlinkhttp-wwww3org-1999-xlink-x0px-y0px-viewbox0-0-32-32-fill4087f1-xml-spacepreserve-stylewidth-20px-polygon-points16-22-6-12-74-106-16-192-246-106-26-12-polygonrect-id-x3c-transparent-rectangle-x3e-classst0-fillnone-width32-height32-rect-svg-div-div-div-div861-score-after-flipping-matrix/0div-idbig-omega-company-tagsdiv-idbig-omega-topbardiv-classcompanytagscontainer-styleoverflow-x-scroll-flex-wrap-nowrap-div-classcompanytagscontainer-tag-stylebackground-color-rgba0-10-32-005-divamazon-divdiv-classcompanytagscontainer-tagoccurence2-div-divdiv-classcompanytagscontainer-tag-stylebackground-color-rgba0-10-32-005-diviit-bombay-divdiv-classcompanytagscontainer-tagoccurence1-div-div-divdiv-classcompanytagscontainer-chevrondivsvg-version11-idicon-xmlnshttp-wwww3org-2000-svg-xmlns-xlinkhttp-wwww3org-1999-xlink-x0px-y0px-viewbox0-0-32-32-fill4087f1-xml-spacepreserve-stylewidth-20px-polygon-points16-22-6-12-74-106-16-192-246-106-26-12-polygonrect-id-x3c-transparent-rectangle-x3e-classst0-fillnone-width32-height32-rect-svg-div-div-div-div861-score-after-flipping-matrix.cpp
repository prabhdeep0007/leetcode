class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
		
		// toggling the rows
		
        for(int i=0;i<m;i++){
            if(grid[i][0] == 0){
                for(int j=0;j<n;j++){
                    if(grid[i][j] == 0)
                        grid[i][j] = 1;
                    else
                        grid[i][j] = 0;
                }
            }
        }
		
		
        for(int i=0;i<n;i++){
            int z = 0, o = 0;
            for(int j=0;j<m;j++){
                if(grid[j][i] == 0) z++;
                else o++;
            }
            if(z > o){
                for(int j=0;j<m;j++){
                    if(grid[j][i] == 0) grid[j][i] = 1;
                    else grid[j][i] = 0;
                }
            }
        }
		
		
		
        int s = 0;
        for(int i=0;i<m;i++){
            for(int j=n-1;j>=0;j--)
            s += (grid[i][j] * (1 << (n - j - 1)));
        }
        return s;
    }
};