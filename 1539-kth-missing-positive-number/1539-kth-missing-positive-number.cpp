class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //brute force
        //MUJHE LAGTA HAI MAXI + 5 rakhna chahiye
        int n = arr.size();
        int maxi =*max_element(arr.begin(),arr.end())+k;
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            s.insert(arr[i]);
        }
        int total = 0;
        for(int i=1;i<=maxi;i++){
            
            if(!s.count(i)){
                total++;
                s.insert(i);
                if(total == k)return i;
            }
        }
        return -1;
    }
};