class Solution {
public:
    void helper(vector<vector<int>>&distance,vector<vector<int>>&grid){
        queue<pair<int,int>>abir;
        abir.push({0,0});

        // directions
        int roww[]={-1,0,1,0,-1,1,1,-1};
        int coll[]={0,1,0,-1,1,1,-1,-1};

        while(!abir.empty()){

            auto pehla=abir.front();
            abir.pop();


            int row=pehla.first;
            int col=pehla.second;

            for(int i=0;i<8;i++){
                int new_row=row+roww[i];
                int new_col=col+coll[i];

                if((new_row>=0&&new_row<grid.size())&&(new_col>=0&&new_col<grid.size())&&grid[new_row][new_col]==0&&distance[row][col]+1<distance[new_row][new_col]){
                    distance[new_row][new_col]=1+distance[row][col];
                    abir.push({new_row,new_col});
                }
            }

        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        if(grid[0][0]==1)return -1;

        // ok so here i have been said that i need to find the shortest path 
        // from 0,0 to n-1,n-1 where i am allowed to move in all 8 directions
        // that being said that within bounds and with 0 in the cell 

        // idhar hum woh unit distance wala bhi laha sakte hai 
        // and using a simple queue and mantaining a distance array 

        // so distance array
        vector<vector<int>>distance(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        distance[0][0]=1;

        helper(distance,grid);

        if(distance[grid.size()-1][grid.size()-1]==INT_MAX)return -1;
        return distance[grid.size()-1][grid.size()-1];

        
    }
};