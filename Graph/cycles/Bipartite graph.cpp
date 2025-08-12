class Solution{
public:
    bool bfs(int i, vector<int> adj[], vector<int>&color, unordered_set<int>&visited){
        color[i]=1;
        visited.insert(i);
        
        queue<int>q;
        q.push(i);

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto neighbor: adj[node]){
                if(visited.count(neighbor)==0){
                    color[neighbor]=1-color[node];
                    visited.insert(neighbor);
                    q.push(neighbor);
                }else {
                    if(color[neighbor]==color[node]){
                        return false;
                    }
                }
            }
        }

        return true;
        
    }
    bool isBipartite(int V, vector<int> adj[])  {
        vector<int>color(V);
        unordered_set<int>visited;
        for(int i=0;i<V;i++){
            if(visited.find(i)==visited.end()){
                if(bfs(i,adj,color,visited)==false)
                    return false;
            }
        }
        return true;
    }
};
