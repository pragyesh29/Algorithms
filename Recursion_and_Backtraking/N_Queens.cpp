#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, vector<string> &board){
    int xi = i, xj = j;
    while(xj >= 0){
        if(board[xi][xj] == 'Q') return false;
        xj--;
    }

    xi = i; xj = j;
    while(xi >= 0 && xj >= 0){
        if(board[xi][xj] == 'Q') return false;
        xi--; xj--;
    }

    xi=i; xj=j;
    while(xi < board.size() && xj >= 0){
        if(board[xi][xj]) return false;
        xi++; xj--;
    }

    return true;
}

void solve(int col, int n, vector<string> &board, vector<vector<string>> &res){
    // If col becomes equal to n means we have a valid set of queens at board
    if(col == n){
        res.push_back(board);
        return;
    }

    // Find the valid position of the queen at column 'col'
    for(int i = 0; i < n; i++){
        if(board[i][col] != 'Q' && isSafe(i, col, board)){
            board[i][col] = 'Q';
            solve(col+1, n, board, res);
            board[i][col] = '.';
        }
    }
}

int main(){
    int n; cin >> n;

    // Initialize the result which will store the state of board with different valid positions of n queens
    vector<vector<string>> res;
    string s(n, '.');
    // Initialize the empty board
    vector<string> board(n, s);

    solve(0, n, board, res);

    for(auto i: res){
        for(string j : i){
            cout << j << "\n";
        }
        cout << '\n';
    }

    return 0;
}