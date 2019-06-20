/*
	A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
	
	The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner 
	of the grid (marked 'Finish' in the diagram below).
	
	Now consider if some obstacles are added to the grids. How many unique paths would there be?
	
	Example 1:
		Input:
			[
	  			[0,0,0],
	  			[0,1,0],
	  			[0,0,0]
			]
		
		Output: 2
		Explanation:
			There is one obstacle in the middle of the 3x3 grid above.
			There are two ways to reach the bottom-right corner:
				1. Right -> Right -> Down -> Down
				2. Down -> Down -> Right -> Right
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
     
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if ( obstacleGrid[0][0] == 1)
            return 0;
        
        long long path[m][n];
        for ( int i=0; i<m; i++) {
            for ( int j=0; j<n; j++)
                path[i][j] = 0;
        }
        
        path[0][0] = 1;
        
        for ( int i=1; i<n; i++){
            if ( obstacleGrid[0][i] == 0 && path[0][i-1]==1 )
                path[0][i] = 1;
            else
                path[0][i] = 0;
        }
        
        for ( int i=1; i<m; i++){
            if ( obstacleGrid[i][0] == 0 && path[i-1][0] == 1 )
                path[i][0] = 1;
            else
                path[i][0] = 0;
        }
        
        for ( int i=1; i<m; i++) {
            for ( int j=1; j<n; j++) {
                if ( obstacleGrid[i][j] == 0 )
                    path[i][j] = (long long)path[i-1][j] + (long long) path[i][j-1];
                else
                    obstacleGrid[i][j] = 0;
            }
        }
        return path[m-1][n-1];
    
    }
};
