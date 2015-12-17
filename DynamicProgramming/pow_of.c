#include<stdio.h>
float pow(float x,int y){
    if(y==0)
        return 1;
    else {
        float temp=pow(x,y/2);
        if(y%2==0)
            return temp*temp;
        else {
                if(y>0)
                    return x*temp*temp;
                else
                    return temp*temp/x;
        }

    }
}

main(){
    float n=pow(2,-1);
    printf("answer is : %f\n",n);
}
