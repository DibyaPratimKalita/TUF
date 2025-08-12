class Solution{
public:
    bool canFinish(int N, vector<vector<int>> arr) {
        unordered_map<int, vector<int>>adj;
        
        for(auto ele: arr) {
            int u = ele[1];  // Prerequisite
            int v = ele[0];  // Course dependent on prerequisite
            adj[u].push_back(v);
        }

        vector<int>indeg(N);
        for(int i=0;i<N;i++){
            for(int ele: adj[i]){
                indeg[ele]++;
            }
        }

        queue<int>q;
        for(int i=0;i<N;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        int count=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;

            for(int neighbor: adj[node]){
                indeg[neighbor]--;
                if(indeg[neighbor]==0){
                    q.push(neighbor);
                }
            }
        }

        return (count==N) ? true : false;
        
    }
};