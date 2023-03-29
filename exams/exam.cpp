#include <iostream>
using namespace std;

class Account
{
    // TODO add the fields and complete the methods
    double *deposits;
    int numberOfDeposits;
    double *withdraws;
    int numberOfWithdraws;

    static int numberOfAccounts;

public:
    Account()
    {
        deposits = new double[1];
        withdraws = new double[1];
        numberOfWithdraws = 0;
        numberOfDeposits = 0;
        numberOfAccounts += 1;
    }

    Account(double balance, double *withdraws, size_t numberOfWithdraws, double *deposits, size_t numberOfDeposits)
        : numberOfDeposits(numberOfDeposits), numberOfWithdraws(numberOfWithdraws)
    {
        if (numberOfDeposits < 0)
        {
            throw invalid_argument("numberOfDeposits must be positive");
        }
        if (numberOfWithdraws < 0)
        {
            throw invalid_argument("numberOfWithdraws must be positive");
        }
        if (!withdraws || !deposits)
        {
            throw invalid_argument("withdraws and deposits must not be nullptr");
        }
        this->deposits = new double[numberOfDeposits];
        for (int i = 0; i < numberOfDeposits; i++)
        {
            this->deposits[i] = deposits[i];
        }

        this->withdraws = new double[numberOfWithdraws];
        for (int i = 0; i < numberOfWithdraws; i++)
        {
            this->withdraws[i] = withdraws[i];
        }
        numberOfAccounts += 1;
    }

    ~Account()
    {
        numberOfAccounts -= 1;
        delete[] withdraws;
        delete[] deposits;
    }

    Account(const Account &other)
        : numberOfDeposits(other.numberOfDeposits), numberOfWithdraws(other.numberOfWithdraws)

    {
        numberOfAccounts += 1;
        this->deposits = new double[other.numberOfDeposits];
        for (int i = 0; i < other.numberOfDeposits; i++)
        {
            this->deposits[i] = other.deposits[i];
        }

        this->withdraws = new double[other.numberOfWithdraws];
        for (int i = 0; i < other.numberOfWithdraws; i++)
        {
            this->withdraws[i] = other.withdraws[i];
        }
    }

    Account &operator=(const Account &other)
    {
        if (this != &other)
        {
            delete[] this->deposits;
            delete[] this->withdraws;

            this->deposits = new double[other.numberOfDeposits];
            for (int i = 0; i < other.numberOfDeposits; i++)
            {
                this->deposits[i] = other.deposits[i];
            }

            this->withdraws = new double[other.numberOfWithdraws];
            for (int i = 0; i < other.numberOfWithdraws; i++)
            {
                this->withdraws[i] = other.withdraws[i];
            }
            this->numberOfDeposits = other.numberOfDeposits;
            this->numberOfWithdraws = other.numberOfWithdraws;
        }
        return *this;
    }

    double getBalance() const
    {
        double dep = 0;
        for (int i = 0; i < this->numberOfDeposits; i++)
        {
            dep += this->deposits[i];
        }

        double withdr = 0;
        for (int i = 0; i < this->numberOfWithdraws; i++)
        {
            withdr += this->withdraws[i];
        }
        return dep - withdr;
    }

    void printAccoutnInformation() const
    {
        cout << getBalance() << " "
             << numberOfDeposits << " "
             << numberOfWithdraws << endl;
    }
};

class BankAccount : public Account
{
    string IBAN;
    string accountHolder;

public:
    BankAccount(const string &IBAN, const string &accountHolder)
        : Account(), IBAN(IBAN), accountHolder(accountHolder)
    {
        if (IBAN.empty() || accountHolder.empty())
        {
            throw invalid_argument("empty string");
        }
    }

    BankAccount(const BankAccount &other)
        : Account(other), IBAN(other.IBAN), accountHolder(other.accountHolder)
    {
    }

    BankAccount &operator=(const BankAccount &other)
    {
        if (this != &other)
        {
            Account::operator=(other);
            this->accountHolder = other.accountHolder;
            this->IBAN = other.IBAN;
        }
        return *this;
    }

    void printAccountInformation() const
    {
        cout << IBAN << " "
             << accountHolder << " ";
        Account::printAccoutnInformation();
    }
};