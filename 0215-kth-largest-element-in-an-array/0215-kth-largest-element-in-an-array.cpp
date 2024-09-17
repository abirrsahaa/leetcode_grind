class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // as it has been said that i need ti return the kth largest element 
        // so i can either do it using 0(nlogn) by using sort function
        // or i can do it using heap for better 0(nlogk)
        // the basic thing is the with heap being of size k
        // by the time we reach the end we will have the k size elements which are the largest 
        // out of which the top one will be thr kth largest as we will be taking min heap
        // and min heap stores the least at the top 
        // and hence we attain the k no of larger elements from the array with kth being at the top


        priority_queue<int,vector<int>,greater<int>>abir; // defining the min priority queue
        int i=0;
        while(i<k){
            abir.push(nums[i++]);
        }
        while(i<nums.size()){
            // mai ab mere queue ko k size ke upar nhi jane dunga 
            abir.push(nums[i++]);
            abir.pop();
        }

        return abir.top();

        
    }
};