//我们首先需要一个棋盘（15 * 15），记录棋盘中每一个位置的“情况”。

//那么我们可以定义一个 chessboard[16][16] 的数组，为什么不是 [15][15] 呢？因为这样我们就可以让数组的坐标正好对应棋盘的行和列，方便后面代码的编写。
//开始编写主函数之前，我们先简单的考虑一下，一个游戏通常的流程是怎么样的 (⊙o⊙?)首 先肯定是进入游戏的一个主界面，然后点击开始按钮进入游戏，接着显示游戏画面，判断输赢，游戏结束。那么一个五子棋游戏的流程呢？
//initGame函数

//在这个函数中，我们要实现的功能是

//  显示一个简单的欢迎界面
//  要求输入Y之后显示出棋盘
//printChessboard 函数

//功能：

//  打印出行号和列号，并打印出棋盘
//  数组元素的值为0，打印出星号（*），表示该位置没有人落子
//  数组元素的值为1，打印实心圆（X，玩家1的棋子）
//  数组元素的值为2，打印空心圆（O，玩家2的棋子）

//playChess 函数

// 函数功能：
//      要求玩家输入准备落子的位置
//  如果当前是玩家1落子，就将1赋值给数组中对应位置的元素
//  如果当前是玩家2落子，就将2赋值给数组中对应位置的元素
//  每次落子完毕，判断当前玩家是否获胜
//judge函数

//函数参数：

//  x：当前落子的行号
//  y：当前落子的列号

//返回值：

//  1或0。1表示当前玩家落子之后出现五子连一线，也就是当前玩家获胜
//棋子 X O

#include <stdio.h>
#include <stdlib.h>

#define N    15

int chessboard[N + 1][N + 1] = { 0 };

//用来记录轮到玩家1还是玩家2
int whoseTurn = 0;

void initGame(void);
void printChessboard(void);
void playChess(void);
int judge(int, int);

int main(void)
{
    //初始化游戏
    initGame();

    while (1)
    {
        //每次循环自增1，实现玩家轮流下子
        whoseTurn++;

        playChess();
    }

    return 0;
}

void initGame(void)
{
    char c;

    printf("欢迎^_^请输入y进入游戏：");
    c = getchar();
    if ('y' != c && 'Y' != c)
        exit(0);

    system("clear");
    printChessboard();
}

void printChessboard(void)
{
    int i, j;

    for (i = 0; i <= N; i++)
    {
        for (j = 0; j <= N; j++)
        {
            if (0 == i)
                printf("%3d", j);
            else if (j == 0)
                printf("%3d", i);
            else if (1 == chessboard[i][j])
                printf("  X");
            else if (2 == chessboard[i][j])
                printf("  O");
            else
                printf("  *");
        }
        printf("\n");
    }
}

void playChess(void)
{
    int i, j, winner;

    if (1 == whoseTurn % 2)
    {
        printf("轮到玩家1，请输入棋子的位置，格式为行号+空格+列号：");
        scanf("%d %d", &i, &j);
        chessboard[i][j] = 1;
    }
    else
    {
        printf("轮到玩家2，请输入棋子的位置，格式为行号+空格+列号：");
        scanf("%d %d", &i, &j);
        chessboard[i][j] = 2;
    }

    system("clear");
    printChessboard();

    if (judge(i, j))
    {
        if (1 == whoseTurn % 2)
            printf("玩家1胜！\n");
        else
            printf("玩家2胜！\n");
    }
}

int judge(int x, int y)
{
    int i, j;
    int t = 2 - whoseTurn % 2;

    for (i = x - 4, j = y; i <= x; i++)
    {
        if (i >= 1 && i <= N - 4 && t == chessboard[i][j] && t == chessboard[i + 1][j] && t == chessboard[i + 2][j] && t == chessboard[i + 3][j] && t == chessboard[i + 4][j])
            return 1;
    }
    for (i = x, j = y - 4; j <= y; j++)
    {
        if (j >= 1 && j <= N - 4 && t == chessboard[i][j] && t == chessboard[i][j + 1] && t == chessboard[i][j + 2] && t == chessboard[i][j + 3] && t == chessboard[i][j + 4])
            return 1;
    }
    for (i = x - 4, j = y - 4; i <= x, j <= y; i++, j++)
    {
        if (i >= 1 && i <= N - 4 && j >= 1 && j <= N - 4 && t == chessboard[i][j] && t == chessboard[i + 1][j + 1] && t == chessboard[i + 2][j + 2] && t == chessboard[i + 3][j + 3] && t == chessboard[i + 4][j + 4])
            return 1;
    }
    for (i = x + 4, j = y - 4; i >= 1, j <= y; i--, j++)
    {
        if (i >= 1 && i <= N - 4 && j >= 1 && j <= N - 4 && t == chessboard[i][j] && t == chessboard[i - 1][j + 1] && t == chessboard[i - 2][j + 2] && t == chessboard[i - 3][j + 3] && t == chessboard[i - 4][j + 4])
            return 1;
    }

    return 0;
}
