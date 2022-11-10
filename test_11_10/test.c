#define _CRT_SECURE_NO_WARNINGS 1




LC 138 给定一个链表，每个结点包含一个额外增加的随机指针，该指针可以指向链表中的任何结点或空结点。

struct Node* copyRandomList(struct Node* head) {
    struct Node* cur = head;
    //1.先在每个结点后面复制一份该结点，保证cur->next指向的是该结点的复制,并链接在原链表中
    while (cur)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        struct Node* next = cur->next;

        copy->val = cur->val;
        copy->next = next;

        cur->next = copy;
        cur = next;
    }
    //2.将copy出来的每个结点的指向的random进行copy->random = cur->random->next;
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;
        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
        }
        cur = next;
    }
    //3.将copy出来的结点断掉，还原 原链表 ，最后将copy结点都链接起来，返回copy链表的头结点
    cur = head;
    struct Node* copyhead = NULL, * copytail = NULL;
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;
        cur->next = next;
        if (copyhead == NULL)
        {
            copyhead = copytail = copy;
        }
        else
        {
            copytail->next = copy;
            copytail = copytail->next;
        }
        cur = next;
    }
    return copyhead;
}