class Solution {
public:
    int minOperations(vector<int>& nums) {
        // similar problem i have already sorted it is almost the same solution no difference tbh
        sort(nums.begin(),nums.end());

        //if i want to do it in o(N) i can do it but i need to use a hash map then 
        // which will use an extra space 
        // so that can be an optimization when constrainsts are tighter 

        // abhi ke liye yahi karte hai 
        int count=1;
        int ele=nums[0];
        int i=1;
        int ans=0;
        while(i<nums.size()){
            if(nums[i]!=ele){
                // diff ele agaya
                if(count==1)return -1;
                else{
                    int x=count/3;
                    if((count%3)!=0)x++;
                    ans+=x;
                    ele=nums[i];
                    count=1;
                }
            }else count++;
            // count++;
            i++;
        }
        cout<<endl;
        if(count==1)return -1;
        else{
            int x=count/3;
            if((count%3)!=0)x++;
            ans+=x;
            // ele=nums[i];
            // count=1;
        }

        return ans;

    }
};