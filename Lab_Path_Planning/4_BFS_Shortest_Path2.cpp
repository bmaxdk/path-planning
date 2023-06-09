// HC
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

/*#### Code the search function which will generate the expansion list ####*/
// Only required to print the final triplet values
void search(Map map, Planner planner)
{
    // Inital found where start position to close
    vector<vector<int>> store;
    int r = planner.start[0];
    int c = planner.start[1];
    int g = 0;
    map.grid[r][c] =1;
    store.push_back({g,r,c});
    vector<vector<int> > expand(map.mapHeight, vector<int>(map.mapWidth, -1));
    int cost = 0;
    expand[0][0] = 0;
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
            if(0<=newr && newr<map.grid.size() && 0<=newc && newc<map.grid[0].size() && map.grid[newr][newc] !=1)
            {
                store.push_back({curr_g+planner.cost, newr, newc});
                map.grid[newr][newc] = 1;
                expand[newr][newc] = ++cost;
            }
        }
    }

    print2DVector(expand);
    vector<vector<string>> path(map.mapHeight, vector<string>(map.mapWidth, "-"));
    int cur_r, cur_c, cur_g;
    cur_r = planner.start[0];
    cur_c = planner.start[1];
    cur_g = expand[cur_r][cur_c];
    while(cur_r != planner.goal[0] or cur_c != planner.goal[1])
    {
        int pos = -1;
        string assign;
        for(int i=0; i<planner.movements.size(); i++)
        {
            int new_r = cur_r + planner.movements[i][0];
            int new_c = cur_c + planner.movements[i][1];
            if (0<= new_r and new_r<expand.size() and 0<=new_c and new_c<expand[0].size())
            {
                int new_g = expand[new_r][new_c];
                if (cur_g < new_g)
                {
                    cur_g = new_g;
                    pos = i;
                }
            }
        }
        assign = planner.movements_arrows[pos];
        path[cur_r][cur_c] = assign;
        cur_r +=  planner.movements[pos][0];
        cur_c +=  planner.movements[pos][1];
     }
    path[planner.goal[0]][planner.goal[1]] = "*";
    print2DVector(path);

}

int main()
{
    // Instantiate map and planner objects
    Map map;
    Planner planner;

    // Search for the expansions
    search(map, planner);
    // print2DVector(map.grid);

    return 0;
}

// Output
// [11, 4, 5]



