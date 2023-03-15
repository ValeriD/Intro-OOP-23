#include <iostream>
#include <cstring>

using namespace std;

class TUES
{
    const string director;
    static int buildings;

public:
    TUES(const string director)
        : director(director)
    {
        buildings++;
        // this->director = director;
    }

    ~TUES()
    {
        buildings--;
    }
    static int getBuildings()
    {
        return buildings;
    }
};

int TUES::buildings = 0;

int main()
{
    TUES t1("Stela");
    cout << TUES::getBuildings() << endl;

    TUES t2("Stela");
    cout << TUES::getBuildings() << endl;
}