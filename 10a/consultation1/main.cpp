#include <iostream>
#include <cstring>
using namespace std;

class Example
{

    int a;

public:
    Example(const string &a)
    {
        if (a.empty())
        {
            throw invalid_argument("Example");
        }
    }
    Example(const Example &other)
    {
        cout << other.getA() << endl;
    }

    int getA() const
    {
        // this->a = 4;
        return a;
    }
};

struct point_t
{
    int x;
    int y;
};

class Marker
{
    struct point_t coordinates;
    char *name;
    static int markersCount;

protected:
    string provider;

public:
    Marker()
    {
        this->coordinates.x = 0;
        this->coordinates.y = 0;
        this->name = strdup("");
        markersCount++;
    }
    Marker(const struct point_t &coordinates, const char *name)
        : coordinates(coordinates)
    {
        if (!name)
            throw invalid_argument("The name must not be nullptr.");
        this->name = strdup(name);
        markersCount++;
    }
    ~Marker()
    {
        delete[] this->name;
        markersCount--;
    }

    Marker(const Marker &other)
        : coordinates(other.coordinates)
    {
        this->name = strdup(other.name);
        markersCount++;
    }

    Marker &operator=(const Marker &other)
    {
        if (this != &other)
        {
            delete[] this->name;
            this->name = strdup(name);
            this->coordinates = other.coordinates;
        }
        return *this;
    }

    const struct point_t &getCoordinates() const
    {
        return this->coordinates;
    }
    const char *getName() const
    {
        return this->name;
    }
    void printCoordinates() const
    {
        cout << "("
             << this->coordinates.x
             << ","
             << this->coordinates.y
             << ")"
             << endl;
    }
    static int getMarkersCount()
    {
        return markersCount;
    }
};

int Marker::markersCount = 0;

class CarCrash : public Marker
{
    char *cityName;

public:
    CarCrash(const struct point_t &point, const char *name, const string &provider)
        : Marker(point, name)
    {
        this->provider = provider;
        cityName = strdup("Sofia");
    }
    ~CarCrash()
    {
        delete[] cityName;
        // Marker::~Marker(); - called automatically
    }
    void printCoordinates() const
    {
        cout << this->provider << " ";
        Marker::printCoordinates();
    }
};

int main()
{
    try
    {
        struct point_t p = {0, 0};
        Marker m(p, "");

        CarCrash cc(p, "test1", "google");
        cc.printCoordinates();
        cout << cc.getName() << endl;
        cout << m.getMarkersCount() << endl;
        cout << "End of the program!" << endl;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
}