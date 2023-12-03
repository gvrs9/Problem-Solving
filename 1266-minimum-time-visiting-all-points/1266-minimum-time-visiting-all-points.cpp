class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int minTimeToVisitAllPoints = 0;
        
        for(int i = 1; i < (int)points.size(); i++) {
            int sourceX = points[i - 1][0], sourceY = points[i - 1][1];
            int destinationX = points[i][0], destinationY = points[i][1];

            minTimeToVisitAllPoints += max(abs(destinationX - sourceX), abs(destinationY - sourceY));
        }

        return minTimeToVisitAllPoints;
    }
};