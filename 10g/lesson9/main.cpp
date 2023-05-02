#include <iostream>
#include <fstream>

using namespace std;

//    istream      ostream
//       |            |
//    ifstream     ofstream
//        \           /
//           fstream

int main()
{
    fstream fs;
    fs.open("tmp.txt", ios::in | ios::out | ios::ate);
    if (!fs.is_open())
    {
        cout << "Error: Cannot open file!" << endl;
        return -1;
    }
    else
    {
        cout << "File opened successfully!" << endl;
    }
    cout << "Current write position: " << fs.tellp() << endl;
    for (int i = 4; i < 5; i++)
    {
        fs.seekp(ios::beg);
        cout << "Current write position: " << fs.tellp() << endl;

        fs << "Line: " << i << endl;
        cout << "Current write position: " << fs.tellp() << endl;

        if (fs.fail())
        {
            cout << "Error: Write in file failed!" << endl;
            fs.close();
            return -1;
        }
        if (fs.good())
        {
            cout << "All good!" << endl;
        }
    }
    // seekg(); // seek get - cursor for reading
    // seekp(); // seek put - cursor for writing
    fs.seekg(ios::beg);
    string line;
    while (!fs.eof())
    {
        // tellg() // tell get - get the position of the cursor for reading
        // tellp() // tell put - get the position of the cursor for writing
        cout << fs.tellg() << " ";
        getline(fs, line);

        cout << line << endl;
    }

    fs.close();
    return 0;
}