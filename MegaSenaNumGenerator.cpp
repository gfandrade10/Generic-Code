#include <exception>
#include <set>
#include <iostream>
#include <random>

#define R_MIN 6
#define R_MAX 15

std::set<int> MyGame (int range)
{
    std::set<int> Game;
    std::random_device rd;
    std::mt19937 seed (rd());
    std::uniform_int_distribution<int> gen {1,60};

    while ((int)Game.size() <= range)
    {
        Game.insert(gen(seed));
    }
    return Game;
}

int main (int argc, char *argv[])
{
    try
    {
        int input = 0;
        std::cout << "Please input a number size between " 
            << R_MIN << " and " << R_MAX << "\nNumber: ";
        std::cin >> input;
        if(input < R_MIN || input > R_MAX)
            throw std::exception();

        std::set<int> game = MyGame(input);
        std::cout << "\n\nSequence: ";
        for(const auto& e: game)
            std::cout << e << "   ";

        std::cout << "\n\n";
    }
    catch(std::exception& e)
    {
        std::cerr << "Error, invalid input\n\n";
        throw std::runtime_error(e.what());
    }
    return 0;
}
