#ifndef __LZ_77_H__
#define __LZ_77_H__

#include <stdint.h>

typedef size_t (*lz77_read_t)(uint8_t* dst, size_t bytes, void* user);
typedef size_t (*lz77_write_t)(const uint8_t* src, size_t bytes, void* user);

enum lz77_status_t {
    e_lz77_success = 0,
    e_lz77_fail_params,
    e_lz77_fail_write,
    e_lz77_fail_read,
    e_lz77_fail_no_mem,
};
typedef enum lz77_status_t lz77_status_t;

lz77_status_t lz77_deflate(
    lz77_read_t read,
    lz77_write_t write,
    size_t window_size,
    void * user);

lz77_status_t lz77_inflate(
    lz77_read_t read,
    lz77_write_t write,
    size_t window_size,
    void * user);

#endif // __LZ_77_H__
