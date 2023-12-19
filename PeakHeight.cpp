#include <string>
#include <vector>
#include <iostream>

int peak_height(const std::vector<std::string>& mountain) 
{
    if (mountain.empty())
        return 0;

    auto Mod = mountain;
    int VecLen = static_cast<int>(mountain.size());    
    int Count = 0;
    int MountainSize = 0;
    int CircuitBreaker = 0;
    bool SizeCheck = true;
    bool MountainFlag = false;
    bool XPass = true;

    while (SizeCheck)
    {
        for(int i = 0; i < VecLen; i++)
        {
            int StrLen = static_cast<int>(mountain[i].size());
            for (int j = 0; j < StrLen; j++)
            {
                if (XPass)
                { 
                    if(Mod[i][j] != ' ')
                    {
                        if(i == 0 || i == VecLen - 1 || j == 0 || j == StrLen - 1)
                        { 
                            Mod[i][j] = 'X'; 
                            Count++;
                            MountainFlag = true;
                        }

                        else if (   Mod[i-1][j] == ' '  ||
                                    Mod[i+1][j] == ' '  ||
                                    Mod[i][j-1] == ' '  ||
                                    Mod[i][j+1] == ' '   )
                        { 
                            Mod[i][j] = 'X'; 
                            Count++;
                            MountainFlag = true;
                        }                 
                    }                                                   
                }
                else
                {
                    if(Mod[i][j] == 'X')
                    {
                        Mod[i][j] = ' ';
                        Count++;
                    }
                }
            }                
        }
        if (Count == 0)
            SizeCheck = false;     
        Count = 0;        
        CircuitBreaker++;
        if(MountainFlag)
        {
            MountainSize++;
            MountainFlag = false;
            XPass = false;
        }
        else
            XPass = true;

        if (CircuitBreaker > 100)
            break;
    }    
    return MountainSize;
}

int main(int argc, char* argv[])
{
    std::vector<std::string> mountain = {
            "^^^^^^        ",
            " ^^^^^^^^     ",
            "  ^^^^^^^     ",
            "  ^^^^^       ",
            "  ^^^^^^^^^^^ ",
            "  ^^^^^^      ",
            "  ^^^^        "
    };

    std::cout << "Mountain Size: " << peak_height(mountain) << "\n\n";
    return 0;
}