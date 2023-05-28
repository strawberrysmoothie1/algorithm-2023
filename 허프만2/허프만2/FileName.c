#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ELEMENT 200

typedef struct TreeNode {
    int weight;
    char ch;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct {
    TreeNode* ptree;
    char ch;
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

HeapType* create_heap() {
    return (HeapType*)malloc(sizeof(HeapType));
}

void init_heap(HeapType* h) {
    h->heap_size = 0;
}

void insert_min_heap(HeapType* h, element item) {
    int i;
    i = ++(h->heap_size);

    while ((i != 1) && (item.key < h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }

    h->heap[i] = item;
}

element delete_min_heap(HeapType* h) {
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;

    while (child <= h->heap_size) {
        if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
            child++;
        if (temp.key < h->heap[child].key)
            break;

        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }

    h->heap[parent] = temp;
    return item;
}

TreeNode* make_tree(TreeNode* left, TreeNode* right) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->left = left;
    node->right = right;
    return node;
}

void destroy_tree(TreeNode* root) {
    if (root == NULL)
        return;
    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root);
}

void print_codes(TreeNode* root, int codes[], int top, FILE* fp) {
    if (root->left) {
        codes[top] = 1;
        print_codes(root->left, codes, top + 1, fp);
    }
    if (root->right) {
        codes[top] = 0;
        print_codes(root->right, codes, top + 1, fp);
    }

    if (!(root->left) && !(root->right)) {
        for (int i = 0; i < top; i++)
            fprintf(fp, "%d", codes[i]);
    }
}

void save_huffman_tree(int freq[], char ch_list[], int n) {
    int i;
    TreeNode* node, * x;
    HeapType* heap;
    element e, e1, e2;
    int codes[100];
    int top = 0;

    heap = create_heap();
    init_heap(heap);
    for (i = 0; i < n; i++) {
        node = make_tree(NULL, NULL);
        e.ch = node->ch = ch_list[i];
        e.key = node->weight = freq[i];
        e.ptree = node;
        insert_min_heap(heap, e);
    }

    for (i = 1; i < n; i++) {
        e1 = delete_min_heap(heap);
        e2 = delete_min_heap(heap);

        x = make_tree(e1.ptree, e2.ptree);
        e.key = x->weight = e1.key + e2.key;
        e.ptree = x;
        insert_min_heap(heap, e);
    }

    e = delete_min_heap(heap);

    FILE* fp = fopen("output.huf", "w");
    if (fp == NULL) {
        printf("출력 파일 열기 실패\n");
        return;
    }
    print_codes(e.ptree, codes, top, fp);
    fclose(fp);

    destroy_tree(e.ptree);
    free(heap);
}



int filesize(const char* filename) {//파일의 크기함수
    int size;

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("파일 열기 실패\n");
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);

    fclose(fp);

    return size;
}


void save_frequency(const char* filename) {
    int counts[65536] = { 0 };
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("파일 열기 실패\n");
        return;
    }
    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        counts[ch]++;
    }
    fclose(fp);

    FILE* output_fp = fopen("stats", "w");
    if (output_fp == NULL) {
        printf("출력 파일 열기 실패\n");
        return;
    }

    for (int i = 0; i < 128; i++) {
        if (counts[i] > 0) {
            fprintf(output_fp, "%c\t%d\n", i, counts[i]);
        }
    }

    fclose(output_fp);
}



int main(void) {
    int hn = filesize("input");//파일의 크기
    save_frequency("input");// stats파일에 ASCLL 글자별 빈도수 저장

    char filename[] = "stats";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("파일 열기 실패\n");
        return 1;
    }

    // 문자와 빈도수를 저장할 배열
    char ch_list[128];
    int freq[128] = { 0 };  // 빈도수 초기화

    // 파일에서 문자 빈도수 읽기
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch >= 0 && ch <= 127) {
            freq[ch]++;
        }
    }
    fclose(fp);

    // 문자와 빈도수를 사용하여 허프만 코드 생성
    save_huffman_tree(freq, ch_list, 128);

    return 0;
}
