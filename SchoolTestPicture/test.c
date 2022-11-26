#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define M 20
int visited[M];
//表结点
typedef struct node {
	int adjvex;
	struct node* next;
}edgenode;

//邻接表表头元素
typedef struct vnode {
	char vertex;
	edgenode* firstedge;
}vertexnode;

//邻接表主表
typedef struct {
	vertexnode adjlist[M];
	int n, e;
}linkedgroud;

//创建一个邻接表
void creatgroud(linkedgroud* g) {
	int i, j, k;
	edgenode* s;
	printf("请输入该图的顶点数和边数：\n");
	scanf("%d %d", &g->n, &g->e);
	printf("请输入各个顶点的值：\n");
	for (i = 0; i < g->n; i++) {
		scanf("%c", &g->adjlist[i].vertex);
		g->adjlist[i].firstedge = NULL;    //初始化
	}
	printf("请输入一条边两个顶点的邻接表序号\n");
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

//dfs遍历一个连通分量
void dfs(linkedgroud g, int i) {
	edgenode* p;
	printf("深度优先遍历：%c\n", g.adjlist[i].vertex);
	visited[i] = 1;
	p = g.adjlist[i].firstedge;
	while (p) {
		if (!visited[p->adjvex])
			dfs(g, p->adjvex);
		p = p->next;
	}
}

//深度遍历整个图
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

//bfs遍历一个连通分量
void bfs(linkedgroud g, int i) {
	int j;
	edgenode* p;
	int queue[M], front, rear;
	front = rear = 0;
	printf("广度优先遍历：%c\n", g.adjlist[i].vertex); //被访问结点访问
	visited[i] = 1;         //被访问结点进队
	queue[rear++] = i;
	while (rear > front) {
		j = queue[front++];   //出队
		p = g.adjlist[j].firstedge;
		while (p) {
			if (visited[p->adjvex] == 0) {
				printf("广度优先遍历：%c\n", g.adjlist[p->adjvex].vertex);
				queue[rear++] = p->adjvex;
				visited[p->adjvex] = 1;
			}
			p = p->next;
		}
	}
}
//bfs遍历整个图
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