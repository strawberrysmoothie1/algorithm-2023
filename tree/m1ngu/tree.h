#pragma once

typedef struct _node {

	int data;
	struct _node* left;
	struct _node* right;

}node;

extern node* maketree();
extern void printtree(node* root);