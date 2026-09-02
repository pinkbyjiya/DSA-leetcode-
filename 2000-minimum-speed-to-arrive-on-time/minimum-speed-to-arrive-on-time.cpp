class Solution {
public:

    bool canReach(vector<int>& dist, double hour, int k) {
        double totalTime = 0;

        for (int i = 0; i < dist.size() - 1; i++) {
            totalTime += ceil((double)dist[i] / k);
        }

        totalTime += (double)dist.back() / k;

        return totalTime <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {

        // Impossible to arrive on time
        if (hour <= dist.size() - 1)
            return -1;

        int low = 1;
        int high = 10000000;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canReach(dist, hour, mid)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};