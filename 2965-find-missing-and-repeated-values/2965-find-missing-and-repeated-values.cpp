class Solution {
public:
    // General solution

    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int repeating = -1;
        int missing = -1;

        int n = grid[0].size();
        int m = grid.size();
        int N = m * n;

        // Expected Sum
        long long Sn = 1LL * N * (N + 1) / 2;

        // Actual Sum from Grid
        long long S = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                S += grid[i][j];
            }
        }

        // Expected Sum of Squares
        long long Sn2 = 1LL * N * (N + 1) * (2 * N + 1) / 6;

        // Actual Sum of Squares from Grid
        long long S2 = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                S2 += 1LL * grid[i][j] * grid[i][j];
            }
        }

        // (X - Y) = Repeating - Missing
        long long temp = S - Sn;

        // Getting X² - Y²
        long long val = S2 - Sn2;

        // Hence X + Y
        long long ans = val / temp;

        // Solving the two equations
        repeating = (temp + ans) / 2;
        missing = repeating - temp;

        return {repeating, missing};
    }
};