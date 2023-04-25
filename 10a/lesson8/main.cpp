#include <iostream>
#include <sstream>
//----------------------------------------------------------------
// istream  ostream
//     \      /
//     iostream
//         |
//      fstream
//----------------------------------------------------------------
using namespace std;

class Point2D
{
    double x, y;

public:
    double getX() const { return x; }
    double getY() const { return y; }
    void setX(double x)
    {
        this->x = x;
    }
    void setY(double y)
    {
        this->y = y;
    }
    // friend istream &operator>>(istream &in, Point2D &p)
    // {
    //     in >> p.x >> p.y;
    //     return in;
    // }
    friend istream &operator>>(istream &in, Point2D &p)
    {
        string line;
        getline(in, line);
        stringstream ss(line);
        string x, y;
        getline(ss, x, ',');
        getline(ss, y);
        x = x.substr(1);
        y = y.substr(0, y.length() - 1);
        
        stringstream xs(x);
        xs >> p.x;
        stringstream ys(y);
        ys >> p.y;
        return in;
    }
    friend ostream &operator<<(ostream &out, Point2D &p)
    {
        out << "(" << p.x << "," << p.y << ")" << endl;
        return out;
    }
};

// ostream &operator<<(ostream &out, Point2D &p)
// {
//     out << "(" << p.getX() << "," << p.getY() << ")" << endl;
//     return out;
// }

int main()
{
    Point2D p;
    Point2D p2;
    cin >> p; // operator>>(cin, p);
    cout << p;
    // cin >> p2;
    // cin >> p >> p2; // operator>>(operator>>(cin,p), p2);
    return 0;
}