#include<stdio.h>
#include <stdbool.h>
int n = 5;
int count = 0; //For getting all possible Nqueens permutation count

void printArray(char chessboard[][n], int n){ //For Printing Array
    for(int i = 0; i < n; i++){
        for(int j = 0; j <n; j++){
            printf("%c ",chessboard[i][j]);
        }
        printf("\n");
    }
}

bool issafe(char chessboard[][n],int row,int col){ // Checking that queens are safe or not.
    for(int i = row -1; i>=0;i--){ // vertical up
        if(chessboard[i][col] == 'Q'){
            return false;
        }
    }

    for(int i = row -1 , j = col -1; i>=0 && j>=0; i--,j--){ //Vertical lef up
        if(chessboard[i][j] == 'Q'){
            return false;
        }
    }

    for(row-1 , col+1; row >=0 && col <n; row--, col++){ //Vertical right up
        if(chessboard[row][col] == 'Q'){
            return false;
        }
    }

    return true; // Queen is safe from other Queen.
}

void nQueens(char chessboard[][n], int row,int n){  // Total possible ways
    if(row == n){
        printf("------ Chessboard ------\n");
        printArray(chessboard,n);
        count++;
        return;
    }
    
    
    for(int j = 0 ; j < n ; j++){
            if(issafe(chessboard,row, j)){
            chessboard[row][j] = 'Q';
            nQueens(chessboard, row+1,n); //Recursive call
            chessboard[row][j] = 'X'; //Backtracking
        }
    }
}

bool one_soln_nQueen(char chessboard[][n], int row,int n){ // Only one possible soln.
    if(row == n){
        return true;
    }
    
    for(int j = 0 ; j < n ; j++){
            if(issafe(chessboard,row, j)){
            chessboard[row][j] = 'Q';
            if(one_soln_nQueen(chessboard, row+1,n)){
                return true;
            }; //Recursive call
            chessboard[row][j] = 'X'; //Backtracking
        }
    }
    return false;
}

void main(){
    char chessboard [n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j <n; j++){
            chessboard[i][j] = 'X';
        }
    }
    // printArray(chessboard, n);

    nQueens(chessboard, 0,n);
    printf("Total number of Possible ways : %d\n", count);
    if(one_soln_nQueen(chessboard,0,n)){
        printf("Solution is Possible.\nOne solution among them is given below...\n");
        printArray(chessboard,n);
    }else {
        printf("Solution is not Possible.\n");
    }
}