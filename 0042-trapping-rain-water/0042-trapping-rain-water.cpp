class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;


        //2 arrays of leftmax and rightmax
        vector<int>leftmax(n);
        vector<int>rightmax(n);

        leftmax[0]=height[0];
        rightmax[n-1]=height[n-1];

        for(int i=1;i<n;i++){


            leftmax[i]=max(leftmax[i-1],height[i-1]);
            cout<<"L : "<<leftmax[i]<<endl;
        }
        for(int i=n-2;i>=0;i--){
            rightmax[i]=max(rightmax[i+1],height[i+1]);
            cout<<"R : "<<rightmax[i]<<endl;
        }

        for(int i=0;i<n;i++){
            int curr=min(leftmax[i],rightmax[i])-height[i];

            if(curr>0){
                ans+=curr;
            }
        }
        return ans;
    }
};