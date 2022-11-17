#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 10

float stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

float post_eval();
void inToPost();
int precedence(char symbol);
void print();
void push(float c);
float pop();
int isEmpty();

int main()
{
    float result;
    printf("\nEnter the postfix expression: ");
    gets(postfix);

    result = post_eval();
    printf("The result obtained after postfix evaluation is: ");
    printf("%.3f\n", result);
    return 0;
}

float post_eval()
{
    int i;
    float a, b;
    for (i = 0; i < strlen(postfix); i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
            push(postfix[i] - '0');
        else
        {
            a = pop();
            b = pop();
            switch (postfix[i])
            {
            case '+':
                push(b + a);
                break;
            case '-':
                push(b - a);
                break;
            case '*':
                push(b * a);
                break;
            case '/':
                push(b / a);
                break;
            case '^':
                push(pow(b, a));
                break;
            }
        }
    }
    return pop();
}

void push(float c)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = c;
}

float pop()
{
    float c;
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    c = stack[top];
    top = top - 1;
    return c;
}

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}