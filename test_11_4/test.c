#define _CRT_SECURE_NO_WARNINGS 1


LC 203ɾ�������е��ڸ���ֵ val �����н��

���ڱ�λ����
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL)
        return NULL;
    struct ListNode* guard, * tail;
    guard = (struct ListNode*)malloc(sizeof(struct ListNode));
    tail = (struct ListNode*)malloc(sizeof(struct ListNode));
    guard = tail;
    guard->next = NULL;
    while (head)
    {
        if (head->val != val)
        {
            tail->next = head;
            tail = tail->next;
            head = head->next;
        }
        else
        {
            struct ListNode* cur = head->next;
            free(head);
            head = cur;
        }
    }
    tail->next = NULL;
    head = guard->next;
    free(guard);
    return head;
}


�����ڱ�λ
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    while (cur)
    {
        if (cur->val != val)
        {
            prev = cur;
            cur = cur->next;
        }
        else if (prev == NULL)
        {
            head = head->next;
            cur = head;
        }
        else
        {
            prev->next = cur->next;
            cur = cur->next;
        }
    }
    return head;
}


LC206 ��ת����

��ת��������巨
struct ListNode* reverseList(struct ListNode* head) {
    if (!head)
        return head;
    struct ListNode* n1 = NULL;
    struct ListNode* n2 = head;
    struct ListNode* n3 = head->next;
    while (n2)
    {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if (n3)
            n3 = n3->next;
    }
    return n1;
}


LC 876 ������м���
����һ������ͷ��� head �ķǿյ���������������м��㡣����������м��㣬�򷵻صڶ����м���

struct ListNode* middleNode(struct ListNode* head) {
    int count = 0;
    struct ListNode* cur = head;
    while (cur)
    {
        cur = cur->next;
        count++;
    }
    int k = 0;
    while (head)
    {
        if (k == count / 2)
            return head;
        head = head->next;
        k++;
    }
    return NULL;
}

����һ����������������е�����k�����
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    struct ListNode* cur = pListHead;
    int count = 0;
    while (cur)
    {
        cur = cur->next;
        count++;
    }
    int true_k = count - k + 1;
    count = 1;
    while (pListHead)
    {
        if (count == true_k)
        {
            return pListHead;
        }
        pListHead = pListHead->next;
        count++;
    }
    return NULL;
}

LC21 �ϲ������������� 
��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������н����ɵ�

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head;
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node = head;
    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            head->next = list1;
            head = head->next;
            list1 = list1->next;
        }
        else
        {
            head->next = list2;
            head = head->next;
            list2 = list2->next;
        }
    }
    if (list1 == NULL)
    {
        head->next = list2;
    }
    else
    {
        head->next = list1;
    }
    return node->next;
}