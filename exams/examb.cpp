#include <iostream>
#include <cstring>

using namespace std;

class TaskList
{
    static int numberOfActiveLists;

protected:
    char *name;
    string *tasks;
    int numberOfTasks;

public:
    TaskList()
    {
        this->name = strdup("");
        tasks = new string[1];
        numberOfTasks = 0;
        numberOfActiveLists++;
    }

    TaskList(const char *name, const string *tasks, int tasksSize)
        : numberOfTasks(tasksSize)
    {
        if (numberOfTasks < 0)
        {
            throw invalid_argument("numberOfTasks must be positive");
        }
        if (!name || !tasks)
        {
            throw invalid_argument("Name and tasks must not be nullptr");
        }
        this->name = strdup(name);
        this->tasks = new string[numberOfTasks];
        for (int i = 0; i < numberOfTasks; i++)
        {
            this->tasks[i] = tasks[i];
        }
        numberOfActiveLists++;
    }

    TaskList(const TaskList &other)
        : numberOfTasks(other.numberOfTasks)
    {
        this->name = strdup(other.name);
        this->tasks = new string[other.numberOfTasks];
        for (int i = 0; i < numberOfTasks; i++)
        {
            this->tasks[i] = other.tasks[i];
        }
        numberOfActiveLists++;
    }

    ~TaskList()
    {
        delete[] name;
        delete[] tasks;
        numberOfActiveLists--;
    }

    TaskList &operator=(const TaskList &other)
    {
        if (this != &other)
        {
            delete[] name;
            delete[] tasks;
            this->name = strdup(other.name);
            this->tasks = new string[other.numberOfTasks];
            for (int i = 0; i < numberOfTasks; i++)
            {
                this->tasks[i] = other.tasks[i];
            }
            numberOfTasks = other.numberOfTasks;
        }
        return *this;
    }

    void printListInformation() const
    {
        cout << this->name << '\n';
        for (int i = 0; i < numberOfTasks; i++)
        {
            cout << this->tasks[i] << '\n';
        }
    }
};

class ShoppingList : public TaskList
{
    string *boughtProducts;
    int numberOfBoughtProducts;

public:
    ShoppingList(const char *name, const string *productsToBuy, int numberOfProductsToBuy, const string *boughtProducts, int numberOfBoughtProducts)
        : TaskList(name, productsToBuy, numberOfProductsToBuy),
          numberOfBoughtProducts(numberOfBoughtProducts)
    {
        if (numberOfBoughtProducts <= 0)
        {
            throw invalid_argument("numberOfBoughtProducts must be positive");
        }
        if (!boughtProducts)
        {
            throw invalid_argument("boughtProducts must not be nullptr");
        }
        boughtProducts = new string[numberOfBoughtProducts];
        for (int i = 0; i < numberOfBoughtProducts; i++)
        {
            this->boughtProducts[i] = boughtProducts[i];
        }
    }

    ShoppingList(const ShoppingList &other)
        : TaskList(other),
          numberOfBoughtProducts(other.numberOfBoughtProducts)
    {
        boughtProducts = new string[numberOfBoughtProducts];
        for (int i = 0; i < numberOfBoughtProducts; i++)
        {
            this->boughtProducts[i] = other.boughtProducts[i];
        }
    }

    ShoppingList &operator=(const ShoppingList &other)
    {
        if (this != &other)
        {
            TaskList::operator=(other);
            delete[] boughtProducts;
            this->boughtProducts = new string[other.numberOfBoughtProducts];
            for (int i = 0; i < numberOfBoughtProducts; i++)
            {
                this->boughtProducts[i] = other.boughtProducts[i];
            }
            this->numberOfBoughtProducts = other.numberOfBoughtProducts;
        }
        return *this;
    }

    ~ShoppingList()
    {
        delete[] boughtProducts;
    }

    void printListInformation() const
    {
        cout << this->name << '\n';
        for (int i = 0; i < this->numberOfTasks; i++)
        {
            cout << tasks[i];
            for (int j = 0; j < this->numberOfBoughtProducts; j++)
            {
                if (boughtProducts[j] == tasks[i])
                {
                    cout << " - bought";
                }
            }
            cout << '\n';
        }
    }
};

// operator++()
// { // i++
//     int res = this->number;
//     this->number += 1;

//     return res;
// }

// operator++(int)
// { // ++i
//     this->number += 1;
//     return this->number;
// }