/*
Modify the search function to generate and print the expansion 2D vector.
*/

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

// Map class
class Map {
public:
    const static int mapWidth = 6;
    const static int mapHeight = 5;
    vector<vector<int> > grid = {
        { 0, 1, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 1, 0 }
    };
};

// Planner class
class Planner : Map {
public:
    int start[2] = { 0, 0 };
    int goal[2] = { mapHeight - 1, mapWidth - 1 };
    int cost = 1;

    string movements_arrows[4] = { "^", "<", "v", ">" };

    vector<vector<int> > movements{
        { -1, 0 },
        { 0, -1 },
        { 1, 0 },
        { 0, 1 }
    };
};

// Template function to print 2D vectors of any type
template <typename T>
void print2DVector(T Vec)
{
    for (int i = 0; i < Vec.size(); ++i) {
        for (int j = 0; j < Vec[0].size(); ++j) {
            cout << Vec[i][j] << ' ';
        }
        cout << endl;
    }
}

/* #### Modify the search function to generate and print the expansion 2D vector #### */
void search(Map map, Planner planner)
{
    // Inital found where start position to close
    vector<vector<int>> store;
    int r = planner.start[0];
    int c = planner.start[1];
    int g = 0;
    map.grid[r][c] = 0;
    store.push_back({g,r,c});

    while(!store.empty())
    {
        sort(store.begin(), store.end());
        reverse(store.begin(), store.end());
        int curr_g = store.front()[0];
        int curr_r = store.front()[1];
        int curr_c = store.front()[2];
        store.pop_back();
        if (curr_r == planner.goal[0] && curr_c == planner.goal[1])
        {
            cout << "[" << curr_g << ", " << curr_r << ", " << curr_c << "]" << endl;
            break;
        }
        for(int i=0; i<planner.movements.size(); i++)
        {
            int newr =curr_r+planner.movements[i][0];
            int newc = curr_c+planner.movements[i][1];
            if(0<=newr && newr<map.grid.size() && 0<=newc && newc<map.grid[0].size())
            {
                if (newr == 0 && newc ==0) continue;
                else if(newr != 1 && newc != 1 && map.grid[newr][newc] == 1)
                {
                    map.grid[newr][newc] = -1;
                    continue;
                }
                else if (map.grid[newr][newc] == 0)
                {
                    store.push_back({curr_g+1, newr, newc});
                    map.grid[newr][newc] = curr_g+1;
                }
            }

        }
    }
    print2DVector(map.grid);

}

int main()
{
    // Instantiate map and planner objects
    Map map;
    Planner planner;

    // Search for the expansions
    search(map, planner);

    return 0;
}
