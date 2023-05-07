#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Dress
{
    // brand -string , color - string, bust - double,  waist - double, hips - double,
public:
    // TODO empty strings and zero values
    Dress();

    // Checks if the dress fits and there should be 5% margin
    bool doesFit(double bust, double hips, double waist);

    friend ostream &operator<<(ostream &out, const Dress &d);

    friend istream operator>>(istream &in, const Dress &d);
};

int main()
{
    vector<Dress> dresses;

    // TODO load all dresses from a file

    cout << "Enter your measurements: "; // - bust, waist, hips
    // TODO load the user's measurements from the console

    // TODO print the dresses that fit the user in the console, and save them in a file
    return 0;
}