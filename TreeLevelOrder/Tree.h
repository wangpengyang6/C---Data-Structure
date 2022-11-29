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

// ����һ�����
TreeNode* CreateTreeNode(TreeDataType x);

// ������ǰ�����
void PrevOrder(TreeNode* root);
// �������������
void InOrder(TreeNode* root);
// �������������
void PostOrder(TreeNode* root);
// �������ڵ����
int TreeNodeSize(TreeNode*root);
// ������Ҷ�ӽڵ����
int TreeLeaveSize(TreeNode* root);
// ���ĸ߶�/���
int TreeHeight(TreeNode* root);
// ��������k��ڵ����
int TreeLevelKSize(TreeNode* root, int k);
// ����������ֵΪx�Ľڵ�
TreeNode* TreeNodeXFind(TreeNode* root, TreeDataType x);
// ����������
void TreeDestroy(TreeNode* root);
