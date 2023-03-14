#include <iostream>

using namespace std;

class _10A
{
    const string yearOfGraduation;
    static int numberOfStudents;

public:
    _10A(const string &yearOfGraduation, int numberOfStudents)
        : yearOfGraduation(yearOfGraduation)
    {
        if (numberOfStudents < 1)
        {
            throw invalid_argument("numberOfStudents must be greater than zero");
        }
        _10A::setNumberOfStudents(numberOfStudents);
        _10A::numberOfStudents++;

        // this->yearOfGraduation = yearOfGraduation;
    }
    static int getNumberOfStudents()
    {
        return numberOfStudents;
    }
    static void setNumberOfStudents(int numberOfStudentsValue)
    {
        numberOfStudents = numberOfStudentsValue;
    }
};

int _10A::numberOfStudents = 0;

int main()
{

    cout << _10A::getNumberOfStudents() << endl;
    _10A::setNumberOfStudents(24);
    cout << _10A::getNumberOfStudents() << endl;

    return 0;
}