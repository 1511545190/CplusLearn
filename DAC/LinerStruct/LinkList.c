//
// Created by 刘日亮 on 2022/12/31.
//带有头指针的链表，
//
// 带有头结点的链表，所有功能都是指向下一个节点
// head node
//    [x]----->[C]---->[A]----->
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
    int index;
};
//初始化
void init(struct Node **pNode);

//求表长
int getlength(struct Node* head);

struct Node* findKth(struct Node* head,int k)
{
    int count =1;
    struct Node* p;
    p=head;
    while(p&&count<k)
    {
        p=p->next;
        count++;
    }
    return p;
}
//print
void print(struct Node* head);

//插入
int  insert(struct Node **pNode,int k,int value);
//删除
int deleteNode(struct Node**pNode,int k)
{
    if(!*pNode||k<1)
        return -1;
    else if(k==1||*pNode){//删除第一个
        *pNode = (*pNode)->next;  //要加括号
    }else{
        struct Node* p =findKth(*pNode,k-1);
        //没有第k个或者没有第k-1个
        if(p==NULL||p->next==NULL)
            return 0;

        //跨node相连
        struct Node* temp = p->next;
        p->next=temp->next;

        free(p);



    }

}
int main()
{
    struct Node* head;
    //指针的指针才能修改指针
    init(&head);
//    int k = getlength(head);
//    printf("%d\n",k);
    //k从1开始数
    insert(&head,1,11);
    insert(&head,1,0);
    insert(&head,3,22);
    print(head);
    deleteNode(&head,2);
    print(head);
    return 0;
}

int insert(struct Node **pNode,int k,int value) {
    if(k==1){
        struct Node* temp = (struct Node*)malloc(sizeof (struct Node));
        temp->next = NULL;
        temp->data = value;

        //temp 是第一个
        temp->next = *pNode;
        *pNode = temp;
    }
    else {

        //先找第k-1个位置
        struct Node *p = findKth(*pNode,k-1);

        //if(t==k-1)
        if (p) {
            struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
            temp->next = NULL;
            temp->data = value;

            temp->next = p->next;
            p->next = temp;

        }
    }
}

void init(struct Node **pNode) {
    *pNode = NULL;
}

int getlength(struct Node *head) {
    int len=0;
    //head 为局部变量
    while(head){
        len++;
        //并没有给头指针
        head=head->next;
    }
    return len;
}

void print(struct Node *head) {
    while(head){
        printf("%d, ",head->data);
        head=head->next;
    }
    printf("\n");
}

