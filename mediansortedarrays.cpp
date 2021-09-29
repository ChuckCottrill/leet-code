

// leetcode
// Median of Two Sorted Arrays

// https://leetcode.com/problems/median-of-two-sorted-arrays/

/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).


*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if( (0 == len1) || (0 == len2) ) {
            if( len1 > 0 ) { return nums1[ (len1+1)/2 ]; }
            if( len2 > 0 ) { return nums2[ (len2+1)/2 ]; }
            return 0.0;
        }
        int midpoint = (len1 + len2 + 1) / 2;
        int idx1 = 0, idx2 = 0;
        double value = nums1[0];
        for( int idx = 0; idx < midpoint; idx++ ) {
            if( idx1 >= len1 ) {
                // return nums2[idx2+len1]; // midpoint - len1
                return nums2[midpoint - len1];
            }
            else if( idx2 >= len2 ) {
                // return nums1[idx1+len2]; // midpoint - len2
                return nums1[midpoint - len2];
            }
            if( nums1[idx1] <= nums2[idx2] ) { idx1++; value = nums1[idx1]; }
            else { idx2++; value = nums2[idx2]; }
        }
        return value;
    }
};


