class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // -------------------------------
        // MOST OPTIMAL APPROACH : Bucket Sort
        // -------------------------------

        // Observation:
        // Maximum frequency of any element can be at most n.
        // So, instead of sorting by frequency, use the frequency itself
        // as the index of a bucket.

        unordered_map<int, int> freq;
        int n = nums.size();

        // Step 1: Store frequency of every element
        for (int x : nums)
            freq[x]++;

        // bucket[i] = stores all elements having frequency i
        vector<vector<int>> bucket(n + 1);

        // Step 2: Place every element into its corresponding frequency bucket
        for (auto &it : freq)
            bucket[it.second].push_back(it.first);

        vector<int> ans;

        // Step 3: Traverse buckets from highest frequency to lowest
        for (int i = n; i >= 1; i--) {

            // Extract all elements having frequency i
            for (int x : bucket[i]) {

                ans.push_back(x);

                // Stop once we have collected k elements
                if (ans.size() == k)
                    return ans;
            }
        }

        return ans;
    }
};

/*
Time Complexity:
----------------
Building Frequency Map  : O(n)
Filling Buckets         : O(m)
Traversing Buckets      : O(n)

Total                   : O(n)

(where m = number of unique elements)

------------------------------------------------

Space Complexity:
-----------------
unordered_map           : O(m)
Buckets                 : O(n)
Answer Vector           : O(k)

Total                   : O(n)

------------------------------------------------

Core Idea:
----------
Maximum frequency of any element is at most n.
So, create n+1 buckets where:
bucket[i] stores all elements having frequency i.

Traverse buckets from n -> 1 to directly obtain
the k most frequent elements without sorting or using a heap.
*/