/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int findInMountainArray(int target, MountainArray &mountainArr) {

        // 1. Find peak index
        int left = 0;
        int right = mountainArr.length() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        int peak = left;

        // 2. Search in increasing part
        left = 0;
        right = peak;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int value = mountainArr.get(mid);

            if (value == target)
                return mid;

            if (value < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        // 3. Search in decreasing part
        left = peak + 1;
        right = mountainArr.length() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int value = mountainArr.get(mid);

            if (value == target)
                return mid;

            if (value > target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        // Target not found
        return -1;
    }
};