#include <iostream>
#include <cstdlib>
using namespace std;
struct dlnode{
   int x;
   struct dlnode *pre,*next;
};

void after_insert (dlnode *h)   //在p之后插入s
{
    dlnode *s,*p;
    s->pre=p;
    s->next=p->next;
    p->next->pre=s;
    p->next=s;
}

void pre_insert(dlnode *h)        //在p之qian插入s
{
    dlnode *s,*p;
    s->pre=p->pre;
    s->next=p;
    p->pre->next=s;
    p->pre=s;
}


void delete(dlnode *h)
{
    dlnode *p;
    p->pre->next=p->next;
    p->next->pre=p->pre;
    free(p);

}

void createdlnode(dlnode *h){
    h->next=h;
    h->pre=h;
    int x;
    dlnode *s;

   while(1){
        s=(dlnode *)malloc(sizeof(dlnode));
        s->data=x;
       + s->next=h->next;
        s->pre=h;
        head->next->pre=s;
        head->next=s;
   }

}


int main()
{

    return 0;
}
