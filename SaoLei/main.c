#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//开始菜单
void menu()
{
	system("cls");
	printf("***************************\n");
	printf("***************************\n");
	printf("**********扫雷传奇*********\n");
	printf("***************************\n");
	printf("***************************\n");
	printf("**********请选择：*********\n");
	printf("1：开始游戏\n");
	printf("2：游戏设置\n");
	printf("3：退出游戏\n");
}
//游戏设置
void game_set(int* num_mine_p,int* size_x_p,int* size_y_p )
{
	char slect;
	system("cls");
	printf("***************************\n");
	printf("***************************\n");
	printf("当前地雷数量为%d\n", *num_mine_p);
	printf("当前游戏大小长为%d\n", *size_x_p);
	printf("当前游戏大小宽为%d\n", *size_y_p);
	printf("***************************\n");
	printf("**********请设置：*********\n");
	printf("新的地雷数量为：\n");
	scanf_s("%d", num_mine_p);
	printf("新的游戏大小长为：\n");
	scanf_s("%d", size_x_p);
	printf("新的游戏大小宽为：\n");
	scanf_s("%d", size_y_p);
	printf("***************************\n");
	printf("***************************\n");
	printf("配置保存成功！输入任意值返回开始菜单\n");
	slect = getchar();
	slect = getchar();


}
//生成随机数
float rand_num(int rand_fact)
{
	float num=0;
	int temp ;
	srand(time(NULL) +rand_fact);

	for (int i = 0; i < 3; i++)
	{
		temp = rand();
		num =num*10+ ((rand()) % 10);
		
	}
	return num;
}
	
//游戏界面
void game_interface(char* map, int* num_mine_p, int* size_x_p, int* size_y_p,int size)
{	
	int i, j, num = 0;
	printf("***************************\n");
	printf("***************************\n");
	//打印横轴坐标
	printf("   ");
	for (i = 0; i < *size_x_p; i++)
	{
		if (i >= 9)
		{
			printf("%d ", i + 1);
		}
		else
			printf("%d  ", i + 1);
	}
	printf("\n");
	for (j = 0; j < *size_y_p; j++)
	{
		//打印纵轴坐标
		if (j >= 9)
		{
			printf("%d ", j+ 1);
		}
		else
			printf("%d  ", j + 1);
		for (i = 0; i < *size_x_p; i++)
		{
			printf("%c  ", map[num]);
			num++;
		}
		printf("\n");
	}
}

//开始游戏
void start_game(int* num_mine_p, int* size_x_p, int* size_y_p)
{
	system("cls");
	char map[900];
	int i;
	int rand_fact=0;
	float rand_port;
	int rand_arr_cord =0;
	int size = ((*size_x_p) * (*size_y_p));
	int x_cord, y_cord;
	char map_ui[900];

	//初始化游戏
	for (i = 0; i <size ; i++)
	{
		map[i] = 'O';
	}
	for (i = 0; i < *num_mine_p; )
	{	
		//两个整数型相除最后得到的也是整数，所以这里将rand_num返回的为浮点数
		//这里没想到更好的办法，只能不断的往里面穿新的数字，来保证输出的是随机不一样的数字
		rand_fact = rand_fact+rand_arr_cord;
		rand_port=  (rand_num(rand_fact)/1000);
		rand_arr_cord = rand_port*(size-1);
		if (map[rand_arr_cord] == 'O')
		{
			printf("%d\n", rand_arr_cord);
			map[rand_arr_cord] = 'X';
			i++;
		}
	}
	game_interface(map,num_mine_p, size_x_p, size_y_p,size);
	scanf_s("%d%d", &x_cord, &y_cord);
}
int main()
{
	int set_opt;
	int num_mine=10;
	int size_x=10;
	int size_y=10;
	//开始菜单
start:
	menu();
	scanf_s("%d", &set_opt);
	switch (set_opt)
	{
	case 1:
		//进入游戏
		start_game(&num_mine, &size_x, &size_y);
		goto start;

	case 2:
		//设置
		game_set(&num_mine,&size_x,&size_y);
		goto start;
	case 3:
		//退出游戏
	default:
		break;
	}

	//进入游戏
	//设置
	//退出游戏
}