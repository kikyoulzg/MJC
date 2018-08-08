//珠玑妙算
//chu ti ;shuru; jiancha youxiaoxin; panduan


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//chuti
void noreno(int x[])
{
    int i,j,val;
    
    for (i = 0; i < 4; i++) {
        do{
            srand(time(NULL));
            val=rand()%10;
            for(j=0;j<i;j++)
                if(val==x[j])
                    break;
        }while(j<i);
        
        x[i]=val;
        
    }
}


//shuru
//void shuru()
//{
//  char s[];
//  int i;
//  printf("qingshuru:\n");
//  for(i=0;i<4;i++)
//      scanf("%s",&s)
//            }
//youxiao,shifouyou4ge,shifoudoushishuzi,nore
int youxiao(const char s[])
{
    int i,j;
    if(strlen(s)!=4)
        return 1;
    for (i=0;i<4;i++){
        if (!isdigit(s[i]))
            return 2;
    for(j=0;j<i;j++)
        if(s[i]==s[j])
            return 3;
    }
    return 0;
}

//panduan
int panduan(const int x[],const char s[],int *hit,int *blow)
{
    int i,j;
    *hit=*blow=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(s[i]==x[j]+'0'){
            if(i==j)
                (*hit)++;
            else(*blow)++;
            }
        }
    }
}   
//hit=4,binggo
void jieguo(int Hit,int HB  ){
    if (Hit==4)
        printf("binggo!\n");
    else
        printf("have %d  answer number\n but just have %d right location\n",HB,Hit );
   }


int main()
{
    int i,o;
    int no[4];
    int chk;
    int hit;
    int blow;
    char buff[10];
    clock_t start,end;
    srand(time(NULL));				/* 设定随机数种子 */

	puts("■ 来玩珠玑妙算吧。");
	puts("■ 请猜4个数字。");
	puts("■ 其中不包含相同数字。");
	puts("■ 请像4307这样连续输入数字。");
	puts("■ 不能输入空格字符。\n");

    printf("loading....\n");

    
miao:     
    noreno(no);
     for(i=0;i<4;i++){
      printf("%d",no[i] );
    }
     printf("\n");
     
    start=clock();

    
    do {
        do{
            printf("please input:\n");
            scanf("%s",buff);

            chk=youxiao(buff);

            switch (chk){
            case 1: puts("please surely input 4 number");break;
            case 2: puts("don't input other char except number");break;
            case 3: puts("don't input similar number");break;
            }
        }while (chk != 0);

        panduan(no,buff,&hit,&blow);
        jieguo(hit,hit+blow);
        
    }while (hit<4);

    end=clock();

    printf("you use %.1f second\n",(double)(end-start)/CLOCKS_PER_SEC);
    printf("play again?\n no(0),yes(1):\n");
    scanf("%d",&o);

    if(o==1){
    goto miao;
    }    

    return 0;
}
    
