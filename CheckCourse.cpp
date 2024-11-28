#include <iostream>
#include <string>
#include <utility>
#include <vector>

class seaMapGame
{
    public:
    enum class moveDir { up, down, left, right, nulldir };
    enum class entityType { ship, navy };
    enum class gameResult { win, lose, running };
    struct entity { int x; int y; moveDir lastDir; moveDir nextDir; entityType eType; };
    struct pair { int xcoord; int ycoord; };

    seaMapGame() = delete;
    seaMapGame(std::vector<std::string>&& seaMap);
    ~seaMapGame() { std::cout << "End of the Game\n"; }

    bool gameLoop();
    void printMap();

    private:
    void updateDirection(entity& ent);
    void addPossibleDirections(std::vector<pair>& possibleDirections, const entity& ent);

    std::vector<std::string> m_seaMap;
    int m_xMax;
    int m_yMax;
    std::vector<entity> m_navyShips;
    entity m_myShip;
    gameResult m_currentState;
};

seaMapGame::seaMapGame(std::vector<std::string>&& seaMap) 
    : m_seaMap(std::move(seaMap))
{
    if(m_seaMap.empty() || m_seaMap[0].empty())
    {
        m_currentState = gameResult::lose;
        return;
    }

    m_xMax = m_seaMap[0].length() - 1;
    m_yMax = m_seaMap.size() - 1;

    for(int i = 0; i <= m_yMax; ++i)
    {
        for (int j = 0; j <= m_xMax; ++j)
        {
            if(m_seaMap[i][j] == 'X')
            {
                m_myShip = {j, i, moveDir::nulldir, moveDir::right, entityType::ship};
            }
            else if(m_seaMap[i][j] == 'N')
            {
                moveDir tmp;
                if (j == 0) tmp = moveDir::down;
                else tmp = moveDir::up;
                m_navyShips.push_back({j, i, moveDir::nulldir, tmp, entityType::navy});
            }
        }
    }
    m_currentState = gameResult::running;
}

void seaMapGame::updateDirection(entity& ent)
{
    if (ent.eType == entityType::ship)    
    {
        ent.x++;
    }

    else if (ent.eType == entityType::navy)
    {
        if(ent.y == 0)
        {
            ent.y++;
            ent.nextDir = moveDir::down;
        }
        else if(ent.y == m_yMax)
        {
            ent.y--;
            ent.nextDir = moveDir::up;
        }
        else if(ent.nextDir == moveDir::down)
        {
            ent.y++;
        }
        else if(ent.nextDir == moveDir::up)
        {
            ent.y--;
        }
    }
}

void seaMapGame::addPossibleDirections(std::vector<pair>& possibleDirections, const entity& ent) 
{
    int x = ent.x;
    int y = ent.y;

    // Ensure all possible directions are within bounds
    if (x > 0) possibleDirections.push_back({x - 1, y});                   // Left
    if (y > 0) possibleDirections.push_back({x, y - 1});                   // Up
    if (x < m_xMax) possibleDirections.push_back({x + 1, y});              // Right
    if (y < m_yMax) possibleDirections.push_back({x, y + 1});              // Down
    if (x > 0 && y > 0) possibleDirections.push_back({x - 1, y - 1});      // Top-left
    if (x < m_xMax && y > 0) possibleDirections.push_back({x + 1, y - 1}); // Top-right
    if (x > 0 && y < m_yMax) possibleDirections.push_back({x - 1, y + 1}); // Bottom-left
    if (x < m_xMax && y < m_yMax) possibleDirections.push_back({x + 1, y + 1}); // Bottom-right
}

bool seaMapGame::gameLoop()
{
    std::vector<pair> possibleDirections;

    while(m_myShip.x <= m_xMax)
    {
        printMap();
        
        if(m_currentState == gameResult::lose) return false;
        if(m_currentState == gameResult::win)  return true;

        addPossibleDirections(possibleDirections, m_myShip);

        for(const auto& e: possibleDirections)
        {
            if(m_seaMap.at(e.ycoord).at(e.xcoord) == 'N')
            {
                m_currentState = gameResult::lose;
                return false;
            }
        }

        if(m_myShip.x == m_xMax)
        {
            m_currentState = gameResult::win;
            return true;
        }

        possibleDirections.clear();

        if(m_myShip.x < m_xMax) 
        {
            m_seaMap.at(m_myShip.y).at(m_myShip.x) = '0';
            updateDirection(m_myShip);
            m_seaMap.at(m_myShip.y).at(m_myShip.x) = 'X';
            for(auto& e: m_navyShips)
            {
                m_seaMap.at(e.y).at(e.x) = '0';
                updateDirection(e);
                m_seaMap.at(e.y).at(e.x) = 'N';
            }
        }
    }
    return false;
}

void seaMapGame::printMap()
{
    for(const auto&e :m_seaMap)
        std::cout << e << "\n";
    std::cout << "\n";
}

bool check_course(std::vector<std::string> sea_map)
{
    seaMapGame game (std::move(sea_map));
    return game.gameLoop();
}

int main (int argc, char *argv[]) 
{
    std::vector<std::string> sample1 = { "0000ON", "000000", "X00000", "000000", "000000" };
    bool result = check_course(sample1);
    std::cout << (result ? "TRUE" : "FALSE") << "\n";
    return 0;
}
