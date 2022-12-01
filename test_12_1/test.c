#define _CRT_SECURE_NO_WARNINGS 1


//LC 226. 翻转二叉树
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL)
        return NULL;
    struct TreeNode* left = invertTree(root->left);
    struct TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}


//LC 110. 平衡二叉树

int TreeHeight(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    int Left = TreeHeight(root->left);
    int Right = TreeHeight(root->right);
    return Left > Right ? Left + 1 : Right + 1;
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL)
        return true;
    int _left = TreeHeight(root->left);
    int _right = TreeHeight(root->right);
    return (abs(_left - _right) <= 1) && isBalanced(root->left) && isBalanced(root->right);
}

//LC 111. 二叉树的最小深度
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if (root->left == NULL || root->right == NULL)
            return left + right + 1;

        return min(left, right) + 1;
    }
};