#include <iostream>
#include <cstdlib>
using namespace std;
struct node{
    int data;
    struct node *next;
}slnode;

slnode *init(){
    slnode *head;
    head=(slnode *)malloc (sizeof(slnode));
    head->next=null;
    return head;
}


int append(slnode *h){
    slnode *p,*q;
    int n,i;
    int a[10];
    printf("请输入单链表最初的结点数n=");
	scanf("%d",&n);
	printf("请输入各个结点数据域的值:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	p=h;
	for(int i=0;i<n-1;i++){
        if ((q=( slnode * )malloc(sizeof(slnode)))==NULL)
		{
			printf("新结点空间申请失败！\n");
			return 0;
		}
		q->data=a[i];
		q->next=null;                       //核心代码
		p->next=q;
		p=q;
	}
    return 1;
}



int insert (slnode *h,int n){
    slnode *p,*q;
    int i,j;
    int x;
    p=h;
    while(n){
        printf("请输入插入结点的位置及结点数据：");
		scanf("%d%d",&i,&x);
        p=h;
        j=0;
		while((p->next!=NULL)&&(j<i-1))
		{
			p=p->next;
			j++;
		}
		if(j!=i-1)
		{
			printf("\n插入位置不合理！\n");
		}
		else
		{
            q=(slnode *)malloc(sizeof(slnode));
            q->data=x;                                        //核心代码
            q->next=p->next;
            p->next=q;
            n--;
		}
    }
}



void delete (slnode *h,int n){
    slnode *p,*q;
    int i,j;
    p=h;
    while(n)
	{
		printf("请输入被删除结点的位置:");
		scanf("%d",&i);
		p=h;
		while((p->next!=NULL)&&(j<i-1))
        {
            p=p->next;
            j++;
        }
        if(j!=i-1)
        {
            printf("删除不合理!");
        }
        else
        {
            p->next=p->next->next;                //核心代码
            free(p->next)
        }
}



void search(slnode *h,int x){
    int l=1;
    slnode *p=h->next;
    while(p!=null && p->data!=x){
        p=p->next;
        l++;
    }
    if(p!=null){
       printf("查找成功，结点位置为:%d\n",l);
    }
}


void display(slnode *h){
    slnode *p=h->next;
    while(p!=null){
        printf("%d",p->data);
        p=p->next;
    }
}


int main()
{

    return 0;
}

























