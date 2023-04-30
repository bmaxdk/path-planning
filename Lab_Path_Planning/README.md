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


# Resource
[2D Vectors](https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/): Learn how to define and use 2D Vectors in C++.

[Documentation](https://cplusplus.com/reference/vector/vector/): Learn the vectors iterators and modifiers.