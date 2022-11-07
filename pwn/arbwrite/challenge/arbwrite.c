// 
#include <stdio.h>
#include <inttypes.h>
#include <unistd.h>
#include <sys/param.h>
#include <stdlib.h>
#include <string.h>
volatile char * date = "date";

void see() {
    char * d;
    puts("Where would you like to look?");
    scanf("%20llu", &d);
    printf("You've found: %s\n", d);
    return;
}

void cast_write() {
    char buf[32];
    unsigned short sz;
    char * d;

    puts("Where would you like to aim?");
    scanf("%20llu", &d);
    puts("Size of spell?");
    scanf("%hu", &sz);
    puts("What are the magic words?");
    read(0, buf, 31);
    puts("Casting...");
    memcpy(d, buf, MIN(sz, 32));
    return;
}

void check_time() {
    printf("Executing: %s\n", date);
    system(date);
    return;
}

void menu() {
    int c;
    puts("1. Look around");
    puts("2. Cast 'arbitrary write'");
    puts("3. Check time");
    c = getchar();
    switch (c) {
        case '1':
            see();
            break;
        case '2':
            cast_write();
            break;
        case '3':
            check_time();
            break;
        default:
            puts("Wrong option");
            break;
    }
    return;
}
int main(int argc, char **argv) {
    puts("Simple text adventure game 0.2\n");
    setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
    puts("You wake up in a dark room...");
    while(1) {
        menu();
    }
}
