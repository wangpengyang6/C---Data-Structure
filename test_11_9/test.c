#define _CRT_SECURE_NO_WARNINGS 1

LC 160 相交链表

给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 NULL
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

LC 141 环形链表  给你一个链表的头节点 head ，判断链表中是否有环
思路：快慢指针，即慢指针一次走一步，快指针一次走两步，两个指针从链表其实位置开始运行，如果链表带环则一定会在环中相遇，否则快指针率先走到链表的末尾

bool hasCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next)
    {
        fast = fast->next->next; 快指针一次走两步 
        slow = slow->next;       慢指针一次走一步
        if (fast == slow)
        {
            return true;
        }

    }
    return false;
}


LC 142 环形链表2  给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL

结论：让一个指针从链表起始位置开始遍历链表，同时让一个指针从判环时相遇点的位置开始绕环运行，两个指针都是每次均走一步，最终肯定会在入口点的位置相遇。


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