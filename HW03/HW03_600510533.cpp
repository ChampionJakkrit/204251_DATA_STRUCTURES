#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int top = -1;
char stack[100];
int i, s;

int push(int x)
{
    if (top >= 100) // max = 100
    {
        assert(0); // ถ้าเกินให้ไม่ทำ
    }
    else {
        top = top + 1;
        stack[top] = x;
        return stack[top];
    }
}

int pop()
{
    if (top == -1){
        return 0;
    }
    else{
        top = top - 1;
        return top;
    }
}
int getTop()
{
    if (top == -1){
        return 0;
    }
    else{
        return stack[top];
    }
}
bool isEmpty()
{
    if (top == -1){
        return true;
    }
    else{
        return false;
    }
}

int size()
{
    s = top + 1;
    return s;
}
int main()
{
    char n[100];
    int len = strlen(n);
    scanf("%s", n);
    for (i = 0 ;i < len; i++)
    {
        if (n[i] == '+' || n[i] == '-' || n[i] == '*'|| n[i] == '/') {
            push(n[i]);
            }
        else {
            printf("%c", n[i]);
            printf("%c", getTop());
        }
        
    }
     

    return 0;
}
   
