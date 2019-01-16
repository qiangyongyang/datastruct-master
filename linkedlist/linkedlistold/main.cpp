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
    printf("�����뵥��������Ľ����n=");
	scanf("%d",&n);
	printf("�������������������ֵ:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	p=h;
	for(int i=0;i<n-1;i++){
        if ((q=( slnode * )malloc(sizeof(slnode)))==NULL)
		{
			printf("�½��ռ�����ʧ�ܣ�\n");
			return 0;
		}
		q->data=a[i];
		q->next=null;                       //���Ĵ���
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
        printf("������������λ�ü�������ݣ�");
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
			printf("\n����λ�ò�����\n");
		}
		else
		{
            q=(slnode *)malloc(sizeof(slnode));
            q->data=x;                                        //���Ĵ���
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
		printf("�����뱻ɾ������λ��:");
		scanf("%d",&i);
		p=h;
		while((p->next!=NULL)&&(j<i-1))
        {
            p=p->next;
            j++;
        }
        if(j!=i-1)
        {
            printf("ɾ��������!");
        }
        else
        {
            p->next=p->next->next;                //���Ĵ���
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
       printf("���ҳɹ������λ��Ϊ:%d\n",l);
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

























