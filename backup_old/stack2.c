#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Third function
int cmsc426(char *str) {
    // 208-byte array (aligned to 16 bytes, since 193 -> 208)
    char fx3[208];
    int n = 3;

    // Copy str into fx3
    strcpy(fx3, str);

    // Print function name
    puts("cmsc426");

    // Return an integer (3 in this function)
    return n;
}

// Second function
int _78493(char *str) {
    // 208-byte array
    char fx2[208];
    int n = 2;

    // Call cmsc426
    cmsc426(str);

    // Print function name
    puts("78493");

    // Return an integer (2 in this function)
    return n;
}

// First function
int TU(char *str) {
    // 208-byte array
    char fx1[208];
    int n = 1;

    // Call _78493
    _78493(str);

    // Print function name
    puts("TU");

    // Return an integer (1 in this function)
    return n;
}

int main() {
    // A simple 128-byte character array
    char x[128] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n;

    // Call TU, which calls _78493, which calls cmsc426
    n = TU(x);

    // Check the return value
    if (n == 1) {
        printf("Returned properly\n");
    } else {
        printf("Improper return\n");
    }

    return 0;
}

