class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
       sort(points.begin(), points.end());
        int maxDist = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            int dist = points[i+1][0] - points[i][0];
            if (dist > maxDist) {
                maxDist = dist;
            }
        }

        return maxDist;
    }
};