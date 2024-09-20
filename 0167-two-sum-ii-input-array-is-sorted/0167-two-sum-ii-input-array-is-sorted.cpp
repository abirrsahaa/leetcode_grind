class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        vector<int>ans;
        while(numbers[i]+numbers[j]!=target){
            if(numbers[i]+numbers[j]>target)j--;
            else i++;
        }
        ans.push_back(i+1);
        ans.push_back(j+1);
        return ans;
        
    }
};