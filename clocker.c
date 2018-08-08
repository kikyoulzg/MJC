#include <time.h>
#include <stdio.h>

int sleep(unsigned long x)
{
    clock_t c1=clock(),c2;//clock()记录时钟数

    do{
        if((c2=clock())==(clock_t)-1)
            return 0;
    }while ((c2-c1)/CLOCKS_PER_SEC<x);//CLOCKS_PER_SEC是每秒的时钟数
    return 1;
}

//duqu yonghu de shizhongshu
//daojishi
//tixing,bin xianshi shichang
int main()
{
    int i,x,y,z,xyz;
    clock_t start,end;
    
printf("请输入时钟数(如：00 00 10):\n");
scanf("%02d %02d %02d",&x,&y,&z);
xyz=(x*60+y)*60+z;
start=clock();
for(i=xyz;i>0;i--){
        printf("\r%2d ",i );
        fflush(stdout);
        sleep(1);
    }

printf("\r\a请休息，亲爱的master～\n");

 end=clock();
    z=(end-start)/CLOCKS_PER_SEC;
    if(z>=60)
        y=z/60;
    else {
        y=0;
    }
    if(y>=60)
        x=y/60;
    else {
        x=0;
    }
    printf("所用时长：%02d时%02d分%02d秒。\n",x,y%60,z%60 );
    return 0;
}





