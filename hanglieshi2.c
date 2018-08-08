#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>             /*头文件*/
#include <stdbool.h>
                                  
int * c,                       
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
bool sa(int * l)            /*sa计算在行列式计算过程中每一项前边的符号是正还是负*/
{
    int n = 0;
    for(int i = 0; i < a-1; i ++)
         for(int j = i+1; j < a; j++)
               if(l[i]>l[j])n++;
    if(n % 2 == 0) return false;
    return true;
}
void perm(int * l,int k,int m)          /*perm整个程序里边的核心函数，找出在不同行不同列的所有组合*/
{
    int i, s = 1;
    if(k > m)
    {
        n++; 
        for(int j = 0; j < a; j ++)
              s *= c[ l[ j ] + a * j ];
        if( sa( l ) ) s*=-1;
      
        printf("%5d      完成度：%2.2f%%\n", sum+=s , n/( aq( a ) * 0.1 ) * 10 );
    }
    else  
    {
        for(i = k; i <= m; i++)
        {
            swap(l + k, l + i);
            perm(l, k + 1, m);
            swap(l + k, l + i);
        }
    }
}
/*---------------------------------------------------------------*/
void main()
{
    int * b,
    i, 
    f, 
    e;
    system("color 3e");
u: system("cls");
    printf("请输入行列式的阶数：\n");
    scanf("%d", &a);//获取行列式的阶数
    b = ( int * ) malloc ( sizeof ( int ) * a );            /*malloc*/
    c = ( int * ) malloc ( sizeof ( int ) * a * a );
    for( i = 0; i < a; i++){
         * ( b + i ) = i;
     printf("hallo\n") ;    
    }
    for( i = 0; i < a * a; i++)
    {
        if( i % a == 0 ){
            printf("请依次输入行列式中第%d行的值（以空格分隔）：\n",i / a + 1 );
        }
            
        scanf("%d", c+i );
        printf("%d | ,%d | ,%d\n",i,c[i],b[i] ); 
        
    }
    
    printf("\n\n");
    perm( b, 0, a - 1 );            /*计算行列式的值*/
    printf("\n行列式展开式共有%d项\n", aq( a ) );
    if ( a % 2 != 0 ) f = a + 1;
        else f = a;
    for( i = 0; i < a * a; i ++ )
    {       
        if ( i / a + 1 == f / 2 && i % a == 0) 
            printf("D = ");//输出“D = ”
        else if ( i % a == 0) 
                    printf("    ");
        if ( i % a == 0) 
            printf("┃");
        if ( ( i + 1 ) % a == 0) 
            printf("%2d", * ( c + i ) );
        else printf("%2d ", * ( c + i ) );
        if ( ( i + 1 ) % a == 0 ) 
            printf("┃");
        if ( ( i + 1 ) / a == f / 2 && ( i + 1 ) % a == 0) 
            printf(" = %d\n",sum);
        else if ( ( i + 1 ) % a == 0 ) 
                    printf("\n");
    }
    printf("%d",n);
    printf("\n\n");
    printf("是否继续？（ 1 / 0 ）\n");
    scanf("%d", &e);
    n = 0;
    if( e ==1 ) goto u;
    else if ( e == 0 ) exit( 0 );
}
