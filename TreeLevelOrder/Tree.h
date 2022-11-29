#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>

typedef int TreeDataType;

typedef struct TreeNode
{
	TreeDataType data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

// 创建一个结点
TreeNode* CreateTreeNode(TreeDataType x);

// 二叉树前序遍历
void PrevOrder(TreeNode* root);
// 二叉树中序遍历
void InOrder(TreeNode* root);
// 二叉树后序遍历
void PostOrder(TreeNode* root);
// 二叉树节点个数
int TreeNodeSize(TreeNode*root);
// 二叉树叶子节点个数
int TreeLeaveSize(TreeNode* root);
// 树的高度/深度
int TreeHeight(TreeNode* root);
// 二叉树第k层节点个数
int TreeLevelKSize(TreeNode* root, int k);
// 二叉树查找值为x的节点
TreeNode* TreeNodeXFind(TreeNode* root, TreeDataType x);
// 二叉树销毁
void TreeDestroy(TreeNode* root);
