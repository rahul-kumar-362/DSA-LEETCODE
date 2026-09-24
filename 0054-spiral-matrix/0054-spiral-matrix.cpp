class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //kya karu kya karu   charo side 1 variable lagadeta hu

        int m = matrix[0].size();
        int n = matrix.size();

        int l=0;//left
        int r=m-1;//right
        int T=0;//Top
        int B=n-1;//Bottom

        vector<int>result;


        while( T<=B && l<=r){

            //----  TOP ----
            for(int i=l;i<=r;i++){
                result.push_back(matrix[T][i]);//top change nhi hora
            }
            T++;//niche jao

            //-----  RIGHT -----            
            for(int i=T;i<=B;i++){
                result.push_back(matrix[i][r]);//right change nhi hora
            }
            r--;
            
            //----- BOTTOM -----
            if(T<=B){ //AGAR TOP B se Bada toh rows khatam
                for(int i = r ; i>=l;i-- ){
                    result.push_back(matrix[B][i]);//top change nhi hora
                }
            }
            B--;

            if(l<=r){//left
                for(int  i = B;i>=T;i--){
                    result.push_back(matrix[i][l]);//top change nhi hora
                }
            }
            l++;

            // //EK CYCLE KE BAAD UPDATE
            // T++;
            // B--;
            // l++;
            // r--;
        }
        return result;
    }
};