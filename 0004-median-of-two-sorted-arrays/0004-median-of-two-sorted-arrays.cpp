class Solution {
public:
    //better solution ...
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1+n2;
        int i = 0;
        int j = 0;
        int prev = 0;
        int curr = 0;

        while( i<n1 && j<n2 ){
            if(nums1[i]<nums2[j]){
                curr = nums1[i];
                i++;
            }
            else{
                curr = nums2[j];
                j++;
            }
            if(n%2!=0 ){//odd
                if(i+j==n/2+1)return curr;
            }

            else{//EVEN
                if(i+j == n/2+1){
                    return (prev+curr)/2.0;
                }
            }

            prev = curr;//storing current to previous 
        }

        while(i<n1){
            curr = nums1[i];
            i++;

            if(n%2!=0 ){//odd
                if(i+j==n/2+1)return curr;
            }

            else{//EVEN
                if(i+j == n/2+1){
                    return (prev+curr)/2.0;
                }
            }

            prev = curr;//storing current to previous 
        }
        while(j<n2){

            curr = nums2[j];
            j++;

            if(n%2!=0 ){//odd
                if(i+j==n/2+1)return curr;
            }

            else{//EVEN
                if(i+j == n/2+1){
                    return (prev+curr)/2.0;
                }
            }

            prev = curr;//storing current to previous 
        }
        return -1;
    }
};