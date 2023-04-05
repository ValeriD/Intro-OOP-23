#include <iostream>

using namespace std;
void setA(int a)
{
    if (a < 0)
        throw invalid_argument("In setter");
}

void handleAInput()
{
    try
    {
        int a;
        cin >> a;
        setA(a);
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
        handleAInput();
    }
}
int main()
{
    // string firstName, lastName;
    // cout << "Enter your name: ";
    // cin >> firstName >> lastName;
    // cout << "Enter age: ";
    // double age;
    // cin >> age;
    // cout
    //     << "Hello, " << firstName << " " << lastName << " " << age << endl;

    // char firstName[256], lastName[256];
    // cin >> firstName >> lastName;
    // cout << "Hello, " << firstName << " " << lastName << endl;

    //
    handleAInput();
    return 0;
}