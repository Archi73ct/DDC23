#include <stdio.h>

const char * flag = "DDC{Super-easy-flag}";

void vulnerable() {
    char * d;
    scanf("%lld\n", &d);
    printf("You've found: %s", d);
    puts("Did you get it?")
    return;
}

int main(int argc, char **argv) {
    puts("Find the flag for me pls!");
    setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
    vulnerable();
}
