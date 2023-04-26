#include <iostream>
#include <fstream>

using namespace std;
// ----------------------------------------------------------------
// istream          ostream
//    |                 |
// ifstream         ofstream
//     \                /
//           fstream

int main()
{
    fstream test1;
    test1.open("tmp.txt", ios::in | ios::out | ios::app);
    if (!test1.is_open())
    {
        cerr << "Could not open tmp.tx" << endl;
        return -1;
    }

    if (test1.bad())
    {
        test1.close();
        return -1;
    }
    if (test1.good())
    {
        cout << "All good!" << endl;
    }

    // test1 << "Our second line!" << endl;
    // if (test1.fail())
    // {
    //     test1.close();
    //     cerr << "Failed to write" << endl;
    //     return -1;
    // }
    // 2 coursors one for read and one for write
    // test1.seekp() // p for put and g for get
    test1.seekg(ios::beg); // Accepts how many bytes from the beginning of the file to move
    cout << "Read cursor position " << test1.tellg() << endl;

    string line;
    // test1 >> line; // First word
    int line_num = 0;
    while (!test1.eof())
    {
        cout << test1.tellg() << " ";
        getline(test1, line);
        line_num++;

        cout << line_num << " " << line << endl;
    }
    // test1.tellp();

    test1.close();

    return 0;
}