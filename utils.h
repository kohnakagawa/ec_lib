#ifndef UTILS_H
#define UTILS_H

#define ECLIB_STR(x) #x
#define ECLIB_CONCATENATE(x, y) x ## y
#define ECLIB_CONCAT(x, y) ECLIB_CONCATENATE(x, y)

#include <stdio.h>
#include <stdlib.h>

void* xmalloc(const size_t size);
void xfree(void* ptr);

#ifdef DEBUG
#define DEBUG_PRINT(...)                        \
  do {                                          \
    fprintf(stderr, __VA_ARGS__);               \
  } while (0)
#else
#define DEBUG_PRINT(...) do {} while (0)
#endif

#include "err_msgs.h"

#define RANGE_CHECK(self, idx)                                          \
  do {                                                                  \
    if ((idx) >= (self)->size) {                                        \
      fprintf(stderr, "%s: at %s %d\n", err_msgs[OUT_OF_RANGE], __FILE__, __LINE__); \
      exit(EXIT_FAILURE);                                               \
    }                                                                   \
  } while (0)

#endif
