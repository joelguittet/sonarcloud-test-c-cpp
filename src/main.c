/**
 * @file      main.c
 * @brief     Main entry point
 */

#include <stdio.h>
#include <unistd.h>

int main() {

    printf("hello World!\n");
    
    /* Control flow statements "if", "for", "while", "switch" and "try" should not be nested too deeply */
    if (1) {
        /* Collapsible "if" statements should be merged */
        if (1) {
            if (1) {
                if (1) {
                    /* Nothing to do */
                }
            }
        }
    }
    
    /* Obsolete POSIX functions should not be used */
    usleep(1);

    return 0;
}
