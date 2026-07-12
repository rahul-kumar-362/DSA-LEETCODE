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

        // vector<pair<int,int>>p;

        priority_queue<pair<int,int>>p;
        for(auto &it:mpp){
            p.push({it.second,it.first});
        }

  


        for(int i=0;i<k;i++){
          ans.push_back(p.top().second);
          p.pop();
        }

        return ans;
    }
};