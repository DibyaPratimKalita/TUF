class Solution {
  public:
    unordered_set<int>visitedDfs;
    unordered_set<int>visitedBfs;

    void dfs(vector<int> adj[], vector<int> &ansDfs, int node){
        if(visitedDfs.find(node)!=visitedDfs.end()){
            return ;
        }

        visitedDfs.insert(node);
        ansDfs.push_back(node);

        for(int neighbor: adj[node]){
            if(visitedDfs.find(neighbor)==visitedDfs.end()){
                dfs(adj, ansDfs,neighbor);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ansDfs;
        
        dfs(adj,ansDfs, 0);
        return ansDfs;
    }

    void bfs(vector<int> adj[], vector<int> &ansBfs, int node){
        visitedBfs.insert(node);
        queue<int>q;
        q.push(node);

        while(q.empty()==false){
            int num=q.front();
            q.pop();

            ansBfs.push_back(num);

            for(int neighbor: adj[num]){
                if(visitedBfs.count(neighbor)==0){
                    visitedBfs.insert(neighbor);
                    q.push(neighbor);
                     
                }
            }
        }
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ansBfs;
        bfs(adj,ansBfs, 0);
        return ansBfs;
    }
};
