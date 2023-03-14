#include <iostream>
#include <cstring>

using namespace std;

size_t StrLen(char *str)
{
    size_t len = 0;
    while (*str)
    {
        len++;
        str++;
    }
    return len;
}

char *StrDup(const char *str)
{
    if (str == nullptr) // !str
    {
        throw invalid_argument("StrDup accepts non null arguments");
    }
    size_t len = strlen(str);
    char *result = new char[len];
    for (size_t i = 0; i < len; i++)
    {
        result[i] = str[i]; // *(result + i) = *(str +i)
    }
    return result;
}

int main()
{
    try
    {
        StrDup(nullptr);
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
    cout << "After duplicate" << endl;
    return 0;
}