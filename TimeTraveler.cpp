#include <exception>
#include <iostream>
#include <initializer_list>
#include <stdexcept>

class Date
{
    public:
    Date()
    {
        m_Day = 0; m_Month = 0;
        m_Year = 0; m_TimeSpan = 0;
    }

    Date(const Date& date)
    {
        m_Day = date.m_Day; m_Month = date.m_Month;
        m_Year = date.m_Year; m_TimeSpan = date.m_TimeSpan;        
    }

    Date(Date&& date)
    {
        m_Day = date.m_Day; m_Month = date.m_Month;
        m_Year = date.m_Year; m_TimeSpan = date.m_TimeSpan;        
    }
    
    Date (std::initializer_list<int> ls)
    {
        try
        {
            if(ls.size() == 3)
            {
                m_Day = *ls.begin(); m_Month = *(ls.begin() + 1);
                m_Year = *(ls.begin() + 2); m_TimeSpan = 0;
            }
            else
                throw std::exception();
        }
        catch (std::exception& e)
        {
            std::cerr << "Invalid date format.\n\n";
            throw std::runtime_error(e.what());
        }
    }

    Date (int date, int month, int year)
    {
        m_Day = date; m_Month = month;
        m_Year = year; m_TimeSpan = 0;
    }

    Date& operator= (const Date& date)
    {
        m_Day = date.m_Day; m_Month = date.m_Month;
        m_Year = date.m_Year; m_TimeSpan = date.m_TimeSpan;
        return *this;
    }

    ~Date() = default;

    void SetTimeSpan()
    {
        const int SHIFT_YEAR = 1752;
        bool LeapYear = false;
        m_TimeSpan = 0;

        for(int i = 0; i < m_Year; i++)
        {
            if(i <= SHIFT_YEAR && i%4 == 0)
                m_TimeSpan += 366;
            else if(i > SHIFT_YEAR && i%4 == 0 && i%100 != 0)
                m_TimeSpan += 366;
            else if(i > SHIFT_YEAR && i%4 == 0 && i%400 ==0)
                m_TimeSpan += 366;
            else
                m_TimeSpan += 365;
        }

        if (m_Year > SHIFT_YEAR ||
            (m_Year == SHIFT_YEAR && m_Month > 9) ||
            (m_Year == SHIFT_YEAR && m_Month == 9 && m_Day > 13))
                m_TimeSpan -= 11;
        
        int mon = m_Month - 1;
        if ((m_Year <= SHIFT_YEAR && m_Year%4 == 0) ||
            (m_Year > SHIFT_YEAR && m_Year%4 == 0 && m_Year%100 != 0) ||
            (m_Year > SHIFT_YEAR && m_Year%4 == 0 && m_Year%400 == 0))
                LeapYear = true;

        switch (mon) 
        {
            case 1:  { m_TimeSpan += 31; break; }
            case 2:  { m_TimeSpan += 59; break; }
            case 3:  { m_TimeSpan += 90; break; }
            case 4:  { m_TimeSpan += 120; break; }
            case 5:  { m_TimeSpan += 151; break; }
            case 6:  { m_TimeSpan += 181; break; }
            case 7:  { m_TimeSpan += 212; break; }
            case 8:  { m_TimeSpan += 243; break; }
            case 9:  { m_TimeSpan += 273; break; }
            case 10: { m_TimeSpan += 304; break; }
            case 11: { m_TimeSpan += 334; break; }
            default: break;
        }

        if (LeapYear && m_Month > 2)
            m_TimeSpan++;
        
        m_TimeSpan += m_Day;
    }

    int GetTimeSpan()
    {
        return m_TimeSpan;
    }

    void PrintDate()
    {
        std::cout << "Date " << m_Day << "\\"
            << m_Month << "\\" << m_Year << "\n\n";
    }

    private:
    int m_Day;
    int m_Month;
    int m_Year;
    int m_TimeSpan;
};

int days(int date, int month, int year)
{
    Date current = {24, 3, 2437};
    Date past = {date, month, year};
    current.SetTimeSpan();
    past.SetTimeSpan();
    return current.GetTimeSpan() - past.GetTimeSpan();
}

int main (int argc, char *argv[])
{
    int res = days(24, 3, 1500);
    std::cout << "Answer: " << res << "\n\n";
    return 0;
}
