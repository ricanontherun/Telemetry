#include "file.h"

FILE *GetFile(const char *path, const char *mode) {
    FILE *fp = fopen(path, mode); 

    if ( fp == NULL ) {
        fclose(fp);
        return NULL;
    }

    return fp;
}
