#include<bits/stdc++.h>
using namespace std;

// Recursive BFS to find the element in 2-d board array
bool wordSearchBFS(vector<vector<char>> &board, vector<vector<bool>> &visited, int row, int col, string word, int index){
    // BASE CONDITIONS
    // Check for out of bounds
    if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return false;
    // If current board character does not matches the corresponding word character
    if(board[row][col] != word[index]) return false;
    // If already visited or not
    if(visited[row][col]) return false;
    // If all characters of given word is found successively then return true
    if(index == word.size() - 1) return true;

    // Mark this cell as visited in board
    visited[row][col] = true;

    // Check up, down, left and right from current position for next corresponding required character in word
    if(
        wordSearchBFS(board, visited, row - 1, col, word, index + 1) || 
        wordSearchBFS(board, visited, row + 1, col, word, index + 1) || 
        wordSearchBFS(board, visited, row, col - 1, word, index + 1) || 
        wordSearchBFS(board, visited, row, col + 1, word, index + 1)
    ) return true;

    // Backtrack
    visited[row][col] = false;

    return false;
}

// Driver function
int main(){
    vector<vector<char>> board{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word;
    cout << "Enter string to Search on the board in uppercase : ";
    cin >> word;
    int board_rows = board.size(), board_cols = board[0].size();
    vector<vector<bool>> visited(board_rows, vector<bool> (board_cols, false));
    for(int i = 0; i < board_rows; i++){
        for(int j = 0; j < board_cols; j++){
            if(wordSearchBFS(board, visited, i, j, word, 0)){
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}