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

void initiate (sequeue *s)/*��ʼ��*/
{
	s->front=0;
	s->rear=0;
	s->count=0;
}

/*���*/
int addqueue(sequeue *s,int n)
{
   while(n--)
   {
       int x;
       if((s->rear+1)%MAX==s->front)
        printf("����!!!");
       else
       {
           printf("������Ҫ��ӵ�����:");
           scanf("%d",&x);
           s->rear=(s->rear+1)%MAX;
           s->queue[s->rear]=x;
           s->count++;
       }
   }
}

void delqueue(sequeue *s,int n)     /*����*/
{
	int i=1;                       /*��ʾ�ǵڼ������ݳ���*/
	datatype x;                    /*���ӵ�����*/
	while(n--)
	{
		if(s->front==s->rear)            /*�жӿ�����*/
		{
			printf("�ӿ�!\n");
			return ;
		}
		s->front=(s->front+1)%MAX;
        x=(s->queue[s->front]);
		printf("��%d�����ӵ�����Ϊ��%d\n",i,x);
		i++;
	}
}

int gettop(sequeue *s )/*ȡ��ͷԪ��*/
{
   int x;
   if(s->front==s->rear)
    printf("�ӿ�!!!");
   else
    x=s->queue[s->front+1];
    printf("��ͷԪ��Ϊ:");
    printf("%d\n",x);
    return 1;
}

int Count(sequeue *s){                     //��ѭ�������е�Ԫ��
    return (s->rear-s->front+MAX)%MAX ;
}

void print(sequeue *s)   /*��ʾ���*/
{
	int m,i;
	m=(s->front+1)% MAX;
	if(s->front==s->rear)    /*�жӿ�����*/
		printf("�ӿ�!����ʾ���!\n");
	else
	{
		for(i=1;i<=Count(s);i++)
		{
			printf("queue[%d]����Ϊ�� %d\n",m,s->queue[m]);
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
    printf("\n���������ӵ����ݸ���:");
    scanf("%d",&n);
    addqueue(s,n);
    print(s);


    printf("\n����������ӵ����ݸ���:");
    scanf("%d",&n);
    delqueue(s,n);
    print(s);

    gettop(s);

    return 0;
}

