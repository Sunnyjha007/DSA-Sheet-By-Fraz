class Solution {
public:
//O(m+n)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m+n-1,i=m-1,j=n-1;
        while(i>=0&&j>=0){
            if(nums2[j]>=nums1[i]){
                nums1[k--] = nums2[j--];
            }else{
                nums1[k--] = nums1[i--];
            }
        }
        while(j>=0){
            nums1[k--] = nums2[j--];
        }
    }
};
/*
//O(m+n)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m+n-1,i=m-1,j=n-1;
        while(j>=0){
            if(i>=0&&nums1[i]>nums2[j])nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
    }
*/
//brute force will be merge them and sort them O((m+n)log(m+n)) 
