//
// Created by 刘日亮 on 2022/12/31.
// 顺序表

//sequence list
#include <stdio.h>
#define MAX 10

struct Slist{
    int data[MAX];
    int length;
};

//initial
void init(struct Slist* p);


//insert,可能成功，可能失败，要返回状态码
int insert(struct Slist* p, int k, int x);

//delete
int delete(struct Slist *p, int k);

//print list
void printList(const struct Slist *slist);

int main()
{
    struct Slist a;
    init(&a);
    printf("length:%d\n",a.length);
    insert(&a,0,1);
    printf("length:%d\n",a.length);
    insert(&a,1,2);
    printf("length:%d\n",a.length);
    printList(&a);
    delete(&a,1);
    printList(&a);
    return 0;
}

//print
void printList(const struct Slist* slist) {
    for (int i = 0; i < slist->length; i++)
        printf("%d ", slist->data[i]);

}
//initial
void init(struct Slist* p){
    p->length = -1;
}

int insert(struct Slist *p,int k ,int x) {
    //当满了或者位置不合法
    if((k<0||k>p->length)&&p->length<MAX)
        return 0;
    else{
        //挪动元素,i从最后一个下标开始
        for(int i = p->length-1;i>=k;i--){
            //后面的元素等于前面的
            p->data[i+1]=p->data[i];
        }
        p->data[k] = x;
        p->length++;

    }

}

int delete(struct Slist *p, int k) {
    if(k<0||k>=p->length) return 0;
    //删除，前挪

    for(int i = k+1;i<p->length;i++)
        p->data[i-1]=p->data[i];
    p->length--;

    return 0;
}


