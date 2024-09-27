class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> mpp;
        int i = 0;
        while(i < asteroids.size()){
            if(mpp.empty()){
                // Stack is empty, push the current asteroid
                mpp.push(asteroids[i]);
            }
            else {
                int pehla = mpp.top(); // Peek the top element in the stack
                if(pehla > 0 && asteroids[i] < 0) {
                    // Potential collision, current asteroid is negative, top is positive
                    int mag = abs(asteroids[i]);
                    if(pehla == mag) {
                        // If magnitudes are equal, both explode
                        mpp.pop();
                    } else if(pehla > mag) {
                        // The top positive asteroid survives
                        // Do nothing, move to the next asteroid
                    } else {
                        // The current negative asteroid survives
                        mpp.pop(); // Remove the positive asteroid
                        continue; // Check the current asteroid again
                    }
                } else {
                    // No collision scenario, push the asteroid
                    mpp.push(asteroids[i]);
                }
            }
            i++;
        }

        // Prepare result from the stack
        vector<int> ans;
        while(!mpp.empty()){
            ans.push_back(mpp.top());
            mpp.pop();
        }
        reverse(ans.begin(), ans.end()); // Stack to result
        return ans;
    }
};
