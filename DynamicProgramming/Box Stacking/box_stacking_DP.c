#include<stdio.h>

struct Box{
    int h;
    int w;
    int d;
};

int max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}
int min(int a,int b){
    if(a<b)
        return a;
    else
        return b;
}
int area(struct Box box){
    return (box.w*box.d);
}
swap(struct Box *a,struct Box *b){
    struct Box *temp;
    *temp=*a;
    *a=*b;
    *b=*temp;
}

sort(struct Box *box,int n){
    int i,j,max;
    for(i=0;i<n;i++){
        max=i;
        for(j=i;j<n;j++){
            if(area(box[max])<area(box[j]))
              max=j;
        }
        //printf("max :%d \n",max);
        swap(&box[i],&box[max]);

    }
}

maxStackHeightDP(struct Box *box,int n){
    struct Box all[3*n];
    int i,x=0;
    for(i=0;i<n;i++){
        all[x]=box[i];
        x++;
        all[x].h=box[i].w;
        all[x].w=min(box[i].h,box[i].d);
        all[x].d=max(box[i].h,box[i].d);
        x++;

        all[x].h=box[i].d;;
        all[x].w=min(box[i].h,box[i].w);
        all[x].d=max(box[i].h,box[i].w);
        x++;
    }
    //for(i=0;i<3*n;i++)
    //    printf("%d,%d,%d\n ",all[i].h,all[i].w,all[i].d);

    printf("\n");
    n=3*n;
    int max_height[n];

    //Here I have used Bubble Sort(n^2) temporarily for  .Please replace this with Quick sort(nlogn) which takes less time than bubble sort.  
    sort(all,n);
    for(i=0;i<n;i++)
        max_height[i]=all[i].h;

    for(i=0;i<n;i++)
        printf("%d,%d,%d\n",all[i].h,all[i].w,all[i].d);

    int j;
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if((all[j].w>all[i].w) && (all[j].d>all[i].d) && (max_height[i]<max_height[j]+all[i].h)){
                max_height[i]=max_height[j]+all[i].h;
            }

        }
    }

    int max=max_height[0];
    for(i=0;i<n;i++){
        if(max_height[i]>max)
            max=max_height[i];
        printf(" %d ",max_height[i]);
    }

    printf("\n max height of stack is %d \n",max);


}

main(){
    struct Box box[]={{4,6,7},{1,2,3},{4,5,6},{10,12,32}};
    int n=sizeof(box)/sizeof(box[0]);
    maxStackHeightDP(box,n);
}
