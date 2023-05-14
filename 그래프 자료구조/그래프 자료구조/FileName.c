#include<stdio.h>
#include<stdlib.h>
typedef struct _NodeInto {
	int id;
	char* name[20];
}Node;

#define INF (9203920249)

//const Node nodeName[4] = { {2323,"n0"},{9903,"n1"},{332,"n2"},{234,"n3"} };
const char* nodeName[4] = { "n0","n1","n2","n3" }; //노드집합
const Node nodeSet[4]; //노드집합
int G[4][4] = {
	{0, 3, INF, INF},
	{INF, 0, 4, INF},
	{INF, INF, 0, 5},
	{INF, INF, 2, 0} };



//반환: 초기화된 이진 트리의 루트노드
typedef struct _Bnode {
	int id;
	Bnode* left;
	Bnode* right;
}Bnode;

Bnode* initTree() {
	Bnode* b0 = (Bnode*)malloc(sizeof(Bnode));
	Bnode* b1 = (Bnode*)malloc(sizeof(Bnode));
	Bnode* b2 = (Bnode*)malloc(sizeof(Bnode));
	Bnode* b3 = (Bnode*)malloc(sizeof(Bnode));
	Bnode* b4 = (Bnode*)malloc(sizeof(Bnode));

	b0->left = b1;
	b1->right = b2;
	b2->left = b3;
	b3->right = b4;
	//..

	return b0;
}






int main() {
	/*Node n1;
	strcpy(n1.name, "n0");
	nodeSet[0] = n1; */



	return 0;
}