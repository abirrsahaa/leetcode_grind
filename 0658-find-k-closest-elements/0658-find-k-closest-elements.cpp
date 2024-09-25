class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        // the intution behind the algo is the fact that 
        // we are reducing the size of the window according to the condition given 

        // acha already sorted hai 
        int i=0;
        int j=arr.size()-1;
        while(i<j&&j-i+1>k){
            if(x-arr[i]>arr[j]-x){
                i++;
            }
            else j--;
        }
        vector<int>ans;
        for(int m=i;m<=j;m++){
            ans.push_back(arr[m]);
        }
        return ans;
        
    }
};