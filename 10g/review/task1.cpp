#include <iostream>

using namespace std;

enum Space
{
    SMALL,
    MEDIUM,
    LARGE
};

class Automobile
{
    string brand;
    Space space;
    string owner;

public:
    Automobile()
        : brand(""), space(Space::SMALL), owner("")
    {
    }

    Automobile(const string &brand, const Space space, const string &owner)
        : owner(owner), space(space), brand(brand)
    {
        if (brand.empty())
        {
            throw std::invalid_argument("Invalid brand provided");
        }
        if (owner.empty())
        {
            throw std::invalid_argument("Invalid owner provided");
        }
    }

    Automobile(const Automobile &other)
        : brand(other.brand), space(other.space), owner(other.owner)
    {
    }

    Automobile &operator=(const Automobile &other)
    {
        if (this != &other)
        {
            this->brand = other.brand;
            this->space = other.space;
            this->owner = other.owner;
        }
        return *this;
    }

    const string &getBrand() const
    {
        return this->brand;
    }
    const string &getOwner() const
    {
        return this->owner;
    }
    const Space getSpace() const
    {
        return this->space;
    }

    void setBrand(const string &brand)
    {
        if (brand.empty())
        {
            throw std::invalid_argument("Invalid brand provided!");
        }
        this->brand = brand;
    }

    void setOwner(const string &owner)
    {
        if (owner.empty())
        {
            throw std::invalid_argument("Invalid owner provided!");
        }
        this->owner = owner;
    }

    void setSpace(const Space space)
    {
        this->space = space;
    }
};