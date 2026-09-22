class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // Cheapest buying price seen so far
        int minPrice = prices[0];

        // Maximum profit found so far
        int maxProfit = 0;

        // Start from the second day
        for(int i = 1; i < prices.size(); i++){

            // Update the cheapest price seen so far
            minPrice = min(minPrice, prices[i]);

            // Calculate profit if we sell today
            int profit = prices[i] - minPrice;

            // Update maximum profit if today's profit is better
            maxProfit = max(maxProfit, profit);
        }

        // Return the maximum profit
        return maxProfit;
    }
};