#include<stdio.h>
#include<string.h>
#define m 50
char infix[50],postfix[50];
int stack1[m];
int top=-1;
int precedence(char symbol)
{
    switch(symbol)
    {
        case '(':
               return 0;
        case '^':
            return 3;
        case '/':
        case '*':
            return 2;
            break;
        case '+':
        case '-':
            return 1;
            break;
        default:
            return 0;
    }
}
void push(char symbol)
{
    if(top==m-1)
    {
        printf("the stack is overflow\n");
        return;
    }
    top=top+1;
    stack1[top]=symbol;
}
char pop()
{
    char k;
    if(top==-1)
    {
        printf("stack in underflow\n");
    }
    else
    {
        k=stack1[top--];
        return k;
    }
}
void infixToPostfix()
{
    int p=0,next;
    char symbol;
    for(int i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        switch(symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            while(pop()!='(')
                postfix[p++]=pop();
            break;
        case '^':
        case '/':
        case '*':
        case '+':
        case '-':
            while(precedence(stack1[top])>=precedence(symbol))
                postfix[p++]=pop();
            push(symbol);
            break;
        default:
            postfix[p++]=symbol;
        }
    }
    while(top!=-1)
        postfix[p++]=pop();
        postfix[p]='\0';
        puts(postfix);
}
void post_evaluation()
{

}
main()
{

    printf("enter the expessoion in infix\n");
    gets(infix);
    infixToPostfix();
    post_evaluation();
}
