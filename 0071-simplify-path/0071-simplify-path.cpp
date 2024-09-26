class Solution {
public:
    string simplifyPath(string s) {

        // first find the first '/'
        int i=0;
        while(s[i]!='/')i++;
        int index=i;
        stack<string>track;
        while(index<s.length()){
            // 3 cases 
            //  '/'
            while(index<s.length()&&s[index]=='/')index++;
            //  '.' '..' '..*'
            if(s[index]=='.'){
                string period="";
                while(index<s.length()&&s[index]!='/'){
                    period+=s[index];
                    index++;
                }
                // 3 cases 
                if(period==".")continue;
                else if(period==".."){
                    if(!track.empty())track.pop();
                    else continue;
                }
                else track.push(period);

            }
            else{

                // faltu ki cheeze
                string faltu="";
                while(index<s.length()&&s[index]!='/'){
                    faltu+=s[index];
                    index++;
                }
                track.push(faltu);

            }
            // other 
        }

        string ans="";
        while(!track.empty()){
            string pehla=track.top();
            reverse(pehla.begin(),pehla.end());
            track.pop();
            // pehla=pehla+'/';
            ans+=pehla;
            // cout<<ans+'/'<<endl;
            if(ans.length()>0)ans+='/';
            
        }
        reverse(ans.begin(),ans.end());
        if(ans.length()==0)return "/";
        return ans;
        
    }
};