class StockSpanner {
public:

    // Stack me {price, span} store karenge
    // price -> stock price
    // span -> us price ka span
    stack<pair<int,int>> st;

    StockSpanner() {

    }

    int next(int price) {

        // Har naye price ka minimum span 1 hota hai
        int span = 1;

        // Jab tak stack ka top current price se chhota ya equal hai,
        // uska pura span current answer me add kar do
        while(!st.empty() && st.top().first <= price){

            span += st.top().second;
            st.pop();
        }

        // Current price aur uska calculated span stack me push kar do
        st.push({price, span});

        // Current day's span return kar do
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */