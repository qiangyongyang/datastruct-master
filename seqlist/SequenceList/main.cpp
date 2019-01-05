#include <stdio.h>
#define MAXLEN 50
#include <cstdlib>

typedef struct
{
	int data[100];
	int len;
}Seqlist;

Seqlist *Inint_Seqlist();
int insertq(Seqlist *l,int n);
int deleteq(Seqlist *l,int n);
int print(Seqlist *l);

int  main()
{
	Seqlist *l;
	int s,n;
	int i = 0 ;    /* s ѡ�����룬 n �����ɾ�����ݵĸ���*/
	while(1){
        printf("���������ѡ��: ");
        scanf("%d",&s);
        switch(s)
        {
            case 1:
            {
              l=Inint_Seqlist();
                  printf("��ɳ�ʼ�� !\n");
                break;
            }
            case 2:
            {
                printf("���������������ݸ���:");
                scanf("%d",&n);
                insertq(l,n);
                print(l);
                break;
            }
            case 3:
            {
                printf("�������ɾ�������ݸ���:");
                scanf("%d",&n);
                deleteq(l,n);
                print(l);
                break;
            }
            case 4:
            {
                print(l);
                printf("������ɾ����λ��:");
                scanf("%d",&i);
                break;
            }
            case 5:
            {
                //exit(0) ;
                return 0;
            }
            default:
                {
                    printf("���ѡ���Ǵ����!\n ");
                    break;
                }
          }
	}
}
Seqlist *Inint_Seqlist() /*��ʼ��*/
{	Seqlist *l;
	l=(Seqlist*)malloc(sizeof(Seqlist));
	l->len=0;
	return l;
}

int insertq(Seqlist *l,int n)      /*����*/
{
    int i,j,x;
    while(n!=0)
    {
    if(l->len==MAXLEN-1)
        printf("�ñ��������޷�����");
      printf("����Ҫ���������:");
      scanf("%d",&x);
    printf("����������λ��:");
		scanf("%d",&i);
     if(i<1||i>l->len+1)
           printf("����λ�ô���");
     else
     {
        for(j=l->len;j>=i;j--)
            l->data[j+1]=l->data[j];
         l->data[i]=x;
         l->len++;
         n--;
         printf("����ɹ���\n");
     }
    }
    return 1;
}

int deleteq(Seqlist *l,int n)           /*ɾ��*/
{
	int i,j;  /*  i ɾ��λ�ã� j ˳����±� */
	while(n!=0)
	{
		if (l->len==0)
		{
			printf ("\n ��գ�����ɾ����\n");
			return 0;
		}
		printf("������ɾ����λ��:");
		scanf("%d",&i);
		if (i<1||i>l->len)
		{
			printf ("\n ɾ��λ�ô���!\n");
		}
		else
		{
			for ( j=i+1; j<=l->len; j++)
				l->data[j-1]=l->data[j];
			l->len--;
			n--;
		}
	}
	printf("ɾ����ɣ�\n");
	return 1;
}

int print (Seqlist *l)           /*��ʾ���*/
{
	int m;
	if (l->len==0)
	{
		printf("˳���Ϊ��!\n");
		return 0;
	}
	else
	{
		printf("��ǰ��˳���Ϊ:\n");
		for(m=1;m<=l->len;m++)
			printf("data[%d]=%d  ",m,l->data[m]);
		printf("\n��Ϊ%d\n",l->len);
		return 1;
	}
}
