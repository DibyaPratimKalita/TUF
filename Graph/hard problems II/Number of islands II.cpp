class disjointSet {
public:
    vector<int> size;
    vector<int> uParents;

    disjointSet(int n) {
        size.resize(n, 1);
        uParents.resize(n);
        for (int i = 0; i < n; i++) {
            uParents[i] = i;
        }
    }
    int findUPar(int node) {
        if (node == uParents[node]) {
            return node;
        }

        return uParents[node] = findUPar(uParents[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            size[ulp_v] += size[ulp_u];
            uParents[ulp_u] = ulp_v;
        } else {
            size[ulp_u] += size[ulp_v];
            uParents[ulp_v] = ulp_u;
        }
    }
};
class Solution {
   public:
    bool isValid(int i, int j, int n, int m){
        if(i<0 || i>=n || j<0 ||j>=m){
            return false;
        }
        return true;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &A) {
        //grid sea
        vector<vector<int>>grid(n,vector<int>(m,0));
        disjointSet ds(n*m);
        vector<int>ans;
        int count=0;
        vector<vector<int>>dirs={{0,1},{1,0},{-1,0},{0,-1}};
        for(auto ele: A){
            int row = ele[0];
            int col = ele[1];

            if(grid[row][col]==1){
                ans.push_back(count);
                continue;
            }
            grid[row][col]=1;
            count++;
            for(auto dir : dirs){
                int new_row = dir[0] + row;
                int new_col = dir[1] + col;

                if(isValid(new_row,new_col,n,m) && grid[new_row][new_col]==1){
                    int oldNode = row * m + col;
                    int newNode = new_row * m + new_col;
                    if(ds.findUPar(oldNode) != ds.findUPar(newNode)){
                        count--;
                        ds.unionBySize(oldNode,newNode);
                    }
                    //else{
                    //     //means they are in the same island;
                    //     continue;
                    // }
                }
            }

            ans.push_back(count);
        }

        return ans;
    }
};