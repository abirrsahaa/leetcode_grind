class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // here the sole thing and crux of the question is to make the 2d linear 
        // and then apply the search we do in linear array 
        int start=0;
        int end=(matrix.size()*matrix[0].size())-1;

        cout<<start<<endl;
        cout<<end<<endl;

        while (start<=end){
            int mid=(start+end)/2;
            int row=mid/matrix[0].size();
            int col=mid%matrix[0].size();
            if(matrix[row][col]==target)return true;
            else if(matrix[row][col]>target)end=mid-1;
            else start=mid+1;
        }
        return false;
        
    }
};