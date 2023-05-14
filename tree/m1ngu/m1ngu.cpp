#include <Stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

node* root = NULL;

node* createnode(int value) {

	//1. sizeof(node) malloc
	//2. 초기화 : n->value =val left right (NULL)
	//3. 만든 nnode 객체 포인터 반환


	node* p = (node*)malloc(sizeof(node));
	p->data = value;
	p->left = NULL;
	p->right = NULL;


	return p;
}

node* connectchild(node* parent, node* left, node* right) {
	if (parent == NULL) { return NULL; }
	parent->left = left;
	parent->right = right;
	return parent;
}

node* maketree() {

	//선언
	node* root = NULL;
	node* left = NULL;
	node* right = NULL;

	/*
	* // 임시 데이터
	root = createnode(1);
	root->left = createnode(2);
	root->right = createnode(3);
	root->left->left = createnode(4);
	root->left->right = createnode(4);
	*/

	//이진트리 초기 설정
	root = createnode(100);
	left = createnode(200);
	right = createnode(300);


	if (connectchild(root, left, right) == NULL) { return NULL; /* error */ }
	root = connectchild(root, left, right);
	left = connectchild(left, createnode(400), createnode(500));
	right = connectchild(right, NULL, NULL);


	return root;
}

void printtree(node* root) {


	/*check error*/
	if (root == NULL) return;
	printf("%d\n", root->data);
	printtree(root->left);
	printtree(root->right);

}