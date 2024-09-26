class StockSpanner {
public:




    int count=0;
    stack<pair<int,int>>abir;
    StockSpanner() {
        
        
    }
    
    int next(int price) {
        // need to include pair 
        count++;

        if(abir.empty()){
            abir.push({price,count});
            return count;
        }
        else{
            while(!abir.empty()&&abir.top().first<=price)abir.pop();
            if(abir.empty()){
                abir.push({price,count});
                return count;
            }
            else {
                int pehla=abir.top().second;
                abir.push({price,count});
                return count-pehla;
            }
        }
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */