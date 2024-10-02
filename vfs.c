#include "vfs.h"
#include <string.h>

#define MAX_FILES 100

file_t files[MAX_FILES];

void vfs_init() {
    // 간단한 VFS 초기화
    // 실제 파일 시스템에서 파일 로드 등
    memset(files, 0, sizeof(files));

    // 예제 파일 추가
    files[0].size = 11;
    strcpy(files[0].name, "hello.txt");
    files[0].data = "Hello World";
}

file_t* vfs_open(const char* filename) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(files[i].name, filename) == 0) {
            return &files[i];
        }
    }
    return NULL; // 파일을 찾지 못함
}

int vfs_read(file_t* file, char* buffer, int size) {
    if (file->position + size > file->size) {
        size = file->size - file->position;
    }
    memcpy(buffer, (char*)file->data + file->position, size);
    file->position += size;
    return size;
}

void vfs_close(file_t* file) {
    file->position = 0;
}
