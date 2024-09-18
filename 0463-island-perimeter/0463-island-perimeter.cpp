class Solution {
public:
    void dfs(vector<vector<int>>&grid,vector<vector<int>>&visited,vector<vector<int>>&abir,int i,int j){
        visited[i][j]=1;

        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};


        int count=0;
        for(int k=0;k<4;k++){
           

            int new_row=i+row[k];
            int new_col=j+col[k];

            if((new_row<0 || new_row>=grid.size()) || (new_col<0 || new_col>=grid[0].size()) )count++;
            else if(!grid[new_row][new_col])count++;
            else if(!visited[new_row][new_col]){
                dfs(grid,visited,abir,new_row,new_col);
            }
        }
        abir[i][j]=count;
    }
    int islandPerimeter(vector<vector<int>>& grid) {


        vector<vector<int>>abir=grid;

        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && !visited[i][j])dfs(grid,visited,abir,i,j);
            }
        }

        int sum=0;

        for(int i=0;i<abir.size();i++){
            for(int j=0;j<abir[i].size();j++){
                sum+=abir[i][j];
            }
        }

        return sum;


        
    }
};