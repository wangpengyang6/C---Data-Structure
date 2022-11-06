#define _CRT_SECURE_NO_WARNINGS 1

CM11 链表分割

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


给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点


优化代码，用快慢指针，快指针是慢指针走的速度的二倍，当快指针走到NULL或快指针->next == NULL时，此时慢指针指向的则为中间结点
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


OR36 链表的回文结构
1.先找到链表的中间结点
2.将链表的中间结点及其之后的结点逆转
3.遍历前后两个链表
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