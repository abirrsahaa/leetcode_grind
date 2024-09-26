class Solution {
public:
    string removeDuplicates(string s, int k) {
        // if i am using string with o(n) space
        // it would be great to have a map which stores the freq of elements in our stack

        stack<char>track;

        // ok so lets write the algo first 
        // every time we might have 2 choices for an element 
        // it exists previously 
        int i=0;
        while(i<s.length()){
            if(track.empty()|| track.top()!=s[i] ){
                // dekh kitna lagatar hai 
                int count=0;
                char ele=s[i];
                while(i<s.length()&&s[i]==ele){
                    count++;
                    i++;
                }
                int insert=count%k;
                while(insert>0){
                    track.push(ele);
                    insert--;
                }
            }
            else if(!track.empty()&&track.top()==s[i]){
                char ele=s[i];
                int count=0;

                // here it is not working somehow 

                while(!track.empty()&&track.top()==ele){
                    count++;
                    track.pop();
                }
                while(i<s.length()&&s[i]==ele){
                    count++;
                    i++;
                }
                int insert=count%k;
                while(insert>0){
                    track.push(ele);
                    insert--;
                }


            }
        }

        string ans="";
        while(!track.empty()){
            ans+=track.top();
            track.pop();
        }


        reverse(ans.begin(),ans.end());
        return ans;

        // it deosn't
        
    }
};