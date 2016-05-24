#include "file.h"

FILE *GetFile(const char *path, const char *mode) {
    FILE *fp = fopen(path, mode);

    if ( fp == NULL ) {
        return NULL;
    }

    return fp;
}
