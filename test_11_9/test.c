#define _CRT_SECURE_NO_WARNINGS 1

LC 160 �ཻ����

���������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣����������������ཻ�ڵ㣬���� NULL
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    int count_A = 0, count_B = 0;
    struct ListNode* heada = headA;
    struct ListNode* headb = headB;
    while (heada)
    {
        count_A++;
        heada = heada->next;
    }
    while (headb)
    {
        count_B++;
        headb = headb->next;
    }
    int differ = abs(count_A - count_B);
    if (count_A < count_B)
    {
        heada = headB;
        headb = headA;
    }
    else
    {
        heada = headA;
        headb = headB;
    }
    while (differ--)
    {
        heada = heada->next;
    }
    while (headb)
    {
        if (heada == headb)
        {
            return headb;
        }
        heada = heada->next;
        headb = headb->next;
    }
    return NULL;
}

LC 141 ��������  ����һ�������ͷ�ڵ� head ���ж��������Ƿ��л�
˼·������ָ�룬����ָ��һ����һ������ָ��һ��������������ָ���������ʵλ�ÿ�ʼ���У�������������һ�����ڻ��������������ָ�������ߵ������ĩβ

bool hasCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next)
    {
        fast = fast->next->next; ��ָ��һ�������� 
        slow = slow->next;       ��ָ��һ����һ��
        if (fast == slow)
        {
            return true;
        }

    }
    return false;
}


LC 142 ��������2  ����һ�������ͷ�ڵ�  head ����������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� NULL

���ۣ���һ��ָ���������ʼλ�ÿ�ʼ��������ͬʱ��һ��ָ����л�ʱ�������λ�ÿ�ʼ�ƻ����У�����ָ�붼��ÿ�ξ���һ�������տ϶�������ڵ��λ��������


struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow = head, * fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            struct ListNode* meet = slow;
            while (head != meet)
            {
                head = head->next;
                meet = meet->next;
            }
            return head;
        }
    }
    return NULL;
}