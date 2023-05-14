#pragma once

typedef struct _Node {
	int value;
    struct Node* left;
    struct Node* right;
}Node;

extern Node* makeTree();
extern void printTree(Node* root);
