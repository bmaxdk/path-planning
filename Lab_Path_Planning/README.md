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


# Resource
[2D Vectors](https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/): Learn how to define and use 2D Vectors in C++.

[Documentation](https://cplusplus.com/reference/vector/vector/): Learn the vectors iterators and modifiers.