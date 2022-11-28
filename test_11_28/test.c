
//KY11 通过先序遍历创建一个二叉树，再对二叉树进行中序遍历
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}Tree;

Tree* ReBuildTree(char* str, int* i)
{
    if (str[*i] == '#')
    {
        (*i)++;
        return NULL;
    }
    Tree* Node = (Tree*)malloc(sizeof(Tree));
    if (Node == NULL)
    {
        perror("malloc fail");
        exit(-1);
    }
    Node->val = str[(*i)++];
    Node->left = ReBuildTree(str, i);
    Node->right = ReBuildTree(str, i);
    return Node;
}
void InOrder(Tree* root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    printf("%c ", root->val);
    InOrder(root->right);
}

int main() {
    char str[100];
    scanf("%s", str);
    int i = 0;
    Tree* root = ReBuildTree(str, &i);
    InOrder(root);
    return 0;
}