#include <iostream>
#include <cstring>

using namespace std;

//----------------------------------------------------------------
// const char* vs char const *
// https://stackoverflow.com/a/890560
//----------------------------------------------------------------

//----------------------------------------------------------------
// References in C++
// https://www.geeksforgeeks.org/references-in-c/
//----------------------------------------------------------------

enum Color
{
    RED,
    GREEN,
    BLUE

};

class Rock
{
    char *name;
    Color color;
    double size;

public:
    Rock(const char *name, Color color, double size)
        : color(color), size(size)
    {
        this->name = strdup(name); // strcpy(char* dest, char* src);
    }

    ~Rock()
    {
        delete[] this->name;
    }

    Rock(Rock &other)
        : color(other.color), size(other.size)
    {
        this->name = strdup(other.name);
    }

    Rock &operator=(Rock &other)
    {
        if (this != &other)
        {
            this->color = other.color;
            this->size = other.size;

            delete[] this->name;
            this->name = strdup(other.name);
        }
        return *this;
    }
    const char *getName() const { return this->name; }
    double getSize() const;

    void setSize(double size) { this->size = size; }
};

void updateSize(Rock &rock)
{
    rock.setSize(1);
}

int main()
{
    Rock rock1("Ivan", Color::BLUE, 1.49);
    cout << rock1.getName()[0] << endl;

    updateSize(rock1);
    cout << rock1.getSize() << endl;

    Rock rock2 = rock1;

    Rock rock3(rock2);
    cout << "First letter before assign operator " << rock3.getName()[0] << endl;
    rock3 = rock3; // rock3 = rock3.operator=(rock1);
    cout << "First letter after assign operator " << rock3.getName()[0] << endl;
    return 0;
}

double Rock::getSize() const
{
    return this->size;
}