class Solution {
public:
    void helper(int index,string&temp,vector<string>&ans,vector<string>&demo,string&digits){
        if(index==digits.length()){
            ans.push_back(temp);
            return;
        }

        int digit=digits[index]-'0';
        for(auto i:demo[digit]){
            // temp=temp+i;
            temp.push_back(i);
            helper(index+1,temp,ans,demo,digits);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
       

        string temp="";
        vector<string>ans;
        vector<string>demo(10);
        demo[2]="abc";
        demo[3]="def";
        demo[4]="ghi";
        demo[5]="jkl";
        demo[6]="mno";
        demo[7]="pqrs";
        demo[8]="tuv";
        demo[9]="wxyz";
        // demo[10]="abc";
        if(digits.length()>0)helper(0,temp,ans,demo,digits);

        return ans;
        
    }
};