/*可以说明++n和n++的不同*/
#include<stdio.h>
#define sqr(x) ((x)*(x))
int main(){
    int n;
    scanf("%d",&n);
    printf("%d \n",sqr(++n));
    return 0;
}
    
