#include<stdio.h>

#define M 5
#define N 5



countIslands(int matrix [M][N]){
    int visited[M][N];
    int count=0;
    int i,j;
    for(i=0;i<M;i++)
        for(j=0;j<N;j++)
        visited[i][j]=0;

    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            if(!visited[i][j] && matrix[i][j]){
                dfs(matrix,visited,i,j);
                count++;
            }

        }
    }
    printf("Number of islands : %d \n ",count);

}

dfs(int matrix[M][N],int visited[M][N],int row,int col){
    int rowNum[8]={-1, -1, -1,  0, 0,  1, 1, 1};
    int colNum[8]={-1,  0,  1, -1, 1, -1, 0, 1};
    int i;
    visited[row][col]=1;
    for(i=0;i<8;i++){
        if(isSafe(matrix,visited,row+rowNum[i],col+colNum[i])){
            dfs(matrix,visited,row+rowNum[i],col+colNum[i]);
        }

    }
    return;
}
int isSafe(int matrix[M][N],int visited[M][N],int row,int col){
    if(!visited[row][col] && matrix[row][col] && row<M && col<N && row>=0 && col>=0)
        return 1;
    return 0;
}


main(){
    int matrix[M][N]={{1, 1, 0, 1, 0},
                      {0, 1, 0, 1, 0},
                      {1, 1, 0, 0, 0},
                      {0, 0, 0, 0, 0},
                      {1, 0, 1, 0, 1}
                     };

    countIslands(matrix);




}

