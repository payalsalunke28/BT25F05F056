
#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Insert an element into the stack
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = value;
}

// Remove and return the top element
int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    return stack[top--];
}

// Evaluate postfix expression
int evaluatePostfix(char exp[])
{
    int i;
    int a, b, result;

    for (i = 0; exp[i] != '\0'; i++)
    {
        char ch = exp[i];

        if (ch == ' ')
            continue;

        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else
        {
            b = pop();
            a = pop();

            switch (ch)
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    if (b == 0)
                    {
                        printf("Division by zero error\n");
                        return -1;
                    }
                    result = a / b;
                    break;

                default:
                    printf("Invalid operator\n");
                    return -1;
            }

            push(result);
        }
    }

    return pop();
}

int main()
{
    char exp[MAX];

    printf("Enter postfix expression: ");
    scanf("%99s", exp);

    printf("Result = %d\n", evaluatePostfix(exp));

    return 0;
}
