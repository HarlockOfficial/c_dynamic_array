#ifndef C_ARRAY_ARRAY_H
#define C_ARRAY_ARRAY_H

typedef struct array_t {
    void* *arr;
    long long length;
    long long last_index;
} array;

array init_array(long long length);

void add_last(array* arr, void *obj);

int add_position(array* arr, void *obj, long long position);

void *remove_last(array* arr);

void *remove_position(array* arr, long long position);

long long find(array arr, void *obj);

#endif //C_ARRAY_ARRAY_H
