class Solution {
public:

    // Check karta hai ki given capacity mein kitne days lagenge
    bool canShip(vector<int>& weights, int days, int capacity) {

        int currentLoad = 0;
        int daysNeeded = 1;

        for (int weight : weights) {

            if (currentLoad + weight > capacity) {
                // Capacity exceed hui, next day
                daysNeeded++;
                currentLoad = weight;
            }
            else {
                currentLoad += weight;
            }
        }

        return daysNeeded <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int low = 0;
        int high = 0;

        // Minimum = heaviest package
        // Maximum = total weight
        for (int weight : weights) {
            low = max(low, weight);
            high += weight;
        }

        // Binary search on capacity
        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canShip(weights, days, mid)) {
                // Ye capacity kaam kar rahi hai,
                // aur smaller try karte hain
                high = mid - 1;
            }
            else {
                // Capacity chhoti hai, badhani padegi
                low = mid + 1;
            }
        }

        return low;
    }
};