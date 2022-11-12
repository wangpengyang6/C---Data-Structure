#define _CRT_SECURE_NO_WARNINGS 1


LC 20 ����ƥ������

˼·���������ŷ���ջ�У�������������ʱ��ȡ��ջ��Ԫ�أ���֮����ƥ��
bool isValid(char* s) {
    Stack sk;
    StackInit(&sk);
    while (*s)
    {
        if (*s == '[' || *s == '{' || *s == '(')
        {
            StackPush(&sk, *s);
        }
        else
        {
            if (StackEmpty(&sk))
                return false;
            char top = StackTop(&sk);
            StackPop(&sk);
            if (top != '{' && *s == '}'
                || top != '(' && *s == ')'
                || top != '[' && *s == ']')
            {
                return false;
            }
        }
        s++;
    }
    bool ret = StackEmpty(&sk);
    StackDestroy(&sk);
    return ret;
}