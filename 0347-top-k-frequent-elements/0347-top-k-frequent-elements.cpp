class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int>ans;
        //SORT BY FREQUENCY
        unordered_map<int,int>mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        

        // priority_queue<pair<int,int>>p;
        // for(auto &it:mpp){
        //     p.push({it.second,it.first});
        // }
        //         Current

        // m insertions

        // O(m log m)

        // Optimized

        // Build vector : O(m)

        // Heapify : O(m)

  

        vector<pair<int,int>>p;
        for(auto &it : mpp){
            p.push_back({it.second, it.first});
        }

        priority_queue<pair<int,int>>pq(p.begin(),p.end());//banado pq O(m) mai...

        for(int i=0;i<k;i++){
          ans.push_back(pq.top().second);
          pq.pop();
        }

        return ans;
    }
};