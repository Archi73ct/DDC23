#include "acomp.h"

#define bool unsigned char
#define TRUE 0x1
#define FALSE 0x0

// Will compress only ASCII

typedef struct huffman_node {
    unsigned char value;
    unsigned int freq;
    struct huffman_node * left;
    struct huffman_node * right;
} huffman_node;


huffman_node * build_huffman_tree(char * buffer, size_t len) {
    unsigned int freq[0xff];
    huffman_node * min_heap_root = NULL;
    // We don't care about empty buffers
    if (len == 0) {
        return NULL;
    }
    for (size_t i = 0; i < len; i++) {
        freq[buffer[i]]++;
    }

    for (unsigned char i = 0; i < 0xff; i++) {
        if (freq[i] > 0) {
            // build the node
            huffman_node * n = malloc(sizeof(huffman_node));
            n->freq = freq[i];
            n->value = i;
            
        }
    }
}

char * huff_compress(char* buffer, size_t size) {
}

char * huff_decompress(char * buffer) {

}

bool check_buffer(char * buffer, size_t size) {
    unsigned char * p = buffer;
    while (*p++) {
        if (*p > 127) break;
    }
    if ((p-size) != buffer) {
        return FALSE;
    }
    return TRUE;
}

int main(int argc, char **argv) {
    printf("%x\n", check_buffer("wjadliwalfunrkusgnfesnclwamif\xfflnse", sizeof("wjadliwalfunrkusgnfesnclwamif\xfflnse")));
    return 0;
}