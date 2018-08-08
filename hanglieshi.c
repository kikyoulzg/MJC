#include<stdio.h>
#define number 100
#define NUMBER 100
int main(){
    static int i,j,I,J ,a [number][NUMBER];
    printf("i:") ; scanf("%d",&i);
    printf("j:") ; scanf("%d",&j);
    printf("input:\n");
    for (I=0;I<i;I++){
        for(J=0;J<j;J++)
            scanf("%d",&a[I][J]);
    }
    for (I=0;I<i;I++){
        for(J=0;J<j;J++)
           printf("a[%d][%d]=%d\n",I,J,a[I][J]);
    }
    return 0;
}                       /*读取行列式*/
