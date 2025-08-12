class Solution {
public:
	string findOrder(string dict[], int N, int K) {
		map<int,vector<int>>adj;
        for(int i=0;i<N-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len=min(s1.size(),s2.size());
            for(int j=0;j<len;j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }

        //topo sort
        vector<int>indeg(K);

        for(int i=0;i<K;i++){
            for(int num: adj[i]){
                indeg[num]++;
            }
        }

        queue<int>q;

        for(int i=0;i<K;i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        string ans;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            ans+=char(node + 'a');
            for(int neighbor: adj[node]){
                indeg[neighbor]--;
                if(indeg[neighbor]==0){   
                    q.push(neighbor);
                }
            }
        }

        return ans;


	}
};
