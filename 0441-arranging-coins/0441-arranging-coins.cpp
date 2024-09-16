class Solution {
public:
    int arrangeCoins(int n) {

        int start=1;
        int end=n;
        int ans=-1;
        long long target=2*1ll*n;
        while(start<=end){
            int mid=(end-start)/2+start;
            long long temp=mid*1ll*(mid+1);
            if(temp<=target){
                ans=mid;
                start=mid+1;
            }
            else end=mid-1;
            
        }

        return ans;
        
    }
};