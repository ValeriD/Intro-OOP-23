#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

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
    string path;
    fstream fs;
    unsigned int mode;

    bool exists(const string &path)
    {
        this->fs.open(path, ios::in);
        if (!this->fs.is_open())
        {
            return false;
        }
        this->fs.close();
        return true;
    }

public:
    File(const string &path, unsigned int mode)
        : path(path)
    {
        if (path.empty())
        {
            throw std::invalid_argument("Invalid path!");
        }
        if (mode & 0x08 && !(mode & 0x10))
        {
            if (!exists(path))
            {
                throw std::runtime_error("File " + path + " not found!");
            }
        }
        this->fs.open(path, static_cast<ios_base::openmode>(mode));
    }
    ~File()
    {
        this->fs.close();
    }
    string readLine()
    {
        string line;
        getline(this->fs, line);
        return line;
    }
    vector<string> readFile()
    {
        string line;
        vector<string> lines;
        while (getline(this->fs, line))
        {
            lines.push_back(line);
        }
        return lines;
    }
    void writeLine()
    {
    }
};

class FileManager
{

public:
    FileManager() = delete;
    FileManager(const FileManager &other) = delete;

    static void read(const string &path, Point3D &result)
    {
        File f(path, ios::in);
        string line = f.readLine();
        stringstream ss(line);
        ss >> result;
    }
    static void read(const string &path, vector<Point3D> &result)
    {
        File f(path, ios::in);
        string line = f.readLine();
        stringstream ss(line);
        string point;
        while (getline(ss, point, ';'))
        {
            stringstream ps(point);
            Point3D tmp;
            ps >> tmp;
            result.push_back(tmp);
        }
    }
};

int main()
{
    // File("tmp.txt", ios::in | ios::out);
    Point3D p;
    FileManager::read("tmp.txt", p);
    cout << p << endl;

    vector<Point3D> triangle;
    FileManager::read("triangle.txt", triangle);
    for (Point3D p : triangle)
    {
        cout << p << ";";
    }
    // for (int i = 0; i < triangle.size(); i++)
    // {
    //     Point3D p = triangle[i];
    // }
    cout << endl;

    return 0;
}