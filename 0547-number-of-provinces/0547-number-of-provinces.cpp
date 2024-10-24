class Solution {
public:

    void bfs(vector<vector<int>>adj,vector<int>&vis,int index){
        vis[index]=1;
        queue<int>q;
        q.push(index);

        while(!q.empty()){
            int top=q.front();
            q.pop();

            for(auto j:adj[top])if(!vis[j]){
                vis[j]=1;
                q.push(j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        // technically this is the problem where we need to find the 
        // number of connected components 

        // for that i would need a counter 
        int count=0;
        vector<int>vis(isConnected.size()+1,0);


        vector<vector<int>>adj(isConnected.size()+1);

        // first to perform bfs or dfs we need to convert this adj matrix to adj list 
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]){
                    if(i!=j){
                        adj[i+1].push_back(j+1);
                    }
                }
            }
        }

        // i have made the adjajency liost here 

        for(int i=1;i<=isConnected.size();i++){
            if(vis[i]==0){
                count++;
                bfs(adj,vis,i);
            }
        }

        return count;
    }
};