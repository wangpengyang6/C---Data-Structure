#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef int BTDataType;

typedef struct Tree
{
	struct Tree* left;
	struct Tree* right;
	char val;
}BTNode;


typedef struct stack
{
	BTNode* data[100];
	int tag[100];
	int top;
} seqstack;

void push(seqstack* s, BTNode* t)
{
	s->data[++s->top] = t;
}

BTNode* pop(seqstack* s)
{ 
	if (s->top != -1) 
	{
		s->top--;
		return(s->data[s->top + 1]);
	}
	else
		return NULL; 
}

//ͨ��ǰ����������鹹�������� ABD##E#H##CF##G##
BTNode* CreateTree(char* str, int* pi)
{
	if (str[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL)
	{
		perror("malloc filed\n");
		exit(-1);
	}
	root->val = str[(*pi)++];
	root->left = CreateTree(str, pi);
	root->right = CreateTree(str, pi);

	return root;
}

// �ݹ������ǰ�����
void PreOrder(BTNode* root)
{
	if (root == NULL)
	{

		return;
	}

	printf("%c ", root->val);
	PreOrder(root->left);
	PreOrder(root->right);
}

// �ǵݹ������ǰ�����
void PreOrder1(BTNode* t)
{
	seqstack s;
	s.top = 0;
	while ((t) || (s.top != 0))
	{ 
		while (t)
		{
			printf("%c ", t->val);
			s.top++;
			s.data[s.top] = t;
			t = t->left;
		}
		if (s.top > 0)
		{
			t = pop(&s);
			t = t->right;
		}
	}
}


// �ݹ�������������
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;

	}

	InOrder(root->left);
	printf("%c ", root->val);
	InOrder(root->right);
}

// �ǵݹ�������������
void InOrder1(BTNode* t)
{ 
	seqstack s;
	s.top = 0;
	while ((t != NULL) || (s.top != 0)) 
	{
		while (t)
		{ 
			push(&s, t);
			t = t->left;
		}
		if (s.top != 0)
		{
			t = pop(&s);
			printf("%c ", t->val);
			t = t->right;
		}
	}
}


// �ݹ�������������
void PostOrder(BTNode* root)
{
	if (root == NULL) 
	{
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->val);
}

// �ǵݹ�������������
void PostOrder1(BTNode* t)
{
	seqstack s;
	s.top = 0;
	while ((t) || (s.top != 0))
	{
		while (t)
		{
			push(&s, t);
			s.tag[s.top] = 0;
			t = t->left;
		}
		while ((s.top > 0) && (s.tag[s.top] == 1))
		{
			t = s.data[s.top];
			printf("%c ", t->val);
			s.top--;
		}
		if (s.top > 0)
		{ 
			t = s.data[s.top];
			s.tag[s.top] = 1;
			t = t->right;
		}
		else t = NULL;
	}
}



// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->val == x)
		return root;

	BTNode* leftRet = BinaryTreeFind(root->left, x);
	if (leftRet)
		return leftRet;

	BTNode* rightRet = BinaryTreeFind(root->right, x);
	if (rightRet)
		return rightRet;

	return NULL;
}

//�������н��ĸ���
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 :BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

//�ж������������Ƿ�ȼ�  �ȼ۷���1�����ȼ۷���0
int BinaryTreeIsEqual(BTNode* T1, BTNode* T2)
{
	int t = 0;
	if (T1 == NULL && T2 == NULL)
		t = 1;
	else
	{
		if (T1 != NULL && T2 != NULL)
		{
			if (T1->val == T2->val)
			{
				if (BinaryTreeIsEqual(T1->left, T2->left))
					t = BinaryTreeIsEqual(T1->right, T2->right);
			}
		}
	}

	return t;
}

// ���������/�߶�
int BinaryTreeDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int leftDepth = BinaryTreeDepth(root->left);
	int rightDepth = BinaryTreeDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

int main()
{
	char str[100];
	printf("��������ȷ�Ķ�������ʽ������#��ʾNULL:\n");
	scanf("%s", str);
	int i = 0;
	BTNode* root = CreateTree(str, &i);

	printf("�ݹ�ǰ��������Ϊ��");
	PreOrder(root);
	printf("\n");
	printf("�ǵݹ�ǰ��������Ϊ��");
	PreOrder1(root);
	printf("\n");
	printf("\n");

	printf("�ݹ�����������Ϊ��");
	InOrder(root);
	printf("\n");
	printf("�ǵݹ�����������Ϊ��");
	InOrder1(root);
	printf("\n");
	printf("\n");


	printf("�ݹ����������Ϊ��");
	PostOrder(root);
	printf("\n");
	printf("�ǵݹ����������Ϊ��");
	PostOrder1(root);
	printf("\n");
	printf("\n");

	printf("���ĸ߶�Ϊ��%d\n", BinaryTreeDepth(root));
	printf("���Ľ�����ʱ��%d\n", BinaryTreeSize(root));

	printf("���ҵ�ֵΪC���ҵ���ֵΪ��");

	BTNode* pos = BinaryTreeFind(root, 'C');

	printf("%c \n",pos->val);

	printf("����������������������#��ʾNULL\n");
	char str1[100];
	char str2[100];
	scanf("%s",str1);
	scanf("%s",str2);
	int k = 0,j = 0;
	BTNode* T1 = CreateTree(str1, &k);
	BTNode* T2 = CreateTree(str1, &j);
	if (BinaryTreeIsEqual(T1, T2) == 1)
		printf("�����������ȼ�\n");
	else
		printf("�������������ȼ�\n");
	return 0;
}