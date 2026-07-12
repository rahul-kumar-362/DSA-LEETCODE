class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    //MOST OPTIMAL SOLUTION IS :
    //BUCKETSORT

    //BASE - max toh frequency k hi hogi kisi ki bhi ...

    unordered_map<int,int>mpp;
    int n=nums.size();

    for(int i=0;i<n;i++){
        mpp[nums[i]]++;//storing the frequency in map
    }
    vector<vector<int>>bucket(n+1);//for storing frequency wise taaki le saku 

    for(auto &i : mpp){
        bucket[i.second].push_back(i.first);//bucket ki uss frequency par pushback bcz max n 
        //{{},{3},{2},{1},{},{}}
    }

    //now traverse from back side since want max
    //THEREFORE,
    vector<int>ans;
    for(int i=n;i>=1;i--){ //uss frequency ke saare elements nikaldo
    // if( !bucket[i].empty()){
    //         ans.push_back(nums[i]);
    //     }
    
        for(int j=0;j<bucket[i].size();j++){
            ans.push_back(bucket[i][j]);//wth

            if(ans.size()==k)return ans;//matlab bhargaya
        }
    }
        return ans;
    }
};