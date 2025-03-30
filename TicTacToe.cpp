#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string displayBoard(const std::vector<char>& board, unsigned short width)
{
    if(board.empty())
        return "";

    std::ostringstream os;
    size_t divisor = static_cast<size_t>(width)*3 + static_cast<size_t>(width) - 1;
    
    std::string strDivisor(divisor+2, '-');
    strDivisor[0] = '\n';
    strDivisor[strDivisor.length() - 1] = '\n';

    size_t counter = 0;
    for(size_t i = 0; i < board.size(); ++i)
    {
        if(board[i] == ' ')
        {
            os << "   ";
            counter++;
        }
        else
        {
            os << " " << board[i] << " ";
            counter++;
        }

        if(counter < static_cast<size_t>(width))
            os << "|";
        
        if(counter == static_cast<size_t>(width) && i != board.size() - 1)
        {
            os << strDivisor;
            counter = 0;
        }
    }

    return os.str();
}

int main()
{
    std::vector<char> input = {'O', 'X', ' ', ' ', 'X', ' ', 'X', 'O', ' ', '0'};
    std::cout << displayBoard(input, 5);
    std::cout << "\n";
}
