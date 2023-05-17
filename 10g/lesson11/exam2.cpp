#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Bet
{
    string name;
    double coefficient;

public:
    Bet()
    {
        this->name = "";
        this->coefficient = 0.0;
    }
    double getCoefficient() const { return this->coefficient; }
    friend istream &operator>>(istream &in, Bet &bet)
    {
        in >> bet.name >> bet.coefficient;
        if (bet.name.empty())
            throw std::runtime_error("Name must not be empty");
        if (bet.coefficient <= 0)
            throw std::runtime_error("Coefficient must be positive");

        return in;
    }
};

class BettingSlip
{
    int id;
    double amount;
    vector<Bet> bets;

public:
    BettingSlip()
    {
        id = 0;
        amount = 0;
    }
    virtual ~BettingSlip();
    double calculateCoefficient() const
    {
        double res = 1;
        for (const Bet &b : bets)
        {
            res *= b.getCoefficient();
        }
        return res;
    }
    virtual double calculateFee() const = 0;

    double estimateProfitBeforeFee() const
    {
        return calculateCoefficient() * amount;
    }

    double calculateProfit() const
    {
        return estimateProfitBeforeFee() - calculateFee();
    }

    friend istream &operator>>(istream &in, BettingSlip *slip)
    {
        in >> slip->id >> slip->amount;
        // in.seekg(ios::cur + 1);
        string line;
        getline(in, line);
        getline(in, line);
        while (line != "-----------------------")
        {
            stringstream bs(line);
            Bet b;
            bs >> b;
            slip->bets.push_back(b);
            getline(in, line);
        }

        return in;
    }
};

class FootballBettingSlip : public BettingSlip
{
public:
    double calculateFee() const
    {
        return estimateProfitBeforeFee() * 0.1;
    }
};

class F1BettingSlip : public BettingSlip
{
public:
    double calculateFee() const
    {
        return estimateProfitBeforeFee() * 0.15;
    }
};

class User
{
    vector<BettingSlip *> bets;

public:
    User(vector<BettingSlip *> bets)
    {
        this->bets = bets;
    }
    ~User()
    {
        for (BettingSlip *b : bets)
        {
            delete b;
        }
    }

    double calculateTotalProfit() const
    {
        double res = 0;
        for (BettingSlip *b : bets)
        {
            res += b->calculateProfit();
        }
        return res;
    }
};

int main()
{
    vector<BettingSlip *> bets;

    // fstream f("bets.txt", ios::in);
    fstream f;
    f.open("bets.txt", ios::in);

    if (!f.is_open())
    {
        return -1;
    }

    string line;
    BettingSlip *b;

    while (!f.eof())
    {
        getline(f, line);

        if (line == "Football")
        {
            b = new FootballBettingSlip();
        }
        else if (line == "F1")
        {
            b = new F1BettingSlip();
        }
        else
        {
            cout << "Unsupported type " << line << endl;
        }
        f >> b;
        bets.push_back(b);
    }

    User u(bets);

    cout << "Total income " << u.calculateTotalProfit() << " BGN" << endl;

    return 0;
}