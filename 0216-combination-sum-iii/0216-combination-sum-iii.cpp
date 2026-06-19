class Solution {
public:

    void solve(int idx,int k,vector<int>&num, int n,vector<vector<int>>&ans ,vector<int>&temp){
        


        // if(idx-1==9)
        if(k==0 && n==0){
            //sum bhi 0 hogya toh 
            //condition reached....
            ans.push_back(temp);//to take all combinations
            return;

        }


        if(idx==9 || k<0 || n<0){
            return;
        }

        temp.push_back(num[idx]);
        solve(idx+1,k-1,num,n-num[idx],ans,temp);//pick branch 
        //num tak reduce sum se aur k-- matlab k reduce agle iteration mai

        //after recursion
        temp.pop_back();
        // n+=num[idx];
        // k++;
        solve(idx+1,k,num,n,ans,temp);//non-pick branch 
        




    }
    vector<vector<int>> combinationSum3(int k, int n) {
        //brute force ... at most 9! mere hisaab se

        vector<int>num={1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>temp;//k num com lene hai

        solve(0,k,num,n,ans,temp);
        return ans;
        
        
    }
};