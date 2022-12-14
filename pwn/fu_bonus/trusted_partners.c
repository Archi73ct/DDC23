/*
    Funny trusted partners readme or smth
*/

#include "trusted_partners.h"

const unsigned char hash[] = "";
const unsigned char code[] = {};

char * hashing(char*);


void setup(){
    // Setup buffers to be non-buffered
    setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
    return;
}

int login() {
    char password[64];
    memset(password, 0, 64);
    puts("Please log in!");
    printf("Password: ");
    scanf("%63s\n", password);
    if (strcmp(hashing(password), hash) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char **argv) {
    unsigned char authenticated = 0;
    // Setup code
    setup();
    // Code here
    authenticated = login();
    if (!authenticated) {
        puts("Error in username or password");
    }

}