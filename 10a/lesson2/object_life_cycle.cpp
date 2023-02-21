#include <iostream>

using namespace std;

class Desk
{
    // Fields of the class
    int length;
    int *legs;

public: // Modificator
    /**
     * @brief Default constructor(does not have any parameters). Construct a new Desk object
     *
     */
    Desk()
    {
        cout << "Hello from default constructor" << endl;
        this->legs = new int[1];
    }
    /**
     * @brief Constructor with parameters. Construct a new Desk object
     *
     * @param length
     */
    Desk(int length)
    {
        this->length = length;
        this->legs = new int[this->length / 2];
    }

    /**
     * @brief Destructor. Destroy the Desk object
     *
     */
    ~Desk()
    {
        cout << "Hello from destructor" << endl;
        delete[] legs;
    }

    /**
     * @brief Getter. Get the Length object
     *
     * @return int
     */
    int getLength() const
    {
        return this->length;
    }

    /**
     * @brief Setter. Set the Length object
     *
     * @param length
     */
    void setLength(int length)
    {
        if (length > 0)
        {
            this->length = length;
        }
    }

private:   // Modificator
protected: // When learning about inheritance
};

int main()
{
    Desk d;                  // Default constructor
    Desk *dptr = new Desk(); // Default constructor
    delete dptr;             // Destructor called
    Desk d2(5);              // Constructor with parameters
} // Here are called the destructors of d and d2, because it is the end of the scopeof the function where they have been created
