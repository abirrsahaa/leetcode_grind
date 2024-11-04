// main thing here is that i think i need to optimize it further 

class Solution {
public:
    void helper(vector<int>&temp,vector<vector<int>>&ans,int index,int k,int n){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        if(index>n)return;
        // include 
        temp.push_back(index);
        helper(temp,ans,index+1,k,n);
        temp.pop_back();
        helper(temp,ans,index+1,k,n);
        // exclude
    }
    vector<vector<int>> combine(int n, int k) {

        // i would be needing 
        // a answer vector , a temp vector, a index 
        vector<int>temp;
        vector<vector<int>>ans;
        helper(temp,ans,1,k,n);
        return ans;
        
    }
};