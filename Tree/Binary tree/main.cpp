#include <iostream>
#include<string.h>
#include <cstdlib>
#include <cstdio>
#include<stack>
#include <queue>
using namespace std;

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
/*
                       1
                2              3
              4   5        6
                         7   8

*/
//1 2 4-1 -1 5 -1 -1 3 6 7 -1 -1 8-1 -1 -1
BiTree CreateBinTree()  // 以递归方式建立二叉树
{
    BiTree T;
    int num;
    scanf("%d",&num);

    if(num==-1)
       T=NULL;   // 以-1作为空结点的值以结束递归
    else
    {
        T=(BiTNode*)malloc(sizeof(BiTNode));
        T->data=num;
        T->lchild=CreateBinTree();
        T->rchild=CreateBinTree();
    }
  return T;
}

void PreOrder(BiTree bt)          //前序遍历
{
    if(bt!=NULL){
        printf("%d ",bt->data);
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}


void PreOrderNoRecursive(BiTree bt){
    stack <BiTree > s;
    BiTree p=bt;
    while(p!=NULL || !s.empty()){
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            s.push(p);
            p=p->lchild;
        }
        if(!s.empty())
        {
            p=s.top();
            s.pop();
            p=p->rchild;
        }
    }
}





void Inorder(BiTree bt){
    if(bt!=NULL){
        Inorder(bt->lchild);
        printf("%d ",bt->data);
        Inorder(bt->rchild);
    }
}



void InorderNoRecursive(BiTree bt){
    stack<BiTree >s;
    BiTree p=bt;
    while(p!=NULL || !s.empty()){
        while(p!=NULL){
            s.push(p);
            p=p->lchild;
        }
        if(!s.empty()){
            p=s.top();
            cout<<p->data<<" ";
            s.pop();
            p=p->rchild;
        }
    }
}



void PostOrder(BiTree bt){
    if(bt!=NULL){
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
        printf("%d ",bt->data);
    }
}


void PostOrderPostOrder(BiTree bt){
    stack<BiTree> s;
    BiTree cur;                      //当前结点
    BiTree pre=NULL;                 //前一次访问的结点
    s.push(bt);
    while(!s.empty())
    {
        cur=s.top();
        if((cur->lchild==NULL&&cur->rchild==NULL)||(pre!=NULL&&(pre==cur->lchild||pre==cur->rchild)))
        {
            cout<<cur->data<<" ";  //如果当前结点没有孩子结点或者孩子节点都已被访问过
            s.pop();
            pre=cur;
        }
        else
        {
            if(cur->rchild!=NULL)
                s.push(cur->rchild);
            if(cur->lchild!=NULL)
                s.push(cur->lchild);
        }
    }
}



void transLevel(BiTree bt){
    queue <BiTree> q;

    BiTree p;
    if(bt!=NULL)
        printf("%d ",bt->data);
    q.push(bt);

    while(!q.empty()){
        p=q.front();
        q.pop();
        if(p->lchild!=NULL){
            printf("%d ",p->lchild->data);
            q.push(p->lchild);
        }
        if(p->rchild!=NULL){
            printf("%d ",p->rchild->data);
            q.push(p->rchild);
        }
    }
}


int AllNode(BiTree bt){
    if(bt==NULL)
        return 0;
    else
        return (1+ AllNode(bt->lchild)+AllNode(bt->rchild));
}


int LeafNode(BiTree bt){
    if(bt==NULL)
        return 0;
    else if(bt->lchild==NULL && bt->rchild==NULL)
        return 1;
    else
        return LeafNode(bt->lchild)+LeafNode(bt->rchild);
}


int heigh(BiTree bt){
    if(bt==NULL)
        return 0;
    return 1+max(heigh(bt->lchild),heigh(bt->rchild));
}

int main()
{
    BiTree bt;

    bt=CreateBinTree();

    printf("先序为：\n");
    PreOrder(bt);
    printf("\n");
    PreOrderNoRecursive(bt);
    printf("\n");

    printf("中序为：\n");
    Inorder(bt);
    printf("\n");
    InorderNoRecursive(bt);
    printf("\n");

    printf("后序为：\n");
    PostOrder(bt);
    printf("\n");
    PostOrderPostOrder(bt);
    printf("\n");

    printf("层次遍历为：\n");
    transLevel(bt);
    printf("\n");


    printf("结点总数为:");
    printf("%d",AllNode(bt));
    printf("\n");

    printf("叶子结点总数：");
    printf("%d",LeafNode(bt));
    printf("\n");

    printf("树的深度为：");
    printf("%d",heigh(bt));
    printf("\n");

}


























































