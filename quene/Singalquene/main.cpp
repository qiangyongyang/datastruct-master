
#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 60 //存储数据元素的最大个数

typedef struct {
    int data[MAXSIZE];
    int front; //记录队列头元素位置
    int rear; //记录队列尾元素位置
}Queue;

Queue* CreateQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) {
        printf("空间不足\n");
        return NULL;
    }
    q->front = 0;
    q->rear = 0;
    return q;
}


void AddQ(Queue* q, int num) {
    if ( q->rear  == MAXSIZE ) {
        printf("队列已满\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = num;
}



int DeleteQ(Queue* q) {
    if (q->rear == q->front) {
        printf("空队列\n");
        return NULL;
    }
    q->front++;
    return q->data[q->front];
}

void PrintQueue(Queue* q) {
    if (q->rear == q->front) {
        printf("空队列\n");
        return;
    }
    printf("打印队列数据元素：\n");
    int index = q->front;
    for (int i = 0; i < (q->rear - q->front); i++) {
        index++;
        printf("%d ", q->data[index]);
    }
    printf("\n");
}

int main() {
    Queue* q = CreateQueue();

    AddQ(q, 0);
    AddQ(q, 1);
    AddQ(q, 2);
    AddQ(q, 3);
    AddQ(q, 4);
    AddQ(q, 5);
    PrintQueue(q);

    DeleteQ(q);
    DeleteQ(q);
    DeleteQ(q);
    PrintQueue(q);

    AddQ(q, 6);
    AddQ(q, 7);
    AddQ(q, 8);
    PrintQueue(q);

    return 0;
}
