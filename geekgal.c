#include <stdio.h>
//显示文字的逻辑处理
//选项liuchengkongzhi
//跳到下一个选项tiaojianyuju
//回忆
//存读档wenjianchuli

//*音乐
//*图像
//P:zhijie shuchu ,R:duqudao kongge huozhe huiche shuchu
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>

char get1char(void)
{
  
    struct termios stored_settings;
    struct termios new_settings;
    tcgetattr (0, &stored_settings);
    new_settings = stored_settings;
    new_settings.c_lflag &= (~ICANON);
    new_settings.c_cc[VTIME] = 0;
       new_settings.c_cc[VMIN] = 1;
    tcsetattr (0, TCSANOW, &new_settings);
    char c;
    c = getchar();
    //printf("\b ");
    tcsetattr (0, TCSANOW, &stored_settings);
    return c;
}

int p(const char *s )
{
    printf("%s",s);
    fflush(stdout);
    return 0;
}

int sleep(unsigned long x)
{
    clock_t c1 = clock(),c2;

    do{
        if((c2=clock())==(clock_t)-1)

            return 0;
    }while ( (c2-c1)/CLOCKS_PER_SEC<x);
    return 1;
}

int stop()
{
      while (get1char() != ' ' ){
         char p[] = "/\r-\r\\\r-\r";
         int s = strlen(p);
         int i;
         for(i=0;i<s;i++){
            putchar(p[i]);
            fflush(stdout);
            sleep(1);
    }
      return 0;
}
}



int main()
{
    p("只有蝉鸣陪伴的炎热夏天，由于睡了太久而变得昏昏沉沉的脑袋好像不属于自己\n");
    stop();
    p("知了~");sleep(1);p("知了~");sleep(1);p("知了~\n");
    stop();
    
    return 0;
        }
