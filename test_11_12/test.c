#define _CRT_SECURE_NO_WARNINGS 1


LC 20 括号匹配问题

思路：将左括号放入栈中，当遇到右括号时，取出栈顶元素，与之进行匹配
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