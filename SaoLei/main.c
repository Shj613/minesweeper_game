#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//��ʼ�˵�
void menu()
{
	system("cls");
	printf("***************************\n");
	printf("***************************\n");
	printf("**********ɨ�״���*********\n");
	printf("***************************\n");
	printf("***************************\n");
	printf("**********��ѡ��*********\n");
	printf("1����ʼ��Ϸ\n");
	printf("2����Ϸ����\n");
	printf("3���˳���Ϸ\n");
}
//��Ϸ����
void game_set(int* num_mine_p,int* size_x_p,int* size_y_p )
{
	char slect;
	system("cls");
	printf("***************************\n");
	printf("***************************\n");
	printf("��ǰ��������Ϊ%d\n", *num_mine_p);
	printf("��ǰ��Ϸ��С��Ϊ%d\n", *size_x_p);
	printf("��ǰ��Ϸ��С��Ϊ%d\n", *size_y_p);
	printf("***************************\n");
	printf("**********�����ã�*********\n");
	printf("�µĵ�������Ϊ��\n");
	scanf_s("%d", num_mine_p);
	printf("�µ���Ϸ��С��Ϊ��\n");
	scanf_s("%d", size_x_p);
	printf("�µ���Ϸ��С��Ϊ��\n");
	scanf_s("%d", size_y_p);
	printf("***************************\n");
	printf("***************************\n");
	printf("���ñ���ɹ�����������ֵ���ؿ�ʼ�˵�\n");
	slect = getchar();
	slect = getchar();


}
//���������
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
	
//��Ϸ����
void game_interface(char* map, int* num_mine_p, int* size_x_p, int* size_y_p,int size)
{	
	int i, j, num = 0;
	printf("***************************\n");
	printf("***************************\n");
	//��ӡ��������
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
		//��ӡ��������
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

//��ʼ��Ϸ
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

	//��ʼ����Ϸ
	for (i = 0; i <size ; i++)
	{
		map[i] = 'O';
	}
	for (i = 0; i < *num_mine_p; )
	{	
		//����������������õ���Ҳ���������������ｫrand_num���ص�Ϊ������
		//����û�뵽���õİ취��ֻ�ܲ��ϵ������洩�µ����֣�����֤������������һ��������
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
	//��ʼ�˵�
start:
	menu();
	scanf_s("%d", &set_opt);
	switch (set_opt)
	{
	case 1:
		//������Ϸ
		start_game(&num_mine, &size_x, &size_y);
		goto start;

	case 2:
		//����
		game_set(&num_mine,&size_x,&size_y);
		goto start;
	case 3:
		//�˳���Ϸ
	default:
		break;
	}

	//������Ϸ
	//����
	//�˳���Ϸ
}