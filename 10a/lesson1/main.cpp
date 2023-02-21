#include <iostream>

using namespace std;

struct temp_t
{
    int a;
};


int main()
{
    printf(""); // std::cout
    std::cout << "Hello World!"
              << "\n"
              << "!!" << std::endl;
    int a;
    float x;
    char c;
    double d;

    // malloc/calloc

    char *str = new char[100];
    struct temp_t *a = new temp_t();

    delete a;
    delete[] str;

    cin >> a;
    cout << (a + 1) << endl;
    return 0;
}