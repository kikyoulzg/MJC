#include <time.h>
#include <stdio.h>
#include <string.h>

int sleep(unsigned long x)
{
    clock_t c1 = clock(),c2;

    do{
        if((c2=clock())==(clock_t)-1)

            return 0;
    }while ( (c2-c1)/CLOCKS_PER_SEC<x);
    return 1;
}

void bput(const char *s, int d, int e, int n )
{
    int x;
    int name_len=strlen(s);
    for (x=0;x<n;x++)
    {
        printf("\r%s",s );
        fflush(stdout);
        sleep(d);
        printf("\r%*s",name_len,"");
        fflush(stdout);
        sleep(e);
    }
    putchar('\n');
}

    int main()
    {
        char *S;
        int D,E,N;
        printf("请输入字符串：\n");
        scanf("%[^\n]s",S);
        printf("请输入参数（格式： 显示秒数 消失秒数 重复次数）\n"); 
        scanf("%d %d %d",&D,&E,&N);
        bput(S,D,E,N);
        return 0;
    }
