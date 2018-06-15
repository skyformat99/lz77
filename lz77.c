#include <assert.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "lz77.h"

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

struct wnd_t {
  uint8_t *start, *end, *head;
};

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

static lz77_status_t _lz77_deflate(lz77_read_t read, lz77_write_t write,
                                   struct wnd_t *wnd, void *user) {
  for (;;) {

  }
  return e_lz77_success;
}

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

static lz77_status_t _lz77_inflate(lz77_read_t read, lz77_write_t write,
                                   struct wnd_t *wnd, void *user) {
  return e_lz77_success;
}

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

lz77_status_t lz77_deflate(lz77_read_t read, lz77_write_t write,
                           size_t window_size, void *user) {
  if (!(read && write && window_size)) {
    return e_lz77_fail_params;
  }
  struct wnd_t wnd;
  wnd.start = wnd.head = (uint8_t *)alloca(window_size);
  wnd.end = wnd.start + window_size;
  if (!wnd.start) {
    return e_lz77_fail_no_mem;
  }
  memset(wnd.start, 0, window_size);
  return _lz77_deflate(read, write, &wnd, user);
}

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

lz77_status_t lz77_inflate(lz77_read_t read, lz77_write_t write,
                           size_t window_size, void *user) {
  if (!(read && write && window_size)) {
    return e_lz77_fail_params;
  }
  struct wnd_t wnd;
  wnd.start = wnd.head = (uint8_t *)alloca(window_size);
  wnd.end = wnd.start + window_size;
  if (!wnd.start) {
    return e_lz77_fail_no_mem;
  }
  memset(wnd.start, 0, window_size);
  return _lz77_inflate(read, write, &wnd, user);
}
