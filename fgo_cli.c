#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
static int i;
//等待x毫秒
int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;

	do {
		if ((c2 = clock()) == (clock_t)-1)    /* 错误 */
			return 0;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x); //CLOCKS_PER_SEC每秒的时钟数
	return 1;
}

int wait()
{
	int  i;
	int q=0;
	char name[] = "咻～咻～咻～";			/* 要显示的字符串 */
	int  name_len = strlen(name);			/* 字符串name的字符数 */

	while (q!=1) {		
		for (i = 0; i < name_len; i++) {	/* 从开头开始逐个显示字符 */
			putchar(name[i]);
			fflush(stdout);
			sleep(200);
		}
		for (i = 0; i < name_len; i++) {	/* 从末尾开始逐个消去字符 */
			printf("\b \b");
			fflush(stdout);
			sleep(100);
		}q=1;
	}
	return 1;
}

int summon(){
   int rand_num;
  srand(time(NULL));
  rand_num = rand()%10;
  if(rand_num>=0 && rand_num<=4 ){
    printf(" R\n");
  }else if(rand_num>=5 && rand_num<=7)
      printf("SR\n");
  else{ printf("SSR\n");
    i++;
  }
  return 1;
  }
  

int main(){
  int n;
  printf("请输入要召唤的次数，master！\n");
  scanf("%d",&n);
  for(n;n>0;n--){
    wait();
    summon();
  }
   printf("一共抽到%d次SSR\n",i);
   return 0;
}
