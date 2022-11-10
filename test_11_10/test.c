#define _CRT_SECURE_NO_WARNINGS 1




LC 138 ����һ������ÿ��������һ���������ӵ����ָ�룬��ָ�����ָ�������е��κν���ս�㡣

struct Node* copyRandomList(struct Node* head) {
    struct Node* cur = head;
    //1.����ÿ�������渴��һ�ݸý�㣬��֤cur->nextָ����Ǹý��ĸ���,��������ԭ������
    while (cur)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        struct Node* next = cur->next;

        copy->val = cur->val;
        copy->next = next;

        cur->next = copy;
        cur = next;
    }
    //2.��copy������ÿ������ָ���random����copy->random = cur->random->next;
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
    //3.��copy�����Ľ��ϵ�����ԭ ԭ���� �����copy��㶼��������������copy�����ͷ���
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