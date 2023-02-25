#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include <graphics.h>
#include <tchar.h>
const int N = 1000;
char str[N];

typedef struct SingleNode
{
	double coefficient;
	int index;
	struct SingleNode* next;
}SinNode;

//ͷɾ
void SinNodePopFront(SinNode** pphead);
//��������
SinNode* BuySinNode(double coefficient);
//��ȫ����λ
void ComplementedSymBol(char* Data);
//��ȫָ��λ
void ComplementedIndex(char* Data);
//ĳ���ַ��������ַ�������ƶ���λ��
void MoveBack(char* now, int x);
//���ݴ���
SinNode* DataProcessing(char* Data);
//���½��β�嵽Ŀ������
void PushBack(SinNode** pphead, SinNode* newnode);
//����ÿ�����ÿ�����в���ϵ��
void SinNodeCoefficientPush(SinNode** pphead, int flag, char* digit);
//��ȡÿһ�������е�ϵ��������
double GetCoefficient(int flag, char* digit);
//��ÿ�����в���ָ��
void SinNodeIndexPush(SinNode** pphead, int flag, char* digit, int n);
//�ϲ��ظ���
void MergeRepetition(SinNode** pphead);
//ɾ��ĳ��λ��
void SinNodeErase(SinNode** pphead, SinNode* pos);
//����ʽ�ӷ�
void Addition(SinNode* Data_1, SinNode* Data_2);
//����Ӽ�������û��ָͬ����Data_1����½��
void MultPushBack(SinNode** pphead, double coefficient, int index);
//����ʽ����
void Subtraction(SinNode* Data_1, SinNode* Data_2);
//����ָ��������ʽ����
void MultSort(SinNode* phead);
//����ʽ��ӡ
char* SinNodePrint(SinNode* phead,int&cnt);
//�������
double get_distance(double x1, double y1, double x2, double y2);
double Evaluation(SinNode* phead, double x);
// ͳ�Ƶ�����ڵ���
int sizeList(SinNode* pHead)
{
	int size = 0;

	while (pHead != NULL)
	{
		size++;         //��������size��С�������ʵ�ʳ���С1
		pHead = pHead->next;
	}
	return size;    //�����ʵ�ʳ���
}
double get_distance(double x1, double y1, double x2, double y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
void Paint()
{
	//��ʼ��һ��380*600�Ļ���
	initgraph(400, 600);
	// RGB����Ϊ�ϳ���ɫ
	setbkcolor(RGB(40, 40, 40));//���ñ���
	for (int y = 0; y < 30; y++)
	{
		setcolor(RGB(40, 40, 40)); //����������ɫ
		//�������������е�����
		line(0, y, 500, y);
	}
	//����������ɫ
	settextcolor(WHITE);
	//����������
	settextstyle(20, 10, "����");
	outtextxy(10, 0, "            ����ʽ������");
	settextstyle(40, 0, "����");
	//��������������õ�ǰ�豸ͼ�������������ʱ�ı���ģʽ��������͸���ġ�
	setbkmode(TRANSPARENT);

	//���������
	setfillcolor(RGB(220, 95, 8));
	setbkcolor(BLACK);
	fillcircle(255, 550, 30);
	settextcolor(WHITE);
	outtextxy(245, 528, "x");
	setcolor(RGB(220, 95, 8));
	setfillcolor(RGB(220, 95, 8));
	setbkcolor(BLACK);
	settextcolor(WHITE);
	fillcircle(255, 480, 30);
	outtextxy(245, 460, "+");
	fillcircle(255, 410, 30);
	outtextxy(245, 393, "-");
	fillcircle(255, 340, 30);
	settextstyle(30, 0, "����");
	outtextxy(245, 335, "^");



	setcolor(RGB(51, 51, 51));
	setfillcolor(RGB(51, 51, 51));
	setbkcolor(BLACK);
	settextcolor(WHITE);
	//��ԲȦ
	settextstyle(40, 0, "����");
	fillcircle(185, 550, 30);
	outtextxy(180, 530, ")");
	fillcircle(185, 480, 30);
	outtextxy(175, 460, "3");
	fillcircle(185, 410, 30);
	outtextxy(175, 390, "6");
	fillcircle(185, 340, 30);
	outtextxy(175, 320, "9");
	fillcircle(115, 550, 30);
	outtextxy(105, 530, "0");
	fillcircle(115, 480, 30);
	outtextxy(105, 460, "2");
	fillcircle(115, 410, 30);
	outtextxy(105, 390, "5");
	fillcircle(115, 340, 30);
	outtextxy(105, 320, "8");
	fillcircle(45, 550, 30);
	outtextxy(35, 530, "(");
	fillcircle(45, 480, 30);
	outtextxy(35, 460, "1");
	fillcircle(45, 410, 30);
	outtextxy(35, 390, "4");
	fillcircle(45, 340, 30);
	outtextxy(35, 320, "7");

	// ������
	setcolor(RGB(169, 169, 169));
	setfillcolor(RGB(169, 169, 169));
	setbkcolor(BLACK);
	settextcolor(WHITE);
	fillcircle(325, 340, 30);
	outtextxy(305, 320, "AC");
	fillcircle(325, 410, 30);
	outtextxy(320, 380, ".");
	fillcircle(325, 480, 30);
	outtextxy(315, 460, "=");
	fillcircle(325, 550, 30);
	outtextxy(315, 530, "F");
	outtextxy(10, 40, "Input:");
	outtextxy(10, 250, "Output:");

	// ������
	MOUSEMSG m;
	int xx = 10, yy = 80,cnt=0;
	settextstyle(30, 15, "����");
	char* Data = (char*)malloc(sizeof(char) * 2000);
	char* Data1 = (char*)malloc(sizeof(char) * 1000);
	char* Data2 = (char*)malloc(sizeof(char) * 1000);
	SinNode* Data_1=NULL,*Data_2=NULL;
	while (1)
	{
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		//���
		case WM_LBUTTONDOWN:
		{
			double x = m.x, y = m.y;
			if (get_distance(x, y, 185, 550) <= 30)
			{
				outtextxy(xx, yy, ")");
				str[cnt++] = ')';
			}
			else if (get_distance(x, y, 185, 480) <= 30)
			{
				outtextxy(xx, yy, "3");
				str[cnt++] = '3';
			}
			else if (get_distance(x, y, 185, 410) <= 30)
			{
				outtextxy(xx, yy, "6");
				str[cnt++] = '6';
			}
			else if (get_distance(x, y, 185, 340) <= 30)
			{
				outtextxy(xx, yy, "9");
				str[cnt++] = '9';
			}
			else if (get_distance(x, y, 115, 550) <= 30)
			{
				outtextxy(xx, yy, "0");
				str[cnt++] = '0';
			}
			else if (get_distance(x, y, 115, 480) <= 30)
			{
				outtextxy(xx, yy, "2");
				str[cnt++] = '2';
			}
			else if (get_distance(x, y, 115, 410) <= 30)
			{
				outtextxy(xx, yy, "5");
				str[cnt++] = '5';
			}
			else if (get_distance(x, y, 115, 340) <= 30)
			{
				outtextxy(xx, yy, "8");
				str[cnt++] = '8';
			}
			else if (get_distance(x, y, 45, 550) <= 30)
			{
				outtextxy(xx, yy, "(");
				str[cnt++] = '(';
			}
			else if (get_distance(x, y, 45, 480) <= 30)
			{
				outtextxy(xx, yy, "1");
				str[cnt++] = '1';
			}
			else if (get_distance(x, y, 45, 410) <= 30)
			{
				outtextxy(xx, yy, "4");
				str[cnt++] = '4';
			}
			else if (get_distance(x, y, 45, 340) <= 30)
			{
				outtextxy(xx, yy, "7");
				str[cnt++] = '7';
			}
			else if (get_distance(x, y, 255, 550) <= 30)
			{
				outtextxy(xx, yy, "x");
				str[cnt++] = 'x';
			}
			else if (get_distance(x, y, 255, 480) <= 30)
			{
				outtextxy(xx, yy, "+");
				str[cnt++] = '+';
			}
			else if (get_distance(x, y, 245, 393) <= 30)
			{
				outtextxy(xx, yy, "-");
				str[cnt++] = '-';
			}
			else if (get_distance(x, y, 255, 340) <= 30)
			{
				outtextxy(xx, yy, "^");
				str[cnt++] = '^';
			}
			else if (get_distance(x, y, 325, 410) <= 30)
			{
				outtextxy(xx, yy, ".");
				str[cnt++] = '.';
			}
			else if (get_distance(x, y, 325, 480) <= 30)
			{
				// ������������ʽ����
				//�и��ַ���
				Data = str;
				const char* p_1 = ")";     
				const char* p_2 = "(";
				char* p1 = strtok(Data, p_1);
				p1++;
				int count = 0;
				while (*p1 != '\0')Data1[count++] = *p1++;
				Data1[count] = '\n';
				char* p2 = strtok(NULL, p_1);
				char symbol = *p2;//�洢�Ӽ�����Z
				p2 += 2;
				count = 0;
				while (*p2 != '\0')Data2[count++] = *p2++;
				Data2[count] = '\n';
				//��ȫ����λ
				ComplementedSymBol(Data1);
				ComplementedSymBol(Data2);
				//��ȫָ����ϵ��λ
				ComplementedIndex(Data1);
				ComplementedIndex(Data2);
				//������õ����ݷ���Data_1��Data_2��
				Data_1 = DataProcessing(Data1);
				Data_2 = DataProcessing(Data2);
				//��Ҫ���أ���ֹ����ʽ�������ظ���ָ����,�ϲ��ظ���
				MergeRepetition(&Data_1);
				MergeRepetition(&Data_2);
				if (symbol == '+')
					Addition(Data_1, Data_2);
				else
					Subtraction(Data_1, Data_2);
				//�������ʽ
				MultSort(Data_2);
				//��ӡ���ս��
				int n = 0;
				char *ans=SinNodePrint(Data_2,n);			
				//�������ֵ
				for (int i = 80; i < 250; i++)
				{
					setcolor(BLACK);
					line(0, i, 500, i);
				}
				// �������õĶ���ʽ
				setcolor(WHITE);
				xx = 10, yy = 80;
				for (int i = 0;i<n; i++)
				{
					outtextxy(xx, yy, ans[i]);
					xx += 15;
					if (xx + 20 >= 400)yy += 35, xx = 10;
				}
			}
			else if (get_distance(x, y, 325, 550) <= 30)
			{
				// ����x
				char c[N];
				int cc = 0;
				bool flag = true;
				while (1)
				{
					if (!flag)break;
					MOUSEMSG nn = GetMouseMsg();
					switch (nn.uMsg)
					{
						case  WM_LBUTTONDOWN:
						{
							double x1 = nn.x, y1 = nn.y;
							if (get_distance(x1, y1, 185, 480) <= 30)c[cc++] = '3';
							else if (get_distance(x1, y1, 185, 410) <= 30)c[cc++] = '6';
							else if (get_distance(x1, y1, 185, 340) <= 30)c[cc++] = '9';
							else if (get_distance(x1, y1, 115, 550) <= 30)c[cc++] = '0';
							else if (get_distance(x1, y1, 115, 480) <= 30)c[cc++] = '2';
							else if (get_distance(x1, y1, 115, 410) <= 30)c[cc++] = '5';
							else if (get_distance(x1, y1, 115, 340) <= 30)c[cc++] = '8';
							else if (get_distance(x1, y1, 45, 480) <= 30)c[cc++] = '1';
							else if (get_distance(x1, y1, 45, 410) <= 30)c[cc++] = '4';
							else if (get_distance(x1, y1, 45, 340) <= 30)c[cc++] = '7';
							else if (get_distance(x1, y1, 325, 410) <= 30)c[cc++] = '.';
							else if (get_distance(x1, y1, 325, 480) <= 30)flag = false;
							break;
						}
					}
				}
				// �����output����

				for (int t = 250; t < 300; t++)
				{
					setcolor(BLACK);
					line(150, t, 500, t);
				}
				setcolor(WHITE);
				char strff[N];
				//�����һ��
				sprintf(strff, "%.1lf", strtod(c, NULL));
				outtextxy(150, 255, "F("); outtextxy(180, 255,strff); outtextxy(240, 255, ")=");
				// ����ֵ����

				double res = Evaluation(Data_2, strtod(c,NULL));
				sprintf(strff,"%.1lf",res);
				outtextxy(270, 255, strff);
				break;
			}
			//}
			else continue;
			xx += 15;
			if (xx + 20 >= 400)yy += 35, xx = 10;
			break;
		}
		case WM_RBUTTONDOWN:
		{
			double x = m.x, y = m.y;
			if (get_distance(x, y, 325, 340) <= 30)return;
			break;
		}
		}
	}
	char c=getchar();
}
//��������
SinNode* BuySinNode(double coefficient)
{
	SinNode* newnode = (SinNode*)malloc(sizeof(SinNode));
	if (newnode == NULL)
	{
		perror("malloc fild");
		exit(-1);
	}
	newnode->coefficient = coefficient;
	newnode->index = 0;
	newnode->next = NULL;

	return newnode;
}
//��ȫ����λ
void ComplementedSymBol(char* Data)
{
	char* cur = Data;
	if (isdigit(*cur) || *cur == 'x')
	{
		char* now = cur;
		int count = 0;
		while (*now != '\n')
		{
			count++;
			now++;
		}
		*(now + 1) = '\n';
		while (count--)
		{
			*now = *(now - 1);
			now--;
		}
		*now = '+';
	}
}
//ĳ���ַ��������ַ�������ƶ���λ��
void MoveBack(char* now, int x)
{
	char* cur = now;
	while (*now != '\n')
	{
		now++;
	}
	now += x;
	while (now != cur + x)
	{
		*now = *(now - x);
		now--;
	}
}
//��ȫָ����ϵ��λ
void ComplementedIndex(char* Data)
{
	char* cur = Data;
	//����ָ������Ϊ1�����  (5x)-(2x+1x)
	while (*cur != '\n')
	{
		if (*cur == 'x' && *(cur + 1) != '^')
		{
			MoveBack(cur, 2);
			//��ʱcur��x��ǰһλ
			*(cur + 1) = '^';
			*(cur + 2) = '1';
		}
		cur++;
	}
	cur = Data;
	//����ϵ������Ϊ1����� (+x)+(-x)
	while (*cur != '\n')
	{
		if ((*cur == '-' || *cur == '+') && *(cur + 1) == 'x')
		{
			MoveBack(cur, 1);
			//��ʱcur��x��ǰһλ
			*(cur + 1) = '1';
		}
		cur++;
	}
	cur = Data;
	//����ָ��Ϊ0�����  (24)+(5x+3x^-2)
	while (*cur != '\n') 
	{
		if (isdigit(*cur) && (*(cur + 1) == '-' || *(cur + 1) == '+' || *(cur + 1) == '\n'))
		{
			char* check = cur;
			while (1)
			{
				if ((*check == '+' || *check == '.') || (*check == '-' && *(check - 1) != '^'))
				{
					MoveBack(cur, 3);
					*(cur + 1) = 'x';
					*(cur + 2) = '^';
					*(cur + 3) = '0';
					break;
				}
				if (*check == '^' || (*check == '-' && *(check - 1) == '^'))
					break;
				check--;
			}
		}
		cur++;
	}
}
//����ʽ��ӡ
char* SinNodePrint(SinNode* phead,int &cnt)
{
	assert(phead);
	SinNode* cur = phead;
	int flag = 1;
	int sym = 1;//��¼�ǲ�������
	char ans[N],cc[N];
	char strff[N];
	while (cur)
	{
		if (cur->coefficient > 0)
		{

			if (cur->coefficient == 1)
			{
				if (sym)//��λ��ӡ
				{
					if (cur->index == 1)ans[cnt++]='x';
						//printf("x");
					else if (cur->index == 0)
					{
						sprintf(strff, "%.1lf", cur->coefficient);
						for (int i = 0; strff[i]; i++)ans[cnt++] = strff[i];
						//printf("%.1lf", cur->coefficient);
					}
					else
					{
						//printf("x^%d", cur->index);
						ans[cnt++] = 'x';ans[cnt++] = '^';
						_itoa(cur->index,cc,10);
						for(int i=0;cc[i];i++)ans[cnt++] = cc[i];
					}

				}
				else
				{
					if (cur->index == 1)
					{
						ans[cnt++] = '+';
						ans[cnt++] = 'x';
					}

					else if (cur->index == 0)
					{
						ans[cnt++] = '+';
						sprintf(strff, "%.1lf", cur->coefficient);
						for (int i = 0; strff[i]; i++)ans[cnt++] = strff[i];
					}
					else
					{
						ans[cnt++] = '+';ans[cnt++] = 'x';ans[cnt++] = '^';
						_itoa(cur->index, cc, 10);
						for (int i = 0; cc[i]; i++)ans[cnt++] = cc[i];
					}
						//printf("+x^%d", cur->index);
				}
				sym = 0;
			}
			else
			{
				if (sym)
				{
					if (cur->index == 1)
					{
						sprintf(strff, "%.1lf", cur->coefficient);
						for (int i = 0; strff[i]; i++)ans[cnt++] = strff[i];
						ans[cnt++] = 'x';

					}
						//printf("%.1lfx", cur->coefficient);
					else if (cur->index == 0)
					{
						sprintf(strff, "%.1lf", cur->coefficient);
						for (int i = 0; strff[i]; i++)ans[cnt++] = strff[i];
						//printf("%.1lf", cur->coefficient);
					}
					else
					{
						sprintf(strff, "%.1lf", cur->coefficient);
						for (int i = 0; strff[i]; i++)ans[cnt++] = strff[i];
						//printf("%.1lfx^%d", cur->coefficient, cur->index);
						ans[cnt++] = 'x'; ans[cnt++] = '^'; 
						_itoa(cur->index, cc, 10);
						for (int i = 0; cc[i]; i++)ans[cnt++] = cc[i];
					}
				}
				else
				{
					if (cur->index == 1)
					{
						ans[cnt++] = '+';
						sprintf(strff, "%.1lf", cur->coefficient);
						for (int i = 0; strff[i]; i++)ans[cnt++] = strff[i];
						ans[cnt++] = 'x';
						//printf("+%.1lfx", cur->coefficient);
					}
					else if (cur->index == 0)
					{
						//printf("+%.1lf", cur->coefficient);
						ans[cnt++] = '+';
						sprintf(strff, "%.1lf", cur->coefficient);
						for (int i = 0; strff[i]; i++)ans[cnt++] = strff[i];
					}
					else
					{
						//printf("+%.1lfx^%d", cur->coefficient, cur->index);
						ans[cnt++] = '+';
						sprintf(strff, "%.1lf", cur->coefficient);
						for (int i = 0; strff[i]; i++)ans[cnt++] = strff[i];
						ans[cnt++] = 'x', ans[cnt++] = '^';
						_itoa(cur->index, cc, 10);
						for (int i = 0; cc[i]; i++)ans[cnt++] = cc[i];
					}
				}
				sym = 0;

			}
			flag = 0;
		}
		else if (cur->coefficient == 0)
		{
			cur = cur->next;
			continue;
		}
		else
		{
			if (cur->coefficient == -1)
			{
				if (cur->index == 1)
				{
					ans[cnt++] = '-';
					ans[cnt++] = 'x';
				}
					//printf("-x");
				else if (cur->index == 0)
				{
					sprintf(strff, "%.1lf", cur->coefficient);
					for (int i = 0; strff[i]; i++)ans[cnt++] = strff[i];
					//printf("%.1lf", cur->coefficient);
				}
				else
				{
					ans[cnt++] = '-';ans[cnt++] = 'x';ans[cnt++] = '^';
					_itoa(cur->index, cc, 10);
					for (int i = 0; cc[i]; i++)ans[cnt++] = cc[i];
				}
					//printf("-x^%d", cur->index);
			}
			else
			{
				if (cur->index == 1)
				{
					sprintf(strff, "%.1lf", cur->coefficient);
					for (int i = 0; strff[i]; i++)ans[cnt++] = strff[i];
					ans[cnt++] = 'x';
					//printf("%.1lfx", cur->coefficient);
				}
				else if (cur->index == 0)
				{
					sprintf(strff, "%.1lf", cur->coefficient);
					for (int i = 0; strff[i]; i++)ans[cnt++] = strff[i];
					//printf("%.1lf", cur->coefficient);
				}
				else
				{
					sprintf(strff, "%.1lf", cur->coefficient);
					for (int i = 0; strff[i]; i++)ans[cnt++] = strff[i];
					ans[cnt++] = 'x', ans[cnt++] = '^';
					_itoa(cur->index, cc, 10);
					for (int i = 0; cc[i]; i++)ans[cnt++] = cc[i];
					//printf("%.1lfx^%d", cur->coefficient, cur->index);
				}
			}
			flag = 0;
		}
		cur = cur->next;
		sym = 0;
	}

	if (flag)ans[cnt++] = '0';
	//printf("%s\n", ans);
	return ans;
}
//���½��β�嵽Ŀ������
void PushBack(SinNode** pphead, SinNode* newnode)
{
	assert(pphead);
	assert(newnode);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//��β
		SinNode* tail = *pphead;

		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;
	}
}
//����ÿһ���ϵ��
double GetCoefficient(int flag, char* digit)
{
	char* cur = digit;
	double coefficient = 0.0;
	//�ҵ�.��λ��
	int index = 0;
	for (int i = 0; *cur != '\n'; i++)
	{
		if (*cur == '.')
		{
			index = i;
			break;      //12.25
		}
		cur++;
	}
	//�����С����
	if (index)
	{
		int integer = 0;
		//double decimals = 0.0;
		cur = digit;
		for (int i = 0; i < index; i++)
		{
			coefficient += (*cur - '0') * (int)pow(10, i);
			cur++;
		}
		cur++;
		int x = -1;
		while (*cur != '\n')
		{
			coefficient += (*cur - '0') * pow(10, x);
			x--;
			cur++;
		}
	}
	//���û��С����
	else
	{
		int count = 0;
		char* cur_d = digit;
		cur = digit;
		//��¼digit���м�λ����
		while (*cur_d != '\n')
		{
			count++;
			cur_d++;
		}
		for (int i = count - 1; i >= 0; i--)
		{
			coefficient += (*cur - '0') * (int)pow(10, i);
			cur++;
		}
	}
	return coefficient * flag;
}
//��ÿ�����в���ϵ��
void SinNodeCoefficientPush(SinNode** pphead, int flag, char* digit)
{
	double coefficient = GetCoefficient(flag, digit);

	SinNode* newnode = BuySinNode(coefficient);//�����½�㣬���½��ϵ����ֵ��ָ���ȸ�ֵΪ0
	PushBack(pphead, newnode);//��������
}
//��ÿ�����в���ָ��
void SinNodeIndexPush(SinNode** pphead, int flag, char* digit, int n)
{
	assert(pphead);
	SinNode* cur = *pphead;
	int count = 0;
	//��¼digit���м�λ����
	char* digit_i = digit;
	while (*digit_i != '\n')
	{
		count++;
		digit_i++;
	}
	int index = 0;
	for (int i = count - 1; i >= 0; i--)
	{
		index += (*digit - '0') * (int)pow(10, i);
		digit++;
	}
	int m = n - 1;
	while (m--)
	{
		cur = cur->next;
	}

	index *= flag;
	cur->index = index;
}
//���ݴ���
SinNode* DataProcessing(char* Data)
{
	SinNode* newx = NULL;     //+2.2x^1+5.5x^8
	char* cur = Data;
	//����ϵ��
	while (*cur != '\n')
	{
		if ((*cur == '-' || *cur == '+') && *(cur - 1) != '^') //+2x^1+5.5x^8
		{
			int flag = 1;
			if (*cur == '-')
			{
				flag = -1;
			}
			cur++;
			char digit[10];
			int count = 0;
			while (*cur != 'x')
			{
				digit[count++] = *cur++;
			}
			digit[count] = '\n'; //�����ֺ��'\n'
			SinNodeCoefficientPush(&newx, flag, digit);
		}
		cur++;
	}
	//+6x^15
//����ָ��
	cur = Data;
	int Index_count = 0;//��Ӧ�����е���
	while (*cur != '\n')
	{
		if (*(cur) == '^')
		{
			cur++;
			Index_count++;
			int flag = 1;
			if (*cur == '-')
			{
				flag = -1;
				cur++;
			}

			char digit[15];//�����ַ�������ָ��

			int count = 0;
			while (isdigit(*cur))
			{
				digit[count++] = *cur++;
			}
			digit[count] = '\n';
			SinNodeIndexPush(&newx, flag, digit, Index_count);//�Ƚ�ָ����� �ٸ�ֵ�����Ӧ�ĵ�������
		}
		else
			cur++;
	}

	return newx;
}
//����ʽ�ӷ�
void Addition(SinNode* Data_1, SinNode* Data_2)
{
	assert(Data_1);
	assert(Data_2);

	SinNode* cur_1 = Data_1;
	SinNode* cur_2 = Data_2;

	//��Data_2��û��Data_1��ָ�����Ҫ��Data_2�������β�������
	while (cur_1 != NULL)
	{
		int flag = 1;
		cur_2 = Data_2;
		while (cur_2 != NULL)
		{
			if (cur_1->index == cur_2->index)
			{
				cur_2->coefficient += cur_1->coefficient;
				flag = 0;
				//break;
			}
			cur_2 = cur_2->next;

		}
		if (flag)
		{
			MultPushBack(&Data_2, cur_1->coefficient, cur_1->index);
		}
		cur_1 = cur_1->next;
	}
}
//����Ӽ�������û��ָͬ����Data_2����½��
void MultPushBack(SinNode** pphead, double coefficient, int index)
{
	assert(pphead);

	SinNode* newnode = BuySinNode(coefficient);

	newnode->index = index;

	PushBack(pphead, newnode);
}
//����ʽ����
void Subtraction(SinNode* Data_1, SinNode* Data_2)
{
	assert(Data_1);
	assert(Data_2);

	SinNode* cur_1 = Data_1;
	SinNode* cur_2 = Data_2;

	while (cur_2)
	{
		cur_2->coefficient *= -1;
		cur_2 = cur_2->next;
	}

	Addition(Data_1, Data_2);
}
//ͷɾ
void SinNodePopFront(SinNode** pphead)
{
	assert(*pphead != NULL);
	assert(pphead);

	SinNode* next = (*pphead)->next;
	free(*pphead);

	*pphead = next;

}
//ɾ��ĳ��λ��
void SinNodeErase(SinNode** pphead, SinNode* pos)
{
	assert(*pphead);
	assert(pos);
	if (*pphead == pos)
	{
		SinNodePopFront(pphead);
	}
	else
	{
		SinNode* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
//�ϲ��ظ���
void MergeRepetition(SinNode** pphead)
{
	SinNode* cur = *pphead;
	while (cur)
	{
		SinNode* n = cur->next;
		while (n)
		{
			if (cur->index == n->index)
			{
				cur->coefficient += n->coefficient;
				//ɾ���˽��
				SinNodeErase(pphead, n);//������ɾ��ĳ��λ��
				break;
			}
			n = n->next;
		}
		cur = cur->next;
	}
}
//����ʵ��ð������
void MultSort(SinNode* pNode) 
{
	SinNode* pMove;
	pMove = pNode;
	//��Ҫ����(n-1)�α���,���ƴ���
	int size = sizeList(pNode);
	for (int i = 0; i < size; i++) {
		while (pMove->next != NULL) {
			if (pMove->index < pMove->next->index) {

				int temp1 = pMove->index;
				double temp2 = pMove->coefficient;
				pMove->index = pMove->next->index;
				pMove->coefficient = pMove->next->coefficient;
				pMove->next->index = temp1;
				pMove->next->coefficient = temp2;
			}
			pMove = pMove->next;
		}
		//ÿ�α���������pMove�����ƶ�������ͷ��
		pMove = pNode;
	}
}
//����ֵ�����ʽ
double Evaluation(SinNode* phead, double x)
{
	double sum = 0;
	SinNode* p = phead;
	while (p != NULL)
	{
		double mul_x = 1;
		for (int i = 1; i <= p->index; i++)
			mul_x *= x;
		sum += (mul_x * p->coefficient);
		p = p->next;
	}
	return sum;
}
int main()
{
	//��������
	// (2x+5x^8-3.1x^11)+(7-5x^8+11x^9)
	// (6x^-3-x+4.4x^2-1.2x^9)-(-6x^-3+5.4x^2-x^2+7.8x^15)
	// (1+x+x^2+x^3+x^4+x^5)+(-x^3-x^4)
	// (x+x^3)+(-x-x^3)
	// (x+x^2+x^3)+(0)
	while (1)Paint();
	return 0;
}