class Solution {
public:

    string reversee(string s){


        stack<char>abir;
        for(auto i:s){
            if(abir.empty()&&i!='#')abir.push(i);
            else{
                if(i!='#')abir.push(i);
                else{
                    if(!abir.empty())abir.pop();
                }
            }
        }

        string ans="";

        while(!abir.empty()){
            ans+=abir.top();
            abir.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;

    }
    bool backspaceCompare(string s, string t) {

        // i am not too confident about 2 pointer in this solution \
        // so need to go through that 

        // the most instant solution which came to me is using stack
        // to bring out the final string after elimination

        // i can make this a function for re-usability

        string a=reversee(s);
        string b=reversee(t);

        return a==b;

       
        
    }
};