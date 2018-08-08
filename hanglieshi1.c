#include <stdio.h>
#include <stdlib.h>             /*头文件*/
#include <stdbool.h>
#define number 100
#define NUMBER 100
                                  
int   *c,
      n = 0,                  
      a,                         
      sum = 0;             
int aq(int a)           /*aq计算阶乘*/              
{
    int s = 1;
    for(int i = 1; i <= a; i ++)
          s *= i;
    return s;
}
void swap(int * a, int * b)         /*swap利用地址传递交换两个数的值*/
{
    int m =* a;
    * a = * b;
    *b = m;
}
bool sa(int *l)            /*sa计算在行列式计算过程中每一项前边的符号是正还是负*/
{
    int n = 0;
    for(int i = 0; i < a-1; i ++)
         for(int j = i+1; j < a; j++)
               if(l[i]>l[j])n++;
    if(n % 2 == 0) return false;
    return true;
}
void perm(int A [number][NUMBER],int k,int m)          /*perm整个程序里边的核心函数，找出在不同行不同列的所有组合*/
{
    int i, s = 1;
    if(k > m)
    {
        n++; 
        for(int j = 0; j < a; j ++)
              s *= c[ A[ j ] + a * j ];
        if( sa( A ) ) s*=-1;
      
        printf("%5d      完成度：%2.2f%%\n", sum+=s , n/( aq( a ) * 0.1 ) * 10 );
    }
    else  
    {
        for(i = k; i <= m; i++)
        {
            swap(A + k, A + i);
            perm(A, k + 1, m);
            swap(A + k, A + i);
        }
    }
}
/*---------------------------------------------------------------*/
void main()
{static int e,i,j,I,J ,A [number][NUMBER];
u: 

    
    printf("i:") ; scanf("%d",&i);
    printf("j:") ; scanf("%d",&j);
    printf("input:\n");
    for (I=0;I<i;I++){
        for(J=0;J<j;J++)
            scanf("%d",&A[I][J]);
    }
    
    printf("\n\n");
    perm( A[I][J], 0, j - 1 );            /*计算行列式的值*/

            printf(" = %d\n",sum);

    printf("\n\n");
    printf("是否继续？（ 1 / 0 ）\n");
    scanf("%d", &e);
    n = 0;
    if( e ==1 ) goto u;
    else if ( e == 0 ) exit( 0 );
}
