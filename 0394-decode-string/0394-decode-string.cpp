class Solution {
public:
    string decodeString(string s) {

        // this is highly implementation based problem
        // stack has this one of the important type of problems

        stack<char>mpp;
        for(auto i:s){
            // what is allowed push it 
            if(i!=']'){
                mpp.push(i);
            }
            else{
                if(!mpp.empty()){
                    // matlab elements hai 
                    string temp="";
                    while(!mpp.empty()&&mpp.top()!='['){
                        temp+=mpp.top();
                        mpp.pop();
                    }
                    // abhi string wala part khthm
                    mpp.pop();
                    string num="";
                    while(!mpp.empty()&&isdigit(mpp.top())){
                        num+=mpp.top();
                        mpp.pop();
                    }
                    reverse(num.begin(),num.end());
                    int number=stoi(num);
                    string conc="";
                    for(int i=0;i<number;i++){
                        conc+=temp;
                    }


                    reverse(conc.begin(),conc.end());

                    for(auto j:conc){
                        mpp.push(j);
                    }
                    

                }
            }

        }

        string ans="";
        while(!mpp.empty()){
            ans+=mpp.top();
            mpp.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};