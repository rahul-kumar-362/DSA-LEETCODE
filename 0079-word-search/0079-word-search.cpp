class Solution {
public:

//BUS THODA DUR...

    bool solve(int i, int j, int k,
               vector<vector<char>>& board,
               string& word) {

        int m = board.size();
        int n = board[0].size();

        // Out of bounds
        if(i < 0 || i >= m || j < 0 || j >= n)
            return false;

        // Character mismatch
        if(board[i][j] != word[k])
            return false;

        // Entire word found
        if(k == word.size() - 1)
            return true;

        // Mark visited
        char temp = board[i][j];
        board[i][j] = '#';

        bool found =
            solve(i + 1, j, k + 1, board, word) ||
            solve(i - 1, j, k + 1, board, word) ||
            solve(i, j + 1, k + 1, board, word) ||
            solve(i, j - 1, k + 1, board, word);

        // Backtrack (undo)
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == word[0]) {
                    if(solve(i, j, 0, board, word))
                        return true;
                }
            }
        }

        return false;
    }
};