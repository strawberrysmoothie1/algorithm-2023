#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#include "tree.h"


int main() {
    // 트리 생성
    Node* root = makeTree();

    // 전체 트리 출력
    printf("=== Print Tree ===\n");
    printTree(root);

    // 전위 순회 출력
    printf("=== Preorder Traversal ===\n");
    preorder(root);
    printf("\n");

    // 중위 순회 출력
    printf("=== Inorder Traversal ===\n");
    inorder(root);
    printf("\n");

    // 후위 순회 출력
    printf("=== Postorder Traversal ===\n");
    postorder(root);
    printf("\n");

    // 특정 값을 가지는 노드 찾기
    int targetValue = 400;
    Node* foundNode = findNode(root, targetValue);
    if (foundNode != NULL) {
        printf("Node with value %d found.\n", targetValue);
    }
    else {
        printf("Node with value %d not found.\n", targetValue);
    }

    // 새로운 노드 삽입
    Node* newNode = createNode(600);
    Node* whereNode = findNode(root, 300);
    if (whereNode != NULL) {
        insertLeftNode(whereNode, newNode);
        printf("New node inserted to the left of node 300.\n");
    }
    else {
        printf("Node 300 not found. New node not inserted.\n");
    }

    // 수정된 트리 출력
    printf("=== Updated Tree ===\n");
    printTree(root);

    // 메모리 해제
    // ... (필요한 경우 노드들을 해제하는 코드를 추가하세요)

    return 0;
}
