// 
#include <stdio.h>

const char * flag = "DDC{this_is_the_real_flag_go_submit}";

void see() {
    char * d;
    puts("Where would you like to look?");
    scanf("%20llu", &d);
    printf("You've found: %s\n", d);
    return;
}
void menu() {
    int c;
    puts("1. Look around");
    puts("2. Walk");
    puts("3. not implemented");
    c = getchar();
    switch (c) {
        case '1':
            see();
            break;
        case '2':
            puts("Not implemented");
            break;
        case '3':
            puts("Not implemented");
            break;
        default:
            puts("Wrong option");
            break;
    }
    return;
}
int main(int argc, char **argv) {
    puts("Simple text adventure game 0.1\n");
    setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
    puts("You wake up in a dark room...");
    while(1) {
        menu();
    }
}
