#include <stdio.h>
#include <ctype.h>
#define MAX 20

char stack[MAX];
char ans[MAX];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}
char pop()
{
    if (top == -1)
        return -1;
    else
    {
        return stack[top--];
    }
}

int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
}

int main()
{
    char exp[MAX];
    char *e, x;
    printf("Enter the infix expression: ");
    scanf("%s", exp);
    e = exp;
    int i = 0;
    while (*e != '\0')
    {
        if (isalnum(*e))
            ans[i++] = *e;
        else if (*e == '(')
            push(*e);
        else if (*e == ')')
        {
            while ((x = pop()) != '(')
                ans[i++] = x;
        }
        else
        {
            while (priority(stack[top]) >= priority(*e))
                ans[i++] = pop();
            push(*e);
        }
        e++;
    }
    while (top != -1)
    {
        ans[i++] = pop();
    }
    printf("Postfix expression: %s\n", ans);
    return 0;
}

