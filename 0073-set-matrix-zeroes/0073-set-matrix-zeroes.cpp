// // CHANGE 1:
// if(matrix[i][0] == 0) col0 = 0;

// // CHANGE 2:
// Remove:
// if(j!=0){
//     matrix[0][j]=0;
// }
// else col0=0;

// Add:
// matrix[0][j] = 0;

// // CHANGE 3:
// for(int j=1; j<m; j++)   // instead of j=0

// // CHANGE 4:
// Remove:
// if(matrix[i][j]!=0)

// // CHANGE 5:
// Handle first row using matrix[0][0]

// // CHANGE 6:
// Handle first column using col0


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        int col0 = 1;

        for(int i = 0; i < n; i++) {

            // CHANGE 1:
            // Add this line to track whether first column should become zero
            if(matrix[i][0] == 0)
                col0 = 0;

            for(int j = 1; j < m; j++) {

                if(matrix[i][j] == 0) {

                    matrix[i][0] = 0;

                    // CHANGE 2:
                    // Remove this entire if-else block
                    // if(j!=0){
                    //     matrix[0][j]=0;
                    // }
                    // else col0=0;

                    // Replace with this single line
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < n; i++) {

            // CHANGE 3:
            // j should start from 1, not 0
            for(int j = 1; j < m; j++) {

                // CHANGE 4:
                // Remove this outer if
                // if(matrix[i][j] != 0)

                if(matrix[0][j] == 0 || matrix[i][0] == 0) {

                    matrix[i][j] = 0;
                }
            }
        }

        // CHANGE 5:
        // Add this block to handle first row
        if(matrix[0][0] == 0) {

            for(int j = 0; j < m; j++) {

                matrix[0][j] = 0;
            }
        }

        // CHANGE 6:
        // Add this block to handle first column
        if(col0 == 0) {

            for(int i = 0; i < n; i++) {

                matrix[i][0] = 0;
            }
        }
    }
};