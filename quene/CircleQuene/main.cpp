#include <stdio.h>
#include <stdlib.h>
#define MAX 6

typedef  int  datatype;
typedef  struct
{
	datatype queue[MAX];
	int front;
	int rear;
	int count;
} sequeue;

void initiate (sequeue *s)/*初始化*/
{
	s->front=0;
	s->rear=0;
	s->count=0;
}

/*入队*/
int addqueue(sequeue *s,int n)
{
   while(n--)
   {
       int x;
       if((s->rear+1)%MAX==s->front)
        printf("队满!!!");
       else
       {
           printf("请输入要入队的数据:");
           scanf("%d",&x);
           s->rear=(s->rear+1)%MAX;
           s->queue[s->rear]=x;
           s->count++;
       }
   }
}

void delqueue(sequeue *s,int n)     /*出队*/
{
	int i=1;                       /*显示是第几个数据出队*/
	datatype x;                    /*出队的数据*/
	while(n--)
	{
		if(s->front==s->rear)            /*判队空条件*/
		{
			printf("队空!\n");
			return ;
		}
		s->front=(s->front+1)%MAX;
        x=(s->queue[s->front]);
		printf("第%d个出队的数据为：%d\n",i,x);
		i++;
	}
}

int gettop(sequeue *s )/*取队头元素*/
{
   int x;
   if(s->front==s->rear)
    printf("队空!!!");
   else
    x=s->queue[s->front+1];
    printf("队头元素为:");
    printf("%d\n",x);
    return 1;
}

int Count(sequeue *s){                     //求循环队列中的元素
    return (s->rear-s->front+MAX)%MAX ;
}

void print(sequeue *s)   /*显示输出*/
{
	int m,i;
	m=(s->front+1)% MAX;
	if(s->front==s->rear)    /*判队空条件*/
		printf("队空!无显示输出!\n");
	else
	{
		for(i=1;i<=Count(s);i++)
		{
			printf("queue[%d]数据为： %d\n",m,s->queue[m]);
			m=(m+1)%MAX;
		}
	}
}



int main()
{
    int n;
	sequeue *s;
    s=( sequeue *)malloc(sizeof(sequeue));

	initiate(s);
    printf("\n请输入待入队的数据个数:");
    scanf("%d",&n);
    addqueue(s,n);
    print(s);


    printf("\n请输入待出队的数据个数:");
    scanf("%d",&n);
    delqueue(s,n);
    print(s);

    gettop(s);

    return 0;
}

