#include <cctype>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

class Bundesliga
{
    //name, matches, wins, defeats, ties, goals made/suffered, points
    using score_tuple = std::tuple<std::string, int, int, int, int, int, int, int>;

    public:
    std::string table(std::vector<std::string> results)
    {
        serialize_data(std::move(results));
        std::ostringstream os;

        for(int i = 0; i < (int)m_score_table.size(); i++)
            os << print_tuple(m_score_table[i], team_positions[i]) << "\n";

        auto return_string = os.str();
        return_string.pop_back();
        return return_string;
    }

    void serialize_data(std::vector<std::string>&& results)
    {
        for(const auto& it: results)
        {
            int first_results = 0, second_results = 0;
            int points_t1 = 0, points_t2 = 0;
            std::string buffer = it;
            char team_1[50], team_2[50];
            bool no_match = false;

            if(it[0] == '-')
            {
                no_match = true;
                buffer[0] = '0';
                buffer[2] = '0';
            }

            const char* c_array = buffer.c_str();
            std::sscanf(c_array, "%d:%d %[^-] - %[^-]", &first_results, &second_results, team_1, team_2);

            std::string first_team = std::string(team_1);
            std::string second_team = std::string(team_2);

            if(!no_match)
            {
                if(first_results > second_results)
                    points_t1 = 3;
                else if (second_results > first_results)
                    points_t2 = 3;
                else if (first_results == second_results)
                {
                    points_t1 = 1;
                    points_t2 = 1;
                }
            }
            else {points_t1 = 0; points_t2 = 0;}

            auto find_score = [&](std::string str) ->std::vector<score_tuple>::iterator{
                for(auto m_ptr = m_score_table.begin(); m_ptr != m_score_table.end(); m_ptr++)
                {
                    if(std::get<0>(*m_ptr) == str)
                        return m_ptr;
                }
                return m_score_table.end();
            };

            auto score_writer = [&](std::vector<score_tuple>::iterator m_ptr, bool team) ->void
            {
                if(m_ptr == m_score_table.end())
                {
                    if(team) {
                        m_score_table.push_back(std::make_tuple(first_team, 
                        no_match ? 0 : 1, 
                        no_match ? 0 : (points_t1 == 3 ? 1 : 0),
                        no_match ? 0 : (points_t1 == 1 ? 1 : 0), 
                        no_match ? 0 : (points_t1 == 0 ? 1 : 0),
                        first_results, second_results, points_t1)); }
                    else {
                        m_score_table.push_back(std::make_tuple(second_team, 
                        no_match ? 0 : 1, 
                        no_match ? 0 : (points_t2 == 3 ? 1 : 0),
                        no_match ? 0 : (points_t2 == 1 ? 1 : 0), 
                        no_match ? 0 : (points_t2 == 0 ? 1 : 0),
                        second_results, first_results, points_t2)); }
                }
                else 
                {
                    if(!no_match)
                        std::get<1>(*m_ptr)++;
                    if(team)
                    {
                        if(points_t1 == 3) std::get<2>(*m_ptr)++;
                        if(points_t1 == 0) std::get<3>(*m_ptr)++;
                        if(points_t1 == 1) std::get<4>(*m_ptr)++;
                    }
                    else
                    {
                        if(points_t2 == 3) std::get<2>(*m_ptr)++;
                        if(points_t2 == 0) std::get<3>(*m_ptr)++;
                        if(points_t2 == 1) std::get<4>(*m_ptr)++;
                    }
                    std::get<5>(*m_ptr) += team ? first_results : second_results;
                    std::get<6>(*m_ptr) += team ? second_results : first_results;
                    std::get<7>(*m_ptr) += team ? points_t1 : points_t2;
                }
            };

            bool flag_t1 = 1, flag_t2 = 0;
            score_writer(find_score(first_team), flag_t1);
            score_writer(find_score(second_team), flag_t2);
        }

        auto sorting_rules = [](score_tuple& sc1, score_tuple& sc2) ->bool
        {
            if(std::get<7>(sc2) != std::get<7>(sc1))
                return std::get<7>(sc2) < std::get<7>(sc1);
            else if(std::get<7>(sc2) == std::get<7>(sc1))
            {
                if(std::get<5>(sc2) - std::get<6>(sc2) != std::get<5>(sc1) - std::get<6>(sc1))
                    return std::get<5>(sc2) - std::get<6>(sc2) < std::get<5>(sc1) - std::get<6>(sc1);
                else if(std::get<5>(sc2) - std::get<6>(sc2) == std::get<5>(sc1) - std::get<6>(sc1))
                {
                    if(std::get<5>(sc2) != std::get<5>(sc1))
                        return std::get<5>(sc2) < std::get<5>(sc1);
                }
            }
            auto s1 = std::get<0>(sc1);
            auto s2 = std::get<0>(sc2);
            std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower); 
            std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
            if(s1[0] == '1') return true;
            if(s2[0] == '1') return false;
            return s2 > s1;
        };
        std::sort(m_score_table.begin(), m_score_table.end(), sorting_rules);

        auto check = [](score_tuple t1, score_tuple t2) ->bool
        { 
            if(std::get<5>(t1) == std::get<5>(t2) && std::get<6>(t1) == std::get<6>(t2) && std::get<7>(t1) == std::get<7>(t2))
                return true;
            else
                 return false;
        };
        
        int pos = 1;
        for(int i = 0; i < (int)m_score_table.size(); i++)
        {
            if (i == 0)
                team_positions.push_back(pos);
            else
            {
                if(check(m_score_table[i-1], m_score_table[i]))
                    team_positions.push_back(pos);
                else
                {
                    pos = i+1;
                    team_positions.push_back(pos);
                }
            }
        }
    }

    std::string print_tuple(const score_tuple& tp, int pos)
    {
        std::string initial_offset = "";
        int str_width = std::to_string((int)m_score_table.size()).length();
        int diff = str_width - std::to_string(pos).length();

        if(diff > 0)
            initial_offset = std::string(diff, ' ');

        auto tmp = initial_offset + std::to_string(pos) + ". " + std::get<0>(tp);

        std::ostringstream os;
        os << tmp << std::string(30 - tmp.length() + str_width + 2, ' ');
        os << std::get<1>(tp) << "  ";
        os << std::get<2>(tp) << "  ";
        os << std::get<3>(tp) << "  ";
        os << std::get<4>(tp) << "  ";
        os << std::get<5>(tp) << ":" << std::get<6>(tp) << "  ";
        os << std::get<7>(tp);
        return os.str();
    }

    private:
    std::vector<score_tuple> m_score_table;
    std::vector<int> team_positions;
};

int main()
{
    std::cout << "\n";
    std::vector<std::string> results =
    {
        "6:0 FC Bayern Muenchen - Werder Bremen",
        "-:- Eintracht Frankfurt - Schalke 04",
        "-:- FC Augsburg - VfL Wolfsburg",
        "-:- Hamburger SV - FC Ingolstadt",
        "-:- 1. FC Koeln - SV Darmstadt",
        "-:- Borussia Dortmund - FSV Mainz 05",
        "-:- Borussia Moenchengladbach - Bayer Leverkusen",
        "-:- Hertha BSC Berlin - SC Freiburg",
        "-:- TSG 1899 Hoffenheim - RasenBall Leipzig"
    };

    Bundesliga obj;
    std::string res = obj.table(results);
    std::cout << res << "\n\n";
}
