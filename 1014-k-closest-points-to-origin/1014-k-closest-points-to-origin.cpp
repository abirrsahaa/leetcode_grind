class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // as i need only k distance points 
        // so i will be using a max heap
        // as i need to print the coordinate 
        // so i will need to store a pair<int(distance),pair<int,int>(coordinates)>abir

        priority_queue< pair <int , pair <int,int> > >abir;
        int i=0;
        while(i<k){
            long long distance=(points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
            abir.push({distance,{points[i][0],points[i][1]}});
            i++;
        }

        while(i<points.size()){
            long long distance=(points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
            abir.push({distance,{points[i][0],points[i][1]}});
            i++;
            abir.pop();

        }

        auto it=abir.top();
        int dis=it.first;
        vector<vector<int>>ans;
        while(!abir.empty()){
            auto it=abir.top();
            abir.pop();
            
            
                vector<int>temp;
                temp.push_back(it.second.first);
                temp.push_back(it.second.second);
                ans.push_back(temp);
           
        }
        return ans;

        
    }
};