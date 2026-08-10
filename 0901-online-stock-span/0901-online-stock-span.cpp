class StockSpanner {
public:
    stack<pair<int , int>>st; //{price , itne isse kam hai}
    StockSpanner() {
        
    }
    
    int next(int price) {

        int lower = 0; 
        while(!st.empty() && st.top().first <= price){
            lower++;
            lower += st.top().second;
            st.pop();
        }

        st.push({price , lower});

        

        return lower + 1;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */