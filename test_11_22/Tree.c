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

// 二叉树前序遍历
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

// 二叉树中序遍历
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

// 二叉树后序遍历
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

// 二叉树节点个数
int TreeNodeSize(TreeNode* root)
{
	//if (root == NULL)
	//	return 0;
	//return 1 + TreeNodeSize(root->left) + TreeNodeSize(root->right);

	return root == NULL ? 0 : 1 + TreeNodeSize(root->left) + TreeNodeSize(root->right);
}

// 二叉树叶子节点个数
int TreeLeaveSize(TreeNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return TreeLeaveSize(root->left) + TreeLeaveSize(root->right);
}

// 树的高度/深度
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

// 二叉树第k层节点个数
int TreeLevelKSize(TreeNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreeLevelKSize(root->left, k - 1) + TreeLevelKSize(root->right, k - 1);
}

// 二叉树查找值为x的节点
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