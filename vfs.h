#ifndef VFS_H
#define VFS_H

typedef struct file {
    char name[32];
    int size;
    int position;
    void* data;
} file_t;

void vfs_init();
file_t* vfs_open(const char* filename);
int vfs_read(file_t* file, char* buffer, int size);
void vfs_close(file_t* file);

#endif
