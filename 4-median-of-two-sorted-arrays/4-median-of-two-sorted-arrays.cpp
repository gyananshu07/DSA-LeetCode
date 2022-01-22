class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        int i{0}, j{0};

        while (i != nums1.size() && j != nums2.size()) {
            if (nums1[i] < nums2[j]) {
                temp.push_back(nums1[i]);
                ++i;
            }
            else if (nums1[i] > nums2[j]) {
                temp.push_back(nums2[j]);
                ++j;
            }
            else {
                temp.push_back(nums2[j]);
                temp.push_back(nums2[j]);
                ++j;
                ++i;
            }
        }
        for (; i < nums1.size(); ++i) temp.push_back(nums1[i]);
        for (; j < nums2.size(); ++j) temp.push_back(nums2[j]);

        if (temp.size() % 2 == 0)
            return (double)(temp[temp.size()/2]+temp[(temp.size()/2)-1])/2;
        else
            return temp[temp.size()/2];
    }
};