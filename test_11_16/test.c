#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct {
    int* a;
    int front; //ָ���ͷλ��
    int rear;  //ָ���β����һ��Ԫ��
    int k;
} MyCircularQueue;


//������һ���ռ�λ��,������ѭ�����еĶ����ӿպ������ж�
// 
//�����������ö��г���Ϊ k
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

//��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
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

//��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
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

//�Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� - 1
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

//��ȡ��βԪ�ء��������Ϊ�գ����� - 1 ��
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

//���ѭ�������Ƿ�Ϊ�ա�
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    assert(obj);

    return obj->front == obj->rear;
}

//���ѭ�������Ƿ�������
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    assert(obj);

    return (obj->rear + 1) % (obj->k + 1) == obj->front;
}

//�ͷŶ��У��ͷ�����Ķѿռ� ��Ҫע����������������ѣ���Ҫ����free��
void myCircularQueueFree(MyCircularQueue* obj) {


    free(obj->a);
    free(obj);
}