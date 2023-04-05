#include <iostream>

using namespace std;

void handleNameInput()
{
    cout << "Enter your name: ";
    char buffer[256];
    cin >> buffer;
    if (buffer[0] < 'A' || buffer[0] > 'Z')
    {
        // throw invalid_argument("Invalid name");
        handleNameInput();
    }
    else
    {
        cout << "Hello, " << buffer << endl;
    }
}
int main()
{
    string firstName;
    string lastName;
    try
    {
        handleNameInput();
    }
    catch (exception &ex)
    {
        cout << ex.what() << endl;
        handleNameInput();
    }
    // string fullName;
    // while (getline(cin, fullName, ','))
    // {
    //     cout << "\nHello, " << fullName << "!" << endl; // Ivan\n
    // }
    // cin >> firstName >> lastName;

    // cout << "Hello, " << firstName << " " << lastName << endl;
    return 0;
}