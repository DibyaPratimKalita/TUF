class DisjointSet {
   public:
    vector<int> rank;
   vector<int> size;
   vector<int> ultiParent;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        ultiParent.resize(n + 1);
        for (int i = 0; i < n + 1; i++) {
            ultiParent[i]=i;
        }
    }
    int findUltiPar(int node){
        //recurvise calling
        
        //base case
        if(node==ultiParent[node]){
            return node;
        }

        return findUltiPar(ultiParent[node]);
    }
    bool find(int u, int v) {
        if(findUltiPar(u)==findUltiPar(v)){
            return true;
        }

        return false;
    }

    void unionByRank(int u, int v) {
         // Get the ultimate parents of both nodes
       int ulp_u = findUltiPar(u);
       int ulp_v = findUltiPar(v);
       
       // Return if nodes already belong to the same component
       if (ulp_u == ulp_v) return;
       
       /* Otherwise, join the node to the other 
       node having higher ranks among the two */
       if (rank[ulp_u] < rank[ulp_v]) {
           // Update the parent
           ultiParent[ulp_u] = ulp_v;
       }
       else if (rank[ulp_v] < rank[ulp_u]) {
           // Update the ultiParent
           ultiParent[ulp_v] = ulp_u;
       }
       
       /* If both have same rank, join any node to the 
       other and increment the rank of the ultiParent node */
       else {
           // Update the ultiParent
           ultiParent[ulp_v] = ulp_u;
           
           // Update the rank
           rank[ulp_u]++;
       }
    }

    void unionBySize(int u, int v) {
        int uP_u = findUltiPar(u);
        int uP_v = findUltiPar(v);
        
        // same compo
        if(uP_u == uP_v) return ;

        if(size[uP_u] < size[uP_v]){
            //ultiParent Update
            ultiParent[uP_u]=uP_v;
            size[uP_v]+=size[uP_u];
        }else{
            ultiParent[uP_v]=uP_u;
            size[uP_u]+=size[uP_v];
        }
    }
};
