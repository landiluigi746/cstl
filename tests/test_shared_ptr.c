#include <cstl/assert.h>
#include <cstl/shared_ptr.h>
#include <stdlib.h>
#include <time.h>

void* get_int(void)
{
    int* x = malloc(sizeof(int));
    *x = 42;
    return x;
}

void* get_random_int(void)
{
    int* x = malloc(sizeof(int));
    *x = rand() % 43;
    return x;
}

int main(void)
{
    srand(time(NULL));

    shared_ptr_t* sptr1 = shared_ptr_make(get_int());
    CSTL_ASSERT(shared_ptr_use_count(sptr1) == 1, "Expected reference count to be 1");
    CSTL_ASSERT(*(int*) shared_ptr_get(sptr1) == 42, "Expected value hold by shared pointer to be 42");

    shared_ptr_t* sptr2 = shared_ptr_clone(sptr1);
    shared_ptr_t* sptr3 = shared_ptr_clone(sptr2);
    CSTL_ASSERT(shared_ptr_use_count(sptr1) == 3 && shared_ptr_use_count(sptr2) == 3 &&
                    shared_ptr_use_count(sptr3) == 3,
                "Expected all reference counts to be 3");

    shared_ptr_release(&sptr1);

    CSTL_ASSERT(shared_ptr_use_count(sptr2) == 2 && shared_ptr_use_count(sptr3) == 2,
                "Expected all reference counts to be 2");
    CSTL_ASSERT(*(int*) shared_ptr_get(sptr2) == 42 && *(int*) shared_ptr_get(sptr3) == 42,
                "Expected value hold by shared pointers to be 42");

    shared_ptr_release(&sptr2);

    CSTL_ASSERT(shared_ptr_use_count(sptr3) == 1, "Expected reference count to be 1");
    CSTL_ASSERT(*(int*) shared_ptr_get(sptr3) == 42, "Expected value hold by shared pointer to be 42");

    shared_ptr_release(&sptr3);

    shared_ptr_t* a = shared_ptr_make(get_random_int());
    shared_ptr_t* b = shared_ptr_make(get_random_int());

    int original_a_val = *(int*) shared_ptr_get(a);
    int original_b_val = *(int*) shared_ptr_get(b);

    shared_ptr_swap(a, b);

    CSTL_ASSERT(original_a_val == *(int*) shared_ptr_get(b),
                "Expected original value hold by pointer A to be hold by pointer B");
    CSTL_ASSERT(original_b_val == *(int*) shared_ptr_get(a),
                "Expected original value hold by pointer B to be hold by pointer A");

    shared_ptr_release(&a);
    shared_ptr_release(&b);

    return 0;
}
