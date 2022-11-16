#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct {
    int* a;
    int front; //指向队头位置
    int rear;  //指向队尾的下一个元素
    int k;
} MyCircularQueue;


//多申请一个空间位置,这样对循环队列的队满队空好容易判断
// 
//构造器，设置队列长度为 k
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* new = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (new == NULL)
    {
        perror("malloc file");
        exit(-1);
    }
    new->a = (int*)malloc(sizeof(int) * (k + 1));
    if (new->a == NULL)
    {
        perror("malloc file");
        exit(-1);
    }
    new->k = k;
    new->front = new->rear = 0;
    return new;
}

//向循环队列插入一个元素。如果成功插入则返回真。
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    assert(obj);
    if ((obj->rear + 1) % (obj->k + 1) == obj->front)
        return false;
    else
    {
        obj->a[obj->rear] = value;
        if (obj->rear == obj->k)
            obj->rear = 0;
        else
            obj->rear += 1;
        // obj->a[obj->rear++] = value;
        // obj->rear %= (obj->k+1);    
        return true;
    }
}

//从循环队列中删除一个元素。如果成功删除则返回真。
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    assert(obj);
    if (obj->front == obj->rear)
    {
        return false;
    }
    else
    {
        if (obj->front == obj->k)
            obj->front = 0;
        else
            obj->front += 1;
        // obj->front++;
        // obj->front %= (obj->k+1);
        return true;
    }
}

//从队首获取元素。如果队列为空，返回 - 1
int myCircularQueueFront(MyCircularQueue* obj) {
    assert(obj);

    if (obj->front == obj->rear)
    {
        return -1;
    }
    else
    {
        return obj->a[obj->front];
    }
}

//获取队尾元素。如果队列为空，返回 - 1 。
int myCircularQueueRear(MyCircularQueue* obj) {
    assert(obj);

    if (obj->front == obj->rear)
    {
        return -1;
    }
    else
    {
        if (obj->rear == 0)
        {
            return obj->a[obj->k];
        }
        else
        {
            return obj->a[obj->rear - 1];
        }

    }
}

//检查循环队列是否为空。
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    assert(obj);

    return obj->front == obj->rear;
}

//检查循环队列是否已满。
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    assert(obj);

    return (obj->rear + 1) % (obj->k + 1) == obj->front;
}

//释放队列，释放申请的堆空间 需要注意这里申请了两层堆，需要依次free掉
void myCircularQueueFree(MyCircularQueue* obj) {


    free(obj->a);
    free(obj);
}