//
// Created by 刘日亮 on 2022/12/31.
//
#include <stdio.h>
#include <stdlib.h>
struct Queue{
    int *data;
    int capacity;
    int front;
    int rear;
    int size;
};
//初始化
void init(struct Queue* pq, int capacity){
    pq->capacity = capacity;
    //准备用相对位置来判断是否满了，所以要size+1
    pq->data = (int*)malloc(sizeof (int)*capacity + 1);
    pq->front= pq->rear= 0;
    pq->size = 0;
}
int isFull(const struct Queue* pq){
    //当0，1，2，3，4
    // 5%5 = 0
    if((pq->rear +1)% (pq->capacity +1) == pq->front) return 1;
    else return 0;
}
int isEmpty(const struct Queue* pq){
    return  pq->rear==pq->front;
}
//入队
int enQueue(struct Queue* pq,int x){
    if(isFull(pq))return 0;
    else{
        pq->data[pq->rear] = x;
        pq->rear = (pq->rear +1) % (pq->capacity+1);
        pq->size++;
        return 1;
    }
}
//出队
int deQueue(struct Queue* pq,int *x)
{
    if(isEmpty(pq)) return 0;
    else{
        *x = pq->data[pq->front];
        pq->front=( pq->front +1) % (pq->capacity+1);
        pq->size --;
    }
}

int main()
{
    struct Queue q;
    init(&q,3);

    //银行排队
    char op[20];
    int id;
    scanf("%s",op);
    while(op[0]!='#'){
        if(op[0]=='I'){
            scanf("%d",&id);
            if(isFull(&q)){
                printf("<%d> rejected.\n",id);
            }else{
                enQueue(&q,id);
                printf("<%d> joined. Total %d\n",id,q.size);
            }
        }
        else
        {
            if(isEmpty(&q)){
                //无人等
                printf("No one!\n");
            }else{
                deQueue(&q,&id);
                printf("<%d> called total %d\n",id,q.size);
            }
        }
        scanf("%s",op);
    }


    return 0;
}