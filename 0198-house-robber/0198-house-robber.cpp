class Solution {
public:


//     🧠 Correct Thinking (Important DP Pattern)

// At every house you have 2 choices:

// 1️⃣ Rob this house
// → then you cannot rob previous house

// 2️⃣ Skip this house
// → take previous best

// So:

// dp[i] = max(
//             nums[i] + dp[i-2],   // rob current
//             dp[i-1]              // skip current
//           )




    int rob(vector<int>& nums) {
        
        //code toh dekhlia maine par samjho ki karna kya hai
        //ADJACENT houses chori nhi kar sakta toh ye kiya hai

        //TAAKI MAX CHORI HO...

        //used dp tabulation maybe but approach samjho ye imp nahi

        int n=nums.size();
        vector<int>amt(n);

        if(n==1)return nums[0];
        amt[0]=nums[0];
        amt[1]=max(amt[0],amt[1]);

        for(int i=2;i<n;i++){
            amt[i]=max(amt[i-1],nums[i]+amt[i-2]);
            //YA toh pichla amount YA toh abhi aur adjacent wali side ka
        }

        return amt[n-1];
    }
};