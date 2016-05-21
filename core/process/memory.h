#ifndef CORE_PROCESS_MEMORY_H
#define CORE_PROCESS_MEMORY_H

#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>

struct process_memory {
    uint64_t size;
    uint64_t resident;
    uint64_t share;
    uint64_t text;
    uint64_t lib;
    uint64_t data;
    uint64_t dirty;
};

struct system_memory {
    uint64_t        page_size;
    uint64_t        total_ram_bytes;
    struct sysinfo  system_info;
};

#endif
