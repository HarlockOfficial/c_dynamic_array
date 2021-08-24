#include "array.h"
#include <stdlib.h>

#define INCREASE_FACTOR 1.5

void shift_to_right(array *arr, long long start_position);

void shift_to_left(array *arr, long long start_position);

void increase_array(array *arr);

array init_array(long long length) {
    array arr;
    arr.arr = malloc(length * sizeof(void *));
    arr.length = length;
    arr.last_index = 0;
    return arr;
}

void add_last(array *arr, void *obj) {
    if (arr->last_index >= arr->length) {
        increase_array(arr);
    }
    arr->arr[arr->last_index++] = obj;
}

int add_position(array *arr, void *obj, long long position) {
    if (position < 0) {
        return -1;
    }
    if (position > arr->length || position > arr->last_index)
        add_last(arr, obj);
    else if (position < arr->last_index) {
        shift_to_right(arr, position);
        arr->arr[position] = obj;
    }
    return 0;
}

//lazy remove
void* remove_last(array *arr) {
    return arr->arr[--arr->last_index];
}

void* remove_position(array *arr, long long position) {
    if (position > arr->last_index) {
        return NULL;
    }
    void *obj = arr->arr[position];
    shift_to_left(arr, position);
    return obj;
}

long long find(array arr, void *obj){
    for(long long i = 0; i<arr.last_index; ++i){
        if(arr.arr[i]==obj){
            return i;
        }
    }
    return -1;
}

void shift_to_right(array *arr, long long start_position) {
    if (arr->last_index == arr->length) {
        increase_array(arr);
    }
    for (long long i = arr->length - 1; i > start_position; --i) {
        arr->arr[i] = arr->arr[i - 1];
    }
}

void shift_to_left(array *arr, long long start_position) {
    for (long long i = start_position; i < arr->last_index; ++i) {
        arr->arr[i] = arr->arr[i + 1];
    }
    arr->last_index--;
}

void increase_array(array *arr) {
    arr->length = (long long) ((double) arr->length * INCREASE_FACTOR);
    arr->arr = realloc(arr->arr, arr->length * sizeof(void *));
}