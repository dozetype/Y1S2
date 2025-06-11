#include <iostream>
#include <random> // for std::mt19937

class hello {
public:
    void operator()() {
        std::cout << "hello world\n";
    }
};

int main()
{
    std::mt19937_64 mt{}; // Instantiate a 32-bit Mersenne Twister
    hello niceman;
    niceman.operator()();
    // Print a bunch of random numbers
    for (int count{ 1 }; count <= 42; ++count)
    {
        std::cout << mt() << '\t'; // generate a random number

        // If we've printed 5 numbers, start a new row
        if (count % 5 == 0)
            std::cout << '\n';
    }

    return 0;
}