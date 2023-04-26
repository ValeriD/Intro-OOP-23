#include <iostream>
#include <sstream>

using namespace std;
// istream     ostream
//       \       /
//        iostream
//            |
//        stringstream

class Point3D
{
    double x, y, z;

public:
    void setX(double x)
    {
        this->x = x;
    }
    void setY(double y)
    {
        this->y = y;
    }
    void setZ(double z)
    {
        this->z = z;
    }
    double getX()
    {
        return this->x;
    }
    double getY() const
    {
        return this->y;
    }
    double getZ() const
    {
        return this->z;
    }
    // friend istream &operator>>(istream &in, Point3D &p)
    // {

    //     in >> p.x >> p.y >> p.z;

    //     return in;
    // }

    friend istream &operator>>(istream &in, Point3D &p)
    {
        //(x,y,z)
        string line;
        getline(in, line);
        stringstream ss(line);
        string x, y, z;
        getline(ss, x, ',');
        getline(ss, y, ',');
        getline(ss, z, ',');
        x.erase(0, 1);
        z = z.substr(0, z.size() - 1);
        stringstream xs(x), ys(y), zs(z);
        xs >> p.x;
        ys >> p.y;
        zs >> p.z;
        return in;
    }

    friend ostream &operator<<(ostream &out, Point3D &p)
    {
        out << "(" << p.x << ", " << p.y << ", " << p.z << ")";
        return out;
    }
};

// istream &operator>>(istream &in, Point3D &p)
// {
//     double x, y, z;
//     in >> x >> y >> z;
//     p.setX(x);
//     p.setY(y);
//     p.setZ(z);

//     return in;
// }

// ostream &operator<<(ostream &out, Point3D &p)
// {
//     out << "(" << p.getX() << ", " << p.getY() << ", " << p.getZ() << ")";
//     return out;
// }

// p1 << cout;

// ostream &operator<<(Point3D &p, ostream &out)
// {
//     out << "(" << p.getX() << ", " << p.getY() << ", " << p.getZ() << ")";
//     return out;
// }
int main()
{
    Point3D p1;
    Point3D p2;
    cin >> p1; // operator>>(cin, p1);
    // cin >> p1 >> p2; // operator>>(operator>>(cin, p1), p2)
    cout << p1 << endl;
    return 0;
}