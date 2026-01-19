#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        // If all characters matched, return true
        if (idx == word.size()) return true;

        // Check boundaries and character match
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx]) {
            return false;
        }

        // Store current character and mark as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore all four directions
        bool found = dfs(board, word, i + 1, j, idx + 1) ||
                     dfs(board, word, i - 1, j, idx + 1) ||
                     dfs(board, word, i, j + 1, idx + 1) ||
                     dfs(board, word, i, j - 1, idx + 1);

        // Restore the character (backtracking)
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

int main(){
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

cout<<exist(board, "ABCCED")<<endl;
cout<<exist(board, "SEE")<<endl;
cout<<exist(board, "ABCD")<<endl;
return 0;
}