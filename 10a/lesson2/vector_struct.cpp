#include <iostream>

// Dark magic
using namespace std;

//============================================================================
// Some of the types in C++:
// -----------------------------------------------------
// size_t === unsigned int
// unsigend int n>=0 (=0,1,2,3,4,5... )
// signed int n <= 0 && n >=0
// short int
// long int
// float vs double (64-bit) double is more precise
// char - the same as in C
// struct - same as in C
// string
//============================================================================

//============================================================================
// Types of writing names:
// -----------------------------------------------------
// Camel case sizeOld
// Kebab case size-old
// Snake case size_old
// Pascal cas SizeOld
//============================================================================

//============================================================================
// Something interesting to checkout:
// -----------------------------------------------------
// RAII (https://medium.com/swlh/what-is-raii-e016d00269f9)
//============================================================================

//============================================================================
// Difference between i++ and ++i
// ----------------------------------------------------------
// int op++(int initial)
// {
//     int res = initial;
//     initial += 1;
//     return res;
// }

// int ++op(int initial)
// {
//     initial += 1;
//     return inital;
// }
//============================================================================

/**
 * @brief Our own implemantation of realloc
 *
 * @param arr the array to be resized
 * @param size_t the new size of the array
 * @return int* the newly created array
 */
int *Realloc(int *arr, int size_t);

/**
 * @brief Our own implementation of malloc
 *
 * @param size the size of the array
 * @return int* the newly created array
 */
int *Malloc(size_t size);

/**
 * @brief Definition of a dynamic array, aka vector
 *
 */
struct vector_t
{
    int *data;
    size_t size;
    size_t capacity;
};

/**
 * @brief Function for creating new object of type vector_t
 *
 * @param size
 * @return struct vector_t*
 */
struct vector_t *init(size_t size);

/**
 * @brief Function for freeing the memory allocated for a vector
 *
 * @param v
 */
void destroy(struct vector_t *v);

/**
 * @brief Function for appending new element to the array
 *
 * @param vector
 * @param v
 * @return struct vector_t*
 */
struct vector_t *add(struct vector_t *vector, int v);

//============================================================================
// HOMEWORK
//============================================================================
/**
 * @brief Create exact clone of a vector
 *
 * @param vector
 * @return struct vector_t*
 */
struct vector_t *clone(struct vector_t *vector);

/**
 * @brief Removes the last element of a vector
 *
 * @param vector
 * @return struct vector_t*
 */
struct vector_t *removeLast(struct vector_t *vector);

/**
 * @brief Retrieves the element at the provided index
 *
 * @param vector
 * @param index
 * @return int
 */
int at(struct vector_t *vector, size_t index);

int main(int argc, char **argv)
{
    return 0;
}

////////////////////////////////////////////////////////////////
// Implementations
////////////////////////////////////////////////////////////////
int *Malloc(size_t size)
{
    int *res = new int[size];
    return res;
}

int *Realloc(int *arr, size_t size)
{
    size_t sizeOld = sizeof(arr) / sizeof(int);
    int *newArr = Malloc(size);

    for (size_t i = 0; i < sizeOld; i++)
    {
        newArr[i] = arr[i];
    }

    delete[] arr;

    return newArr;
};

struct vector_t *init(size_t size)
{
    struct vector_t *res = new struct vector_t;
    res->data = Malloc(size);
    res->size = 0;
    res->capacity = size;

    return res;
}
void destroy(struct vector_t *v)
{
    delete[] v->data;
    delete v;
}

struct vector_t *add(struct vector_t *vector, int v)
{
    if (vector->size == vector->capacity)
    {
        vector->data = Realloc(vector->data, vector->capacity * 2);
        vector->capacity *= 2;
    }
    vector->data[vector->size++] = v;
    return vector;
}