#include<stdio.h>

#define N 9

int findUnassignedLocation(int grid[N][N],int *row,int *column){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(grid[i][j]==0){
                *row=i;
                *column=j;
                return 1;
            }
        }
    }
    return 0;
}

int isSafe(int grid[N][N],int row,int column,int n){
    int i,j;

    //check rows
    for(i=0;i<N;i++){
        if(grid[i][column]==n)
            return 0;
    }
    //check columns
    for(i=0;i<N;i++){
        if(grid[row][i]==n)
            return 0;
    }
    //check box
    row=row-row%3;
    column=column-column%3;
    for(i=row;i<row+3;i++){
        for(j=column;j<column+3;j++){
            if(grid[i][j]==n)
                return 0;
        }
    }
    return 1;
}

int solveUsingBacktracking(int grid[N][N]){
    int row,column,i;
    if(!findUnassignedLocation(grid,&row,&column))
        return 1;

    for(i=1;i<=N;i++){
        if(isSafe(grid,row,column,i)){
            grid[row][column]=i;
            if(solveUsingBacktracking(grid))
                return 1;
            grid[row][column]=0;
        }

    }
    return 0;
}

printGrid(int grid[N][N]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
}

main(){
    /*int grid[N][N]={{3, 0, 6, 5, 0, 8, 4, 0, 0},
                    {5, 2, 0, 0, 0, 0, 0, 0, 0},
                    {0, 8, 7, 0, 0, 0, 0, 3, 1},
                    {0, 0, 3, 0, 1, 0, 0, 8, 0},
                    {9, 0, 0, 8, 6, 3, 0, 0, 5},
                    {0, 5, 0, 0, 9, 0, 6, 0, 0},
                    {1, 3, 0, 0, 0, 0, 2, 5, 0},
                    {0, 0, 0, 0, 0, 0, 0, 7, 4},
                    {0, 0, 5, 2, 0, 6, 3, 0, 0}};*/
    int grid[N][N];
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            grid[i][j]=0;

    if(solveUsingBacktracking(grid)){
        printf("Solved grid : \n");
        printGrid(grid);
    }
    else
        printf("solution doesn't exist for given grid\n");
}
