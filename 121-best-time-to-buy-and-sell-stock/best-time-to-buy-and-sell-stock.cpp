class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0]; //by default pehle index wale ko minimum lenge fir aage compare krte jaenge 
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++) { //isliye 1 se start kiya kyuki pehle index wake ko se to intitialise kr diya naa
            minPrice = min(minPrice, prices[i]);
            int profit = prices[i] - minPrice;
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};