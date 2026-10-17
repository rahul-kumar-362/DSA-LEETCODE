class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {//ANOTHER BRUTE FORCE...
        int n = arr.size();
        //ASSUMING K character, & if nums present just K++
        for(int i=0;i<n;i++){
            if(arr[i]<=k){
                k++;
            }
            else break;
        }
        return k;
    }
};