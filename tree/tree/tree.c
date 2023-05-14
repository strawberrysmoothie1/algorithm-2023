#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "tree.h"


Node* root = NULL;

Node* createNode(int val) {
	//1. sizeof(Node) malloc;
	Node* pNode = (Node*)malloc(sizeof(Node));

	//2. 초기화 : n->value = val, left, right (NULL);
	pNode->value = val;
	pNode->left = NULL;
	pNode->right = NULL;

	//3. 반환 Node 객체(변수) 포인터 반환
	return pNode;
}

void connectChild(Node* parent, Node* left, Node* right) {
	if (parent == NULL) return NULL;

	parent->left = left;
	parent->right = right;
	return parent;
}

Node* makeTree() {
	Node* root = createNode(100);
	Node* node200 = createNode(200);
	Node* node300 = createNode(300);
	Node* node400 = createNode(400);
	Node* node500 = createNode(500);

	root->left = node200;
	root->right = node300;
	node300->left = node400;
	node300->right = node500;

	return root;
}

void printTree(Node* root) {
	if (root == NULL) return;

	printf("Node: %d\n", root->value);
	printTree(root->left);
	printTree(root->right);
}

void preorder(Node* n) {
	if (n != NULL) {
		printf("[%d]", n->value);
		preorder(n->left);
		preorder(n->right);
	}
}
void inorder(Node* n) {
	if (n != NULL) {
		inorder(n->left);
		printf("[%d]", n->value);
		inorder(n->right);
	}
}

void postorder(Node* n) {
	if (n != NULL) {
		postorder(n->left);
		postorder(n->right);
		printf("[%d]", n->value);
	}
}


Node* findNode(Node* root, int value) {
	if (root == NULL || root->value == value)
		return root;

	Node* foundNode = findNode(root->left, value);
	if (foundNode == NULL)
		foundNode = findNode(root->right, value);

	return foundNode;
}

Node* insertLeftNode(Node* where, Node* new_node) {
	if (where == NULL)
		return NULL;

	Node* parentNode = createNode(where->value); // 부모 노드 복사
	where->left = parentNode; // 기존 노드의 왼쪽 자식으로 연결

	// 새로운 노드와 연결
	parentNode->left = new_node;

	return parentNode; // 새로운 부모 노드 반환
}


Node* insertRightNode(Node* where, Node* new_node) {
	if (where == NULL)
		return NULL;

	Node* parentNode = createNode(where->value); // 부모 노드 복사
	where->right = parentNode; // 기존 노드의 오른쪽 자식으로 연결

	// 새로운 노드와 연결
	parentNode->right = new_node;

	return parentNode; // 새로운 부모 노드 반환
}
