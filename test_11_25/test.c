#define _CRT_SECURE_NO_WARNINGS 1


//LeetCode 965��ֵ������

bool isUnivalTree(struct TreeNode* root) {
    if (root == NULL)
    {
        return true;
    }
    if (root->left && root->left->val != root->val)
        return false;
    if (root->right && root->right->val != root->val)
        return false;
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}

//LeetCode 100����������Ƿ���ͬ

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL)
        return false;
    if (p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

//LeetCode 101 �Գƶ�����

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL)
        return false;
    if (p->val != q->val)
        return false;
    return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
}
bool isSymmetric(struct TreeNode* root) {
    return isSameTree(root->left, root->right);
}