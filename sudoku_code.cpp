#include<iostream>
using namespace std;

void print(int board[][9], int n){
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            cout<<board[row][col]<<" ";
        }cout<<endl;
    } 
    cout<<endl;
}

bool isSafe(int board[][9], int row, int col, int n, int value) {

        for(int i=0; i<n; i++) {
            //row check
            if(board[row][i] == value)
                return false;
            
            //col check
            if(board[i][col] == value) 
                return false;

            //3*3 box check
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == value) 
                return false;
        }

        return true;
}

bool sudokuSolver(int board[][9], int row, int col, int n){
    //Base case
    if(row == n){
        print(board,n);
        return true;
    }
    //if we are not inside the board
    if(col == n){
        return sudokuSolver(board,row+1,0,n);
    }

    //move ahead if cell is already filled
    if(board[row][col] != 0){
       return sudokuSolver(board,row,col+1,n);
    }
    
    else{
    //Trying to fill the cell with an appropriate number
        for(int value = 1; value <= 9; value++){

            //check if value can be filled
            if(isSafe(board,row,col,n,value)){
                board[row][col] = value;
                bool remainingBoardSolution = sudokuSolver(board,row,col+1,n);
                if(remainingBoardSolution){
                    return true;
                }
                else{
                    //Backtracking -> undo the change
                    board[row][col] = 0;
                }
            }
        }
    }
    return false;
}

int main(){
    int n = 9;
    int board[9][9] = {
        {0, 0, 7, 1, 0, 0, 0, 6, 0},
        {1, 0, 5, 2, 0, 8, 0, 0, 0},
        {6, 0, 0, 0, 0, 7, 1, 2, 0},
        {3, 1, 2, 4, 0, 5, 0, 0, 8},
        {0, 0, 6, 0, 9, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 3, 0, 0, 1},
        {0, 0, 1, 0, 0, 4, 9, 8, 6},
        {8, 0, 3, 9, 0, 6, 0, 0, 0},
        {0, 6, 0, 0, 8, 2, 7, 0, 3}
    };

    sudokuSolver(board, 0, 0, n);

    return 0;
    
}