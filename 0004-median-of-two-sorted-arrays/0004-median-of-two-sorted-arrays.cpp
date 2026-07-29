class Solution {
public:
    //BRUTE FORCE ...
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1+n2;

        //if(n==even ) if(n==odd)
        vector<int>arr;
        for(int i=0;i<n1;i++){
            arr.push_back(nums1[i]);
        }
        for(int i=0;i<n2;i++){
            arr.push_back(nums2[i]);
        }

        sort(arr.begin(),arr.end());

        if(n%2!=0){
            return arr[n/2];
        }
        else{
           return (arr[n/2]+arr[n/2-1])/2.0;
        }
        return -1;
    }
};