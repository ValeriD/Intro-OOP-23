#include <iostream>

using namespace std;

class String
{
    char *data;
    size_t length;

public:
    String(const char *data);

    String(const String &other);

    String &operator=(const String &other);

    ~String();

    const char *getCString() const
    {
        return this->data;
    }

    size_t strlength() const
    {
        return this->length;
    }
};

int main()
{
    String myString("Test message");

    cout << "Expected: Test message, got: " << myString.getCString() << endl;

    String stringFromCopyConstructor(myString);
    cout << "Expected: Test message, got: " << stringFromCopyConstructor.getCString() << endl;

    String string("Test message 2");

    string = myString;
    cout << "Expected: Test message, got: " << string.getCString() << endl;
}