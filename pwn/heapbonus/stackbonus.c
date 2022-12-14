/*
    Custom shadow stack implementation:
    This will allocate a page of memory seperate from the stack.
    On every function call, put : *++sh_stack = ststack_enter();
    On every function exit, put : shstack_exit(*sh_stack);
    
    This will put all return values on the shadow stack at function entry,
    and replace all function returns with the shadow stack copy on return.

    Authors note:
        Yes, this might be hard, it will require you to understand exactly
        what is going on.
        Be creative <3
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
unsigned long * sh_stack;

static inline unsigned long shstack_enter() {
    unsigned long ret;
      asm(".intel_syntax noprefix;"
        "mov r10, [rsp];"
        "mov %0, [r10+8];"
        ".att_syntax;"
        : "=r"(ret)
        :                   /* no input*/
    );
    return ret;
}

static inline unsigned long shstack_exit(unsigned long v) {
    unsigned long ret;
      asm(".intel_syntax noprefix;"
        "mov r10, [rsp];"
        "mov [r10+8], %0;"
        ".att_syntax;"
        : // nope
        : "r" (v)
    );
    return ret;
}


void test() {
    *++sh_stack = shstack_enter();
    char buffer[128];
    puts("Give me your exploit: ");
    gets(buffer);
    shstack_exit(*sh_stack--);
    return;
}


void demo() {
    *++sh_stack = shstack_enter();
    puts("This is a demo of my shadow stack");
    puts("I have introduced a gets() call");
    puts("See if you can pwn me :D");
    printf("%p %p %p ");
    test();
    shstack_exit(*sh_stack--);
    return;
}


int main() {
    sh_stack = (unsigned long*) malloc(0x1000);
    *++sh_stack = shstack_enter();
    demo();
    puts("You probably didn't succeed :P");
    shstack_exit(*sh_stack--);
}