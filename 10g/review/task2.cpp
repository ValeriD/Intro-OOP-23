#include "task1.cpp"

using namespace std;

class ParkingLot
{
    string name;
    string address;
    int currentSpace;

    Automobile **automobiles;
    unsigned int capacity;
    unsigned int size;

    void deleteAutomobiles()
    {
        for (size_t i = 0; i < size; i++)
        {
            delete automobiles[i];
        }
        delete[] automobiles;
    }

    void resize()
    {
        this->capacity = capacity * 2;
        Automobile **new_arr = new Automobile *[this->capacity];
        for (size_t i = 0; i < size; i++)
        {
            new_arr[i] = new Automobile(*automobiles[i]);
        }
        // Delete the old automobiles
        deleteAutomobiles();
        // Assign the new array
        this->automobiles = new_arr;
    }
    void shiftLeft(size_t startIndex)
    {
        for (size_t i = startIndex; i < this->size - 1; i++)
        {
            this->automobiles[i] = this->automobiles[i + 1];
        }
    }

public:
    ParkingLot()
        : name(""),
          address(""),
          currentSpace(0),
          capacity(2),
          size(0),
          automobiles(new Automobile *[capacity])
    {
    }

    ~ParkingLot()
    {
        deleteAutomobiles();
    }

    ParkingLot(const ParkingLot &other)
        : name(other.name),
          address(other.address),
          currentSpace(other.currentSpace),
          capacity(other.capacity),
          size(other.size),
          automobiles(new Automobile *[capacity])
    {
        for (size_t i = 0; i < other.size; i++)
        {
            automobiles[i] = new Automobile(*other.automobiles[i]);
        }
    }
    ParkingLot &operator=(const ParkingLot &other)
    {
        if (this != &other)
        {
            this->name = other.name;
            this->address = other.address;
            this->currentSpace = other.currentSpace;
            this->size = other.size;
            this->capacity = other.capacity;

            deleteAutomobiles();
            /*
            You can check this out

            delete this;
            this = new ParkingLot(other);
            */
            this->automobiles = new Automobile *[capacity];
            for (size_t i = 0; i < other.size; i++)
            {
                automobiles[i] = new Automobile(*other.automobiles[i]);
            }
        }
        return *this;
    }

    ParkingLot &addAutomobile(Automobile *other)
    {
        if (this->size == this->capacity)
        {
            resize();
        }
        this->automobiles[size++] = other;

        return *this;
    }

    ParkingLot &removeAutomobile(const string &brand, const string &owner)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (this->automobiles[i]->getBrand() == brand && this->automobiles[i]->getOwner() == owner)
            {
                delete this->automobiles[i];
                shiftLeft(i);
                size--;
                return *this;
            }
        }
        return *this;
    }
};