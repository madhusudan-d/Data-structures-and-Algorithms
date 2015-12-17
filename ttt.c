#include<stdio.h>

char arr[3][3];

printboard(char arr[3][3]){
    int i=0,j=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%c ",arr[i][j]);
        }
        printf("\n");
    }
}

play(){
    int x,y;
    printf("User: please enter x,y value");
    scanf("%d %d",&x,&y);
    printf("entered value is %d ,%d\n",x,y);
    arr[x][y]='O';
    printboard(arr);
    computerplay();
    play();
}

computerplay(){
    for (i=0;i<)
}


main(){

    int i=0,j=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            arr[i][j]='-';
    }
    printf("welcome to tic tac toe game\n");
    printf("empty board\n");
    printboard(arr);
    play();

}
