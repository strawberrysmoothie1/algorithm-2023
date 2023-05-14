#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#include "tree.h"


int main() {
    // Ʈ�� ����
    Node* root = makeTree();

    // ��ü Ʈ�� ���
    printf("=== Print Tree ===\n");
    printTree(root);

    // ���� ��ȸ ���
    printf("=== Preorder Traversal ===\n");
    preorder(root);
    printf("\n");

    // ���� ��ȸ ���
    printf("=== Inorder Traversal ===\n");
    inorder(root);
    printf("\n");

    // ���� ��ȸ ���
    printf("=== Postorder Traversal ===\n");
    postorder(root);
    printf("\n");

    // Ư�� ���� ������ ��� ã��
    int targetValue = 400;
    Node* foundNode = findNode(root, targetValue);
    if (foundNode != NULL) {
        printf("Node with value %d found.\n", targetValue);
    }
    else {
        printf("Node with value %d not found.\n", targetValue);
    }

    // ���ο� ��� ����
    Node* newNode = createNode(600);
    Node* whereNode = findNode(root, 300);
    if (whereNode != NULL) {
        insertLeftNode(whereNode, newNode);
        printf("New node inserted to the left of node 300.\n");
    }
    else {
        printf("Node 300 not found. New node not inserted.\n");
    }

    // ������ Ʈ�� ���
    printf("=== Updated Tree ===\n");
    printTree(root);

    // �޸� ����
    // ... (�ʿ��� ��� ������ �����ϴ� �ڵ带 �߰��ϼ���)

    return 0;
}
