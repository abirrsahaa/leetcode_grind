class Solution {
public:
    static bool comp(int a,int b){
        return a>b;
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(),g.end(),comp);
        sort(s.begin(),s.end(),comp);

        int cg=0;
        int cs=0;

        int count=0;

        while(cg<g.size()&&cs<s.size()){
            if(g[cg]<=s[cs]){
                count++;
                cg++;
                cs++;
            }
            else{
                cg++;
            }
        }

        return count;
        
    }
};