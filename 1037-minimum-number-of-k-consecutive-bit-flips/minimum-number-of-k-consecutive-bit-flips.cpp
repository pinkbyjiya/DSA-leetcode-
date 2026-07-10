class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {

        int n = nums.size();

        // Ye array batayega ki kisi index se flip effect start hua tha ya nahi
        vector<int> isFlipped(n, 0);

        int flip = 0;     // Current index par total active flips odd hain ya even
        int ans = 0;      // Total flips count

        for(int i = 0; i < n; i++) {

            // Agar koi flip ka effect yaha khatam ho raha hai,
            // to uska effect hata do
            if(i >= k)
                flip ^= isFlipped[i - k];

            // Agar current bit flip hone ke baad bhi 0 ban rahi hai,
            // to hume yaha se naya flip start karna padega
            if((nums[i] ^ flip) == 0) {

                // Agar remaining elements k se kam hain,
                // to flip possible hi nahi hai
                if(i + k > n)
                    return -1;

                // Yaha se naya flip start kar diya
                isFlipped[i] = 1;

                // Active flips ki parity change ho gayi
                flip ^= 1;

                // Answer increase
                ans++;
            }
        }

        return ans;
    }
};