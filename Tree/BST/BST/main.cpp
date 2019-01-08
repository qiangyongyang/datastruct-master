#include <cstdio>
#include <cstdlib>
int a[100];

typedef struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
}BSTree;


//递归查找
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

//非递归查找
int FindNoDigui(BSTree *bt,int num){
    while(bt != NULL){
        if(num == bt->data){
            return bt->data
        }
    }
}


//递归建立
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


//删除
//a：删除叶子结点，只要将其双亲结点链接到它的指针置空即可。
//b：删除单支结点，只要将其后继指针链接到它所在的链接位置即可
//c：删除双支结点，一般采用的方法是首先把它的中序前驱结点的值赋给该结点的值域，
//然后再删除它的中序前驱结点，若它的中序前驱结点还是双支结点，继续对其做同样的操作，
//若是叶子结点或单支结点则做对应的操作，若是根结点则结束。
int Delete(BSTree *bt, int num){
    BSTree *temp;
    temp=bt;
    if(bt == NULL ){
        return 0;
    }
    if(num < bt->data){                  //带删除元素小于树根结点值，继续在左子树中删除
        return Delete(bt->lchild, num);
    }
    if(num > bt->data){                    //带删除元素大于树根结点值，继续在右子树中删除
        return Delete(bt->rchild, num);
    }


    if(bt->lchild == NULL){              //待删除元素等于树根结点值且左子树为空，将右子树作为整个树并返回1

        bt=bt->rchild;
        free(temp);
        return 1;
    }
    else if(bt->rchild == NULL){           //待删除元素等于树根结点值且右子树为空，将左子树作为整个树并返回1
        bt=bt->lchild;
        free(temp);
        return 1;
    }
    else{                                  //待删除元素等于树根结点值且左右子树均不为空时处理情况


        if(bt->lchild->rchild == NULL){   //中序前驱结点就是左孩子结点时，把左孩子结点赋值给树根结点
                                        //然后从左子树中删除跟结点
            bt->data ==bt->lchild->data;
            return Delete(bt->lchild,bt->data);
        }
        else{  //查找出中序前驱结点，把该结点值赋给树根结点，然后从中序前驱结点为根结点的树上删除根结点
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

    printf("中序遍历：\n");
    InOrder(bt);
    printf("\n");

    printf("输入待查找元素值：");
    scanf(" %d", &x);//格式串中的空格可以跳过任何空白符
    if (x = Find(bt, x))
        printf("查找成功！得到的x为：%d\n", x);
    else
        printf("查找失败！\n");



    printf("输入待插入元素值：");
    scanf(" %d", &x);
    Insert(bt, x);

    printf("输入待插入元素值：");
    scanf(" %d", &x);
    Insert(bt, x);

    printf("输入待插入元素值：");
    scanf(" %d", &x);
    Insert(bt, x);



    printf("进行相应操作后的中序遍历为：\n");
    InOrder(bt);
    printf("\n");

    printf("输入待删除元素值：");
    scanf(" %d", &x);
    if (Delete(bt, x))
        printf("1\n");
    else
        printf("0\n");


    printf("进行相应操作后的中序遍历为：\n");
    InOrder(bt);
    printf("\n");

    return 0;
}




