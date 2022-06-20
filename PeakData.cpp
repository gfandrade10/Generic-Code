#include <vector>
#include <iostream>

typedef struct {
    std::vector<int> pos, peaks;
} PeakData;

PeakData pick_peaks(const std::vector<int> &v) 
{
    PeakData result;
    bool plateauFinder = false;
    int ps;
    for(std::size_t i = 1; i < v.size()-1; ++i)
    {
        if (v[i] > v[i-1] && v[i] > v[i+1])
        {
            result.pos.push_back(i);
            result.peaks.push_back(v[i]);
            if (plateauFinder) plateauFinder = false;
        }
        else if(v[i] > v[i-1] && v[i] == v[i+1])
        {
            plateauFinder = true;
            ps = i;
        }
        else if(plateauFinder && v[i] > v[i+1])
        {
            plateauFinder = false;
            result.pos.push_back(ps);
            result.peaks.push_back(v[i]);
        }
    }
    return result;
}

int main(int argc, char *argv[])
{
    PeakData val = pick_peaks({3, 2, 3, 6, 4, 1, 2, 3, 2, 1, 2, 2, 2, 1});
    for(std::size_t i = 0; i < val.pos.size(); i++)
        std::cout << val.pos[i] << "\t" << val.peaks[i] << "\n";
    std::cout << std::endl;
    return 0;
}