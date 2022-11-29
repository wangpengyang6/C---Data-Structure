#define _CRT_SECURE_NO_WARNINGS 1
#include"Tree.h"
#include"Queue.h"

// 层序遍历
void LevelOrder(TreeNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q,root);
	while (!QueueEmpty(&q))
	{
		TreeNode* Node = QueueFront(&q);
		printf("%d ",Node->data);
		QueuePop(&q);
		if (Node->left)
			QueuePush(&q, Node->left);
		if (Node->right)
			QueuePush(&q, Node->right);
	}
	printf("\n");
	QueueDestroy(&q);
}

//判断是否为完全二叉树
bool TreeComplete(TreeNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		TreeNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL) // 在队列中遇到NULL，跳出循环进行判断剩下的队列元素中还有没有非NULL元素
		{
			break;
		}
		else
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
	}
	while (!QueueEmpty(&q))
	{
		TreeNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)
		{
			QueueDestroy(&q);

			return false;
		}
	}
	QueueDestroy(&q);

	return true;

}
int main()
{
	TreeNode* n1 = CreateTreeNode(1);
	TreeNode* n2 = CreateTreeNode(2);
	TreeNode* n3 = CreateTreeNode(3);
	TreeNode* n4 = CreateTreeNode(4);
	TreeNode* n5 = CreateTreeNode(5);
	TreeNode* n6 = CreateTreeNode(6);
	TreeNode* n7 = CreateTreeNode(7);
	n1->left = n2;
	n1->right = n4;
	n2->left = n3;
	n4->left = n5;
	n4->right = n6;
	n2->right = n7;
	LevelOrder(n1);
	printf("%d ", TreeComplete(n1));

	TreeDestroy(n1); 
	return 0;
}