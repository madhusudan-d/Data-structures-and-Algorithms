#include<stdio.h>

#define N 8


int count=0;

int isSafe(int board[N][N],int row,int col){
    int i,j;
    //check rows
    for(i=0;i<N;i++){
        if(board[i][col]==1)
            return 0;
    }
    //check columns
    for(i=0;i<N;i++){
        if(board[row][i]==1)
            return 0;
    }
    //check left upper diagonal
    i=row;
    j=col;
    while(i>=0 && j>=0){
        if(board[i][j]==1)
            return 0;
        i--;
        j--;
    }
    //check right lower diagonal
    i=row;
    j=col;
    while(i<N && j<N){
        if(board[i][j]==1)
            return 0;
        i++;
        j++;
    }
    //check right upper diagonal
    i=row;
    j=col;
    while(i>=0 && j<N){
        if(board[i][j]==1)
            return 0;
        i--;
        j++;
    }
    //check right upper diagonal
    i=row;
    j=col;
    while(i<N && j>=0){
        if(board[i][j]==1)
            return 0;
        i++;
        j--;
    }


    return 1;

}

int solve(int board[N][N],int col){
    int i;
    if(col>=N){
        count++;
        printBoard(board);
        //return 1;
    }
    for(i=0;i<N;i++){
        if (isSafe(board,i,col)){
           board[i][col]=1;
           if(solve(board,col+1))
                return 1;
           board[i][col]=0;
           //return 0;
        }
    }
    return 0;
}

printBoard(int board[N][N]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d  ",board[i][j]);
        }
        printf("\n\n");
    }
    printf("\n\n");
}

main(){
    int board[N][N],i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            board[i][j]=0;

    solve(board,0);
    //printBoard(board);

    printf("number of possible solution is %d\n" ,count );
}
