class Solution {
public:

    // MOST OPTIMAL O(N) - GREEDY APPROACH
    int jump(vector<int>& nums) {

        int n = nums.size();
        if(n == 1) return 0;

        int jumps = 0;
        int L = 0;      // Current index
        int R = 0;      // Current jump ki boundary
        int temp = 0;   // Farthest index jo ab tak reach kar sakte hain

        while(L < n - 1) {

            // Current position se sabse door tak pahunch sakte hain
            temp = max(temp, L + nums[L]);

            // Agar current jump ki boundary par aa gaye
            if(L == R) {
                jumps++;
                R = temp;
            }

            L++;
        }

        return jumps;
    }
};