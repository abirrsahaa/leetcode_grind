class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(nums.size()==1)return 0;
        sort(nums.begin(),nums.end());
        // return nums[nums.size()-1]-nums[nums.size()-2];
        // lets apply sliding window here 
        // with basically two pointers 

        // the whole intuition here is the fact that 
        // i a window of k characters i want the min diff of max and min
        // what better than sorting the elements 
        // now i want min diff for that sorting is the best way as because 

        // for a particular window 
            // if i take the greater beyond that greater the diff will increase 
            // and if i take any smaller the diff will increase so this is the 
            // only possible way 


            // now my intuition says to try out every possiblw window of 
            // and i will slide my window of size k from last to first or from first to last and update my answer accordingly

        int j=nums.size()-1;
        int i=(j-k)+1;
        int ans=INT_MAX;

        while(i!=-1){

            ans=min(ans,(nums[j]-nums[i]));
            i--;
            j--;

        }
        return ans;


    }
};