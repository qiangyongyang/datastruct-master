#include <cstdio>
#include <cstdlib>
int a[100];

typedef struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
}BSTree;


//�ݹ����
int Find(BSTree *bt,int num){
    if(bt==NULL){
        return NULL;
    }
    else{
        if(num == bt->data ){
            return bt->data ;
        }
        else if(num < bt->data){
            return Find(bt->lchild,num);
        }
        else{
            return Find(bt->rchild,num);
        }
    }
}

//�ǵݹ����
int FindNoDigui(BSTree *bt,int num){
    while(bt != NULL){
        if(num == bt->data){
            return bt->data
        }
    }
}


//�ݹ齨��
void Insert(BSTree *bt,int num){
    if(bt==NULL){
        BSTree *p=(BSTree *)malloc(sizeof(BSTree));
        p->data = num;
        p->lchild = NULL;
        p->rchild = NULL;
        bt=p;
    }
    else if(num < bt->data){
        Insert(bt->lchild , num);
    }
    else{
        Insert(bt->rchild , num);
    }
}


//ɾ��
//a��ɾ��Ҷ�ӽ�㣬ֻҪ����˫�׽�����ӵ�����ָ���ÿռ��ɡ�
//b��ɾ����֧��㣬ֻҪ������ָ�����ӵ������ڵ�����λ�ü���
//c��ɾ��˫֧��㣬һ����õķ��������Ȱ���������ǰ������ֵ�����ý���ֵ��
//Ȼ����ɾ����������ǰ����㣬����������ǰ����㻹��˫֧��㣬����������ͬ���Ĳ�����
//����Ҷ�ӽ���֧���������Ӧ�Ĳ��������Ǹ�����������
int Delete(BSTree *bt, int num){
    BSTree *temp;
    temp=bt;
    if(bt == NULL ){
        return 0;
    }
    if(num < bt->data){                  //��ɾ��Ԫ��С���������ֵ����������������ɾ��
        return Delete(bt->lchild, num);
    }
    if(num > bt->data){                    //��ɾ��Ԫ�ش����������ֵ����������������ɾ��
        return Delete(bt->rchild, num);
    }


    if(bt->lchild == NULL){              //��ɾ��Ԫ�ص����������ֵ��������Ϊ�գ�����������Ϊ������������1

        bt=bt->rchild;
        free(temp);
        return 1;
    }
    else if(bt->rchild == NULL){           //��ɾ��Ԫ�ص����������ֵ��������Ϊ�գ�����������Ϊ������������1
        bt=bt->lchild;
        free(temp);
        return 1;
    }
    else{                                  //��ɾ��Ԫ�ص����������ֵ��������������Ϊ��ʱ�������


        if(bt->lchild->rchild == NULL){   //����ǰ�����������ӽ��ʱ�������ӽ�㸳ֵ���������
                                        //Ȼ�����������ɾ�������
            bt->data ==bt->lchild->data;
            return Delete(bt->lchild,bt->data);
        }
        else{  //���ҳ�����ǰ����㣬�Ѹý��ֵ����������㣬Ȼ�������ǰ�����Ϊ����������ɾ�������
            BSTree *p1=bt;
            BSTree *p2=p1->lchild;
            while(p2->rchild != NULL){
                p1=p2;
                p2=p2->rchild;
            }
            bt->data = p2->data;
            return Delete(p1->rchild, p2->data);

        }
    }


}




void createBSTree(BSTree *bt,int n){
    bt = NULL;
    for(int i=0;i<n;i++){
        Insert(bt,a[i]);
    }
}


void InOrder(BSTree *bt){
    if(bt != NULL){
        InOrder(bt->lchild);
        printf("%d ",bt->data);
        InOrder(bt->rchild);
    }
}


int main()
{
    int a[10]={30,50,20,40,25,70,54,23,80,92};
    int x;
    BSTree *bt = NULL;
    createBSTree(bt,10);

    printf("���������\n");
    InOrder(bt);
    printf("\n");

    printf("���������Ԫ��ֵ��");
    scanf(" %d", &x);//��ʽ���еĿո���������κοհ׷�
    if (x = Find(bt, x))
        printf("���ҳɹ����õ���xΪ��%d\n", x);
    else
        printf("����ʧ�ܣ�\n");



    printf("���������Ԫ��ֵ��");
    scanf(" %d", &x);
    Insert(bt, x);

    printf("���������Ԫ��ֵ��");
    scanf(" %d", &x);
    Insert(bt, x);

    printf("���������Ԫ��ֵ��");
    scanf(" %d", &x);
    Insert(bt, x);



    printf("������Ӧ��������������Ϊ��\n");
    InOrder(bt);
    printf("\n");

    printf("�����ɾ��Ԫ��ֵ��");
    scanf(" %d", &x);
    if (Delete(bt, x))
        printf("1\n");
    else
        printf("0\n");


    printf("������Ӧ��������������Ϊ��\n");
    InOrder(bt);
    printf("\n");

    return 0;
}




