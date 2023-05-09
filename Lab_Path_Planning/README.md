# Path Planning Lab
The purpose of this lab is to find the shortest path for a robot moving inside a 5x6 map from start to goal position using different path planning algorithms. The robot can only move in four directions: up, left, down, and right. 

## Modeling
***Grid(5x6)***
```text
0 1 0 0 0 0
0 1 0 0 0 0
0 1 0 0 0 0
0 1 0 0 0 0
0 0 0 1 1 0
```
Where 1's represent obstacles and 0's represent free space.

***Robot Start position***: 0,0

***Robot Goal Position***: 4,5
```text
s 1 0 0 0 0
0 1 0 0 0 0
0 1 0 0 0 0
0 1 0 0 g 0
0 0 0 1 1 0
```
***Direction of Movement***: 
* Up(-1,0) 
* Left(0,-1) 
* Down(1,0) 
* Right(0,1)

***Movement Arrows***: 
* Up(^) 
* Left(<) 
* Down(v) 
* Right(>)
The Direction of Movement vector is a collection of four different 2D vectors each of which enables you to move between grid cells in the map.

***Cost of Movement***: 1

The Cost of Movement value indicates how much it cost to move from one cell to another.

[1_modeling.cpp](https://github.com/bmaxdk/path-planning/blob/main/Lab_Path_Planning/1_modeling.cpp)

## BFS: Expansion List
In BFS algorithm, it will expand the cells with the lowest cost until the goal is reached. triplet value **[g, r, c]** where *g* represents the total cost of expanding toward this cell, *r* is the row value, and *c* is the column value. Function should print the final triplet value of the goal once it expands towards it.

Multiple things to keep in mind while coding the search function
* As you expand towards a new cell, check if you have reached the goal; and once you reach it, print its triplet value.
* Actively check if you have reached a roadblock. If you do, stop expanding and print a message indicating that you have failed to reach the goal.
* Expand the cells with the lowest g value and store your expansions in an open vector. If two cells have equal g values, then you can to pick one of them to expand further.

Ex.

```text
Expansion #: 0
Open List: [0 0 0 ]
Cell Picked: [0 0 0]

Expansion #: 1
Open List: [1 1 0 ]
Cell Picked: [1 1 0]

Expansion #: 2
Open List: [2 2 0 ]
Cell Picked: [2 2 0]

Expansion #: 3
Open List: [3 3 0 ]
Cell Picked: [3 3 0]

Expansion #: 4
Open List: [4 4 0 ]
Cell Picked: [4 4 0]

Expansion #: 5
Open List: [5 4 1 ]
Cell Picked: [5 4 1]

Expansion #: 6
Open List: [6 4 2 ]
Cell Picked: [6 4 2]

Expansion #: 7
Open List: [7 3 2 ]
Cell Picked: [7 3 2]

Expansion #: 8
Open List: [8 3 3 ], [8 2 2 ]
Cell Picked: [8 2 2]

Expansion #: 9
Open List: [9 2 3 ], [9 1 2 ], [8 3 3 ]
Cell Picked: [8 3 3]

Expansion #: 10
Open List: [9 3 4 ], [9 2 3 ], [9 1 2 ]
Cell Picked: [9 1 2]

Expansion #: 11
Open List: [10 1 3 ], [10 0 2 ], [9 3 4 ], [9 2 3 ]
Cell Picked: [9 2 3]

Expansion #: 12
Open List: [10 2 4 ], [10 1 3 ], [10 0 2 ], [9 3 4 ]
Cell Picked: [9 3 4]

Expansion #: 13
Open List: [10 3 5 ], [10 2 4 ], [10 1 3 ], [10 0 2 ]
Cell Picked: [10 0 2]

Expansion #: 14
Open List: [11 0 3 ], [10 3 5 ], [10 2 4 ], [10 1 3 ]
Cell Picked: [10 1 3]

Expansion #: 15
Open List: [11 1 4 ], [11 0 3 ], [10 3 5 ], [10 2 4 ]
Cell Picked: [10 2 4]

Expansion #: 16
Open List: [11 2 5 ], [11 1 4 ], [11 0 3 ], [10 3 5 ]
Cell Picked: [10 3 5]

Expansion #: 17
Open List: [11 4 5 ], [11 2 5 ], [11 1 4 ], [11 0 3 ]
Cell Picked: [11 0 3]

Expansion #: 18
Open List: [12 0 4 ], [11 4 5 ], [11 2 5 ], [11 1 4 ]
Cell Picked: [11 1 4]

Expansion #: 19
Open List: [12 1 5 ], [12 0 4 ], [11 4 5 ], [11 2 5 ]
Cell Picked: [11 2 5]

Expansion #: 20
Open List: [12 1 5 ], [12 0 4 ], [11 4 5 ]
Cell Picked: [11 4 5]

```
[2_BFS_Expansion_List](https://github.com/bmaxdk/path-planning/blob/main/Lab_Path_Planning/2_BFS_Expansion_List.cpp) 

## BFS Expansion List
Previously, have expanded the cells until it reached the goal. Now, print the order in which each cell was expanded. To do so, it need to modify the `search function` and create a 2D expansion vector that is equal in size to the map. Each cell in the expansion vector will store the order at which it was expanded. Some of the cells were never expanded, and should show a value of -1.

Take a look at the expansion list generated after running the code:
```text
0 -1 13 17 -1 -1
1 -1 10 14 18 -1
2 -1  8 11 15 19
3 -1  7  9 12 16
4  5  6 -1 -1 20
```
You can see that we started with the first cell and ended at the goal cell which was expanded after 20 iterations. All the obstacles and some cells were never expanded and thus are showing a value of -1.

[BFS Expansion List](https://github.com/bmaxdk/path-planning/blob/main/Lab_Path_Planning/3_BFS_Expansion_Vector2.cpp)

## BFS: Shortest Path
The final step is to print the shortest path that the robot has to take in order to travel from start to goal. You will need to record each action that the robot should take(ex: turning left <) and store all the actions in a policy 2D vector.

```text
v - - - - - 
v - - - - - 
v - - - - - 
v - > > > v 
> > ^ - - * 
```
[Shortest Path](https://github.com/bmaxdk/path-planning/blob/main/Lab_Path_Planning/4_BFS_Shortest_Path3.cpp)

## A*: Shortest Path
Implement the A* algorithm and find the shortest path. A* is based on a heuristic function. Thus, we will implement a Manhattan-based heuristic vector and compute the Manhattan distance of each cell with respect to the goal position where:

$x_{d} = x_{goal} - x_{cell position}$

$y_{d} = y_{goal} - y_{cell position}$

**Manhattan distance (L1 norm)** d = $∣x_{d}∣+∣y_{d}∣$

By computing the Manhattan distance of each cell, we'll obtain this heuristic vector, **Manhattan Heuristic Vector**:
```txt
9 8 7 6 5 4
8 7 6 5 4 3
7 6 5 4 3 2
6 5 4 3 2 1
5 4 3 2 1 0
```
Other heuristic-based vectors such as the **Euclidean distance (L2 norm)**  or the **Chebyshev distance (Norm p or L-infinity norm)** where:

Euclidean distance d = $sqrt(x_{d}^2 + y_{d}^2)$

**Euclidean Heuristic Vector**
```txt
6 5 5 4 4 4
5 5 4 3 3 3
5 4 3 2 2 2
5 4 3 2 1 1
5 4 3 2 1 0
```

Chebyshev distance d = max( $∣x_{d}∣, ∣y_{d}∣$ )

**Chebyshev Heuristic Vector**
```txt
5 4 4 4 4 4
5 4 3 3 3 3
5 4 3 2 2 2
5 4 3 2 1 1
5 4 3 2 1 0
```

### Expansion
Now instead of expanding cells with lowest path cost **g**, you’ll expand cells with lowest **f** value which is the sum of the path cost **g** and the heuristic value **h** of that cell.
Each cell is now represented with a quadruplet **[f,g,x,y]** instead of a triplet **[g,x,y]**.

```txt
Map	0	1	2	3	4	5
0	0	1	0	0	0	0
1	0	1	0	0	0	0
2	0	1	0	0	0	0
3	0	1	0	0	0	0
4	0	0	0	1	1	0
```
```txt
Expansion #: 0
Open List: [9 0 0 0 ]
Cell Picked: [9 0 0 0]

Expansion #: 1
Open List: [9 1 1 0 ]
Cell Picked: [9 1 1 0]

Expansion #: 2
Open List: [9 2 2 0 ]
Cell Picked: [9 2 2 0]

Expansion #: 3
Open List: [9 3 3 0 ]
Cell Picked: [9 3 3 0]

Expansion #: 4
Open List: [9 4 4 0 ]
Cell Picked: [9 4 4 0]

Expansion #: 5
Open List: [9 5 4 1 ]
Cell Picked: [9 5 4 1]

Expansion #: 6
Open List: [9 6 4 2 ]
Cell Picked: [9 6 4 2]

Expansion #: 7
Open List: [11 7 3 2 ]
Cell Picked: [11 7 3 2]

Expansion #: 8
Open List: [13 8 2 2 ], [11 8 3 3 ]
Cell Picked: [11 8 3 3]

Expansion #: 9
Open List: [13 9 2 3 ], [13 8 2 2 ], [11 9 3 4 ]
Cell Picked: [11 9 3 4]

Expansion #: 10
Open List: [13 10 2 4 ], [13 9 2 3 ], [13 8 2 2 ], [11 10 3 5 ]
Cell Picked: [11 10 3 5]

Expansion #: 11
Open List: [13 11 2 5 ], [13 10 2 4 ], [13 9 2 3 ], [13 8 2 2 ], [11 11 4 5 ]
Cell Picked: [11 11 4 5]
```

### Comparison
**BFS**
```txt
0 -1 13 17 -1 -1
1 -1 10 14 18 -1
2 -1  8 11 15 19
3 -1  7  9 12 16
4  5  6 -1 -1 20
```

**A star**
```txt
0 -1 -1 -1 -1 -1 
1 -1 -1 -1 -1 -1 
2 -1 -1 -1 -1 -1 
3 -1  7  8  9 10 
4  5  6 -1 -1 11 
```

**Path**
```txt
v - - - - - 
v - - - - - 
v - - - - - 
v - > > > v 
> > ^ - - * 
```

[A* shortest path](https://github.com/bmaxdk/path-planning/blob/main/Lab_Path_Planning/Astar_Shortest_Path.cpp)

It clearly show that A* is more efficient since it did not expand in the free space as BFS did. With A* we reached the goal with only 11 expansions compared to 20 with BFS.

### A*: Real-World Map

If you recall, this map is the one you generated with the occupancy grid mapping algorithm using both sonar and odometry data. Our aim is now to find the shortest path for the robot to cross from start o to goal ***** position.

Given:

**Map(300x150)**: The map data stored in the `map.txt` file in form of log odds values. As a reminder, here's how you should interpret these numbers:

* A cell is considered **unknown** if its log odds value is **equal to 0**.
* A cell is considered as **occupied** if its log odds is **larger than 0**.
* A cell is considered as **free** if its log odds value is **less than 0**.

**Grid(300x150)**: The log odds values converted to 0’s and 1’s where **0** represents the **free space** and **1** represents the **occupied** or **unknown space**.

**Robot Start position**: 230, 145

**Robot Goal Position**: 60, 50

**Direction of Movement**: 
* Up(-1,0) 
* left(0,-1) 
* down(1,0) 
* right(0,1)

**Movement Arrows**: 
* Up(^) 
* left(<) 
* down(v) 
* right(>)

**Cost of Movement**: 1

**Heuristic Vector**: Manhattan

If you scroll down to the code, you will notice that I added three new functions to the Map class. I coded a GetMap function which reads the map.txt log odds values and assign them the map variable. You will code the MapToGrid function in order to convert the log odds values to 0’s and 1’s. These 0 and 1 values will be assigned to the grid variable. And finally, the GeneratedHeuristic function is another function that you have to code in order to generate a Manhattan-based heuristic vector by computing the Manhattan distance of each cell with respect to the goal position.



[A* Real World Map](https://github.com/bmaxdk/path-planning/blob/main/Lab_Path_Planning/Astar_2_Real_World_Map.cpp)

### [Addition] Plot
[matplotlib](https://github.com/lava/matplotlib-cpp)
Plot edit main.cpp
Modify the visualization function and plot the start position, goal position, and path using the matplotlib python library. Note that you are required to use letter 'o' (not number character '0') and the asterisk '*' to mark the start and end states in visualization! 
``` C++ 
void visualization(Map map, Planner planner) { 
//Graph Format plt::title("Path"); plt::xlim(0, map.mapHeight); plt::ylim(0, map.mapWidth);
```

``` C++
    // Draw every grid of the map:
    for (double x = 0; x < map.mapHeight; x++) {
        cout << "Remaining Rows= " << map.mapHeight - x << endl;
        for (double y = 0; y < map.mapWidth; y++) {
            if (map.map[x][y] == 0) { //Green unkown state
                plt::plot({ x }, { y }, "g.");
            }
            else if (map.map[x][y] > 0) { //Black occupied state
                plt::plot({ x }, { y }, "k.");
            }
            else { //Red free state
                plt::plot({ x }, { y }, "r.");
            }
        }
    }

    // Plot start and end states in blue colors using o and * respectively
    
    // Plot the robot path in blue color using a .
    
    //Save the image and close the plot
    plt::save("./Images/Path.png");
    plt::clf();
}
```
```bash
$ g++ main.cpp -o app -std=c++11 -I/usr/include/python2.7 -lpython2.7
$ ./app
```
Here are some helpful commands you can use to generate plots with the matplotlib library:

* Set Title: plt::title("Your Title");
* Set Limits: plt::xlim(x-axis lower limit, x-axis upper limit );
* Plot Data:plt::plot({ x-value }, { y-value }, "Color and Shape");
* Save Plot: plt::save("File name and directory");
* Close Plot: plt::clf();

[image1]: path.png "img1"
![alt text][image1]


* Green: Unkown/Undiscovered zone
* Red: Free zone
* Black: Occupied zone
* Blue: Shortest Path


# Resource
[2D Vectors](https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/): Learn how to define and use 2D Vectors in C++.

[Documentation](https://cplusplus.com/reference/vector/vector/): Learn the vectors iterators and modifiers.

