class Solution {
public:
    int maxSubArray(vector<int>& nums) {



//         🧠 Thought Process:

// At index i:

// You have 2 choices:

// 1️⃣ Extend previous subarray
// 2️⃣ Start fresh from current element

// So:
      int n=nums.size();
      int maxsum=INT_MIN;
      int currsum=0;


        for(int i=0;i<n;i++){
            currsum+=nums[i];//har baar cur_sum nikal lo
            currsum=max(currsum,nums[i]);
            maxsum=max(currsum,maxsum);
        }

        //💡 5. WHY This Works (Deep Intuition)

        // 👉 If previous sum is NEGATIVE:

        // It will only decrease future sum
        // So discard it ❌

        // 👉 If previous sum is POSITIVE:

        // It helps increase sum
        // So keep it ✅


        return maxsum;
    }
};