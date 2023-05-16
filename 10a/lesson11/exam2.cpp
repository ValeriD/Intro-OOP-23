#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Product
{
    string name;
    double price;

public:
    Product()
    {
        this->name = "";
        this->price = 0.0;
    }

    double getPrice() const
    {
        return this->price;
    }

    friend istream &operator>>(istream &in, Product &p)
    {
        in >> p.name >> p.price;
        if (p.name.empty())
        {
            throw std::runtime_error("Product name must not be empty");
        }
        if (p.price <= 0)
        {
            throw std::runtime_error("Product price must be positive");
        }
        return in;
    }
};

class Order
{
    unsigned int table;
    double payedAmount;
    vector<Product> orders;

protected:
    double calculateOrderTotal() const
    {
        double result = 0.0;

        for (const Product &p : this->orders)
        {
            result += p.getPrice();
        }

        // for (int i = 0; i < orders.size(); i++)
        // {
        //     Product p = orders[i];
        //     result += p.getPrice();
        // }

        return result;
    }

public:
    Order()
    {
        this->table = 0;
        this->payedAmount = 0.0;
    }
    virtual ~Order() {}
    double calculateTips() const
    {
        return this->payedAmount - this->calculateOrderTotal();
    }

    virtual double calculateSalary() const = 0;

    double calculateTotalIncome() const
    {
        return this->payedAmount - calculateSalary() - calculateTips();
        // return calculateOrderTotal() - calculateSalary();
    }

    friend istream &operator>>(istream &in, Order *order)
    {
        in >> order->table >> order->payedAmount;
        if (order->table == 0)
            throw std::runtime_error("Table id must be non-zero");
        if (order->payedAmount <= 0)
            throw std::runtime_error("Invalid amount provided");

        string line;
        getline(in, line);
        getline(in, line);
        while (line != "-----------------------")
        {
            stringstream ps(line);
            Product p;
            ps >> p;
            order->orders.push_back(p);
            getline(in, line);
        }
        if (order->orders.size() == 0)
            throw std::runtime_error("Invalid order provided");
        return in;
    }
};

class KitchenOrder : public Order
{
public:
    double calculateSalary() const
    {
        return calculateOrderTotal() * 0.15;
    }
};

class BarOrder : public Order
{
public:
    double calculateSalary() const
    {
        return calculateOrderTotal() * 0.075;
    }
};

class Manager
{
    vector<Order *> orders;

public:
    Manager(vector<Order *> orders)
    {
        this->orders = orders;
    }
    ~Manager()
    {
        for (Order *o : orders)
        {
            delete o;
        }
    }
    double calculateIncome() const
    {
        double res = 0;
        for (const Order *o : orders)
        {
            res += o->calculateTotalIncome();
        }
        return res;
    }
};
int main()
{
    vector<Order *> orders;
    fstream f;
    f.open("orders.txt", ios::in);
    if (!f.is_open())
        throw runtime_error("File not opened!");

    Order *o;
    string type;

    while (!f.eof())
    {
        getline(f, type);
        if (type == "Kitchen")
        {
            o = new KitchenOrder();
        }
        else
        {
            o = new BarOrder();
        }
        f >> o;
        orders.push_back(o);
    }
    Manager m(orders);
    cout << "Total income: " << m.calculateIncome() << " BGN" << endl;
    return 0;
}