// doubt tha is question mai pehle bar mai nahi huya 
// the entire intuition was finding pattern and continuity

// multiply the koi fixed pattern nahi tha 
// so rather than going from value to target 
// what we decided is we will go from target to value 
// thereby leveraging the fact that we can now divide and add 
// in place of multiply and subtract


class Solution {
public:
    int brokenCalc(int startValue, int target) {

        if(startValue>=target)return startValue-target;

        if(!(target&1))return 1+brokenCalc(startValue,target/2);
        else return 1+brokenCalc(startValue,target+1);
        
    }
};