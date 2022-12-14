#include "acomp.h"
using namespace std;

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

class HuffmanNode {
    public:
        unsigned char value;
        unsigned int freq;
        HuffmanNode * left;
        HuffmanNode * Right;
};

struct greater : binary_function<HuffmanNode, HuffmanNode, bool> {
  bool operator()(const HuffmanNode& x, const HuffmanNode& b) const {
    return x.freq > b.freq;
}


HuffmanNode build_huffman_tree(char * buffer, size_t len) {
    unsigned int freq[0xff] = {0x0};
    huffman_node * min_heap_root = NULL;
    priority_queue <HuffmanNode, vector<HuffmanNode>, greater > pq;
    // We don't care about empty buffers
    if (len == 0) {
        return (HuffmanNode)NULL;
    }
    for (size_t i = 0; i < len; i++) {
        freq[buffer[i]]++;
    }

    for (unsigned char i = 0; i < 0xff; i++) {
        if (freq[i] > 0) {
            HuffmanNode * n = new HuffmanNode();
            n->freq = freq[i];
            n->value = i;
            pq.push(n);
        }
    }
    return NULL;
}

char * huff_compress(char* buffer, size_t size) {
    return NULL;
}

char * huff_decompress(char * buffer) {
    return NULL;
}

bool check_buffer(char * buffer, size_t size) {
    unsigned char * p = (unsigned char *) buffer;
    while (*p++) {
        if (*p > 127) break;
    }
    if ((p-size) != (unsigned char*)buffer) {
        return FALSE;
    }
    return TRUE;
}

int main(int argc, char **argv) {
    printf("%x\n", check_buffer("wjadliwalfunrkusgnfesnclwamif\xfflnse", sizeof("wjadliwalfunrkusgnfesnclwamif\xfflnse")));
    return 0;
}