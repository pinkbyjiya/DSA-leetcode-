class NumArray {
    vector<int> prefix;

public:

    // Constructor: build the prefix sum array
    NumArray(vector<int>& nums) {

        // First element is the first prefix sum
        prefix.push_back(nums[0]);

        // Build the remaining prefix sums
        for(int i = 1; i < nums.size(); i++){

            // Previous prefix sum + current element
            prefix.push_back(prefix.back() + nums[i]);
        }
    }

    // Return sum of elements from left to right
    int sumRange(int left, int right) {

        // If range starts from index 0,
        // prefix[right] is already the complete answer
        if(left == 0){
            return prefix[right];
        }

        // Remove the sum of elements before 'left'
        return prefix[right] - prefix[left - 1];
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */