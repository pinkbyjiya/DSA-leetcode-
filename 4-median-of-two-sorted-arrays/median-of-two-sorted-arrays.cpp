class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> temp(m+n); //m+n size ka kyuki dono merge ho jaenge 

        int i = 0; //nums1 ko point krega 
        int j = 0; //nums2 ko point krega 

        int k = 0; //jo temp array hum bnage to merge both the nums1 and 2 arrays usko point krega 

        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                //ye basically agr humara nums1 ka i pointer hai aur vo chota h 
                //to pehle vo temp array me jaega
                temp[k++] = nums1[i++];
            }
            else {
                //agr nums2 ka j pointer chota h to pehle vo temp array me jaega
                //because hum already sorted order me elements daal rhe hai temp me
                temp[k++] = nums2[j++];
            }
        }

        while(i < m) {
            temp[k++] = nums1[i++];
        }

        while(j < n) {
            temp[k++] = nums2[j++];
        }

        int size = m+n;

        if(size % 2 == 1) { //odd
            return temp[size/2];
        }
        else {
            return (temp[size/2] + temp[(size/2)-1]) / 2.0;
        }
    }
};