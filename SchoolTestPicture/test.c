#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define M 20
int visited[M];
//����
typedef struct node {
	int adjvex;
	struct node* next;
}edgenode;

//�ڽӱ��ͷԪ��
typedef struct vnode {
	char vertex;
	edgenode* firstedge;
}vertexnode;

//�ڽӱ�����
typedef struct {
	vertexnode adjlist[M];
	int n, e;
}linkedgroud;

//����һ���ڽӱ�
void creatgroud(linkedgroud* g) {
	int i, j, k;
	edgenode* s;
	printf("�������ͼ�Ķ������ͱ�����\n");
	scanf("%d %d", &g->n, &g->e);
	printf("��������������ֵ��\n");
	for (i = 0; i < g->n; i++) {
		scanf("%c", &g->adjlist[i].vertex);
		g->adjlist[i].firstedge = NULL;    //��ʼ��
	}
	printf("������һ��������������ڽӱ����\n");
	for (k = 0; k < g->e; k++) {
		scanf("%d %d", &i, &j);
		s = (edgenode*)malloc(sizeof(edgenode));
		s->adjvex = j;
		s->next = g->adjlist[i].firstedge;
		g->adjlist[i].firstedge = s;
		s = (edgenode*)malloc(sizeof(edgenode));
		s->adjvex = i;
		s->next = g->adjlist[j].firstedge;
		g->adjlist[j].firstedge = s;
	}
}

//dfs����һ����ͨ����
void dfs(linkedgroud g, int i) {
	edgenode* p;
	printf("������ȱ�����%c\n", g.adjlist[i].vertex);
	visited[i] = 1;
	p = g.adjlist[i].firstedge;
	while (p) {
		if (!visited[p->adjvex])
			dfs(g, p->adjvex);
		p = p->next;
	}
}

//��ȱ�������ͼ
void dfsgroud(linkedgroud g) {
	int i;
	for (i = 0; i < g.n; i++) {
		visited[i] = 0;
	}
	for (i = 0; i < g.n; i++) {
		if (!visited[i])
			dfs(g, i);
	}
}

//bfs����һ����ͨ����
void bfs(linkedgroud g, int i) {
	int j;
	edgenode* p;
	int queue[M], front, rear;
	front = rear = 0;
	printf("������ȱ�����%c\n", g.adjlist[i].vertex); //�����ʽ�����
	visited[i] = 1;         //�����ʽ�����
	queue[rear++] = i;
	while (rear > front) {
		j = queue[front++];   //����
		p = g.adjlist[j].firstedge;
		while (p) {
			if (visited[p->adjvex] == 0) {
				printf("������ȱ�����%c\n", g.adjlist[p->adjvex].vertex);
				queue[rear++] = p->adjvex;
				visited[p->adjvex] = 1;
			}
			p = p->next;
		}
	}
}
//bfs��������ͼ
void bfsgroud(linkedgroud g) {
	int i;
	for (i = 0; i < g.n; i++) {
		visited[i] = 0;
	}
	for (i = 0; i < g.n; i++) {
		if (visited[i] == 0) {
			bfs(g, i);
		}
	}
}
int main() {
	linkedgroud g;
	creatgroud(&g);
	dfsgroud(g);
	bfsgroud(g);
}