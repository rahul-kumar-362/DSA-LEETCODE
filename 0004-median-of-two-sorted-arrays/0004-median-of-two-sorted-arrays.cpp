class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = (n1+n2+1)/2;//ELEMENTS NEEDED... ALSO FOR ODD

        if(n1>n2){
            return findMedianSortedArrays(nums2,nums1);//AGAR n2 chota to uske liye
        }
        
        int st = 0;
        int end = n1;
        while(st<=end){
            int mid1 = st + (end  - st)/2;
            int mid2 = n-mid1;

            int l1 = (mid1-1)>=0?nums1[mid1-1]:INT_MIN;
            int l2 = (mid2-1)>=0?nums2[mid2-1]:INT_MIN;
            int r1 = (mid1)<n1?nums1[mid1]:INT_MAX;
            int r2 = (mid2)<n2?nums2[mid2]:INT_MAX;


            if(l1<=r2 && l2<=r1){//SAB SAHI 
                //EVEN KE LIYE...
                if((n1+n2)%2==0){
                    return (max(l1,l2)+ min(r1,r2))/2.0;
                }
                else{//ODD
                    return max(l1,l2);
                }
            }
            else if(l1>r2){
                end = mid1 - 1;//PRUNE RIGHT of smallest arr
            }
            else if(l2>r1){
                st = mid1 + 1;//PRUNE LEFT
            }
        }
        return -1;
    }
};