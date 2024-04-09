#pragma once
#include <vector>

using namespace std;

class Solution {
    public: 
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
    private:
        int findr(vector<int>& nums2, int x);
        double findd(vector<int>& nums1, vector<int>& nums2, int x);
};