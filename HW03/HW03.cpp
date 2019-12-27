
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 50

char stack[MAX];

int top = -1;

void push(char element)
{
    stack[++top] = element;
}

char pop()
{
    return(stack[top--]);
}

char tope()
{
    return(stack[top]);
}

int prec(char c)
{
    switch(c){
        case '+':
        case '-' : return 1;
                    break;
        case '*' :
        case '/' : return 2;
                   break;
        default:
                   return 0;
                   break;
        }
}

int main()
{

    char post[MAX],in[MAX],ch,element;
    scanf("%s",in);

    int i=0,k=0;

    in[strlen(in)] = ')';
    push('(');

    while((ch = in[i++]) != '\0')
    {
        if(isalnum(ch))
            post[k++] = ch;
        if(ch == '(') 
            push(ch);
        if(ch == ')')
        {
            while(tope() != '(')
            {
                post[k++] = pop();
            }
            pop();
        }
        if(ch == '+' || ch =='-' || ch == '*' || ch == '/')
        {
            while(prec(ch) <= prec(tope()))
            {
                post[k++] = pop();
            }
            push(ch);
        }
    }
    post[k] = '\0';

    printf("%s",post);

    return 0;a

}