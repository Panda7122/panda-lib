
#ifndef __UDS_PANDA_H
#define __UDS_PANDA_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// define swap function
void SWAP_DEFAULT(void*, void*, size_t);
// define sort function
bool less_then_signed(const void*, const void*, int, const size_t);
bool less_then_unsigned(const void*, const void*, int, const size_t);
bool less_then_float(const void*, const void*, int, const size_t);
bool less_then_double(const void*, const void*, int, const size_t);

void SORT_DEFAULT(void*, void*, int, int,
                  bool (*cmp)(const void*, const void*, int, const size_t));
// define lower_bound
void* LOWER_BOUND_DEFAULT(void*, void*, void*, size_t,
                          bool (*cmp)(const void*, const void*, int,
                                      const size_t));

// define upper_bound
void* UPPER_BOUND_DEFAULT(void*, void*, void*, size_t,
                          bool (*cmp)(const void*, const void*, int,
                                      const size_t));
// generic swap
#define SWAP_ERROR printf("at %d swap error\n", __LINE__)
#define swap(a, b)                       \
    if (sizeof(a) == sizeof(b)) {        \
        printf("%d \n", sizeof(a));      \
        SWAP_DEFAULT(&a, &b, sizeof(a)); \
    } else {                             \
        SWAP_ERROR;                      \
        exit(1);                         \
    }
// generic max
#define MAX_DEFAULT(a, b) (a > b ? a : b)
#define max(a, b) MAX_DEFAULT(a, b)
// generic min
#define MIN_DEFAULT(a, b) (a < b ? a : b)
#define min(a, b) MIN_DEFAULT(a, b)
// generic sort
#define SORT_ERROR                          \
    printf("at %d sort error\n", __LINE__); \
    exit(1)
#define sort(a, b) \
    _Generic((a), int*                            \
             : (_Generic((b), int*                \
                         : SORT_DEFAULT(a, b, sizeof(int),0, less_then_signed),default     \
                         : SORT_ERROR)),         \
               char*                              \
             : (_Generic((b), char*               \
                         : SORT_DEFAULT(a, b, sizeof(char),0, less_then_signed), default     \
                         : SORT_ERROR)),         \
               long long*                         \
             : (_Generic((b), long long*          \
                         : SORT_DEFAULT(a, b, sizeof(long long),0, less_then_signed), default     \
                         : SORT_ERROR)),         \
               float*                             \
             : (_Generic((b), float*              \
                         : SORT_DEFAULT(a, b, sizeof(float),0, less_then_float), default      \
                         : SORT_ERROR)),         \
               double*                            \
             : (_Generic((b), double*             \
                         : SORT_DEFAULT(a, b, sizeof(double),0, less_then_double), default     \
                         : SORT_ERROR)),\
                short* \
            :(_Generic((b), short*             \
                         : SORT_DEFAULT(a, b, sizeof(short),0, less_then_signed), default     \
                         : SORT_ERROR)),\
                unsigned int* \
            :(_Generic((b), unsigned int*             \
                         : SORT_DEFAULT(a, b, sizeof(unsigned int),0, less_then_unsigned), default     \
                         : SORT_ERROR)),\
                unsigned short* \
            :(_Generic((b), unsigned short*             \
                         : SORT_DEFAULT(a, b, sizeof(unsigned short),0, less_then_unsigned), default     \
                         : SORT_ERROR)),\
                unsigned long long* \
            :(_Generic((b), unsigned long long*             \
                         : SORT_DEFAULT(a, b, sizeof(unsigned long long),0, less_then_unsigned), default     \
                         : SORT_ERROR)))

// generic lower_bound
#define LOWER_BOUND_ERROR                          \
    printf("at %d lower_bound error\n", __LINE__); \
    exit(1)
#define lower_bound(a, b, v) \
    _Generic((a), int*                            \
             : (_Generic((b), int*                \
                         :(int*)LOWER_BOUND_DEFAULT(a, b, &v, sizeof(int), less_then_signed), char*        \
                         : LOWER_BOUND_ERROR, long long* \
                         : LOWER_BOUND_ERROR, float*     \
                         : LOWER_BOUND_ERROR, double*    \
                         : LOWER_BOUND_ERROR, short* \
                         : LOWER_BOUND_ERROR, unsigned int*\
                         : LOWER_BOUND_ERROR, unsigned short*\
                         : LOWER_BOUND_ERROR, unsigned long long*\
                         : LOWER_BOUND_ERROR)),         \
               char*                              \
             : (_Generic((b), char*               \
                         :(char*)LOWER_BOUND_DEFAULT(a, b, &v, sizeof(char), less_then_signed), int*        \
                         : LOWER_BOUND_ERROR, long long* \
                         : LOWER_BOUND_ERROR, float*     \
                         : LOWER_BOUND_ERROR, double*    \
                         : LOWER_BOUND_ERROR, short* \
                         : LOWER_BOUND_ERROR, unsigned int*\
                         : LOWER_BOUND_ERROR, unsigned short*\
                         : LOWER_BOUND_ERROR, unsigned long long*\
                         : LOWER_BOUND_ERROR)),         \
               long long*                         \
             : (_Generic((b), long long*          \
                         :(long long*)LOWER_BOUND_DEFAULT(a, b, &v, sizeof(long long), less_then_signed), char*        \
                         : LOWER_BOUND_ERROR, int* \
                         : LOWER_BOUND_ERROR, float*     \
                         : LOWER_BOUND_ERROR, double*    \
                         : LOWER_BOUND_ERROR, short* \
                         : LOWER_BOUND_ERROR, unsigned int*\
                         : LOWER_BOUND_ERROR, unsigned short*\
                         : LOWER_BOUND_ERROR, unsigned long long*\
                         : LOWER_BOUND_ERROR)),         \
               float*                             \
             : (_Generic((b), float*              \
                         :(float*)LOWER_BOUND_DEFAULT(a, b, &v, sizeof(float), less_then_float), char*        \
                         : LOWER_BOUND_ERROR, long long* \
                         : LOWER_BOUND_ERROR, int*     \
                         : LOWER_BOUND_ERROR, double*    \
                         : LOWER_BOUND_ERROR, short* \
                         : LOWER_BOUND_ERROR, unsigned int*\
                         : LOWER_BOUND_ERROR, unsigned short*\
                         : LOWER_BOUND_ERROR, unsigned long long*\
                         : LOWER_BOUND_ERROR)),         \
               double*                            \
             : (_Generic((b), double*             \
                         :(double*)LOWER_BOUND_DEFAULT(a, b, &v, sizeof(double), less_then_double), char*        \
                         : LOWER_BOUND_ERROR, long long* \
                         : LOWER_BOUND_ERROR, float*     \
                         : LOWER_BOUND_ERROR, int*    \
                         : LOWER_BOUND_ERROR, short* \
                         : LOWER_BOUND_ERROR, unsigned int*\
                         : LOWER_BOUND_ERROR, unsigned short*\
                         : LOWER_BOUND_ERROR, unsigned long long*\
                         : LOWER_BOUND_ERROR)), \
                short*                            \
             : (_Generic((b), short*                \
                         :(short*)LOWER_BOUND_DEFAULT(a, b, &v, sizeof(short), less_then_signed), char*        \
                         : LOWER_BOUND_ERROR, long long* \
                         : LOWER_BOUND_ERROR, float*     \
                         : LOWER_BOUND_ERROR, double*    \
                         : LOWER_BOUND_ERROR, int* \
                         : LOWER_BOUND_ERROR, unsigned int*\
                         : LOWER_BOUND_ERROR, unsigned short*\
                         : LOWER_BOUND_ERROR, unsigned long long*\
                         : LOWER_BOUND_ERROR)), \
                unsigned int*                            \
             : (_Generic((b), unsigned int*                \
                         :(unsigned int*)LOWER_BOUND_DEFAULT(a, b, &v, sizeof(unsigned int), less_then_unsigned), char*        \
                         : LOWER_BOUND_ERROR, long long* \
                         : LOWER_BOUND_ERROR, float*     \
                         : LOWER_BOUND_ERROR, double*    \
                         : LOWER_BOUND_ERROR, short* \
                         : LOWER_BOUND_ERROR, int*\
                         : LOWER_BOUND_ERROR, unsigned short*\
                         : LOWER_BOUND_ERROR, unsigned long long*\
                         : LOWER_BOUND_ERROR)), \
                unsigned short*                            \
             : (_Generic((b), unsigned short*                \
                         :(unsigned short*)LOWER_BOUND_DEFAULT(a, b, &v, sizeof(unsigned short), less_then_unsigned), char*        \
                         : LOWER_BOUND_ERROR, long long* \
                         : LOWER_BOUND_ERROR, float*     \
                         : LOWER_BOUND_ERROR, double*    \
                         : LOWER_BOUND_ERROR, short* \
                         : LOWER_BOUND_ERROR, unsigned int*\
                         : LOWER_BOUND_ERROR, int*\
                         : LOWER_BOUND_ERROR, unsigned long long*\
                         : LOWER_BOUND_ERROR)), \
                unsigned long long*                            \
             : (_Generic((b), unsigned long long*                \
                         :(unsigned long long*)LOWER_BOUND_DEFAULT(a, b, &v, sizeof(unsigned long long), less_then_unsigned), char*        \
                         : LOWER_BOUND_ERROR, long long* \
                         : LOWER_BOUND_ERROR, float*     \
                         : LOWER_BOUND_ERROR, double*    \
                         : LOWER_BOUND_ERROR, short* \
                         : LOWER_BOUND_ERROR, unsigned int*\
                         : LOWER_BOUND_ERROR, unsigned short*\
                         : LOWER_BOUND_ERROR, int*\
                         : LOWER_BOUND_ERROR)))
// generic upper_bound
#define UPPER_BOUND_ERROR                          \
    printf("at %d upper_bound error\n", __LINE__); \
    exit(1)
#define upper_bound(a, b, v) \
    _Generic((a), int*                            \
             : (_Generic((b), int*                \
                         :(int*)UPPER_BOUND_DEFAULT(a, b, &v, sizeof(int), less_then_signed), char*        \
                         : UPPER_BOUND_ERROR, long long* \
                         : UPPER_BOUND_ERROR, float*     \
                         : UPPER_BOUND_ERROR, double*    \
                         : UPPER_BOUND_ERROR, short* \
                         : UPPER_BOUND_ERROR, unsigned int*\
                         : UPPER_BOUND_ERROR, unsigned short*\
                         : UPPER_BOUND_ERROR, unsigned long long*\
                         : UPPER_BOUND_ERROR)),         \
               char*                              \
             : (_Generic((b), char*               \
                         :(char*)UPPER_BOUND_DEFAULT(a, b, &v, sizeof(char), less_then_signed), int*        \
                         : UPPER_BOUND_ERROR, long long* \
                         : UPPER_BOUND_ERROR, float*     \
                         : UPPER_BOUND_ERROR, double*    \
                         : UPPER_BOUND_ERROR, short* \
                         : UPPER_BOUND_ERROR, unsigned int*\
                         : UPPER_BOUND_ERROR, unsigned short*\
                         : UPPER_BOUND_ERROR, unsigned long long*\
                         : UPPER_BOUND_ERROR)),         \
               long long*                         \
             : (_Generic((b), long long*          \
                         :(long long*)UPPER_BOUND_DEFAULT(a, b, &v, sizeof(long long), less_then_signed), char*        \
                         : UPPER_BOUND_ERROR, int* \
                         : UPPER_BOUND_ERROR, float*     \
                         : UPPER_BOUND_ERROR, double*    \
                         : UPPER_BOUND_ERROR, short* \
                         : UPPER_BOUND_ERROR, unsigned int*\
                         : UPPER_BOUND_ERROR, unsigned short*\
                         : UPPER_BOUND_ERROR, unsigned long long*\
                         : UPPER_BOUND_ERROR)),         \
               float*                             \
             : (_Generic((b), float*              \
                         :(float*)UPPER_BOUND_DEFAULT(a, b, &v, sizeof(float), less_then_float), char*        \
                         : UPPER_BOUND_ERROR, long long* \
                         : UPPER_BOUND_ERROR, int*     \
                         : UPPER_BOUND_ERROR, double*    \
                         : UPPER_BOUND_ERROR, short* \
                         : UPPER_BOUND_ERROR, unsigned int*\
                         : UPPER_BOUND_ERROR, unsigned short*\
                         : UPPER_BOUND_ERROR, unsigned long long*\
                         : UPPER_BOUND_ERROR)),         \
               double*                            \
             : (_Generic((b), double*             \
                         :(double*)UPPER_BOUND_DEFAULT(a, b, &v, sizeof(double), less_then_double), char*        \
                         : UPPER_BOUND_ERROR, long long* \
                         : UPPER_BOUND_ERROR, float*     \
                         : UPPER_BOUND_ERROR, int*    \
                         : UPPER_BOUND_ERROR, short* \
                         : UPPER_BOUND_ERROR, unsigned int*\
                         : UPPER_BOUND_ERROR, unsigned short*\
                         : UPPER_BOUND_ERROR, unsigned long long*\
                         : UPPER_BOUND_ERROR)), \
                short*                            \
             : (_Generic((b), short*                \
                         :(short*)UPPER_BOUND_DEFAULT(a, b, &v, sizeof(short), less_then_signed), char*        \
                         : UPPER_BOUND_ERROR, long long* \
                         : UPPER_BOUND_ERROR, float*     \
                         : UPPER_BOUND_ERROR, double*    \
                         : UPPER_BOUND_ERROR, int* \
                         : UPPER_BOUND_ERROR, unsigned int*\
                         : UPPER_BOUND_ERROR, unsigned short*\
                         : UPPER_BOUND_ERROR, unsigned long long*\
                         : UPPER_BOUND_ERROR)), \
                unsigned int*                            \
             : (_Generic((b), unsigned int*                \
                         :(unsigned int*)UPPER_BOUND_DEFAULT(a, b, &v, sizeof(unsigned int), less_then_unsigned), char*        \
                         : UPPER_BOUND_ERROR, long long* \
                         : UPPER_BOUND_ERROR, float*     \
                         : UPPER_BOUND_ERROR, double*    \
                         : UPPER_BOUND_ERROR, short* \
                         : UPPER_BOUND_ERROR, int*\
                         : UPPER_BOUND_ERROR, unsigned short*\
                         : UPPER_BOUND_ERROR, unsigned long long*\
                         : UPPER_BOUND_ERROR)), \
                unsigned short*                            \
             : (_Generic((b), unsigned short*                \
                         :(unsigned short*)UPPER_BOUND_DEFAULT(a, b, &v, sizeof(unsigned short), less_then_unsigned), char*        \
                         : UPPER_BOUND_ERROR, long long* \
                         : UPPER_BOUND_ERROR, float*     \
                         : UPPER_BOUND_ERROR, double*    \
                         : UPPER_BOUND_ERROR, short* \
                         : UPPER_BOUND_ERROR, unsigned int*\
                         : UPPER_BOUND_ERROR, int*\
                         : UPPER_BOUND_ERROR, unsigned long long*\
                         : UPPER_BOUND_ERROR)), \
                unsigned long long*                            \
             : (_Generic((b), unsigned long long*                \
                         :(unsigned long long*)UPPER_BOUND_DEFAULT(a, b, &v, sizeof(unsigned long long), less_then_unsigned), char*        \
                         : UPPER_BOUND_ERROR, long long* \
                         : UPPER_BOUND_ERROR, float*     \
                         : UPPER_BOUND_ERROR, double*    \
                         : UPPER_BOUND_ERROR, short* \
                         : UPPER_BOUND_ERROR, unsigned int*\
                         : UPPER_BOUND_ERROR, unsigned short*\
                         : UPPER_BOUND_ERROR, int*\
                         : UPPER_BOUND_ERROR)))
// vector
#define Vector(_type, _name)                                              \
    typedef struct _name {                                                \
        _type* data;                                                      \
        size_t size;                                                      \
        size_t capacity;                                                  \
        void (*insert)(struct _name * this, size_t idx, _type elm);       \
        _type (*remove)(struct _name * this, size_t idx);                 \
        void (*set)(struct _name * this, size_t idx, _type elm);          \
        _type (*get)(struct _name * this, size_t idx);                    \
        void (*push)(struct _name * this, _type elm);                     \
        _type (*pop)(struct _name * this);                                \
        _type (*back)(struct _name * this);                               \
        _type (*front)(struct _name * this);                              \
        void (*clear)(struct _name * this);                               \
        void (*free)(struct _name * this);                                \
        void (*resize)(struct _name * this, size_t size);                 \
        bool (*empty)(struct _name * this);                               \
        /** Utilities */                                                  \
        void (*swap)(struct _name * this, size_t idx1, size_t idx2);      \
        void (*sort)(struct _name * this,                                 \
                     int (*compare)(const _type*, const _type*));         \
    } _name;                                                              \
    _name* create_vector_##_name();                                       \
    void insert_##_name(_name* vector, size_t _idx, _type val) {          \
        if (vector->size == vector->capacity) {                           \
            vector->capacity <<= 1;                                       \
            vector->data =                                                \
                realloc(vector->data, vector->capacity * sizeof(_type));  \
        }                                                                 \
        for (size_t i = vector->size; i > _idx; i--) {                    \
            vector->data[i] = vector->data[i - 1];                        \
        }                                                                 \
        vector->data[_idx] = val;                                         \
        vector->size++;                                                   \
    }                                                                     \
    _type remove_##_name(_name* vector, size_t _idx) {                    \
        if (_idx >= vector->size || _idx < 0) {                           \
            return -1;                                                    \
        }                                                                 \
        _type val = vector->data[_idx];                                   \
        for (size_t i = _idx; i < vector->size - 1; i++) {                \
            vector->data[i] = vector->data[i + 1];                        \
        }                                                                 \
        vector->size--;                                                   \
        return val;                                                       \
    }                                                                     \
    void set_##_name(_name* vector, size_t _idx, _type val) {             \
        if (_idx >= vector->size || _idx < 0) {                           \
            return;                                                       \
        }                                                                 \
        vector->data[_idx] = val;                                         \
    }                                                                     \
    _type get_##_name(_name* vector, size_t _idx) {                       \
        if (_idx >= vector->size || _idx < 0) {                           \
            return -1;                                                    \
        }                                                                 \
        return vector->data[_idx];                                        \
    }                                                                     \
    void push_##_name(_name* vector, _type val) {                         \
        insert_##_name(vector, vector->size, val);                        \
    }                                                                     \
    _type pop_##_name(_name* vector) {                                    \
        return remove_##_name(vector, vector->size - 1);                  \
    }                                                                     \
    _type back_##_name(_name* vector) {                                   \
        return get_##_name(vector, vector->size - 1);                     \
    }                                                                     \
    _type front_##_name(_name* vector) { return get_##_name(vector, 0); } \
    void clear_##_name(_name* vector) { vector->size = 0; }               \
    void free_##_name(_name* vector) {                                    \
        free(vector->data);                                               \
        free(vector);                                                     \
    }                                                                     \
    bool empty_##_name(_name* vector) { return vector->size == 0; }       \
    void resize_##_name(_name* vector, size_t size) {                     \
        vector->data = realloc(vector->data, size * sizeof(_type));       \
        vector->capacity = size;                                          \
        if (vector->size > size) {                                        \
            vector->size = size;                                          \
        }                                                                 \
    }                                                                     \
    void swap_##_name(_name* vector, size_t idx1, size_t idx2) {          \
        if (idx1 >= vector->size || idx2 >= vector->size) {               \
            return;                                                       \
        }                                                                 \
        _type tmp = vector->data[idx1];                                   \
        vector->data[idx1] = vector->data[idx2];                          \
        vector->data[idx2] = tmp;                                         \
    }                                                                     \
    void sort_##_name(_name* vector,                                      \
                      int (*compare)(const _type*, const _type*)) {       \
        qsort(vector->data, vector->size, sizeof(_type),                  \
              (int (*)(const void*, const void*))compare);                \
    }                                                                     \
    _name* create_vector_##_name() {                                      \
        _name* vector = malloc(sizeof(_name));                            \
        vector->size = 0;                                                 \
        vector->capacity = 16;                                            \
        vector->data = malloc(vector->capacity * sizeof(_type));          \
        vector->insert = &insert_##_name;                                 \
        vector->remove = &remove_##_name;                                 \
        vector->set = &set_##_name;                                       \
        vector->get = &get_##_name;                                       \
        vector->push = &push_##_name;                                     \
        vector->pop = &pop_##_name;                                       \
        vector->back = &back_##_name;                                     \
        vector->front = &front_##_name;                                   \
        vector->clear = &clear_##_name;                                   \
        vector->free = &free_##_name;                                     \
        vector->empty = &empty_##_name;                                   \
        vector->resize = &resize_##_name;                                 \
        vector->swap = &swap_##_name;                                     \
        vector->sort = &sort_##_name;                                     \
        return vector;                                                    \
    }
// linked-list
#define List(_type, _name)                                                    \
    typedef struct node_##_name {                                             \
        _type v;                                                              \
        struct node_##_name *pref, *nxt;                                      \
    } node_##_name;                                                           \
                                                                              \
    typedef struct _name {                                                    \
        size_t size;                                                          \
        node_##_name first;                                                   \
        void (*insert)(node_##_name * idx, _type elm);                        \
        void (*remove)(node_##_name * idx);                                   \
        void (*set)(node_##_name * idx, _type elm);                           \
        _type (*get)(node_##_name * idx);                                     \
        void (*push_back)(struct _name * this, _type elm);                    \
        void (*push_front)(struct _name * this, _type elm);                   \
        _type (*pop_front)(struct _name * this);                              \
        _type (*pop_back)(struct _name * this);                               \
        _type (*back)(struct _name * this);                                   \
        _type (*front)(struct _name * this);                                  \
        bool (*empty)(struct _name * this);                                   \
        void (*clear)(struct _name * this);                                   \
        void (*free)(struct _name * this);                                    \
        /** Utilities */                                                      \
        void (*swap)(node_##_name * idx1, node_##_name* idx2);                \
        void (*sort)(struct _name * this,                                     \
                     int (*compare)(const _type*, const _type*));             \
    } _name;                                                                  \
    _name* create_list_##_name();                                             \
    void insert_##_name(node_##_name* idx, _type elm) {                       \
        node_##_name* new_element = malloc(sizeof(node_##_name));             \
        new_element->v = elm;                                                 \
        idx->nxt->pref = new_element;                                         \
        new_element->nxt = idx->nxt;                                          \
        idx->nxt = new_element;                                               \
        new_element->pref = idx;                                              \
        list->size++;                                                         \
    }                                                                         \
    void remove_##_name(node_##_name* idx) {                                  \
        idx->pref->nxt = idx->nxt;                                            \
        idx->nxt->pref = idx->pref;                                           \
        free(idx);                                                            \
    }                                                                         \
    void set_##_name(node_##_name* idx, _type elm) { idx->v = elm; }          \
    _type get_##_name(node_##_name* idx) { return idx->v; }                   \
    void push_back_##_name(_name* list, _type val) {                          \
        insert_##_name(list->first.pref, val);                                \
    }                                                                         \
    _type pop_back_##_name(_name* list) {                                     \
        return remove_##_name(list->first.pref);                              \
    }                                                                         \
    void push_front_##_name(_name* list, _type val) {                         \
        insert_##_name(&(list->first), val);                                  \
    }                                                                         \
    _type pop_front_##_name(_name* list) {                                    \
        return remove_##_name(list->first.nxt);                               \
    }                                                                         \
    _type back_##_name(_name* list) { return get_##_name(list->first.pref); } \
    _type front_##_name(_name* list) { return get_##_name(list->first.nxt); } \
    void clear_##_name(_name* list) {                                         \
        while (list->size) {                                                  \
            pop_back_##_name(list);                                           \
        }                                                                     \
    }                                                                         \
    void free_##_name(_name* list) {                                          \
        clear_##_name(list);                                                  \
        free(list);                                                           \
    }                                                                         \
    bool empty_##_name(_name* list) { return list->size == 0; }               \
    void swap_##_name(node_##_name* idx1, node_##_name* idx2) {               \
        _type tmp = idx1->v;                                                  \
        idx1->v = idx2->v;                                                    \
        idx2->v = tmp;                                                        \
    }                                                                         \
    void SORT_##_name(node_##_name* l, node_##_name* r, size_t sz,            \
                      int (*compare)(const _type*, const _type*)) {           \
        if (sz == 0 || sz == 1) return;                                       \
        node_##_name* mid = l;                                                \
        for (int i = 0; i < (sz >> 1); ++i) {                                 \
            mid = mid->nxt;                                                   \
        }                                                                     \
        SORT_##_name(l, mid);                                                 \
        SORT_##_name(mid, r);                                                 \
        _type* new;                                                           \
        new = malloc(sizeof(_type) * sz);                                     \
        node_##_name *tmpl = l, *tmpr = mid;                                  \
        size_t cnt_new = 0;                                                   \
        while (tmpl != mid && tmpr != r) {                                    \
            if (compare(tmpl->v, tmpr->v)) {                                  \
                new[cnt_new] = tmpl->v;                                       \
                tmpl = tmpl->nxt;                                             \
            } else {                                                          \
                new[cnt_new] = tmpr->v;                                       \
                tmpr = tmpr->nxt;                                             \
            }                                                                 \
            cnt_new++;                                                        \
        }                                                                     \
        while (tmpl != mid) {                                                 \
            new[cnt_new] = tmpl->v;                                           \
            tmpl = tmpl->nxt;                                                 \
            cnt_new++;                                                        \
        }                                                                     \
        while (tmpr != r) {                                                   \
            new[cnt_new] = tmpr->v;                                           \
            tmpr = tmpr->nxt;                                                 \
            cnt_new++;                                                        \
        }                                                                     \
        node_##_name* now = l;                                                \
        for (int i = 0; i < sz; ++i) {                                        \
            now->v = new[i];                                                  \
            now = now->nxt;                                                   \
        }                                                                     \
    }                                                                         \
    void sort_##_name(_name* list,                                            \
                      int (*compare)(const _type*, const _type*)) {           \
        SORT_##_name(list->first.nxt, &(list->first), list->size, compare);   \
    }                                                                         \
    _name* create_list_##_name() {                                            \
        _name* list = malloc(sizeof(_name));                                  \
        list->size = 0;                                                       \
        list->first.nxt = &(list->first);                                     \
        list->first.pref = &(list->first);                                    \
        list->insert = &insert_##_name;                                       \
        list->remove = &remove_##_name;                                       \
        list->set = &set_##_name;                                             \
        list->get = &get_##_name;                                             \
        list->push_back = &push_back_##_name;                                 \
        list->push_front = &push_front_##_name;                               \
        list->pop_back = &pop_back_##_name;                                   \
        list->pop_front = &pop_front_##_name;                                 \
        list->back = &back_##_name;                                           \
        list->front = &front_##_name;                                         \
        list->clear = &clear_##_name;                                         \
        list->free = &free_##_name;                                           \
        list->empty = &empty_##_name;                                         \
        list->swap = &swap_##_name;                                           \
        list->sort = &sort_##_name;                                           \
        return list;                                                          \
    }
// stack
#define Stack(_type, _name)                                           \
    typedef struct node_##_name {                                     \
        _type v;                                                      \
        struct node_##_name *pref, *nxt;                              \
    } node_##_name;                                                   \
                                                                      \
    typedef struct _name {                                            \
        size_t size;                                                  \
        node_##_name first;                                           \
        void (*push)(struct _name * this, _type elm);                 \
        void (*pop)(struct _name * this);                             \
        _type (*top)(struct _name * this);                            \
        bool (*empty)(struct _name * this);                           \
        void (*clear)(struct _name * this);                           \
        void (*free)(struct _name * this);                            \
    } _name;                                                          \
    _name* create_stack_##_name();                                    \
    void push_##_name(_name* stack, _type val) {                      \
        node_##_name* new_element = malloc(sizeof(node_##_name));     \
        new_element->v = val;                                         \
        (stack->first).pref->nxt = new_element;                       \
        new_element->nxt = &(stack->first);                           \
        new_element->pref = stack->first.pref;                        \
        stack->first.pref = new_element;                              \
        stack->size++;                                                \
    }                                                                 \
    void pop_##_name(_name* stack) {                                  \
        node_##_name* idx = stack->first.pref;                        \
        idx->pref->nxt = &(stack->first);                             \
        stack->first.pref = idx->pref;                                \
        free(idx);                                                    \
        stack->size--;                                                \
    }                                                                 \
    _type top_##_name(_name* stack) { return stack->first.pref->v; }  \
    void clear_##_name(_name* stack) {                                \
        while (stack->size) {                                         \
            pop_##_name(stack);                                       \
        }                                                             \
    }                                                                 \
    void free_##_name(_name* stack) {                                 \
        clear_##_name(stack);                                         \
        free(stack);                                                  \
    }                                                                 \
    bool empty_##_name(_name* stack) { return ((stack->size) == 0); } \
    _name* create_stack_##_name() {                                   \
        _name* stack = malloc(sizeof(_name));                         \
        stack->size = 0;                                              \
        stack->first.nxt = &(stack->first);                           \
        stack->first.pref = &(stack->first);                          \
        stack->push = &push_##_name;                                  \
        stack->pop = &pop_##_name;                                    \
        stack->top = &top_##_name;                                    \
        stack->clear = &clear_##_name;                                \
        stack->empty = &empty_##_name;                                \
        stack->free = &free_##_name;                                  \
        return stack;                                                 \
    }
// queue
#define Queue(_type, _name)                                           \
    typedef struct node_##_name {                                     \
        _type v;                                                      \
        struct node_##_name *pref, *nxt;                              \
    } node_##_name;                                                   \
                                                                      \
    typedef struct _name {                                            \
        size_t size;                                                  \
        node_##_name first;                                           \
        void (*push)(struct _name * this, _type elm);                 \
        void (*pop)(struct _name * this);                             \
        _type (*front)(struct _name * this);                          \
        _type (*back)(struct _name * this);                           \
        bool (*empty)(struct _name * this);                           \
        void (*clear)(struct _name * this);                           \
        void (*free)(struct _name * this);                            \
    } _name;                                                          \
    _name* create_queue_##_name();                                    \
    void push_##_name(_name* queue, _type val) {                      \
        node_##_name* new_element = malloc(sizeof(node_##_name));     \
        new_element->v = val;                                         \
        ((queue->first).pref)->nxt = new_element;                     \
        new_element->nxt = &(queue->first);                           \
        new_element->pref = queue->first.pref;                        \
        (queue->first).pref = new_element;                            \
        queue->size++;                                                \
    }                                                                 \
    void pop_##_name(_name* queue) {                                  \
        node_##_name* idx = queue->first.nxt;                         \
        idx->nxt->pref = &(queue->first);                             \
        queue->first.nxt = idx->nxt;                                  \
        queue->size--;                                                \
        free(idx);                                                    \
    }                                                                 \
    _type back_##_name(_name* queue) { return queue->first.pref->v; } \
    _type front_##_name(_name* queue) { return queue->first.nxt->v; } \
    void clear_##_name(_name* queue) {                                \
        while (queue->size) {                                         \
            pop_##_name(queue);                                       \
        }                                                             \
    }                                                                 \
    void free_##_name(_name* queue) {                                 \
        clear_##_name(queue);                                         \
        free(queue);                                                  \
    }                                                                 \
    bool empty_##_name(_name* queue) { return queue->size == 0; }     \
    _name* create_queue_##_name() {                                   \
        _name* queue = malloc(sizeof(_name));                         \
        queue->size = 0;                                              \
        queue->first.nxt = &(queue->first);                           \
        queue->first.pref = &(queue->first);                          \
        queue->push = &push_##_name;                                  \
        queue->pop = &pop_##_name;                                    \
        queue->front = &front_##_name;                                \
        queue->back = &back_##_name;                                  \
        queue->clear = &clear_##_name;                                \
        queue->empty = &empty_##_name;                                \
        queue->free = &free_##_name;                                  \
        return queue;                                                 \
    }
// priority_queue
#define Priority_Queue(_type, _name, _cmp)                                  \
    typedef struct _name {                                                  \
        _type* data;                                                        \
        size_t size;                                                        \
        size_t capacity;                                                    \
        void (*push)(struct _name * this, _type elm);                       \
        void (*pop)(struct _name * this);                                   \
        _type (*top)(struct _name * this);                                  \
        bool (*empty)(struct _name * this);                                 \
        void (*clear)(struct _name * this);                                 \
        void (*free)(struct _name * this);                                  \
    } _name;                                                                \
    _name* create_priority_queue_##_name();                                 \
    void push_##_name(_name* priority_queue, _type elm) {                   \
        if (priority_queue->size == priority_queue->capacity) {             \
            priority_queue->capacity <<= 1;                                 \
            priority_queue->data =                                          \
                realloc(priority_queue->data,                               \
                        (priority_queue->capacity + 1) * sizeof(_type));    \
        }                                                                   \
        ++(priority_queue->size);                                           \
        priority_queue->data[(priority_queue->size)] = elm;                 \
        size_t now = priority_queue->size;                                  \
        while (now > 1) {                                                   \
            if (_cmp(priority_queue->data[now],                             \
                     priority_queue->data[now >> 1])) {                     \
                _type tmp = priority_queue->data[now];                      \
                priority_queue->data[now] = priority_queue->data[now >> 1]; \
                priority_queue->data[now >> 1] = tmp;                       \
                now >>= 1;                                                  \
            } else {                                                        \
                break;                                                      \
            }                                                               \
        }                                                                   \
        return;                                                             \
    }                                                                       \
    void pop_##_name(_name* priority_queue) {                               \
        if ((priority_queue->size)) {                                       \
            priority_queue->data[1] =                                       \
                priority_queue->data[priority_queue->size];                 \
            --(priority_queue->size);                                       \
            size_t now = 1;                                                 \
            while (now <= priority_queue->size) {                           \
                if ((now << 1) <= priority_queue->size) {                   \
                    if (_cmp(priority_queue->data[now << 1],                \
                             priority_queue->data[now])) {                  \
                        if ((now << 1 | 1) <= priority_queue->size) {       \
                            if (_cmp(priority_queue->data[now << 1 | 1],    \
                                     priority_queue->data[now << 1])) {     \
                                _type tmp = priority_queue->data[now];      \
                                priority_queue->data[now] =                 \
                                    priority_queue->data[now << 1 | 1];     \
                                priority_queue->data[now << 1 | 1] = tmp;   \
                                now = now << 1 | 1;                         \
                            } else {                                        \
                                _type tmp = priority_queue->data[now];      \
                                priority_queue->data[now] =                 \
                                    priority_queue->data[now << 1];         \
                                priority_queue->data[now << 1] = tmp;       \
                                now = now << 1;                             \
                            }                                               \
                        } else {                                            \
                            _type tmp = priority_queue->data[now];          \
                            priority_queue->data[now] =                     \
                                priority_queue->data[now << 1];             \
                            priority_queue->data[now << 1] = tmp;           \
                            now = now << 1;                                 \
                        }                                                   \
                    } else {                                                \
                        if ((now << 1 | 1) <= priority_queue->size) {       \
                            if (_cmp(priority_queue->data[now << 1 | 1],    \
                                     priority_queue->data[now])) {          \
                                _type tmp = priority_queue->data[now];      \
                                priority_queue->data[now] =                 \
                                    priority_queue->data[now << 1 | 1];     \
                                priority_queue->data[now << 1 | 1] = tmp;   \
                                now = now << 1 | 1;                         \
                            } else {                                        \
                                break;                                      \
                            }                                               \
                        } else {                                            \
                            break;                                          \
                        }                                                   \
                    }                                                       \
                } else {                                                    \
                    break;                                                  \
                }                                                           \
            }                                                               \
        }                                                                   \
    }                                                                       \
    _type top_##_name(_name* priority_queue) {                              \
        if (!(priority_queue->size)) return NULL;                           \
        return (priority_queue->data[1]);                                   \
    }                                                                       \
    bool empty_##_name(_name* priority_queue) {                             \
        return !(priority_queue->size);                                     \
    }                                                                       \
    void clear_##_name(_name* priority_queue) {                             \
        while (priority_queue->size) {                                      \
            pop_##_name(priority_queue);                                    \
        }                                                                   \
    }                                                                       \
    void free_##_name(_name* priority_queue) {                              \
        clear_##_name(priority_queue);                                      \
        free(priority_queue);                                               \
    }                                                                       \
    _name* create_priority_queue_##_name() {                                \
        _name* Priority_Queue = malloc(sizeof(_name));                      \
        Priority_Queue->size = 0;                                           \
        Priority_Queue->capacity = 16;                                      \
        Priority_Queue->data =                                              \
            malloc((Priority_Queue->capacity + 1) * sizeof(_type));         \
        Priority_Queue->push = &push_##_name;                               \
        Priority_Queue->pop = &pop_##_name;                                 \
        Priority_Queue->top = &top_##_name;                                 \
        Priority_Queue->empty = &empty_##_name;                             \
        Priority_Queue->clear = &clear_##_name;                             \
        Priority_Queue->free = &free_##_name;                               \
        return Priority_Queue;                                              \
    }
// set
#define Set(_type, _name, _cmp)                                                \
    typedef struct node_##_name {                                              \
        _type value;                                                           \
        int64_t bf;                                                            \
        int64_t height;                                                        \
        int64_t left, right;                                                   \
    } node_##_name;                                                            \
    typedef struct _name {                                                     \
        size_t size;                                                           \
        size_t capacity;                                                       \
        node_##_name* tree;                                                    \
        void (*insert)(struct _name * this, _type elm);                        \
        void (*erase)(struct _name * this, _type elm);                         \
        bool (*count)(struct _name * this, _type elm);                         \
        bool (*empty)(struct _name * this);                                    \
        void (*clear)(struct _name * this);                                    \
        void (*free)(struct _name * this);                                     \
        node_##_name* (*lowerbound)(struct _name * this, _type value);         \
        node_##_name* (*upperbound)(struct _name * this, _type value);         \
    } _name;                                                                   \
    _name* create_set_##_name();                                               \
    void update_##_name(_name* set, size_t now) {                              \
        if (set->tree[now].height == -1) return;                               \
        if (set->tree[now].left != -1)                                         \
            update_##_name(set, set->tree[now].left);                          \
        if (set->tree[now].right != -1)                                        \
            update_##_name(set, set->tree[now].right);                         \
        if (set->tree[now].left == -1) {                                       \
            set->tree[now].height = -1;                                        \
            set->tree[now].bf = -1;                                            \
        } else if (set->tree[set->tree[now].left].height == -1) {              \
            set->tree[now].height = -1;                                        \
            set->tree[now].bf = -1;                                            \
        } else {                                                               \
            set->tree[now].height = set->tree[set->tree[now].left].height;     \
            set->tree[now].bf = set->tree[set->tree[now].left].height;         \
        }                                                                      \
        if (set->tree[now].right == -1) {                                      \
            set->tree[now].bf -= -1;                                           \
        } else if (set->tree[set->tree[now].right].height == -1) {             \
            set->tree[now].bf -= -1;                                           \
        } else {                                                               \
            if ((set->tree[set->tree[now].right].height) >                     \
                (set->tree[now].height)) {                                     \
                set->tree[now].height =                                        \
                    set->tree[set->tree[now].right].height;                    \
            }                                                                  \
            set->tree[now].bf -= set->tree[set->tree[now].right].height;       \
        }                                                                      \
        (set->tree[now].height) += 1;                                          \
    }                                                                          \
    void LeftRotation_##_name(_name* set, size_t now) {                        \
        node_##_name A = set->tree[now];                                       \
        int64_t AL = set->tree[now].left;                                      \
        node_##_name B = set->tree[set->tree[now].right];                      \
        int64_t BL = set->tree[set->tree[now].right].left;                     \
        int64_t BR = set->tree[set->tree[now].right].right;                    \
        set->tree[now].value = B.value;                                        \
        set->tree[set->tree[now].right].value = A.value;                       \
        set->tree[now].left = set->tree[now].right;                            \
        set->tree[set->tree[now].left].left = AL;                              \
        set->tree[set->tree[now].left].right = BL;                             \
        set->tree[now].right = BR;                                             \
        return;                                                                \
    }                                                                          \
    void RightRotation_##_name(_name* set, size_t now) {                       \
        node_##_name A = set->tree[now];                                       \
        int64_t AR = set->tree[now].right;                                     \
        node_##_name B = set->tree[set->tree[now].left];                       \
        int64_t BL = set->tree[set->tree[now].left].left;                      \
        int64_t BR = set->tree[set->tree[now].left].right;                     \
        set->tree[now].value = B.value;                                        \
        set->tree[set->tree[now].left].value = A.value;                        \
        set->tree[now].right = set->tree[now].left;                            \
        set->tree[now].left = BL;                                              \
        set->tree[set->tree[now].right].left = BR;                             \
        set->tree[set->tree[now].right].right = AR;                            \
        return;                                                                \
    }                                                                          \
    void push_##_name(_name* set, _type elm, size_t now) {                     \
        if (now >= set->capacity) {                                            \
            set->capacity <<= 1;                                               \
            set->tree = realloc(set->tree,                                     \
                                (set->capacity + 1) * sizeof(node_##_name));   \
            for (size_t i = (set->capacity) >> 1; i <= set->capacity; ++i) {   \
                set->tree[now].value = 0;                                      \
                set->tree[now].bf = 0;                                         \
                set->tree[now].height = -1;                                    \
                set->tree[now].left = -1;                                      \
                set->tree[now].right = -1;                                     \
            }                                                                  \
        }                                                                      \
        if (set->tree[now].height == -1) {                                     \
            set->tree[now].value = elm;                                        \
            set->size++;                                                       \
            set->tree[now].height = 0;                                         \
            set->tree[now].bf = 0;                                             \
            return;                                                            \
        }                                                                      \
        if (set->tree[now].value == elm)                                       \
            return;                                                            \
        else if (_cmp(set->tree[now].value, elm) > 0) {                        \
            if (set->tree[now].left == -1) set->tree[now].left = set->size;    \
            push_##_name(set, elm, set->tree[now].left);                       \
        } else {                                                               \
            if (set->tree[now].right == -1) set->tree[now].right = set->size;  \
            push_##_name(set, elm, set->tree[now].right);                      \
        }                                                                      \
        if (set->tree[now].left == -1) {                                       \
            set->tree[now].height = -1;                                        \
            set->tree[now].bf = -1;                                            \
        } else if (set->tree[set->tree[now].left].height == -1) {              \
            set->tree[now].height = -1;                                        \
            set->tree[now].bf = -1;                                            \
        } else {                                                               \
            set->tree[now].height = set->tree[set->tree[now].left].height;     \
            set->tree[now].bf = set->tree[set->tree[now].left].height;         \
        }                                                                      \
        if (set->tree[now].right == -1) {                                      \
            set->tree[now].bf -= -1;                                           \
        } else if (set->tree[set->tree[now].right].height == -1) {             \
            set->tree[now].bf -= -1;                                           \
        } else {                                                               \
            if ((set->tree[set->tree[now].right].height) >                     \
                (set->tree[now].height)) {                                     \
                set->tree[now].height =                                        \
                    set->tree[set->tree[now].right].height;                    \
            }                                                                  \
            set->tree[now].bf -= set->tree[set->tree[now].right].height;       \
        }                                                                      \
        ++(set->tree[now].height);                                             \
        if (set->tree[now].bf >= 2) {                                          \
            if (set->tree[set->tree[now].left].bf > 0) {                       \
                RightRotation_##_name(set, now);                               \
            } else {                                                           \
                LeftRotation_##_name(set, set->tree[now].left);                \
                RightRotation_##_name(set, now);                               \
            }                                                                  \
            update_##_name(set, now);                                          \
        } else if (set->tree[now].bf <= -2) {                                  \
            if (set->tree[set->tree[now].right].bf > 0) {                      \
                RightRotation_##_name(set, set->tree[now].right);              \
                LeftRotation_##_name(set, now);                                \
            } else {                                                           \
                LeftRotation_##_name(set, now);                                \
            }                                                                  \
            update_##_name(set, now);                                          \
        }                                                                      \
        return;                                                                \
    };                                                                         \
    void pullup_##_name(_name* set, size_t now) {                              \
        if (set->tree[now].left == -1) {                                       \
            set->tree[now].value = 0;                                          \
            set->tree[now].bf = 0;                                             \
            set->tree[now].height = -1;                                        \
            set->tree[now].left = -1;                                          \
            set->tree[now].right = -1;                                         \
            return;                                                            \
        }                                                                      \
        set->tree[now].value = set->tree[set->tree[now].left].value;           \
        pullup_##_name(set, set->tree[now].left);                              \
        if (set->tree[now].height != -1) {                                     \
            if (set->tree[now].left == -1) {                                   \
                set->tree[now].height = -1;                                    \
                set->tree[now].bf = -1;                                        \
            } else if (set->tree[set->tree[now].left].height == -1) {          \
                set->tree[now].height = -1;                                    \
                set->tree[now].bf = -1;                                        \
            } else {                                                           \
                set->tree[now].height = set->tree[set->tree[now].left].height; \
                set->tree[now].bf = set->tree[set->tree[now].left].height;     \
            }                                                                  \
            if (set->tree[now].right == -1) {                                  \
                set->tree[now].bf -= -1;                                       \
            } else if (set->tree[set->tree[now].right].height == -1) {         \
                set->tree[now].bf -= -1;                                       \
            } else {                                                           \
                if ((set->tree[set->tree[now].right].height) >                 \
                    (set->tree[now].height)) {                                 \
                    set->tree[now].height =                                    \
                        set->tree[set->tree[now].right].height;                \
                }                                                              \
                set->tree[now].bf -= set->tree[set->tree[now].right].height;   \
            }                                                                  \
            ++(set->tree[now].height);                                         \
            if (set->tree[now].bf >= 2) {                                      \
                if (set->tree[set->tree[now].left].bf > 0) {                   \
                    RightRotation_##_name(set, now);                           \
                } else {                                                       \
                    LeftRotation_##_name(set, set->tree[now].left);            \
                    RightRotation_##_name(set, now);                           \
                }                                                              \
                update_##_name(set, now);                                      \
            } else if (set->tree[now].bf <= -2) {                              \
                if (set->tree[set->tree[now].right].bf > 0) {                  \
                    RightRotation_##_name(set, set->tree[now].right);          \
                    LeftRotation_##_name(set, now);                            \
                } else {                                                       \
                    LeftRotation_##_name(set, now);                            \
                }                                                              \
                update_##_name(set, now);                                      \
            }                                                                  \
        }                                                                      \
        return;                                                                \
    }                                                                          \
    void pop_##_name(_name* set, _type elm, size_t now) {                      \
        if (set->tree[now].height == -1) {                                     \
            return;                                                            \
        }                                                                      \
        if (set->tree[now].value == elm) {                                     \
            bool lh = 0;                                                       \
            bool rh = 0;                                                       \
            if (set->tree[now].left == -1)                                     \
                lh = 1;                                                        \
            else if (set->tree[set->tree[now].left].height == -1)              \
                lh = 1;                                                        \
            if (set->tree[now].right == -1)                                    \
                rh = 1;                                                        \
            else if (set->tree[set->tree[now].right].height == -1)             \
                rh = 1;                                                        \
            if (lh && rh) {                                                    \
                set->tree[now].value = 0;                                      \
                set->tree[now].bf = 0;                                         \
                set->tree[now].height = -1;                                    \
                set->tree[now].left = -1;                                      \
                set->tree[now].right = -1;                                     \
            } else if (lh) {                                                   \
                node_##_name tmp = set->tree[set->tree[now].right];            \
                set->tree[now].value = tmp.value;                              \
                set->tree[now].left = tmp.left;                                \
                set->tree[now].right = tmp.right;                              \
            } else if (rh) {                                                   \
                node_##_name tmp = set->tree[set->tree[now].left];             \
                set->tree[now].value = tmp.value;                              \
                set->tree[now].left = tmp.left;                                \
                set->tree[now].right = tmp.right;                              \
            } else {                                                           \
                pullup_##_name(set, now);                                      \
            }                                                                  \
            --(set->size);                                                     \
            return;                                                            \
        } else if (_cmp(set->tree[now].value, elm) > 0) {                      \
            if (set->tree[now].left != -1) {                                   \
                pop_##_name(set, elm, set->tree[now].left);                    \
            }                                                                  \
        } else {                                                               \
            if (set->tree[now].right != -1) {                                  \
                pop_##_name(set, elm, set->tree[now].right);                   \
            }                                                                  \
        }                                                                      \
        if (set->tree[now].left == -1) {                                       \
            set->tree[now].height = -1;                                        \
            set->tree[now].bf = -1;                                            \
        } else if (set->tree[set->tree[now].left].height == -1) {              \
            set->tree[now].height = -1;                                        \
            set->tree[now].bf = -1;                                            \
        } else {                                                               \
            set->tree[now].height = set->tree[set->tree[now].left].height;     \
            set->tree[now].bf = set->tree[set->tree[now].left].height;         \
        }                                                                      \
        if (set->tree[now].right == -1) {                                      \
            set->tree[now].bf -= -1;                                           \
        } else if (set->tree[set->tree[now].right].height == -1) {             \
            set->tree[now].bf -= -1;                                           \
        } else {                                                               \
            if ((set->tree[set->tree[now].right].height) >                     \
                (set->tree[now].height)) {                                     \
                set->tree[now].height =                                        \
                    set->tree[set->tree[now].right].height;                    \
            }                                                                  \
            set->tree[now].bf -= set->tree[set->tree[now].right].height;       \
        }                                                                      \
        (set->tree[now].height) += 1;                                          \
        if (set->tree[now].bf >= 2) {                                          \
            if (set->tree[set->tree[now].left].bf > 0) {                       \
                RightRotation_##_name(set, now);                               \
            } else {                                                           \
                LeftRotation_##_name(set, set->tree[now].left);                \
                RightRotation_##_name(set, now);                               \
            }                                                                  \
            update_##_name(set, now);                                          \
        } else if (set->tree[now].bf <= -2) {                                  \
            if (set->tree[set->tree[now].right].bf > 0) {                      \
                RightRotation_##_name(set, set->tree[now].right);              \
                LeftRotation_##_name(set, now);                                \
            } else {                                                           \
                LeftRotation_##_name(set, now);                                \
            }                                                                  \
            update_##_name(set, now);                                          \
        }                                                                      \
        return;                                                                \
    };                                                                         \
    void insert_##_name(_name* set, _type elm) {                               \
        push_##_name(set, elm, 0);                                             \
        return;                                                                \
    }                                                                          \
    void erase_##_name(_name* set, _type elm) {                                \
        pop_##_name(set, elm, 0);                                              \
        return;                                                                \
    }                                                                          \
    bool count_##_name(_name* set, _type elm) {                                \
        size_t now = 0;                                                        \
        while (set->tree[now].height != -1) {                                  \
            if (set->tree[now].value == elm) return 1;                         \
            if (set->tree[now].value > elm)                                    \
                if (set->tree[now].left != -1)                                 \
                    now = set->tree[now].left;                                 \
                else                                                           \
                    break;                                                     \
            else if (set->tree[now].right != -1)                               \
                now = set->tree[now].right;                                    \
            else                                                               \
                break;                                                         \
        }                                                                      \
        return 0;                                                              \
    }                                                                          \
    bool empty_##_name(_name* set) { return !(set->size); }                    \
    void clear_##_name(_name* set) {                                           \
        while (set->size) {                                                    \
            pop_##_name(set, set->tree[0].value, 0);                           \
        }                                                                      \
    }                                                                          \
    void free_##_name(_name* set) {                                            \
        clear_##_name(set);                                                    \
        free(set);                                                             \
    }                                                                          \
    node_##_name* lower_bound_##_name(_name* set, _type value) {               \
        int64_t now = 0;                                                       \
        int64_t father = -1;                                                   \
        while (set->tree[now].height != -1) {                                  \
            if (_cmp((set->tree[now]).value, value) == 0)                      \
                return &set->tree[now];                                        \
            else if (_cmp((set->tree[now]).value, value) > 0) {                \
                if (set->tree[now].left == -1) return &set->tree[now];         \
                father = now;                                                  \
                now = set->tree[now].left;                                     \
            } else if (set->tree[now].right != -1) {                           \
                father = now;                                                  \
                now = set->tree[now].right;                                    \
            } else                                                             \
                return &set->tree[father];                                     \
        }                                                                      \
        return &set->tree[set->size];                                          \
    }                                                                          \
    node_##_name* upper_bound_##_name(_name* set, _type value) {               \
        int64_t now = 0;                                                       \
        int64_t father = -1;                                                   \
        while (set->tree[now].height != -1) {                                  \
            if (_cmp(set->tree[now].value, value) > 0) {                       \
                if (set->tree[now].left == -1) return &set->tree[now];         \
                father = now;                                                  \
                now = set->tree[now].left;                                     \
            } else if (set->tree[now].right != -1) {                           \
                father = now;                                                  \
                now = set->tree[now].right;                                    \
            } else                                                             \
                return &set->tree[father];                                     \
        }                                                                      \
        return &set->tree[set->size];                                          \
    }                                                                          \
    _name* create_set_##_name() {                                              \
        _name* set = malloc(sizeof(_name));                                    \
        set->size = 0;                                                         \
        set->capacity = 16;                                                    \
        set->tree = malloc((set->capacity + 1) * sizeof(node_##_name));        \
        for (size_t i = 0; i <= set->capacity; ++i) {                          \
            set->tree[i].value = 0;                                            \
            set->tree[i].bf = 0;                                               \
            set->tree[i].height = -1;                                          \
            set->tree[i].left = -1;                                            \
            set->tree[i].right = -1;                                           \
        }                                                                      \
        set->insert = &insert_##_name;                                         \
        set->erase = &erase_##_name;                                           \
        set->count = &count_##_name;                                           \
        set->empty = &empty_##_name;                                           \
        set->clear = &clear_##_name;                                           \
        set->free = &free_##_name;                                             \
        set->lowerbound = &lower_bound_##_name;                                \
        set->upperbound = &upper_bound_##_name;                                \
        return set;                                                            \
    }
// map
#define Map(_typeOfIndex, _typeOfValue, _name, _cmp)                           \
    typedef struct node_##_name {                                              \
        int64_t bf;                                                            \
        int64_t height;                                                        \
        int64_t left, right;                                                   \
        _typeOfIndex index;                                                    \
        _typeOfValue value;                                                    \
    } node_##_name;                                                            \
    typedef struct _name {                                                     \
        size_t size;                                                           \
        size_t capacity;                                                       \
        node_##_name* tree;                                                    \
        void (*insert)(struct _name * this, _typeOfIndex idx,                  \
                       _typeOfValue elm);                                      \
        void (*erase)(struct _name * this, _typeOfIndex idx);                  \
        bool (*count)(struct _name * this, _typeOfIndex idx);                  \
        _typeOfValue (*val)(struct _name * this, _typeOfIndex idx);            \
        void (*set)(struct _name * this, _typeOfIndex idx, _typeOfValue elm);  \
        bool (*empty)(struct _name * this);                                    \
        void (*clear)(struct _name * this);                                    \
        void (*free)(struct _name * this);                                     \
        node_##_name* (*lowerbound)(struct _name * this, _typeOfIndex index);  \
        node_##_name* (*upperbound)(struct _name * this, _typeOfIndex index);  \
    } _name;                                                                   \
    _name* create_map_##_name();                                               \
    void update_##_name(_name* map, size_t now) {                              \
        if (map->tree[now].height == -1) return;                               \
        if (map->tree[now].left != -1)                                         \
            update_##_name(map, map->tree[now].left);                          \
        if (map->tree[now].right != -1)                                        \
            update_##_name(map, map->tree[now].right);                         \
        if (map->tree[now].left == -1) {                                       \
            map->tree[now].height = -1;                                        \
            map->tree[now].bf = -1;                                            \
        } else if (map->tree[map->tree[now].left].height == -1) {              \
            map->tree[now].height = -1;                                        \
            map->tree[now].bf = -1;                                            \
        } else {                                                               \
            map->tree[now].height = map->tree[map->tree[now].left].height;     \
            map->tree[now].bf = map->tree[map->tree[now].left].height;         \
        }                                                                      \
        if (map->tree[now].right == -1) {                                      \
            map->tree[now].bf -= -1;                                           \
        } else if (map->tree[map->tree[now].right].height == -1) {             \
            map->tree[now].bf -= -1;                                           \
        } else {                                                               \
            if ((map->tree[map->tree[now].right].height) >                     \
                (map->tree[now].height)) {                                     \
                map->tree[now].height =                                        \
                    map->tree[map->tree[now].right].height;                    \
            }                                                                  \
            map->tree[now].bf -= map->tree[map->tree[now].right].height;       \
        }                                                                      \
        (map->tree[now].height) += 1;                                          \
    }                                                                          \
    void LeftRotation_##_name(_name* map, size_t now) {                        \
        node_##_name A = map->tree[now];                                       \
        int64_t AL = map->tree[now].left;                                      \
        node_##_name B = map->tree[map->tree[now].right];                      \
        int64_t BL = map->tree[map->tree[now].right].left;                     \
        int64_t BR = map->tree[map->tree[now].right].right;                    \
        map->tree[now].index = B.index;                                        \
        map->tree[now].value = B.value;                                        \
        map->tree[map->tree[now].right].index = A.index;                       \
        map->tree[map->tree[now].right].value = A.value;                       \
        map->tree[now].left = map->tree[now].right;                            \
        map->tree[map->tree[now].left].left = AL;                              \
        map->tree[map->tree[now].left].right = BL;                             \
        map->tree[now].right = BR;                                             \
        return;                                                                \
    }                                                                          \
    void RightRotation_##_name(_name* map, size_t now) {                       \
        node_##_name A = map->tree[now];                                       \
        int64_t AR = map->tree[now].right;                                     \
        node_##_name B = map->tree[map->tree[now].left];                       \
        int64_t BL = map->tree[map->tree[now].left].left;                      \
        int64_t BR = map->tree[map->tree[now].left].right;                     \
        map->tree[now].index = B.index;                                        \
        map->tree[now].value = B.value;                                        \
        map->tree[map->tree[now].left].index = A.index;                        \
        map->tree[map->tree[now].left].value = A.value;                        \
        map->tree[now].right = map->tree[now].left;                            \
        map->tree[now].left = BL;                                              \
        map->tree[map->tree[now].right].left = BR;                             \
        map->tree[map->tree[now].right].right = AR;                            \
        return;                                                                \
    }                                                                          \
    void push_##_name(_name* map, _typeOfIndex idx, _typeOfValue elm,          \
                      size_t now) {                                            \
        if (now >= map->capacity) {                                            \
            map->capacity <<= 1;                                               \
            map->tree = realloc(map->tree,                                     \
                                (map->capacity + 1) * sizeof(node_##_name));   \
            for (size_t i = (map->capacity) >> 1; i <= map->capacity; ++i) {   \
                map->tree[now].index = 0;                                      \
                map->tree[now].value = 0;                                      \
                map->tree[now].bf = 0;                                         \
                map->tree[now].height = -1;                                    \
                map->tree[now].left = -1;                                      \
                map->tree[now].right = -1;                                     \
            }                                                                  \
        }                                                                      \
        if (map->tree[now].height == -1) {                                     \
            map->tree[now].index = idx;                                        \
            map->tree[now].value = elm;                                        \
            map->size++;                                                       \
            map->tree[now].height = 0;                                         \
            map->tree[now].bf = 0;                                             \
            return;                                                            \
        }                                                                      \
        if (_cmp(map->tree[now].index, idx) == 0) {                            \
            map->tree[now].value = elm;                                        \
            return;                                                            \
        } else if (_cmp(map->tree[now].index, idx) > 0) {                      \
            if (map->tree[now].left == -1) map->tree[now].left = map->size;    \
            push_##_name(map, idx, elm, map->tree[now].left);                  \
        } else {                                                               \
            if (map->tree[now].right == -1) map->tree[now].right = map->size;  \
            push_##_name(map, idx, elm, map->tree[now].right);                 \
        }                                                                      \
        if (map->tree[now].left == -1) {                                       \
            map->tree[now].height = -1;                                        \
            map->tree[now].bf = -1;                                            \
        } else if (map->tree[map->tree[now].left].height == -1) {              \
            map->tree[now].height = -1;                                        \
            map->tree[now].bf = -1;                                            \
        } else {                                                               \
            map->tree[now].height = map->tree[map->tree[now].left].height;     \
            map->tree[now].bf = map->tree[map->tree[now].left].height;         \
        }                                                                      \
        if (map->tree[now].right == -1) {                                      \
            map->tree[now].bf -= -1;                                           \
        } else if (map->tree[map->tree[now].right].height == -1) {             \
            map->tree[now].bf -= -1;                                           \
        } else {                                                               \
            if ((map->tree[map->tree[now].right].height) >                     \
                (map->tree[now].height)) {                                     \
                map->tree[now].height =                                        \
                    map->tree[map->tree[now].right].height;                    \
            }                                                                  \
            map->tree[now].bf -= map->tree[map->tree[now].right].height;       \
        }                                                                      \
        ++(map->tree[now].height);                                             \
        if (map->tree[now].bf >= 2) {                                          \
            if (map->tree[map->tree[now].left].bf > 0) {                       \
                RightRotation_##_name(map, now);                               \
            } else {                                                           \
                LeftRotation_##_name(map, map->tree[now].left);                \
                RightRotation_##_name(map, now);                               \
            }                                                                  \
            update_##_name(map, now);                                          \
        } else if (map->tree[now].bf <= -2) {                                  \
            if (map->tree[map->tree[now].right].bf > 0) {                      \
                RightRotation_##_name(map, map->tree[now].right);              \
                LeftRotation_##_name(map, now);                                \
            } else {                                                           \
                LeftRotation_##_name(map, now);                                \
            }                                                                  \
            update_##_name(map, now);                                          \
        }                                                                      \
        return;                                                                \
    };                                                                         \
    void pullup_##_name(_name* map, size_t now) {                              \
        if (map->tree[now].left == -1) {                                       \
            map->tree[now].index = 0;                                          \
            map->tree[now].value = 0;                                          \
            map->tree[now].bf = 0;                                             \
            map->tree[now].height = -1;                                        \
            map->tree[now].left = -1;                                          \
            map->tree[now].right = -1;                                         \
            return;                                                            \
        }                                                                      \
        map->tree[now].index = map->tree[map->tree[now].left].index;           \
        map->tree[now].value = map->tree[map->tree[now].left].value;           \
        pullup_##_name(map, map->tree[now].left);                              \
        if (map->tree[now].height != -1) {                                     \
            if (map->tree[now].left == -1) {                                   \
                map->tree[now].height = -1;                                    \
                map->tree[now].bf = -1;                                        \
            } else if (map->tree[map->tree[now].left].height == -1) {          \
                map->tree[now].height = -1;                                    \
                map->tree[now].bf = -1;                                        \
            } else {                                                           \
                map->tree[now].height = map->tree[map->tree[now].left].height; \
                map->tree[now].bf = map->tree[map->tree[now].left].height;     \
            }                                                                  \
            if (map->tree[now].right == -1) {                                  \
                map->tree[now].bf -= -1;                                       \
            } else if (map->tree[map->tree[now].right].height == -1) {         \
                map->tree[now].bf -= -1;                                       \
            } else {                                                           \
                if ((map->tree[map->tree[now].right].height) >                 \
                    (map->tree[now].height)) {                                 \
                    map->tree[now].height =                                    \
                        map->tree[map->tree[now].right].height;                \
                }                                                              \
                map->tree[now].bf -= map->tree[map->tree[now].right].height;   \
            }                                                                  \
            ++(map->tree[now].height);                                         \
            if (map->tree[now].bf >= 2) {                                      \
                if (map->tree[map->tree[now].left].bf > 0) {                   \
                    RightRotation_##_name(map, now);                           \
                } else {                                                       \
                    LeftRotation_##_name(map, map->tree[now].left);            \
                    RightRotation_##_name(map, now);                           \
                }                                                              \
                update_##_name(map, now);                                      \
            } else if (map->tree[now].bf <= -2) {                              \
                if (map->tree[map->tree[now].right].bf > 0) {                  \
                    RightRotation_##_name(map, map->tree[now].right);          \
                    LeftRotation_##_name(map, now);                            \
                } else {                                                       \
                    LeftRotation_##_name(map, now);                            \
                }                                                              \
                update_##_name(map, now);                                      \
            }                                                                  \
        }                                                                      \
        return;                                                                \
    }                                                                          \
    void pop_##_name(_name* map, _typeOfIndex idx, size_t now) {               \
        if (map->tree[now].height == -1) {                                     \
            return;                                                            \
        }                                                                      \
        if (map->tree[now].index == idx) {                                     \
            bool lh = 0;                                                       \
            bool rh = 0;                                                       \
            if (map->tree[now].left == -1)                                     \
                lh = 1;                                                        \
            else if (map->tree[map->tree[now].left].height == -1)              \
                lh = 1;                                                        \
            if (map->tree[now].right == -1)                                    \
                rh = 1;                                                        \
            else if (map->tree[map->tree[now].right].height == -1)             \
                rh = 1;                                                        \
            if (lh && rh) {                                                    \
                map->tree[now].index = 0;                                      \
                map->tree[now].value = 0;                                      \
                map->tree[now].bf = 0;                                         \
                map->tree[now].height = -1;                                    \
                map->tree[now].left = -1;                                      \
                map->tree[now].right = -1;                                     \
            } else if (lh) {                                                   \
                node_##_name tmp = map->tree[map->tree[now].right];            \
                map->tree[now].index = tmp.index;                              \
                map->tree[now].value = tmp.value;                              \
                map->tree[now].left = tmp.left;                                \
                map->tree[now].right = tmp.right;                              \
            } else if (rh) {                                                   \
                node_##_name tmp = map->tree[map->tree[now].left];             \
                map->tree[now].index = tmp.index;                              \
                map->tree[now].value = tmp.value;                              \
                map->tree[now].left = tmp.left;                                \
                map->tree[now].right = tmp.right;                              \
            } else {                                                           \
                pullup_##_name(map, now);                                      \
            }                                                                  \
            --(map->size);                                                     \
            return;                                                            \
        } else if (_cmp(map->tree[now].index, idx) > 0) {                      \
            if (map->tree[now].left != -1) {                                   \
                pop_##_name(map, idx, map->tree[now].left);                    \
            }                                                                  \
        } else {                                                               \
            if (map->tree[now].right != -1) {                                  \
                pop_##_name(map, idx, map->tree[now].right);                   \
            }                                                                  \
        }                                                                      \
        if (map->tree[now].left == -1) {                                       \
            map->tree[now].height = -1;                                        \
            map->tree[now].bf = -1;                                            \
        } else if (map->tree[map->tree[now].left].height == -1) {              \
            map->tree[now].height = -1;                                        \
            map->tree[now].bf = -1;                                            \
        } else {                                                               \
            map->tree[now].height = map->tree[map->tree[now].left].height;     \
            map->tree[now].bf = map->tree[map->tree[now].left].height;         \
        }                                                                      \
        if (map->tree[now].right == -1) {                                      \
            map->tree[now].bf -= -1;                                           \
        } else if (map->tree[map->tree[now].right].height == -1) {             \
            map->tree[now].bf -= -1;                                           \
        } else {                                                               \
            if ((map->tree[map->tree[now].right].height) >                     \
                (map->tree[now].height)) {                                     \
                map->tree[now].height =                                        \
                    map->tree[map->tree[now].right].height;                    \
            }                                                                  \
            map->tree[now].bf -= map->tree[map->tree[now].right].height;       \
        }                                                                      \
        (map->tree[now].height) += 1;                                          \
        if (map->tree[now].bf >= 2) {                                          \
            if (map->tree[map->tree[now].left].bf > 0) {                       \
                RightRotation_##_name(map, now);                               \
            } else {                                                           \
                LeftRotation_##_name(map, map->tree[now].left);                \
                RightRotation_##_name(map, now);                               \
            }                                                                  \
            update_##_name(map, now);                                          \
        } else if (map->tree[now].bf <= -2) {                                  \
            if (map->tree[map->tree[now].right].bf > 0) {                      \
                RightRotation_##_name(map, map->tree[now].right);              \
                LeftRotation_##_name(map, now);                                \
            } else {                                                           \
                LeftRotation_##_name(map, now);                                \
            }                                                                  \
            update_##_name(map, now);                                          \
        }                                                                      \
        return;                                                                \
    };                                                                         \
    void insert_##_name(_name* map, _typeOfIndex idx, _typeOfValue elm) {      \
        push_##_name(map, idx, elm, 0);                                        \
        return;                                                                \
    }                                                                          \
    void erase_##_name(_name* map, _typeOfIndex idx) {                         \
        pop_##_name(map, idx, 0);                                              \
        return;                                                                \
    }                                                                          \
    bool count_##_name(_name* map, _typeOfIndex idx) {                         \
        size_t now = 0;                                                        \
        while (map->tree[now].height != -1) {                                  \
            if (map->tree[now].index == idx) return 1;                         \
            if (_cmp(map->tree[now].index, idx) > 0)                           \
                if (map->tree[now].left != -1)                                 \
                    now = map->tree[now].left;                                 \
                else                                                           \
                    break;                                                     \
            else if (map->tree[now].right != -1)                               \
                now = map->tree[now].right;                                    \
            else                                                               \
                break;                                                         \
        }                                                                      \
        return 0;                                                              \
    }                                                                          \
    _typeOfValue val_##_name(_name* map, _typeOfIndex idx) {                   \
        size_t now = 0;                                                        \
        while (map->tree[now].height != -1) {                                  \
            if (map->tree[now].index == idx) return map->tree[now].value;      \
            if (_cmp(map->tree[now].index, idx) > 0)                           \
                if (map->tree[now].left != -1)                                 \
                    now = map->tree[now].left;                                 \
                else                                                           \
                    break;                                                     \
            else if (map->tree[now].right != -1)                               \
                now = map->tree[now].right;                                    \
            else                                                               \
                break;                                                         \
        }                                                                      \
        exit(1);                                                               \
    }                                                                          \
    void set_##_name(_name* map, _typeOfIndex idx, _typeOfValue elm) {         \
        size_t now = 0;                                                        \
        while (map->tree[now].height != -1) {                                  \
            if (map->tree[now].index == idx) {                                 \
                map->tree[now].value = elm;                                    \
                return;                                                        \
            }                                                                  \
            if (_cmp(map->tree[now].index, idx) > 0)                           \
                if (map->tree[now].left != -1)                                 \
                    now = map->tree[now].left;                                 \
                else                                                           \
                    break;                                                     \
            else if (map->tree[now].right != -1)                               \
                now = map->tree[now].right;                                    \
            else                                                               \
                break;                                                         \
        }                                                                      \
        return;                                                                \
    }                                                                          \
    bool empty_##_name(_name* map) { return !(map->size); }                    \
    void clear_##_name(_name* map) {                                           \
        while (map->size) {                                                    \
            pop_##_name(map, map->tree[0].index, 0);                           \
        }                                                                      \
    }                                                                          \
    void free_##_name(_name* map) {                                            \
        clear_##_name(map);                                                    \
        free(map);                                                             \
    }                                                                          \
    node_##_name* lower_bound_##_name(_name* map, _typeOfIndex index) {        \
        int64_t now = 0;                                                       \
        int64_t father = -1;                                                   \
        while (map->tree[now].height != -1) {                                  \
            if (_cmp((map->tree[now]).index, index) == 0)                      \
                return &map->tree[now];                                        \
            else if (_cmp((map->tree[now]).index, index) > 0) {                \
                if (map->tree[now].left == -1) return &map->tree[now];         \
                father = now;                                                  \
                now = map->tree[now].left;                                     \
            } else if (map->tree[now].right != -1) {                           \
                father = now;                                                  \
                now = map->tree[now].right;                                    \
            } else                                                             \
                return &map->tree[father];                                     \
        }                                                                      \
        return &map->tree[map->size];                                          \
    }                                                                          \
    node_##_name* upper_bound_##_name(_name* map, _typeOfIndex index) {        \
        int64_t now = 0;                                                       \
        int64_t father = -1;                                                   \
        while (map->tree[now].height != -1) {                                  \
            if (_cmp(map->tree[now].index, index) > 0) {                       \
                if (map->tree[now].left == -1) return &map->tree[now];         \
                father = now;                                                  \
                now = map->tree[now].left;                                     \
            } else if (map->tree[now].right != -1) {                           \
                father = now;                                                  \
                now = map->tree[now].right;                                    \
            } else                                                             \
                return &map->tree[father];                                     \
        }                                                                      \
        return &map->tree[map->size];                                          \
    }                                                                          \
    _name* create_map_##_name() {                                              \
        _name* map = malloc(sizeof(_name));                                    \
        map->size = 0;                                                         \
        map->capacity = 16;                                                    \
        map->tree = malloc((map->capacity + 1) * sizeof(node_##_name));        \
        for (size_t i = 0; i <= map->capacity; ++i) {                          \
            map->tree[i].index = 0;                                            \
            map->tree[i].value = 0;                                            \
            map->tree[i].bf = 0;                                               \
            map->tree[i].height = -1;                                          \
            map->tree[i].left = -1;                                            \
            map->tree[i].right = -1;                                           \
        }                                                                      \
        map->insert = &insert_##_name;                                         \
        map->erase = &erase_##_name;                                           \
        map->count = &count_##_name;                                           \
        map->val = &val_##_name;                                               \
        map->set = &set_##_name;                                               \
        map->empty = &empty_##_name;                                           \
        map->clear = &clear_##_name;                                           \
        map->free = &free_##_name;                                             \
        map->lowerbound = &lower_bound_##_name;                                \
        map->upperbound = &upper_bound_##_name;                                \
        return map;                                                            \
    }
// Treap
#ifndef nullptr
#define nullptr ((void*)0)
#endif

#define Treap(_type, _name, _cmp, _pullUp, _pushDown)                          \
    typedef struct node_##_name {                                              \
        struct node_##_name *leftNode, *rightNode;                             \
        _type treeKey;                                                         \
        int heapKey;                                                           \
    } node_##_name;                                                            \
    typedef struct _name {                                                     \
        node_##_name* tree;                                                    \
        node_##_name* (*build)(struct _name * this, _type key);                \
        node_##_name* (*merge)(struct _name * this, node_##_name* a,           \
                               node_##_name* b);                               \
        void (*split)(struct _name * this, node_##_name* cur, _type key,       \
                      node_##_name** a, node_##_name** b);                     \
        void (*free)(struct _name * this);                                     \
    } _name;                                                                   \
    _name* create_treap_##_name();                                             \
    node_##_name* build_##_name(struct _name* treap, data key) {               \
        node_##_name* ret = malloc(sizeof(node_##_name));                      \
        ret->leftNode = ret->rightNode = nullptr;                              \
        ret->treeKey = key;                                                    \
        ret->heapKey = rand();                                                 \
        return ret;                                                            \
    }                                                                          \
    node_##_name* merge_##_name(struct _name* treap, node_##_name* a,          \
                                node_##_name* b) {                             \
        if (a == nullptr && b == nullptr) return nullptr;                      \
        if (a == nullptr) return b;                                            \
        if (b == nullptr) return a;                                            \
        _pushDown(                                                             \
            &(a->treeKey),                                                     \
            ((a->leftNode == nullptr) ? nullptr : (&(a->leftNode->treeKey))),  \
            ((a->rightNode == nullptr) ? nullptr                               \
                                       : (&(a->rightNode->treeKey))));         \
        _pushDown(                                                             \
            &(b->treeKey),                                                     \
            ((b->leftNode == nullptr) ? nullptr : (&(b->leftNode->treeKey))),  \
            ((b->rightNode == nullptr) ? nullptr                               \
                                       : (&(b->rightNode->treeKey))));         \
        if (a->heapKey < b->heapKey) {                                         \
            a->rightNode = merge_##_name(treap, a->rightNode, b);              \
            _pullUp(&(a->treeKey),                                             \
                    ((a->leftNode == nullptr) ? nullptr                        \
                                              : (&(a->leftNode->treeKey))),    \
                    ((a->rightNode == nullptr) ? nullptr                       \
                                               : (&(a->rightNode->treeKey)))); \
            return a;                                                          \
        }                                                                      \
        b->leftNode = merge_##_name(treap, a, b->leftNode);                    \
        _pullUp(                                                               \
            &(b->treeKey),                                                     \
            ((b->leftNode == nullptr) ? nullptr : (&(b->leftNode->treeKey))),  \
            ((b->rightNode == nullptr) ? nullptr                               \
                                       : (&(b->rightNode->treeKey))));         \
        return b;                                                              \
    }                                                                          \
    void split_##_name(struct _name* treap, node_##_name* cur, _type key,      \
                       node_##_name** a, node_##_name** b) {                   \
        if (cur == nullptr) {                                                  \
            *a = nullptr;                                                      \
            *b = nullptr;                                                      \
            return;                                                            \
        }                                                                      \
        _pushDown(                                                             \
            &(cur->treeKey),                                                   \
            ((cur->leftNode == nullptr) ? nullptr                              \
                                        : (&(cur->leftNode->treeKey))),        \
            ((cur->rightNode == nullptr) ? nullptr                             \
                                         : (&(cur->rightNode->treeKey))));     \
        if (_cmp(cur->treeKey, key)) {                                         \
            *a = cur;                                                          \
            split_##_name(treap, (*a)->rightNode, key, &((*a)->rightNode), b); \
            _pullUp(                                                           \
                &((*a)->treeKey),                                              \
                (((*a)->leftNode == nullptr) ? nullptr                         \
                                             : (&((*a)->leftNode->treeKey))),  \
                (((*a)->rightNode == nullptr)                                  \
                     ? nullptr                                                 \
                     : (&((*a)->rightNode->treeKey))));                        \
        } else {                                                               \
            *b = cur;                                                          \
            split_##_name(treap, (*b)->leftNode, key, a, &((*b)->leftNode));   \
            _pullUp(                                                           \
                &((*b)->treeKey),                                              \
                (((*b)->leftNode == nullptr) ? nullptr                         \
                                             : (&((*b)->leftNode->treeKey))),  \
                (((*b)->rightNode == nullptr)                                  \
                     ? nullptr                                                 \
                     : (&((*b)->rightNode->treeKey))));                        \
        }                                                                      \
    }                                                                          \
    void free_node_##_name(node_##_name* nowNode) {                            \
        if (nowNode == nullptr) return;                                        \
        free_node_##_name(nowNode->leftNode);                                  \
        free_node_##_name(nowNode->righttNode);                                \
        free(nowNode);                                                         \
        return;                                                                \
    }                                                                          \
    void free_##_name(struct _name* treap) {                                   \
        free_node_##_name(treap->tree);                                        \
        free(treap);                                                           \
    }                                                                          \
    _name* create_treap_##_name() {                                            \
        srand(time(NULL));                                                     \
        _name* treap = malloc(sizeof(_name));                                  \
        treap->tree = nullptr;                                                 \
        treap->build = &build_##_name;                                         \
        treap->merge = &merge_##_name;                                         \
        treap->split = &split_##_name;                                         \
        return treap;                                                          \
    }
#endif
