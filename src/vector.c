#include "cstl/vector.h"

#include "cstl/assert.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct vector
{
    destructor_t element_destructor;
    size_t element_size;
    size_t size;
    size_t capacity;
    uint8_t data[];
};

#define VECTOR_CAPACITY_GROWTH_FACTOR 3 / 2
#define VECTOR_AT(v, i) ((v)->data + (i) * (v)->element_size)

static vector_t* vector_grow_if_necessary(vector_t* vector)
{
    if (vector->size < vector->capacity)
        return vector;

    size_t new_capacity = (vector->capacity == 0) ? 4 : vector->capacity * VECTOR_CAPACITY_GROWTH_FACTOR;
    vector = realloc(vector, sizeof(*vector) + new_capacity * vector->element_size);
    CSTL_ASSERT(vector != NULL, "Failed to allocate memory for a vector growth");

    vector->capacity = new_capacity;

    return vector;
}

vector_t* vector_create(size_t element_size, size_t capacity, destructor_t element_destructor)
{
    CSTL_ASSERT_DEBUG(element_size != 0, "Can't create a vector of elements of 0 bytes");

    vector_t* vector = malloc(sizeof(*vector) + capacity * element_size);
    CSTL_ASSERT(vector != NULL, "Failed to allocate memory for a new vector");

    vector->element_destructor = element_destructor;
    vector->element_size = element_size;
    vector->size = 0;
    vector->capacity = capacity;

    return vector;
}

void vector_clear(vector_t* vector)
{
    CSTL_ASSERT_DEBUG(vector != NULL, "Can't clear a non-existent vector");
    vector->size = 0;
}

vector_t* vector_push_back(vector_t* vector, const void* data)
{
    CSTL_ASSERT_DEBUG(vector != NULL, "Can't insert data into a non-existent vector");

    vector = vector_grow_if_necessary(vector);

    if (data != NULL)
        memcpy(VECTOR_AT(vector, vector->size), data, vector->element_size);

    ++vector->size;
    return vector;
}

void vector_pop_back(vector_t* vector)
{
    CSTL_ASSERT_DEBUG(vector != NULL, "Can't erase data from a non-existent vector");

    if (vector->size == 0)
        return;

    if (vector->element_destructor != NULL)
        vector->element_destructor(VECTOR_AT(vector, vector->size - 1));

    --vector->size;
}

vector_t* vector_reserve(vector_t* vector, size_t new_capacity)
{
    CSTL_ASSERT_DEBUG(vector != NULL, "Can't reserve space for a non-existent vector");

    if (new_capacity <= vector->capacity)
        return vector;

    vector = realloc(vector, sizeof(*vector) + new_capacity * vector->element_size);
    CSTL_ASSERT(vector != NULL, "Failed to allocate memory for a vector growth");

    vector->capacity = new_capacity;

    return vector;
}

vector_t* vector_shrink_to_fit(vector_t* vector)
{
    CSTL_ASSERT_DEBUG(vector != NULL, "Can't shrink a non-existent vector");

    if (vector->size == vector->capacity)
        return vector;

    vector = realloc(vector, sizeof(*vector) + vector->size * vector->element_size);
    CSTL_ASSERT(vector != NULL, "Failed to allocate memory for a vector shrink");

    vector->capacity = vector->size;

    return vector;
}

void* vector_at(vector_t* vector, size_t index)
{
    CSTL_ASSERT_DEBUG(vector != NULL, "Can't get data from a non-existent vector");
    CSTL_ASSERT_DEBUG(index < vector->size, "Index is out of vector bounds");
    return VECTOR_AT(vector, index);
}

void* vector_begin(vector_t* vector)
{
    CSTL_ASSERT_DEBUG(vector != NULL, "Can't get pointer to the beginning of a non-existent vector");
    return VECTOR_AT(vector, 0);
}

void* vector_end(vector_t* vector)
{
    CSTL_ASSERT_DEBUG(vector != NULL, "Can't get pointer to the end of a non-existent vector");
    return VECTOR_AT(vector, vector->size - 1);
}

size_t vector_get_size(const vector_t* vector)
{
    CSTL_ASSERT_DEBUG(vector != NULL, "Can't get size of a non-existent vector");
    return vector->size;
}

size_t vector_get_capacity(const vector_t* vector)
{
    CSTL_ASSERT_DEBUG(vector != NULL, "Can't get capacity of a non-existent vector");
    return vector->capacity;
}

void vector_destroy(vector_t** vector)
{
    CSTL_ASSERT_DEBUG(vector != NULL && *vector != NULL, "Can't destroy a non-existent vector");

    size_t i;
    if ((*vector)->element_destructor != NULL)
    {
        for (i = 0; i < (*vector)->size; ++i)
            (*vector)->element_destructor(VECTOR_AT(*vector, i));
    }

    free(*vector);
    *vector = NULL;
}
