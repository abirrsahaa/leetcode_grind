class Solution {
public:
    int minimumRounds(vector<int>& tasks) {

        // the fact that even if i sort i cannot apply bs
        // as for bs i dont know which value to find 
        // although it can be done by finding one after the other starting from the first 
        // but let that be a topic of optimization 

        sort(tasks.begin(),tasks.end());
        if(tasks.size()==1)return -1;
        int operation=0;
        int count=1;
        int ele=tasks[0];

        for(int i=1;i<tasks.size();i++){

            if(tasks[i]!=ele){
                // calculate 
                if(count==1)return -1;
                // here i have been said to do min operation 
                // so why not make maximum grouop of 3 
                // remaining would be 0 1 2 
                // if 0 all gone if 1 hai ya 2 ak hi operation extra lagega 
                // kyu ki 1 matlab 4 extra so 3 se ak operation - and 2 se 2 plus net 1 plus
                operation+=count/3;
                if((count%3)!=0)operation++;

                // for the next operation
                count=1;
                ele=tasks[i];

            }else count++;
            
        }

        if(count==1)return -1;
                // here i have been said to do min operation 
                // so why not make maximum grouop of 3 
                // remaining would be 0 1 2 
                // if 0 all gone if 1 hai ya 2 ak hi operation extra lagega 
        operation+=count/3;
        if((count%3)!=0)operation++;

        return operation;
    }
};