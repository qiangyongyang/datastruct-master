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
	int i = 0 ;    /* s 选择输入， n 插入或删除数据的个数*/
	while(1){
        printf("请输入你的选择: ");
        scanf("%d",&s);
        switch(s)
        {
            case 1:
            {
              l=Inint_Seqlist();
                  printf("完成初始化 !\n");
                break;
            }
            case 2:
            {
                printf("请输入待插入的数据个数:");
                scanf("%d",&n);
                insertq(l,n);
                print(l);
                break;
            }
            case 3:
            {
                printf("请输入待删除的数据个数:");
                scanf("%d",&n);
                deleteq(l,n);
                print(l);
                break;
            }
            case 4:
            {
                print(l);
                printf("请输入删除的位置:");
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
                    printf("你的选择是错误的!\n ");
                    break;
                }
          }
	}
}
Seqlist *Inint_Seqlist() /*初始化*/
{	Seqlist *l;
	l=(Seqlist*)malloc(sizeof(Seqlist));
	l->len=0;
	return l;
}

int insertq(Seqlist *l,int n)      /*插入*/
{
    int i,j,x;
    while(n!=0)
    {
    if(l->len==MAXLEN-1)
        printf("该表已满，无法插入");
      printf("输入要插入的数据:");
      scanf("%d",&x);
    printf("请输入插入的位置:");
		scanf("%d",&i);
     if(i<1||i>l->len+1)
           printf("插入位置错误");
     else
     {
        for(j=l->len;j>=i;j--)
            l->data[j+1]=l->data[j];
         l->data[i]=x;
         l->len++;
         n--;
         printf("插入成功！\n");
     }
    }
    return 1;
}

int deleteq(Seqlist *l,int n)           /*删除*/
{
	int i,j;  /*  i 删除位置， j 顺序表下标 */
	while(n!=0)
	{
		if (l->len==0)
		{
			printf ("\n 表空，不能删除！\n");
			return 0;
		}
		printf("请输入删除的位置:");
		scanf("%d",&i);
		if (i<1||i>l->len)
		{
			printf ("\n 删除位置错误!\n");
		}
		else
		{
			for ( j=i+1; j<=l->len; j++)
				l->data[j-1]=l->data[j];
			l->len--;
			n--;
		}
	}
	printf("删除完成！\n");
	return 1;
}

int print (Seqlist *l)           /*显示输出*/
{
	int m;
	if (l->len==0)
	{
		printf("顺序表为空!\n");
		return 0;
	}
	else
	{
		printf("当前的顺序表为:\n");
		for(m=1;m<=l->len;m++)
			printf("data[%d]=%d  ",m,l->data[m]);
		printf("\n表长为%d\n",l->len);
		return 1;
	}
}
