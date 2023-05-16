#pragma once

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
    Product();

    double getPrice() const;

    friend istream &operator>>(istream &in, Product &p);
};

class Order
{
    unsigned int table;
    double payedAmount;
    vector<Product> orders;

public:
    Order();
    virtual ~Order() {}
    double calculateTips() const;

    virtual double calculateSalary() const = 0;

    double calculateTotalIncome() const;

    friend istream &operator>>(istream &in, Order *order);
};

class KitchenOrder : public Order
{
public:
    double calculateSalary() const;
};

class BarOrder : public Order
{

public:
    double calculateSalary() const;
};

class Manager
{
    vector<Order *> orders;

public:
    Manager(vector<Order *> orders);
    ~Manager();
    double calculateIncome();
};