#include <iostream>

using namespace std;

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
struct vector_t *init()
{
    struct vector_t *vector = new vector_t;
    vector->capacity = 2;
    vector->data = new int[vector->capacity];
    vector->size = 0;
    return vector;
}

/**
 * @brief Function for freeing the memory allocated for a vector
 *
 * @param v
 */
void deleteVector(vector_t *vector)
{
    // for (size_t i = 0; i < vector->capacity; i++)
    // {
    //     delete vector->data[i];
    // }
    delete[] vector->data;
    delete vector;
}

/**
 * @brief Resizes the vector with double the current capacity
 *
 * @param vector
 */
void resize(vector_t *vector)
{
    int *newArray = new int[vector->capacity * 2];
    for (int i = 0; i < vector->size; i++)
    {
        newArray[i] = vector->data[i];
    }
    delete[] vector->data;
    vector->data = newArray;
}

/**
 * @brief Function for appending new element to the array
 *
 * @param vector
 * @param v
 */
void add(vector_t *vector, int value)
{
    if (vector->size == vector->capacity)
    {
        resize(vector);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

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

int main()
{
    printf("Hello, world!\n");
    int a = 1;
    cout << "Hello, world!\n"
         << a << endl;
    cin >> a;
    // int, float, char, bool - c
    // int, double, float, char, string, bool, signed, unsigned, short, long
    char *str = new char[100];
    struct vector_t *vector = init();
    return 0;
}