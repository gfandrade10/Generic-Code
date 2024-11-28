#include <iostream>
#include <string>

class makeLooper
{
    public:
    makeLooper(const std::string& str)
        : m_str(str), m_it(m_str.begin()) {}

    char operator()()
    {
        if(m_it == m_str.end())
            m_it = m_str.begin();

        return *(m_it++);
    }

    private:
    std::string m_str;
    std::string::const_iterator m_it;
};

int main (int argc, char *argv[]) 
{
    auto test = makeLooper("hello");
    std::cout << test() << "  " << test() << "  " << test() << "\n";
    return 0;
}
