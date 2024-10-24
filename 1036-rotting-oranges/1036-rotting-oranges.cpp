class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<pair<int,int>,int>>abir;

        vector<vector<int>>visited(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    pair<int,int>manu={i,j};
                    pair<pair<int,int>,int>pyar={manu,0};
                    visited[i][j]=1;
                    abir.push(pyar);
                }
            }
        }

        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};

        // initial states have been pushed 

        int ans=0;

        while(!abir.empty()){

            pair<pair<int,int>,int>pehla=abir.front();
            abir.pop();
            pair<int,int>pairi=pehla.first;
            int time=pehla.second;
            ans=time;


            for(int i=0;i<4;i++){

                int new_row=pairi.first+row[i];
                int new_col=pairi.second+col[i];

                if((new_row>=0&&new_row<n)&&(new_col>=0&&new_col<m)&&(grid[new_row][new_col]==1)&&!visited[new_row][new_col]){
                    visited[new_row][new_col]=1;
                    pair<int,int>manu={new_row,new_col};
                    pair<pair<int,int>,int>pyar={manu,time+1};
                    abir.push(pyar);

                }

            }

        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]!=1 && grid[i][j]==1)return -1;
            }
        }

        return ans;

    }
};