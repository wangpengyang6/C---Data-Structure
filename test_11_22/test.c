#define _CRT_SECURE_NO_WARNINGS 1
#include"Tree.h"



int main()
{
	TreeNode* n1 = CreateTreeNode(1);
	TreeNode* n2 = CreateTreeNode(2);
	TreeNode* n3 = CreateTreeNode(3);
	TreeNode* n4 = CreateTreeNode(4);
	TreeNode* n5 = CreateTreeNode(5);
	TreeNode* n6 = CreateTreeNode(6);
	//TreeNode* n7 = CreateTreeNode(7);
	n1->left = n2;
	n1->right = n4;
	n2->left = n3;
	n4->left = n5;
	n4->right = n6;
	//n3->right = n7;
	PrevOrder(n1);
	printf("\n");
	InOrder(n1);
	printf("\n");

	PostOrder(n1);
	printf("\n");

	printf("TreeNodeSize:%d\n", TreeNodeSize(n1));


	printf("TreeLeaveSize:%d\n", TreeLeaveSize(n1));
	printf("TreeHeight:%d\n", TreeHeight(n1));
	printf("TreeLevelKSize:%d\n", TreeLevelKSize(n1,2));

	TreeNode* Find = TreeNodeXFind(n1,4);
	return 0;
}