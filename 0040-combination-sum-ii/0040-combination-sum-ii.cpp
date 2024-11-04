class Solution {
public:
    void helper(vector<int>& candidates, int target,int index,vector<int>&temp,vector<vector<int>>&ans){
        if(index==candidates.size()){
            if(target==0)ans.push_back(temp);
            return;
        }
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0)return;

        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1])continue;
            temp.push_back(candidates[i]);
            helper(candidates,target-candidates[i],i+1,temp,ans);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,0,temp,ans);
        return ans;
    }
};