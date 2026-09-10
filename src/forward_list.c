#include "cstl/forward_list.h"

#include "cstl/assert.h"
#include "cstl/iterator.h"
#include "cstl/utility.h"

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct forward_list_node
{
    struct forward_list_node* next;
    uint8_t data[];
} forward_list_node_t;

struct forward_list
{
    destructor_t element_destructor;
    size_t element_size;
    forward_list_node_t* head;
};

static iterator_t forward_list_it_next(iterator_t it)
{
    it.pointer = ((forward_list_node_t*) it.pointer)->next;
    return it;
}

static void* forward_list_it_get(iterator_t it)
{
    return ((forward_list_node_t*) it.pointer)->data;
}

static int forward_list_it_cmp(const iterator_t a, const iterator_t b)
{
    return !(a.pointer == b.pointer);
}

static const iterator_funcs_t forward_list_it_funcs = {
    .next = &forward_list_it_next,
    .prev = NULL,
    .get = &forward_list_it_get,
    .cmp = &forward_list_it_cmp,
    .distance = NULL,
    .advance = NULL,
};

forward_list_t* forward_list_create(size_t element_size, destructor_t element_destructor)
{
    CSTL_ASSERT_DEBUG(element_size != 0, "Can't create a forward list of elements of 0 bytes");

    forward_list_t* list = malloc(sizeof(*list));
    CSTL_ASSERT(list != NULL, "Failed to allocate memory for a new forward list");

    list->element_destructor = element_destructor;
    list->element_size = element_size;
    list->head = NULL;

    return list;
}

void forward_list_clear(forward_list_t* list)
{
    CSTL_ASSERT_DEBUG(list != NULL, "Can't clear a non-existent forward list");

    forward_list_node_t* tmp;
    while (list->head != NULL)
    {
        tmp = list->head;
        list->head = list->head->next;
        if (list->element_destructor != NULL)
            list->element_destructor(tmp->data);
        free(tmp);
    }
}

forward_list_t* forward_list_push_front(forward_list_t* list, const void* data)
{
    CSTL_ASSERT_DEBUG(list != NULL, "Can't insert data into a non-existent forward list");

    forward_list_node_t* new_node = malloc(sizeof(*new_node) + list->element_size);
    CSTL_ASSERT(new_node != NULL, "Failed to allocate memory for a new forward list element");

    if (data != NULL)
        memcpy(new_node->data, data, list->element_size);

    new_node->next = list->head;
    list->head = new_node;

    return list;
}

void forward_list_pop_front(forward_list_t* list)
{
    CSTL_ASSERT_DEBUG(list != NULL, "Can't erase data from a non-existent forward list");

    if (list->head == NULL)
        return;

    forward_list_node_t* tmp = list->head;
    list->head = tmp->next;

    if (list->element_destructor)
        list->element_destructor(tmp->data);

    free(tmp);
}

void* forward_list_begin(forward_list_t* list)
{
    CSTL_ASSERT_DEBUG(list != NULL, "Can't get pointer to the beginning of a non-existent forward list");
    return (list->head != NULL) ? list->head->data : NULL;
}

void* forward_list_end(forward_list_t* list)
{
    CSTL_ASSERT_DEBUG(list != NULL, "Can't get pointer to the end of a non-existent forward list");
    return NULL;
}

iterator_t forward_list_it_begin(const forward_list_t* list)
{
    CSTL_ASSERT_DEBUG(list != NULL, "Can't get iterator to the beginning of a non-existent forward list");
    return (iterator_t){
        .context = (void*) list,
        .pointer = (void*) list->head,
        .funcs = &forward_list_it_funcs,
    };
}

iterator_t forward_list_it_end(const forward_list_t* list)
{
    CSTL_ASSERT_DEBUG(list != NULL, "Can't get iterator to the end of a non-existent forward list");
    return (iterator_t){
        .context = (void*) list,
        .pointer = (void*) NULL,
        .funcs = &forward_list_it_funcs,
    };
}

void forward_list_destroy(forward_list_t** list)
{
    CSTL_ASSERT_DEBUG(list != NULL && *list != NULL, "Can't destroy a non-existent forward list");

    forward_list_clear(*list);

    free(*list);
    *list = NULL;
}
