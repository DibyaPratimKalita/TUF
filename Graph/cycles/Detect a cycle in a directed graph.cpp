class Solution{
public:
    bool dfs(int i, vector<int> adj[], vector<bool> &visited, vector<bool> &pathVisited){
        visited[i]=true;
        pathVisited[i]=true;

        for(int neighbor: adj[i]){
            if(visited[neighbor]==false){
                if(dfs(neighbor, adj, visited, pathVisited)==true){
                    return true;
                }
            }else if(pathVisited[neighbor]==true){
                return true;
            }
        }


        pathVisited[i]=false;
        return false;
    }
    bool isCyclic(int N, vector<int> adj[]) {
        vector<bool>visited(N,false);
        vector<bool>pathVisited(N,false);

        for(int i=0;i<N;i++){
            if(visited[i]==false){
                if(dfs(i, adj, visited, pathVisited)==true){
                    return true;
                }
            }
        }
        return false;
    }
};
