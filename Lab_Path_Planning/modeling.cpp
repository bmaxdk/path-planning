#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

/*  
    Define a Map class 5x6
    0 1 0 0 0 0
    0 1 0 0 0 0
    0 1 0 0 0 0
    0 1 0 0 0 0
    0 0 0 1 1 0
    Inside the map class, define the mapWidth, mapHeight and grid as a 2D vector
*/
class Map{
public:
    const static int w = 6;
    const static int h = 5;
    vector<vector<int> grid = {
                                {0, 1, 0, 0, 0, 0},
                                {0, 1, 0, 0, 0, 0},
                                {0, 1, 0, 0, 0, 0},
                                {0, 1, 0, 0, 0, 0},
                                {0, 0, 0, 1, 1, 0}};
};

/* 
    Define a Planner class wheree stat(0,0), goal(4,5), cost =1
    Inside the Planner class, define the start, goal, cost, movements, and movements_arrows
    Note: The goal should be defined it terms of the mapWidth and mapHeight
*/
class Planner : Map {
public:
    int start[2] = {0, 0};
    int goal[2] = {h-1, w-1};
    int cost = 1;
    string movement_arrows[4] = {"^", "<", "v", ">"};
    int movements[4][2] = {{-1, 0}, {0, -1}, {1,0}, {0,1}};
};

/* 
    Define a print2DVector function which will print 2D vectors of any data type
    Example

    Input: 
    vector<vector<int> > a{{ 1, 0 },{ 0, 1 }};
    print2DVector(a);
    vector<vector<string> > b{{ "a", "b" },{ "c", "d" }};
    print2DVector(b);

    Output:
    1 0
    0 1
    a b
    c d
    use templates
*/

/*############ Don't modify the main function############*/
int main()
{
    // Instantiate map and planner objects
    Map map;
    Planner planner;

    // Print classes variables
    cout << "Map:" << endl;
    print2DVector(map.grid);
    cout << "Start: " << planner.start[0] << " , " << planner.start[1] << endl;
    cout << "Goal: " << planner.goal[0] << " , " << planner.goal[1] << endl;
    cout << "Cost: " << planner.cost << endl;
    cout << "Robot Movements: " << planner.movements_arrows[0] << " , " << planner.movements_arrows[1] << " , " << planner.movements_arrows[2] << " , " << planner.movements_arrows[3] << endl;
    cout << "Delta:" << endl;
    print2DVector(planner.movements);

    return 0;
}
