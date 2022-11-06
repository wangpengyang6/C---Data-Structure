#define _CRT_SECURE_NO_WARNINGS 1

CM11 ����ָ�

class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        ListNode* lesshead, * lesstail;
        ListNode* greaterhead, * greatertail;
        lesshead = lesstail = (ListNode*)malloc(sizeof(ListNode));
        greaterhead = greatertail = (ListNode*)malloc(sizeof(ListNode));
        lesshead->next = NULL;
        greaterhead->next = NULL;
        while (pHead)
        {
            if (pHead->val < x)
            {
                lesstail->next = pHead;
                lesstail = lesstail->next;
            }
            else
            {
                greatertail->next = pHead;
                greatertail = greatertail->next;
            }
            pHead = pHead->next;
        }
        greatertail->next = NULL;
        lesstail->next = greaterhead->next;
        pHead = lesshead->next;
        free(lesshead);
        free(greaterhead);

        return pHead;
    }
};


����һ������ͷ��� head �ķǿյ���������������м��㡣����������м��㣬�򷵻صڶ����м���


�Ż����룬�ÿ���ָ�룬��ָ������ָ���ߵ��ٶȵĶ���������ָ���ߵ�NULL���ָ��->next == NULLʱ����ʱ��ָ��ָ�����Ϊ�м���
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow;
    struct ListNode* fast;
    slow = fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


OR36 ����Ļ��Ľṹ
1.���ҵ�������м���
2.��������м��㼰��֮��Ľ����ת
3.����ǰ����������
class PalindromeList {
public:
    struct ListNode* middleNode(struct ListNode* head) {
        struct ListNode* slow;
        struct ListNode* fast;
        slow = fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    struct ListNode* reverseList(struct ListNode* head) {
        if (head == NULL)
            return NULL;
        struct ListNode* n1 = NULL;
        struct ListNode* n2 = head;
        struct ListNode* n3 = head->next;
        while (n2) {
            n2->next = n1;
            n1 = n2;
            n2 = n3;
            if (n3)
                n3 = n3->next;
        }
        return n1;
    }
    bool chkPalindrome(ListNode* A) {
        ListNode* mid = middleNode(A);
        ListNode* newnode = reverseList(mid);
        while (A && newnode)
        {
            if (A->val != newnode->val)
            {
                return false;
            }
            A = A->next;
            newnode = newnode->next;
        }
        return true;
    }
};