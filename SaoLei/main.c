#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void show_in_map_ui(char* map_ui, char* map, int* num_mine_p, int* size_x_p, int* size_y_p, int size, int i);

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
void game_interface(char* map_ui, char* map, int* num_mine_p, int* size_x_p, int* size_y_p,int size)
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
			printf("%c  ", map_ui[num]);
			num++;
		}
		printf("\n");
	}
}

//��Ϸ����
void gameover(int flag)
{
	if (flag == 1)
	{
		printf("�ȵ����ˣ���Ϸ����������\n");
	}
	if (flag == 2)
	{
		printf("��ϲ�㣬�ɹ��ˣ�����\n");
	}

}

void show_in_map_ui(char* map_ui, char* map, int* num_mine_p, int* size_x_p, int* size_y_p, int size,int i)
{
	//�ж����Ͻ�
	if ((i % (*size_x_p) >= 1) && (i >= *size_x_p))
	{
		if (map[i - *size_x_p - 1] != 'X')
		{
			map_ui[i - *size_x_p - 1]=map[i - *size_x_p - 1];
			
		}
		if (map[i - *size_x_p - 1] == '0')
		{
			map_ui[i - *size_x_p - 1] = ' ';
			map[i - *size_x_p - 1] = ' ';
			show_in_map_ui(map_ui, map, num_mine_p, size_x_p, size_y_p, size, (i - *size_x_p - 1));
		}
			
	}
	//�ж�����
	if ((i >= *size_x_p))
	{
		if (map[i - *size_x_p] != 'X')
		{
			map_ui[i - *size_x_p] = map[i - *size_x_p];
		}
		if (map[i - *size_x_p] == '0')
		{
			map[i - *size_x_p] = ' ';
			map_ui[i - *size_x_p] = ' ';
			show_in_map_ui(map_ui, map, num_mine_p, size_x_p, size_y_p, size, (i - *size_x_p));
		}

	}
	//�ж����Ͻ�
	if (((i % (*size_x_p)) < (*size_x_p - 1)) && (i >= *size_x_p))
	{
		if (map[i - *size_x_p + 1] != 'X')
		{
			map_ui[i - *size_x_p + 1] = map[i - *size_x_p + 1];

		}
		if (map[i - *size_x_p + 1] == '0')
		{
			map[i - *size_x_p + 1] = ' ';
			map_ui[i - *size_x_p + 1] = ' ';

			show_in_map_ui(map_ui, map, num_mine_p, size_x_p, size_y_p, size, (i - *size_x_p + 1));
		}

	}
	//�ж����
	if ((i % (*size_x_p) >= 1))
	{
		if (map[i - 1] != 'X')
		{
			map_ui[i - 1] = map[i - 1];

		}
		if (map[i - 1] == '0')
		{
			map[i - 1] = ' ';
			map_ui[i - 1] = ' ';

			show_in_map_ui(map_ui, map, num_mine_p, size_x_p, size_y_p, size, (i - 1));
		}

	}
	//�м�
	if (map[i] != 'X')
	{
		map_ui[i] = map[i];

	}
	if (map[i] == '0')
		map[i] = ' ';
	//�ж��ұ�
	if ((i % (*size_x_p)) < (*size_x_p - 1))
	{
		if (map[i + 1] != 'X')
		{
			map_ui[i + 1] = map[i + 1];

		}
		if (map[i + 1] == '0')
		{
			map[i + 1] = ' ';
			map_ui[i + 1] = ' ';

			show_in_map_ui(map_ui, map, num_mine_p, size_x_p, size_y_p, size, (i + 1));
		}

	}
	//���½�
	if (((i % (*size_x_p) >= 1)) && (i < (size - *size_x_p)))
	{
		if (map[i + *size_x_p - 1] != 'X')
		{
			map_ui[i + *size_x_p - 1] = map[i + *size_x_p - 1];

		}
		if (map[i + *size_x_p - 1] == '0')
		{
			map[i + *size_x_p - 1] = ' ';
			map_ui[i + *size_x_p - 1] = ' ';

			show_in_map_ui(map_ui, map, num_mine_p, size_x_p, size_y_p, size, (i + *size_x_p - 1));
		}

	}
	//����
	if (i < (size - *size_x_p))
	{
		if (map[i + *size_x_p] != 'X')
		{
			map_ui[i + *size_x_p] = map[i + *size_x_p];

		}
		if (map[i + *size_x_p] == '0')
		{
			map[i + *size_x_p] = ' ';
			map_ui[i + *size_x_p] = ' ';

			show_in_map_ui(map_ui, map, num_mine_p, size_x_p, size_y_p, size, (i + *size_x_p));
		}

	}
	//���½�
	if (((i % (*size_x_p)) < (*size_x_p - 1)) && (i < (size - *size_x_p)))
	{
		if (map[i + *size_x_p + 1] != 'X')
		{
			map_ui[i + *size_x_p + 1] = map[i + *size_x_p + 1];

		}
		if (map[i + *size_x_p + 1] == '0')
		{
			map[i + *size_x_p + 1] = ' ';
			map_ui[i + *size_x_p + 1] = ' ';

			show_in_map_ui(map_ui, map, num_mine_p, size_x_p, size_y_p, size, (i + *size_x_p + 1));
		}

	}
}

//��ʼ��Ϸ
void start_game(int* num_mine_p, int* size_x_p, int* size_y_p)
{
	system("cls");
	char map[900];
	//int mine_pose[900];
	int i,j;
	int rand_fact=0;
	float rand_port;
	int rand_arr_cord =0;
	int size = ((*size_x_p) * (*size_y_p));
	int x_cord, y_cord,xy_cord;
	char map_ui[900];
	int win_lose = 0;
	int blank_num;
	char a;

	//��ʼ����Ϸ
	for (i = 0; i <size ; i++)
	{
		map[i] = 'O';
		map_ui[i] = 'O';

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
			//printf("%d\n", rand_arr_cord);
			map[rand_arr_cord] = 'X';
			i++;
		}
	}
	//��˽�������ơ�ÿ��������Χ�м�����
	for (i = 0; i < size; i++)
	{
		j = 0;
		if (map[i] == 'O')
		{
			//�ж����Ͻ�
			if ((i%(*size_x_p)>=1)&&(i>=*size_x_p))
			{
				if (map[i - *size_x_p - 1] == 'X')
				{
					j++;
				}
			}
			//�ж�����
			if ((i >= *size_x_p))
			{
				if (map[i - *size_x_p ] == 'X')
				{
					j++;
				}
			}
			//�ж����Ͻ�
			if (((i % (*size_x_p)) < (*size_x_p-1)) && (i >= *size_x_p))
			{
				if (map[i - *size_x_p + 1] == 'X')
				{
					j++;
				}
			}
			//�ж����
			if ((i % (*size_x_p) >= 1))
			{
				if (map[i  - 1] == 'X')
				{
					j++;
				}
			}
			//�ж��ұ�
			if ((i % (*size_x_p)) < (*size_x_p - 1))
			{
				if (map[i + 1] == 'X')
				{
					j++;
				}
			}
			//���½�
			if (((i % (*size_x_p) >= 1)) && (i <(size- * size_x_p )))
			{
				if (map[i + *size_x_p - 1] == 'X')
				{
					j++;
				}
			}
			//����
			if (i < (size - *size_x_p))
			{
				if (map[i + *size_x_p ] == 'X')
				{
					j++;
				}
			}
			//���½�
			if (((i % (*size_x_p)) < (*size_x_p - 1)) && (i < (size - *size_x_p)))
			{
				if (map[i + *size_x_p + 1] == 'X')
				{
					j++;
				}
			}
			map[i] =j+'0';

		}
	}

	// 
	//��ʾui����
	game_interface(map_ui,map,num_mine_p, size_x_p, size_y_p,size);

	//��������
	while (1)
	{
		blank_num = 0;
		scanf_s("%d%d", &x_cord, &y_cord);
		xy_cord = (*size_x_p * (y_cord-1)) + x_cord - 1;
		//�ȶ������λ���Ƿ�����
		if (map[xy_cord] == 'X')
		{
			win_lose = 1;
			gameover(win_lose);
			break;
		}
		else
		{
			map_ui[xy_cord] = map[xy_cord];
			//��ĳ�������Χȫ����ʾ����
			show_in_map_ui(map_ui, map, num_mine_p, size_x_p, size_y_p, size, xy_cord);
		}
		game_interface(map_ui, map, num_mine_p, size_x_p, size_y_p, size);
		//��������Ϸ���������������
		//�����������Ϸ������ʾ��Ӧ�Ļ���

		//�����Ϸ�Ƿ����
		for (i = 0; i < size; i++)
		{
			if (map_ui[i] == 'O')
				blank_num++;
		}
		if (blank_num == *num_mine_p)
		{
			win_lose = 2;
			gameover(win_lose);
			break;
		}
	}
	printf("�����������");
	scanf_s("%c", &a);
	scanf_s("%c", &a);

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