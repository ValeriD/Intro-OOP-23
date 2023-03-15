#include <iostream>

using namespace std;

double divide(int a, int b)
{
    if (b == 0)
    {
        throw invalid_argument("division of zero");
    }
    return double(a / b);
}

int main()
{
    try
    {
        cout << divide(4, 1) << endl;
        cout << "After div" << endl;
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
    }
    catch (out_of_range &e)
    {
    }
    catch (exception &e)
    {
        
    }

    cout << "After try/catch" << endl;
}