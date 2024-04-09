#include "solution4.h"

double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    if (!m && n) {
        if (n&1) return nums2[n >> 1];
        else return (double)(nums2[(n >> 1)-1]+nums2[n >> 1])/2;
    } else if (!n && m) {
        if (m&1) return nums1[m >> 1];
        else return (double)(nums1[(m >> 1)-1]+nums1[m >> 1])/2;
    }


    if ((m + n) & 1) return findd(nums1, nums2, ((m + n) >> 1) + 1);
    else return (double)(findd(nums1, nums2, (m + n) >> 1) + findd(nums1, nums2, ((m + n) >> 1) + 1))/2;    
}

int Solution::findr(vector<int>& nums2, int x) {
    int l=0, r = nums2.size() - 1, mid;
    // find the first index in nums2 where nums2[ind] > x
    while (l < r) {
        mid = (l + r) >> 1;
        if (nums2[mid] <= x) {
            l = mid + 1;
        } else r = mid;
    }
    if (nums2[l] > x) return l;
    else return l+1;
}

double Solution::findd(vector<int>& nums1, vector<int>& nums2, int x) {
    int l = 0, r = nums1.size() - 1, mid;
    // find the first index in nums1 where the rank > x
    while (l < r) {
        mid = (l + r) >> 1;
        int rank = findr(nums2, nums1[mid]);
        if (rank+mid+1==x) return nums1[mid];
        else if (rank + mid + 1 > x) r = mid;
        else l = mid + 1;
    }
    if (findr(nums2,nums1.back())+(int)nums1.size()<x) return nums2[x-nums1.size()-1];
    else if (findr(nums2,nums1.back())+(int)nums1.size()==x) return nums1.back();
    return nums2[x - l-1];
}