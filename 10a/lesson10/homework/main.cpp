#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Dress
{
    string brand;
    string colour;
    double bust, hips, waist;
    bool checkFivePercent(double n1, double n2) const
    {
        return n2 >= n1 * 0.95 && n2 <= n1 * 1.05;
    }

public:
    Dress()
    {
        brand = "";
        colour = "";
        bust = 0;
        hips = 0;
        waist = 0;
    }

    // Checks if the dress fits and there should be 5% margin
    bool doesFit(double bust, double waist, double hips) const
    {
        return checkFivePercent(this->bust, bust) &&
               checkFivePercent(this->hips, hips) &&
               checkFivePercent(this->waist, waist);
    }

    friend ostream &operator<<(ostream &out, const Dress &d)
    {
        out << d.brand << "\n"
            << d.colour << "\n"
            << d.bust << " " << d.hips << " " << d.waist << endl;
        return out;
    }

    friend istream &operator>>(istream &in, Dress &d)
    {
        getline(in, d.brand);
        getline(in, d.colour);

        string measurements;
        getline(in, measurements);
        stringstream measurementsStream(measurements);

        measurementsStream >> d.bust >> d.hips >> d.waist;
        return in;
    }
};

int main()
{
    vector<Dress> dresses;

    fstream f;
    f.open("dresses.txt", ios::in);
    if (!f.is_open())
    {
        cout << "Error: Could not open file dresses.txt!" << endl;
        return -1;
    }

    while (!f.eof())
    {
        Dress d;
        f >> d;
        dresses.push_back(d);
    }
    f.close();

    cout << "Enter your measurements: "; // - bust, waist, hips
    string measurements;
    getline(cin, measurements);
    stringstream measurementsStream(measurements);
    double bust, waist, hips;
    measurementsStream >> bust >> hips >> waist;

    f.open("matches.txt", ios::out | ios::trunc);
    if (!f.is_open())
    {
        cout << "Error: Could not open file matches.txt!" << endl;
        return -1;
    }

    for (const Dress &d : dresses)
    {
        if (d.doesFit(bust, waist, hips))
        {
            f << d;
            cout << d;
        }
    }

    f.close();

    return 0;
}