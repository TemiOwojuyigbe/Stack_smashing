#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * cmsc426() is our final function. It reads from "badfile"
 * into a local buffer that's intentionally too small, causing
 * a buffer overflow that can overwrite return addresses, etc.
 */
int cmsc426(char *str) {
    
    char fx3[208];
    int n = 3;

    // Open badfile
    FILE *fp = fopen("badfile", "r");
    if (fp == NULL) {
        // Just in case file not found
        perror("fopen");
        return n;
    }

    
    fread(fx3, sizeof(char), 300, fp);
    fclose(fp);

    // Now copy into 'str', which might also be smaller in main.
    strcpy(str, fx3);

    puts("cmsc426");
    return n;
}

/*
 * _78493() calls cmsc426(), sets up the chain of calls.
 */
int _78493(char *str) {
    char fx2[208];
    int n = 2;

    // Call cmsc426
    cmsc426(str);

    puts("78493");
    return n;
}

/*
 * TU() is our first function. It calls _78493().
 */
int TU(char *str) {
    char fx1[208];
    int n = 1;

    // Call _78493
    _78493(str);

    puts("TU");
    return n;
}

/*
 * main() calls TU(), which calls _78493(), which calls cmsc426().
 */
int main() {
    // use a 128-byte array in main, just like your sample code.
    char x[128] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n;

    // Call TU
    n = TU(x);

    // Check the return value
    if (n == 1) {
        printf("Returned properly\n");
    } else {
        printf("Improper return\n");
    }

    return 0;
}
