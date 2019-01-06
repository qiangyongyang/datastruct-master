#include<stdlib.h>
#include<stdio.h>

typedef struct
{
    int top;
    int data[0];
}Stack;

//创建栈
Stack * init(int n)
{
    if(n <= 0)
    {
        printf("请输入正确的栈大小!\n");
    }
    Stack *p = (Stack *)malloc(sizeof(Stack) + sizeof(int)*n );
    p->top = -1;
    return p;
}

void PushStack(Stack *p,int data)
{
     (p->top)++;
     p->data[p->top] = data;
}

int PopStack(Stack *p)
{
    (p->top)--;
}

void LookStackTop(Stack *p)
{
    printf("stack top:%d\n",p->data[p->top]);
}

void Print(Stack *p)
{
    if(p->top == -1)
    {
        printf("empty stack\n");
        return ;
    }
    int i = p->top;
    while(i > -1)
    {
        printf("---->%d\n",p->data[i--]);
    }
}

int main()
{
    Stack *a = init(5); //创建大小为5的栈
    PushStack(a,5);
    PushStack(a,4);
    PushStack(a,3);
    PushStack(a,2);
    PushStack(a,1);
    Print(a);
    PopStack(a);
    PopStack(a);
    Print(a);
    LookStackTop(a);
    return 0;
}






















