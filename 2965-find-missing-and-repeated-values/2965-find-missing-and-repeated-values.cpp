class Solution {
public:
    // General solution

    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int repeating = -1;
        int missing = -1;

        int n = grid[0].size();
        int m = grid.size();
        int N = m * n;

        //X->Repeating
        //Y->Missing

        //first Xor All
        //1 to N & all in the vector  ----Remaining will be X^Y

        int Xor = 0;//since 0 se fark nahi padta

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                Xor^=grid[i][j];
            }
        }

        for(int i=1;i<=N;i++){
            Xor^=i;
        }


        //Since 2 different no.
        //Different AT atleast 1 bit 🙂

        //HENCE , take any setbit  and MAKE 2 BUCKETS A&B 

        //CONCEPT - > Others WIll occur Even No, of times and IT occur Odd no. of times



        int setBit = Xor & (-Xor); // Xor ka sabse right wala bit nikal LO...

        int bucket1 = 0;
        int bucket2 = 0;

        // Divide grid numbers into 2 buckets
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] & setBit)
                    bucket1 ^= grid[i][j];
                else
                    bucket2 ^= grid[i][j];
            }
        }

        // Divide 1...N into same buckets
        for(int i = 1; i <= N; i++){
            if(i & setBit)
                bucket1 ^= i;
            else
                bucket2 ^= i;
        }

        // bucket1 and bucket2 are X and Y (order unknown)

        for(auto &row : grid){
            for(int num : row){
                if(num == bucket1){
                    repeating = bucket1;
                    missing = bucket2;
                    return {repeating, missing};
                }
            }
        }

        repeating = bucket2;//ELSE case
        missing = bucket1;

        return {repeating, missing};
    }

};