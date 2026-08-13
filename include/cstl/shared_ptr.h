#ifndef CSTL_SHARED_PTR_H
#define CSTL_SHARED_PTR_H

#include <stddef.h>
#include <stdint.h>

typedef void (*deleter_t)(void*);
typedef struct shared_ptr shared_ptr_t;

shared_ptr_t* shared_ptr_make(void* data);
shared_ptr_t* shared_ptr_make_deleter(void* data, deleter_t deleter);
shared_ptr_t* shared_ptr_clone(const shared_ptr_t* src);
void shared_ptr_swap(shared_ptr_t* a, shared_ptr_t* b);
void* shared_ptr_get(const shared_ptr_t* src);
deleter_t shared_ptr_get_deleter(const shared_ptr_t* src);
uint32_t shared_ptr_use_count(const shared_ptr_t* src);
void shared_ptr_release(shared_ptr_t** ptr);

#endif
