#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

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

class File
{
    fstream fs;

public:
    File(const string &filePath, int flags)
    {
        this->fs.open(filePath, flags);
        if (!this->fs.is_open())
        {
            throw std::runtime_error("File " + filePath + "could not be opened!");
        }
    }
    ~File()
    {
        this->fs.close();
    }
    fstream &getFileStream()
    {
        return this->fs;
    }
};

class FileManager
{

public:
    static Point2D readPoint2D(File &f)
    {
        Point2D p;
        f.getFileStream().seekg(ios::beg);
        f.getFileStream() >> p;
        return p;
    }
    static Point3D readPoint3D(File &f)
    {
        Point3D p;
        f.getFileStream().seekg(ios::beg);
        f.getFileStream() >> p;
        return p;
    }
    static vector<Point2D> readTriangle(File &f)
    {
        vector<Point2D> triangle;
        string line;
        getline(f.getFileStream(), line);
        stringstream ss(line);
        string point;
        while (getline(ss, point, ';'))
        {
            stringstream ps(point);
            Point2D p;
            ps >> p;
            triangle.push_back(p);
        }

        return triangle;
    }
};

int main()
{
    File f1("tmp.txt", ios::in | ios::out | ios::app);
    Point2D p = FileManager::readPoint2D(f1);
    cout << p << endl;
    return 0;
}