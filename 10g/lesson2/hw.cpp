#include <iostream>

using namespace std;

class Theatre
{
    // Add fields:
    // Number of total tickets to stop and one
    // Number of sold tickets

public:
    /**
     * @brief Construct a new empty Parking object - 0 tickets, 0 taken
     *
     */
    Theatre();

    /**
     * @brief Construct a new Parking object with total tickets and 0 takne
     *
     * @param totalTickets
     */
    Theatre(int totalTickets);

    /**
     * @brief Construct a new Parking object with total tickets and taken tickets
     *
     * @param totaltickets
     * @param soldTickets
     */
    Theatre(int totalTickets, int soldTickets);

    /**
     * @brief Get the total free tickets
     *
     */
    int getTotalAvailableTickets() const;
};

int main()
{
    /*// TODO remove this comment to test the functionalities
    Theatre p1;
    cout << "There should be 0 tickets, and there are: " << p1.getTotalAvailableTickets() << endl;

    Theatre p2(10);
    cout << "There should be 10 tickets, and there are: " << p2.getTotalAvailableTickets() << endl;

    Theatre p3(10, 5);
    cout << "There should be 5 tickets, and there are: " << p2.getTotalAvailableTickets() << endl;
    */
}