/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:
A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

Example 2:
Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 
Constraints:
board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.
*/

#include<bits/stdc++.h>
using namespace std;

bool ValidInRow(vector<vector<char>>& board, int i){
    set<char> s;
    for(int k = 0; k < 9; k++){
        if(s.find(board[i][k]) != s.end()){
            return false;
        }
        if(board[i][k] != '.'){
            s.insert(board[i][k]);
        }
    }
    return true;
}

bool ValidInCol(vector<vector<char>>& board, int j){
    set<char> s;
    for(int k = 0; k < 9; k++){
        if(s.find(board[k][j]) != s.end()){
            return false;
        }
        if(board[k][j] != '.'){
            s.insert(board[k][j]);
        }
    }
    return true;
}

bool ValidInBox(vector<vector<char>>& board, int i,int j){
    set<char> s;
    for(int k = 0; k < 3; k++){
        for(int l = 0; l < 3; l++){
            char ch = board[k+i][l+j];
            if(s.find(ch) != s.end()) return false;
            if(board[k+i][l+j] != '.') s.insert(board[k+i][j+l]);
        }
    }
    return true;
}

bool IsValidSudoku(vector<vector<char>>& board) {
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if((ValidInRow(board,i) && ValidInCol(board,j) && ValidInBox(board,i - i % 3,j - j % 3)) == false){
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<vector<char>> board =    {{'5','3','.','.','7','.','.','.','.'}
                                    ,{'6','.','.','1','9','5','.','.','.'}
                                    ,{'.','9','8','.','.','.','.','6','.'}
                                    ,{'8','.','.','.','6','.','.','.','3'}
                                    ,{'4','.','.','8','.','3','.','.','1'}
                                    ,{'7','.','.','.','2','.','.','.','6'}
                                    ,{'.','6','.','.','.','.','2','8','.'}
                                    ,{'.','.','.','4','1','9','.','.','5'}
                                    ,{'.','.','.','.','8','.','.','7','9'}};
    cout<<IsValidSudoku(board);
    return 0;
}