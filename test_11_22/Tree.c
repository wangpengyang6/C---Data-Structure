#define _CRT_SECURE_NO_WARNINGS 1
#include"Tree.h"


TreeNode* CreateTreeNode(TreeDataType x)
{
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	if (root == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	root->left = NULL;
	root->right = NULL;
	root->data = x;

	return root;
}

// ������ǰ�����
void PrevOrder(TreeNode* root)
{
	if(root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

// �������������
void InOrder(TreeNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%d ",root->data);
	InOrder(root->right);
}

// �������������
void PostOrder(TreeNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);

}

// �������ڵ����
int TreeNodeSize(TreeNode* root)
{
	//if (root == NULL)
	//	return 0;
	//return 1 + TreeNodeSize(root->left) + TreeNodeSize(root->right);

	return root == NULL ? 0 : 1 + TreeNodeSize(root->left) + TreeNodeSize(root->right);
}

// ������Ҷ�ӽڵ����
int TreeLeaveSize(TreeNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return TreeLeaveSize(root->left) + TreeLeaveSize(root->right);
}

// ���ĸ߶�/���
int TreeHeight(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int LeftTreeHeight = TreeHeight(root->left);
	int RightTreeHeight = TreeHeight(root->right);

	return LeftTreeHeight > RightTreeHeight ? TreeHeight(root->left) + 1 : TreeHeight(root->right) + 1;
}

// ��������k��ڵ����
int TreeLevelKSize(TreeNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreeLevelKSize(root->left, k - 1) + TreeLevelKSize(root->right, k - 1);
}

// ����������ֵΪx�Ľڵ�
TreeNode* TreeNodeXFind(TreeNode* root, TreeDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	TreeNode* n1 = TreeNodeXFind(root->left, x);
	if (n1)
		return n1;
	TreeNode* n2 = TreeNodeXFind(root->right, x);
	if (n2)
		return n2;
}