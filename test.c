#include"game.h"

void menu()
{
	printf("*********************\n");
	printf("****   1.play    ****\n");
	printf("****   0.exit    ****\n");
	printf("*********************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//存放布置好的雷的信息
	char show[ROWS][COLS] = { 0 };//存放排查出的雷的信息
	//初始化数组的内容为指定的内容
	
	//mine数组在没有布置雷的时候，都是'0'
	InitBoard(mine,ROWS,COLS,'0');
	
	//show数组在没有排查雷的时候，都是'*'
	InitBoard(show,ROWS,COLS,'*');

	//设置雷
	SetMine(mine, ROW, COL);

	//打印mine数组
	DisplayBoard(mine, ROW, COL);

	//打印show数组
	DisplayBoard(show, ROW, COL);

	//排查雷
	FineMine(mine,show,ROW,COL);

}

int main()
{
	int input = 0;
	//设置随机数的生成起点
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入(1/0):");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}
