class Solution {
public:
    /* Function to find the shortest distance 
    between every pair of vertices. */
    void shortestDistance(vector<vector<int>> &matrix){
        
        // Getting the number of nodes
	    int n = matrix.size();
	    
	    // For each intermediate node k
	    for(int k=0; k<n; k++) {
	        
	        // Check for every (i, j) pair of nodes
	        for(int i=0; i<n; i++) {
	            for(int j=0; j<n; j++) {
	                
	                /* If k is not an intermediate 
	                node, skip the iteration */
	                if(matrix[i][k] == -1 || 
	                   matrix[k][j] == -1) 
	                        continue;
	                
	                /* If no direct edge from 
	                i to v is present */
	                if(matrix[i][j] == -1) {
	                    
	                    // Update the distance
	                    matrix[i][j] = 
	                        matrix[i][k] + matrix[k][j];
	                }
	                
	                /* Else update the distance to 
	                minimum of both paths */
	                else {
	                    matrix[i][j] = 
	                        min(matrix[i][j] , 
	                             matrix[i][k] + matrix[k][j]
	                            );
	                }
	            }
	        }
	    }
	}
};