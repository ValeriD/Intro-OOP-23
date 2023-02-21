#include <iostream>

using namespace std;

struct vector_t
{
    int *data;
    size_t size;
    size_t capacity;
};

struct vector_t *init()
{
    struct vector_t *vector = new vector_t[1];
    vector->capacity = 2;
    vector->data = new int[vector->capacity];
    vector->size = 0;
    return vector;
}

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

void add(vector_t *vector, int value)
{
    if (vector->size == vector->capacity)
    {
        resize(vector);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

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