#include <Stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"


void main() {

	node* root = NULL;

	root = maketree();

	printtree(root);

}