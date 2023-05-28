#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2000

typedef struct HNode {
    int freq;
    char data;
    struct HNode* left;
    struct HNode* right;
} HNode;

HNode* create_node(char data, int freq) {
    HNode* node = (HNode*)malloc(sizeof(HNode));
    node->data = data;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

HNode* heap[MAX];
int heap_size;

#define Parent(i) (heap[i/2])
#define Left(i) (heap[i*2])
#define Right(i) (heap[i*2+1])

void init_heap() {
    heap_size = 0;
}

int is_empty_heap() {
    return heap_size == 0;
}

int is_full_heap() {
    return heap_size == MAX - 1;
}

HNode* find_heap() {
    return heap[1];
}

void insert_heap(HNode* n) {
    int i;
    if (is_full_heap()) return;
    i = ++heap_size;
    while (i != 1 && n->freq < Parent(i)->freq) {
        heap[i] = Parent(i);
        i /= 2;
    }
    heap[i] = n;
}

HNode* delete_heap() {
    HNode* hroot, * last;
    int parent = 1, child = 2;
    if (is_empty_heap()) {
        printf("힙 트리 공백 에러\n");
        exit(1);
    }
    hroot = heap[1];
    last = heap[heap_size--];
    while (child <= heap_size) {
        if (child < heap_size && Left(parent)->freq > Right(parent)->freq)
            child++;
        if (last->freq <= heap[child]->freq)
            break;
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = last;
    return hroot;
}

void make_tree(int freq[], char data[], int n) {
    HNode* e1, * e2;
    int i;

    init_heap();
    for (i = 0; i < n; i++) {
        HNode* node = create_node(data[i], freq[i]);
        insert_heap(node);
    }

    for (i = 1; i < n; i++) {
        e1 = delete_heap();
        e2 = delete_heap();

        HNode* new_node = create_node('\0', e1->freq + e2->freq);
        new_node->left = e1;
        new_node->right = e2;

        insert_heap(new_node);
    }
}

void encode(HNode* root, char* code, int top, char encoding[][MAX], char* data) {
    if (root->left) {
        code[top] = '0';
        encode(root->left, code, top + 1, encoding, data);
    }

    if (root->right) {
        code[top] = '1';
        encode(root->right, code, top + 1, encoding, data);
    }

    if (!root->left && !root->right) {
        code[top] = '\0';
        strcpy(encoding[root->data], code);
        strcpy(data + root->data * MAX, code);
    }
}

void compress_file(const char* input_file, const char* output_file) {
    FILE* fp_in, * fp_out;
    int freq[MAX] = { 0 };
    char data[MAX];
    int n = 0;

    // 2. input.txt를 읽어서 ASCII 글자별로 빈도수 계산
    fp_in = fopen(input_file, "r");
    if (fp_in == NULL) {
        printf("파일 열기 실패\n");
        return;
    }

    int ch;
    while ((ch = fgetc(fp_in)) != EOF) {
        if (ch >= 0 && ch <= 127) {
            freq[ch]++;
        }
    }
    fclose(fp_in);

    // 3. stats.txt에 빈도수 저장
    fp_out = fopen("stats.txt", "w");
    if (fp_out == NULL) {
        printf("파일 열기 실패\n");
        return;
    }

    for (int i = 0; i < MAX; i++) {
        if (freq[i] > 0) {
            fprintf(fp_out, "%c\t%d\n", i, freq[i]);
            data[n] = i;
            n++;
        }
    }

    fclose(fp_out);

    // 4. Huffman Coding 알고리즘으로 Huffman Tree 만들기
    make_tree(freq, data, n);

    // 5. encoding 배열에 각 문자의 Huffman 코드 저장
    char encoding[MAX][MAX];
    char code[MAX];
    encode(find_heap(), code, 0, encoding, (char*)encoding);

    // 6. input.txt를 Huffman 압축하여 output.huf 파일로 저장
    fp_in = fopen(input_file, "r");
    if (fp_in == NULL) {
        printf("파일 열기 실패\n");
        return;
    }

    fp_out = fopen(output_file, "wb");
    if (fp_out == NULL) {
        printf("파일 열기 실패\n");
        return;
    }

    int bit_count = 0;
    unsigned char buffer = 0;

    while ((ch = fgetc(fp_in)) != EOF) {
        if (ch >= 0 && ch <= 127) {
            char* code = encoding[ch];
            for (int i = 0; code[i] != '\0'; i++) {
                if (code[i] == '1') {
                    buffer |= (1 << (7 - bit_count));
                }
                bit_count++;

                if (bit_count == 8) {
                    fwrite(&buffer, sizeof(unsigned char), 1, fp_out);
                    buffer = 0;
                    bit_count = 0;
                }
            }
        }
    }

    if (bit_count > 0) {
        fwrite(&buffer, sizeof(unsigned char), 1, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);
}
int compare_files(const char* file1, const char* file2) {
    FILE* fp1 = fopen(file1, "r");
    FILE* fp2 = fopen(file2, "r");

    if (fp1 == NULL || fp2 == NULL) {
        printf("파일 열기 실패\n");
        return 0; // 파일 열기 실패 시 비교 실패로 간주
    }

    int ch1, ch2;

    while ((ch1 = fgetc(fp1)) != EOF && (ch2 = fgetc(fp2)) != EOF) {
        if (ch1 != ch2) {
            fclose(fp1);
            fclose(fp2);
            return 0; // 파일 내용이 다름
        }
    }

    // 두 파일 중 하나라도 끝에 도달하지 않았을 경우
    if (ch1 != EOF || ch2 != EOF) {
        fclose(fp1);
        fclose(fp2);
        return 0; // 파일 내용이 다름
    }

    fclose(fp1);
    fclose(fp2);

    return 1; // 파일 내용이 동일
}
void calculate_frequency(const char* file_name, const char* output_file) {
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("파일 열기 실패\n");
        return;
    }

    int freq[128] = { 0 };  // ASCII 문자에 해당하는 빈도수를 저장하는 배열

    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch >= 0 && ch <= 127) {
            freq[ch]++;
        }
    }

    fclose(fp);

    FILE* output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        printf("파일 열기 실패\n");
        return;
    }

    for (int i = 0; i < 128; i++) {
        if (freq[i] > 0) {
            fprintf(output_fp, "%c\t%d\n", i, freq[i]);
        }
    }

    fclose(output_fp);
}
void generate_ascii_text(const char* file_name) {
    FILE* fp = fopen(file_name, "w");
    if (fp == NULL) {
        printf("파일 열기 실패\n");
        return;
    }

    for (int i = 32; i <= 126; i++) {
        fputc(i, fp);
    }

    fclose(fp);
}

void decompress_file(const char* input_file, const char* output_file) {
    FILE* fp_in, * fp_out;

    // 8. stats.txt에서 빈도수와 문자를 읽어와 Huffman Tree 재구성
    int freq[MAX] = { 0 };
    char data[MAX];
    int n = 0;

    fp_in = fopen("stats.txt", "r");
    if (fp_in == NULL) {
        printf("파일 열기 실패\n");
        return;
    }

    int ch;
    while ((ch = fgetc(fp_in)) != EOF) {
        if (ch >= 0 && ch <= 127) {
            char freq_str[10] = { 0 };
            int i = 0;

            while ((ch = fgetc(fp_in)) != '\t') {
                freq_str[i++] = ch;
            }

            int frequency = atoi(freq_str);
            freq[data[n]] = frequency;
            n++;
        }
    }

    fclose(fp_in);

    make_tree(freq, data, n);

    // 9. input.huf를 읽어와 Huffman 압축 해제하여 output.txt로 저장
    fp_in = fopen(input_file, "rb");
    if (fp_in == NULL) {
        printf("파일 열기 실패\n");
        return;
    }

    fp_out = fopen(output_file, "w");
    if (fp_out == NULL) {
        printf("파일 열기 실패\n");
        return;
    }

    HNode* root = find_heap();

    HNode* node = root;
    while ((ch = fgetc(fp_in)) != EOF) {
        for (int i = 0; i < 8; i++) {
            int bit = (ch >> (7 - i)) & 1;
            if (bit == 0) {
                node = node->left;
            }
            else {
                node = node->right;
            }

            if (node->left == NULL && node->right == NULL) {
                fprintf(fp_out, "%c", node->data);
                node = root;
            }
        }
    }

    fclose(fp_in);
    fclose(fp_out);
}

int main() {
    const char* input = "input.txt";
    const char* stats = "stats.txt";
    const char* compressed_file = "output.huf";
    const char* decompressed_file = "output.txt";

    // 1. 입력 파일로부터 ASCII 영문 텍스트를 생성
    generate_ascii_text(input);

    // 2. input.txt를 읽어서 ASCII 글자별로 빈도수 계산 및 stats.txt에 저장
    calculate_frequency(input, stats);

    // 3. Huffman Coding 알고리즘으로 Huffman Tree 생성

    // 4. input.txt를 Huffman 압축하여 output.huf 파일로 저장
    compress_file(input, compressed_file);

    // 5. stats.txt를 읽어서 Huffman Tree 재구성 및 output.huf를 output.txt로 저장
    decompress_file(compressed_file, decompressed_file);

    // 6. input.txt와 output.txt 파일 비교
    if (compare_files(input, decompressed_file)) {
        printf("압축 및 해제 성공\n");
    }
    else {
        printf("압축 및 해제 실패\n");
    }

    return 0;
}
