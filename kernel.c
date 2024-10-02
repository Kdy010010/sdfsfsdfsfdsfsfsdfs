#include "vfs.h"
#include <stdio.h>

void kernel_main() {
    vfs_init();

    file_t* file = vfs_open("hello.txt");
    if (file != NULL) {
        char buffer[12];
        int bytesRead = vfs_read(file, buffer, 11);
        buffer[bytesRead] = '\0';

        printf("File contents: %s\n", buffer);

        vfs_close(file);
    } else {
        printf("File not found.\n");
    }
}
