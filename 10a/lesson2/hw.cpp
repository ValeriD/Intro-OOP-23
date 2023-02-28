#include <iostream>

using namespace std;

class Parking
{
    // Add fields:
    // Number of total spots to stop and one
    // Number of taken spots

public:
    /**
     * @brief Construct a new empty Parking object - 0 spots, 0 taken
     *
     */
    Parking();

    /**
     * @brief Construct a new Parking object with total spots and 0 takne
     *
     * @param totalSpots
     */
    Parking(int totalSpots);

    /**
     * @brief Construct a new Parking object with total spots and taken spots
     *
     * @param totalSpots
     * @param takenSpots
     */
    Parking(int totalSpots, int takenSpots);

    /**
     * @brief Takes one spot
     *
     */
    void takeSpot();

    /**
     * @brief Frees one spot
     *
     */
    void freeSpot();

    /**
     * @brief Get the total free spots in the parking lot
     *
     */
    int getTotalFreeSpots() const;
};

int main()
{
    /* TODO remove this comment to test the functionalities
    Parking p1;
    cout << "There should be 0 spots, and there are: " << p1.getTotalFreeSpots() << endl;

    Parking p2(10);
    cout << "There should be 10 spots, and there are: " << p2.getTotalFreeSpots() << endl;

    Parking p3(10, 5);
    cout << "There should be 5 spots, and there are: " << p2.getTotalFreeSpots() << endl;

    p1.freeSpot();
    cout << "There should be 0 spots, and there are: " << p1.getTotalFreeSpots() << endl;

    p1.getSpot();
    cout << "There should be 0 spots, and there are: " << p1.getTotalFreeSpots() << endl;

    p2.getSpot()
    cout << "There should be 9 spots, and there are: " << p2.getTotalFreeSpots() << endl;

    p3.freeSpot()
    cout << "There should be 6 spots, and there are: " << p3.getTotalFreeSpots() << endl;


    */
}