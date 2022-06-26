#include <iostream>
#include <vector>

template<typename Arg>
constexpr void print_stuff() {  }

template<typename Arg>
constexpr void print_stuff(Arg&& input) 
{ 
    std::cout << input << "\n"; 
}

template<typename ...Args>
constexpr void UltimatePrinter(Args&&... args)
{ 
    std::size_t count = 0;
    int exp[] = {0, ((void)print_stuff(std::forward<Args>(args)),0)...};
}

int main(int argc, char **argv)
{
    UltimatePrinter("hello friend", 50, 4.25, 'c');
    std::cout << std::endl;
    return 0;
}