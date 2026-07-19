class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // i -> nums1 ke valid elements ka last index
        int i = m - 1;

        // j -> nums2 ka last index
        int j = n - 1;

        // k -> nums1 ke last index se filling start karenge
        int k = m + n - 1;

        // Jab tak dono arrays me elements bache hain
        while (i >= 0 && j >= 0) {

            // Jo bada element hoga usko end me rakh denge
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            }
            else {
                nums1[k] = nums2[j];
                j--;
            }

            // Har baar next position pe move karna hai
            k--;
        }

        // Agar nums2 ke kuch elements abhi bhi bach gaye hain
        // to unhe nums1 me copy kar do
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }

        // Agar nums1 ke elements bach gaye hain,
        // to kuch karne ki zarurat nahi hai.
        // Wo already sahi position pe hain.
    }
};

// Time Complexity : O(m + n)
// Space Complexity : O(1)