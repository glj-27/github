/*
1.ʵ������
2.����
3.�ж�ʤ����ƽ�֡�
*/
 
#include<iostream>
#include<stdlib.h> 
using namespace std;
char chessboard[9];//����ȫ������ 
void init();
void input();
void cls();
int winorflase();
int main()
{//���� 
	cout << "0  " << "1  " << "2  " << endl;
	cout << "3  " << "4  " << "5  " << endl;
	cout << "6  " << "7  " << "8  " << endl;
	cout << "������������0-8�����λ�����ϣ�A-o,B-x,������~��ʼ" << endl;
 
	//��ʼ������Ϊ1	
	for (int i = 0; i<9; i++)
	{
		chessboard[i] = '*';
	}
	init();
	input();//���˶��� 
	winorflase();//�ж�ʤ����ƽ�� 
 
}
 
//��ʼ�����̵ĺ��� 
void init()
{
	char chessboard[9];
	for (int i = 0; i<9; i++)
	{
		chessboard[i] = '*';
	}
	for (int i = 0; i<9; i++)
	{
 
		cout << "  " << chessboard[i];
		if (i == 2 || i == 5 || i == 8)
		{
			cout << endl;
		}
	}
}
 
 
void cls()
{
	system("cls");
}
 
//������ĵ�λ�õĺ��� 
void input()
{
	for (int i = 0; i<9; i++)
	{
 
		if (i % 2 == 0)
		{
		lop:
			cout << "turn to A:";
			int x;
			cin >> x;
			
			if (chessboard[x] != '*')
			{
				cout << "error,can't do it\n";
				goto lop;
			}
			switch (x)
			{
			case 0:chessboard[0] = 'o'; break;
			case 1:chessboard[1] = 'o'; break;
			case 2:chessboard[2] = 'o'; break;
			case 3:chessboard[3] = 'o'; break;
			case 4:chessboard[4] = 'o'; break;
			case 5:chessboard[5] = 'o'; break;
			case 6:chessboard[6] = 'o'; break;
			case 7:chessboard[7] = 'o'; break;
			case 8:chessboard[8] = 'o'; break;
			default:cout << "Error,you input out!\n"; break;
			}
 
			cls();
			for (int i = 0; i<9; i++)
			{
 
				cout << "  " << chessboard[i];
				if (i == 2 || i == 5 || i == 8)
				{
					cout << endl;
				}
			}
		}
 
 
 
 
		if (i % 2 != 0)
		{
		loop:
			cout << "turn to B:";
			int y;
			cin >> y;
			//cout<<chessboard[y]<<"\n";
			if (chessboard[y] != '*')
			{
				cout << "error,can't do it\n";
				goto loop;
			}
			switch (y)
			{
			case 0:chessboard[0] = 'x'; break;
			case 1:chessboard[1] = 'x'; break;
			case 2:chessboard[2] = 'x'; break;
			case 3:chessboard[3] = 'x'; break;
			case 4:chessboard[4] = 'x'; break;
			case 5:chessboard[5] = 'x'; break;
			case 6:chessboard[6] = 'x'; break;
			case 7:chessboard[7] = 'x'; break;
			case 8:chessboard[8] = 'x'; break;
			default:cout << "Error,you input out!\n"; break;
			}
			cls();
			for (int i = 0; i<9; i++)
			{
 
				cout << "  " << chessboard[i];
				if (i == 2 || i == 5 || i == 8)
				{
					cout << endl;
				}
			}
		}
		if (i >= 9)
		{
			cout << "ƽ�֣�����һ�ְ�";
			getchar();
			break;
		}
		int b;
		b = winorflase();
		if (b == 0)
		{
			break;
		}
	}
 
}
 
 
//�ж�ʤ���ĺ��� 
int winorflase()
{
	if (chessboard[0] == 'o' && chessboard[4] == 'o' && chessboard[8] == 'o')
	{
		printf("A win");
		getchar();
		return 0;
 
	}
	if (chessboard[2] == 'o' && chessboard[4] == 'o' && chessboard[6] == 'o')
	{
		printf("A win");
		getchar();
		return 0;
	}
	if (chessboard[0] == 'o' && chessboard[1] == 'o' && chessboard[2] == 'o')
	{
		printf("A win");
		getchar();
		return 0;
	}
 
	if (chessboard[3] == 'o' && chessboard[4] == 'o' && chessboard[5] == 'o')
	{
		printf("A win");
		getchar();
		return 0;
	}
 
	if (chessboard[6] == 'o' && chessboard[7] == 'o' && chessboard[8] == 'o')
	{
		printf("A win");
		getchar();
		return 0;
	}
 
	if (chessboard[0] == 'o' && chessboard[3] == 'o' && chessboard[6] == 'o')
	{
		printf("A win");
		getchar();
		return 0;
	}
 
	if (chessboard[1] == 'o' && chessboard[4] == 'o' && chessboard[7] == 'o')
	{
		printf("A win");
		getchar();
		return 0;
	}
 
 
	if (chessboard[2] == 'o' && chessboard[5] == 'o' && chessboard[8] == 'o')
	{
		printf("A win");
		getchar();
		return 0;
	}
 
 
	if (chessboard[0] == 'x' && chessboard[4] == 'x' && chessboard[8] == 'x')
	{
		printf("B win");
		getchar();
		return 0;
	}
	if (chessboard[2] == 'x' && chessboard[4] == 'x' && chessboard[6] == 'x')
	{
		printf("B win");
		getchar();
		return 0;
	}
	if (chessboard[0] == 'x' && chessboard[1] == 'x' && chessboard[2] == 'x')
	{
		printf("B win");
		getchar();
		return 0;
	}
 
	if (chessboard[3] == 'x' && chessboard[4] == 'x' && chessboard[5] == 'x')
	{
		printf("B win");
		getchar();
		return 0;
	}
 
	if (chessboard[6] == 'x' && chessboard[7] == 'x' && chessboard[8] == 'x')
	{
		printf("B win");
		getchar();
		return 0;
	}
 
	if (chessboard[0] == 'x' && chessboard[3] == 'x' && chessboard[6] == 'x')
	{
		printf("B win");
		getchar();
		return 0;
	}
 
	if (chessboard[1] == 'x' && chessboard[4] == 'x' && chessboard[7] == 'x')
	{
		printf("B win");
		getchar();
		return 0;
	}
 
 
	if (chessboard[2] == 'x' && chessboard[5] == 'x' && chessboard[8] == 'x')
	{
		printf("B win");
		getchar();
		return 0;
	}
 
 
 
 
 
 
}
 

