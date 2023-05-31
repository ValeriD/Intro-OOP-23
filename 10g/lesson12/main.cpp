#include <iostream>
#include <vector>
using namespace std;

class Vector
{
    int x, y;

public:
    Vector()
        : x(0), y(0)
    {
    }
    Vector &operator=(const Vector &other)
    {
        if (this != &other)
        {
            this->x = other.x;
            this->y = other.y;
        }
        return *this;
    }
    int getX() const { return x; }
    int getY() const { return y; }
    Vector &setX(int x)
    {
        this->x = x;
        return *this;
    }
    Vector &setY(int y)
    {
        this->y = y;
        return *this;
    }
    friend istream &operator>>(istream &in, Vector &v)
    {
        in >> v.x >> v.y; // Because of friend keyword

        return in;
    }
};

// istream &operator>>(istream &in, Vector &v)
// {
//     int x, y;
//     in >> x >> y;
//     v.setX(x)
//         .setY(y);

//     return in;
// }

ostream &operator<<(ostream &out, Vector &v)
{
    out << "(" << v.getX() << "," << v.getY() << ")" << endl;

    return out;
}

int main()
{
    cout << "Enter a vector dimensions: ";

    Vector v;           // (0,0)
    Vector v1;          // (0, 0)
    operator>>(cin, v); // v -> (3,2)
    // v = v1;             // v -> (0,0);
    vector<Vector> arr = {v, v1};
    arr.push_back(v);
    arr.push_back(v1);

    for (int i = 0; i < arr.size() - 1; ++i)
    {
        Vector tmp;
        tmp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = tmp;
    }
    cout << arr[0] << arr[1] << arr[2] << arr[3];

    /*
    Vector **arrr = new Vector *[5];
    for (int i = 0; i < 5; i++)
    {
        arrr[i] = new Vector();
    }

    for (int i = 0; i < 5; i++)
    {
        delete arrr[i];
    }
    delete[] arrr;
    */
    return 0;
}