class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // so it is given that the element in the array are >=1

        // so find a 1 if it is in the array and swap it this should be the first step
        // else just make the first element 1

        // if there is 1 why not sort it this would ensure that further we donot get 
        // any element which is smaller 
        sort(arr.begin(),arr.end());


        // the intuition here is that 
        // i need to mantain the condition 
        // and the maximum possible answer in the worst case would be equal to the length of the array
        // so the thing is i should be just traversing the array and mantaining the condition
        if(arr[0]!=1)arr[0]=1;
        int maxi=1;
        for(int i=1;i<arr.size();i++){
            if(abs(arr[i]-arr[i-1])<=1){
                maxi=max(maxi,arr[i]);
            }
            else{
                arr[i]=arr[i-1]+1;
                maxi=max(maxi,arr[i]);
            }
        }

        return maxi;
    }
};