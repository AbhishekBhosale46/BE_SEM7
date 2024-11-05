#include<bits/stdc++.h>
using namespace std;

// Check if placing queen at given row col is safe
bool isSafe(int row, int col, vector<vector<char>> board){

    // horizontal
    for(int i=0; i<board.size(); i++){
        if(board[row][i]=='Q'){
            return false;
        }
    }

    // vertical
    for(int i=0; i<board.size(); i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }

    // upper left
    int r=row;
    for(int c=col; c>=0 && r>=0; c--, r--){
        if(board[r][c]=='Q'){
            return false;
        }
    }

    // upper right
    r=row;
    for(int c=col; c<board.size() && r>=0; c++, r--){
        if(board[r][c]=='Q'){
            return false;
        }
    }

    // lower left
    r=row;
    for(int c=col; c>=0 && r<board.size(); c--, r++){
        if(board[r][c]=='Q'){
            return false;
        }
    }

    // lower right
    r=row;
    for(int c=col; c<board.size() && r<board.size(); c++, r++){
        if(board[r][c]=='Q'){
            return false;
        }
    }

    return true;
}


void solve(int col, vector<vector<char>> &board, vector<vector<string>> &allBoards){

    // If all columns are filled, then its a safe board and add it to list of allBoards
    if(col==board.size()){
        vector<string> b;
        for(auto r: board){
            string s = "";
            for(auto c: r){
                s += c;
            }
            b.push_back(s);
        }
        allBoards.push_back(b);
        return;
    }

    // Else recursively try placing queen on each row of given column and backtrack
    for(int row=0; row<board.size(); row++){
        if(isSafe(row, col, board)){
            board[row][col] = 'Q';
            solve(col+1, board, allBoards);
            board[row][col] = '.';
        }
    }

}


void solveNqueens(int n){
    vector<vector<char>> board(n, vector<char>(n, '.'));
    vector<vector<string>> allBoards;
    solve(0, board, allBoards);
    for(auto b:allBoards){
        for(auto s:b){
            cout<<s<<endl;
        }
        cout<<endl;
    }
    return;
}

int main(){

    int N;
    cout<<"Enter the size of the board (N): ";
    cin>>N;
    solveNqueens(N);
}