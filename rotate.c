#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

int main()
{
    while (1){
        char p[] = "/\r-\r\\\r";
         int s = strlen(p);
         int i;
         for(i=0;i<s;i++){
            putchar(p[i]);
            fflush(stdout);
            sleep(0);
         }
   }
