class Solution{
public:
    unordered_set<int>visited;
    void bfs(int node, bool &ans, vector<int> adj[]){
        visited.insert(node);
        queue<pair<int,int>>q;
        q.push({node,-1});

        while(!q.empty()){
            auto front=q.front();
            q.pop();

            for(int neighbor : adj[front.first]){
                if(visited.find(neighbor)!=visited.end() && neighbor!=front.second){
                    ans= true;
                    return;
                }else if (visited.count(neighbor)==0){
                    visited.insert(neighbor);
                    q.push({neighbor,front.first});
                }
            }
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        bool ans=false;
        for(int i=0;i<V;i++){
            if(visited.find(i)==visited.end()){
                bfs(i, ans, adj);
                if(ans==true) break;
            }
        }
        
        return ans;
    }
};