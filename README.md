[image1]: img/a1.png "img1"
[image2]: img/a2.png "img2"
[image3]: img/a3.png "img3"
[image4]: img/a4.png "img4"

[image5]: img/a5.png "img5"
[image6]: img/a6.png "img6"
[image7]: img/a7.png "img7"
[image8]: img/a8.png "img8"
[image9]: img/a9.png "img9"
[image10]: img/a10.png "img10"

[image11]: img/a11.png "img11"
[image12]: img/a12.png "img12"
[image13]: img/a13.png "img13"
[image14]: img/a14.png "img14"

[image15]: img/a15.png "img15"
[image16]: img/a16.png "img16"
[image17]: img/a17.png "img17"
[image18]: img/a18.png "img18"

[image19]: img/a19.png "img19"
[image20]: img/a20.png "img20"
[image21]: img/a21.png "img21"
[image22]: img/a22.png "img22"

[image23]: img/a23.png "img23"
[image24]: img/a24.png "img24"
[image25]: img/a25.png "img25"
[image26]: img/a26.png "img26"

[image27]: img/a27.png "img27"
[image28]: img/a28.png "img28"
[image29]: img/a29.png "img29"
[image30]: img/a30.png "img30"

[image31]: img/a31.png "img31"
[image32]: img/a32.png "img32"
[image33]: img/a33.png "img33"
[image34]: img/a34.png "img34"
[image35]: img/a35.png "img35"
[image36]: img/a36.png "img36"

[image33]: img/a37.png "img37"
[image34]: img/a38.png "img38"
[image35]: img/a39.png "img39"
[image36]: img/a40.png "img40"

# path-planning
Path Planning

## Approaches to Path Planning
Three different approaches:

* `Discrete (or combinatorial) path planning`
* `Sample-based path planning`
* `Probabilistic path planning`

## Discrete Planning
![alt text][image18]

Discretize the robot’s workspace into a connected graph, and apply a graph-search algorithm to calculate the best path. It is very computationall very expensive. Therefore, it is best suited for low-dimensional problems. For high-dimensional problems, sample-based path planning is a more appropriate approach.

![alt text][image1]
* Develop a convenient `continuous representation`. This can be done by representing the problem space as the configuration space (C space). C space takes into account the geometry of the robot and makes it easier to apply discrete search algorithms.
* `Discretization`. The configuration space must be discretized into a representation that is more easily manipulated by algorithms.
* `Graph Search`. The descretized space is represented by a graph to use search algorithm. Find the best path from the start node to the goal node. 

### Continuous Representation
Find a curved or piece wise linear path connecting the robot start pose to the goal pose that does not collied with any obstacles.
![alt text][image2]
![alt text][image3]
Inflate every single obstacle by the radius of the robot and then treat the robot as a point.

![alt text][image4]
This kinds of environment is the configuration space(C space). A configuration space is a set of all robot poses. The C space is divided into $C_{free}$ and $C_{obstacle}$. $C_{obstacle}$ is the compliment to $C_{free}$ representing the set of robot pauses that are in collision with obstacles or walls.

### Minkowski Sum
Let P and R be two sets in $\mathbb{R}_{2}$

$P \oplus R$ = {p+r | p $\in$ P $\wedge$ r $\in$ R}

where p+r = ($p_{x}+r_{x}, p_{y}+r_{y}$)

The [Minkowski sum](https://github.com/bmaxdk/path-planning/blob/main/minkowski_sum.cpp) is a mathematical property that can be used to compute the configuration space given an obstacle geometry and robot geometry. To create the configuration space, the Minkowski sum is calculated in such a way for every obstacle in the workspace. The image below shows three configuration spaces created from a single workspace with three different sized robots.
![alt text][image5]
For convex polygons, computing the convolution is trivial and can be done in linear time - however for non-convex polygons (i.e. ones with gaps or holes present), the computation is much more expensive. 
Plot check [RoboND-MinkowskiSum](https://github.com/udacity/RoboND-MinkowskiSum)

### 3D Configuration Space
Configuration space changes depending on the orientation of the robot. The apporpriate way to represent this in the configuration space is to add a dimension. The x-y plane would continue to represent the translation of the robot in the workspace, while the vertical axis would represent rotation of the robot.

The dimension of the configuration space is equal to the number of degrees of freedom that the robot has. While a 2D configuration space was able to represent the x- and y-translation of the robot, a third dimension is required to represent the rotation of the robot. A three-dimensional configuration space can be generated by stacking two-dimensional configuration spaces as layers.
![alt text][image6]
The image above displays the configuration space for a triangular robot that is able to translate in two dimensions as well as rotate about its z-axis. 
[Configuration Space Visualization](https://www.youtube.com/watch?v=SBFwgR4K1Gk&ab_channel=Dr.DrorAtariah)

### Roadmap
These methods represent the configuration space using a simple connected graph - similar to how a city can be represented by a metro map.

![alt text][image7]

Roadmap methods are typically implemented in two phases:

* The `construction phase` builds up a graph from a continuous representation of the space. This phase usually takes a significant amount of time and effort, but the resultant graph can be used for multiple queries with minimal modifications.
* The `query phase` evaluates the graph to find a path from a start location to a goal location. This is done with the help of a search algorithm.

### Visibility Graph
The Visibility Graph builds a roadmap by connecting the start node, all of the obstacles’ vertices, and goal node to each other - except those that would result in collisions with obstacles. The Visibility Graph has its name for a reason - it connects every node to all other nodes that are ‘visible’ from its location.

* `Nodes`: Start, Goal, and all obstacle vertices.
* `Edges`: An edge between two nodes that does not intersect an obstacle, including obstacle edges.

![alt text][image8]

The motivation for building Visibility Graphs is that the shortest path from the start node to the goal node will be a piecewise linear path that bends only at the obstacles’ vertices. This makes sense intuitively - the path would want to hug the obstacles’ corners as tightly as possible, as not to add any additional length. In certain applications, such as animation or path planning for video games, this is acceptable. However the uncertainty of real-world robot localization makes this method impractical. [Complete and optimal path]

### Voronoi Diagram
Another discretization method that generates a roadmap is called the Voronoi Diagram. Unlike the visibility graph method which generates the shortest paths, Voronoi Diagrams maximize clearance between obstacles. A Voronoi Diagram is a graph whose edges bisect the free space in between obstacles. Every edge lies equidistant from each obstacle around it - with the greatest amount of clearance possible.

![alt text][image9]

Once a Voronoi Diagram is constructed for a workspace, it can be used for multiple queries. Start and goal nodes can be connected into the graph by constructing the paths from the nodes to the edge closest to each of them.

Every edge will either be a straight line, if it lies between the edges of two obstacles, or it will be a quadratic, if it passes by the vertex of an obstacle. [Complete path]

### Cell Decomposition
Another discretization method that can be used to convert a configuration space into a representation that can easily be explored by a search algorithm is `cell decomposition`. Cell decomposition divides the space into discrete cells, where each cell is a node and adjacent cells are connected with edges. There are two distinct types of cell decomposition:

* Exact Cell Decomposition
* Approximate Cell Decomposition.

#### Exact Cell Decomposition
Exact cell decomposition divides the space into `non-overlapping cells`. This is commonly done by breaking up the space into triangles and trapezoids, which can be accomplished by adding vertical line segments at every obstacle’s vertex. 
![alt text][image10]
Once a space has been decomposed, the resultant graph can be used to search for the shortest path from start to goal.
![alt text][image11]
Exact cell decomposition is elegant because of its precision and completeness. Every cell is either ‘full’, meaning it is completely occupied by an obstacle, or it is ‘empty’, meaning it is free. And the union of all cells exactly represents the configuration space. If a path exists from start to goal, the resultant graph will contain it.

To implement exact cell decomposition, the algorithm must order all obstacle vertices along the x-axis, and then for every vertex determine whether a new cell must be created or whether two cells should be merged together. Such an algorithm is called the `Plane Sweep algorithm`.

#### Approximate Cell Decomposition
Approximate cell decomposition divides a configuration space into discrete cells of simple, regular shapes - such as rectangles and squares (or their multidimensional equivalents). Aside from simplifying the computation of the cells, this method also supports hierarchical decomposition of space.

##### Simple Decomposition
A 2-dimensional configuration space can be decomposed into a grid of rectangular cells. Then, each cell could be marked full or empty, as before. A search algorithm can then look for a sequence of free cells to connect the start node to the goal node.

Such a method is more efficient than exact cell decomposition, but it loses its completeness. It is possible that a particular configuration space contains a feasible path, but the resolution of the cells results in some of the cells encompassing the path to be marked ‘full’ due to the presence of obstacles. A cell will be marked ‘full’ whether 99% of the space is occupied by an obstacle or a mere 1%. Evidently, this is not practical.

#### Iterative Decomposition
An alternate method of partitioning a space into simple cells exists. Instead of immediately decomposing the space into small cells of equal size, the method recursively decomposes a space into four quadrants. Each quadrant is marked full, empty, or a new label called ‘mixed’ - used to represent cells that are somewhat occupied by an obstacle, but also contain some free space. If a sequence of free cells cannot be found from start to goal, then the mixed cells will be further decomposed into another four quadrants. Through this process, more free cells will emerge, eventually revealing a path if one exists.

![alt text][image12]

The 2-dimensional implementation of this method is called quadtree decomposition.

#### Algorithm
The algorithm behind approximate cell decomposition is much simpler than the exact cell decomposition algorithm.
![alt text][image13]
```
Decompose the configuration space into four cells, label cells free, mixed, or full.

Search for a sequence of free cells that connect the start node to the goal node.

if (sequence exists):
    Return path

else
    Further decompose the mixed cells
```
The three dimensional equivalent of quadtrees are octrees.
The method of discretizing a space with any number of dimensions follows the same procedure as the algorithm described above, but expanded to accommodate the additional dimensions.
![alt text][image14]
Although exact cell decomposition is a more elegant method, it is much more computationally expensive than approximate cell decomposition for non-trivial environments. For this reason, approximate cell decomposition is commonly used in practice.

With enough computation, approximate cell decomposition approaches completeness. However, it is not optimal - the resultant path depends on how cells are decomposed. Approximate cell decomposition finds the obvious solution quickly. It is possible that the optimal path squeezes through a minuscule opening between obstacles, but the resultant path takes a much longer route through wide open spaces - one that the recursively-decomposing algorithms would find first.

Approximate cell decomposition is functional, but like all discrete/combinatorial path planning methods - it starts to be computationally intractable for use with high-dimensional environments.

### ***Potential Field***

Unlike the methods discussed thus far that discretize the continuous space into a connected graph, the potential field method performs a different type of discretization.

To accomplish its task, the potential field method generates two functions - one that attracts the robot to the goal and one that repels the robot away from obstacles. The two functions can be summed to create a discretized representation. By applying an optimization algorithm such as gradient descent, a robot can move toward the goal configuration while steering around obstacles. 

#### Attractive Potential Field
The attractive potential field is a function with the global minimum at the goal configuration. If a robot is placed at any point and required to follow the direction of steepest descent, it will end up at the goal configuration. This function does not need to be complicated, a simple quadratic function can achieve all of the requirements discussed above.

$f_{att} (x) = \nu_{att} (||x-x_{goal}||)^{2}$

where x represents the robot's current position, and $x_{goal}$ the goal position. $/nu$ is a scaling factor.

A fragment of the attractive potential field:
![alt text][image15]

#### Repulsive Potential Field
The repulsive potential field is a function that is equal to zero in free space, and grows to a large value near obstacles. One way to create such a potential field.


   $$\nu_{rep} (\frac{1}{\rho(x)} - \frac{1}{\rho_{0}})^{2}  ~~~~ ~~~~  ~~~~    ~~~~  ~~~~  ~~~~  ~~~~  if \rho \leq \rho_{0}$$
$~~~~ ~~~~  ~~~~  ~~~~  ~~~~  ~~~~  ~~~~  ~~~~  ~~~~   ~~~~ f_{rep} ~~~~ ~~~~ ~~~~ =  $ 
        
   $$ 0  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ if \rho > \rho_{0}$$


* The function $\rho (x)$ returns the distance from the robot to its nearest obstacle.
* $\rho_{0}$ is a scaling parameter that defines the reach of an obstacle's repulsiveness.
* $\nu$ is a scaling parameter.


An image of a repulsive potential field for an arbitrary configuration space
![alt text][image16]

The value $\rho_{0}$ controls how far from an obstacle the potential field will be non-zero, and how steep the area surrounding an obstacle will be.

#### Potential Field Sum
The attractive and repulsive functions are summed to produce the potential field that is used to guide the robot from anywhere in the space to the goal.
![alt text][image17]
The gradient of the function dictates which direction the robot should move, and the speed can be set to be constant or scaled in relation to the distance between the robot and the goal.


### ***Graph Search***
**Graph Search** is used to find finite sequence of discrete action to connect a start state to a goal state.
![alt text][image19]

Types of Search Algorithm:
* **Uniformed** : Search blindly which are not provided with any information about the whereabouts of the goal. ***Breadth-First Search***, ***Depth-First Search***, ***Uniform Cost Search***
* **Informed** : Can guid the search algorithm to make more intelligeent decisions which are provided with information pertaining to the location of the goal. `A* search`

**** Breadth-First Search (BFS)
![alt text][image20]
Breadth-First Search is the data structure underlying the frontier is a ***queue***. In a queue, the first element to enteer will be the first to exit. Add child nodes of the first node that will be added to frontier. BFS is still complete and optimal since it will always find goal soluttion. It is optimal because it will always find tthe shorteest solution since it explorees the shortest routes firs. It is optimal because it expands the shallowest unexplored node with every step. However BFS is limited to graphs wheere all step costs are equal. It also might take the algorithm a long time to find the solution. Therefore, algorithm is not efficient.
![alt text][image21]

**** Depth-First Search (DFS)
![alt text][image22]
Depth-First Search expand newly visited nodes first. The data structrue undrlying the frontier will be ***stack***. DFS is exploring deep on the upwards direction. DFS is neither complete, nor optimal, nor efficient.
![alt text][image23]


**** Uniform Cost Search
![alt text][image24]
As shown in BFS and DFS are not too efficient. Uniform Cost Search builds upon BfS to be able to search graphs with differing eedge costs. ***Uniform Cost Search*** is optimal because it expands nodes in order of increasing path cost.
![alt text][image25]
As shown above higher cost to the edge is consider delay. The ***Uniform Cost Search*** splores the node of the frontier starting with the node that has the lowest path cost. ***Path Cost*** refers to the sum of all edge costs leading from the start to the node.
![alt text][image26]
As shown above the first child nodes of path costs are 1<2 which start to explore lowst costs (left node).
![alt text][image27]

Uniform Cost search explore nodes with lowest path costs first. To accommodate this, it use a ***priority queue*** that is a queue that is organized by the path cost.
![alt text][image28]
![alt text][image29]
![alt text][image30]
![alt text][image31]

Uniform Cost Search is complete if every step cost is greater than some value, otherwise it can get stuck in infinitee loops. And it is also optimal.

**** A* Search
`A* Search` is an informed search. This means that it takes into account information about the goal's location as it goes aboout its search. It uses a heuristic function.


## Sample-Based Planning
Sample-based path planning probes the workspace to incrementally construct a graph. Instead of discretizing every segment of the workspace, sample-based planning takes a number of samples and uses them to build a discrete representation of the workspace. The resultant graph is not as precise as one created using discrete planning, but it is much quicker to construct because of the relatively small number of samples used. A path generated using sample-based planning may not be the best path, but in certain applications - it’s better to generate a feasible path quickly than to wait hours or even days to generate the optimal path.
```text
h(n) = distance to goal 
g(n) = path cost
f(n) = g(n) + h(n)
```
It represents the distance from a node to the goal. It is estimation of the distance as the only way to know the true distance would be to traverse the graph. 
![alt text][image31]
![alt text][image32]
![alt text][image33]
Minimizing g(n) favors shorter paths and minimizing h(n) favors paths in the direction of the goal. A* searches for the shortest path in the direction of the goal. For valid heuristic, h(x) would be the Euclidean distance from a node to the goal. Nodes close to the goal have a low heuristic value, and nodes further away from the goal have a higher heeuristic value. As shown below, The goal itself has a heuristic of zero. In A* use ***Priority Queue*** as the data structure underlying the frontier. Unlike UCS, A* search is directed towards the goal. The nodes on the left hand side of the graaph have not been explored. This instance where nodes' path and f(n) value aree updated based on h(n).

![alt text][image34]
![alt text][image35]
![alt text][image36]
![alt text][image37]
A heuristic function provides the robot with knowledge about the environment, guiding it in the direction of the goal. A* uses tthe sum of the path cost and the heuristic function to determine which nodes to explore next. Choosing an appropriate heuristic function(Euclidean distance, Manhattan distance, etc) is importnat. the order in which nodes are explored will change from one heuristic to another. However, A* search algorithm isn’t guaranteed to be optimal.

A* search will find the optimal path if* the following conditions are met:
* Every edge must have a cost greater than some value, ϵ, otherwise, the search can get stuck in infinite loops and the search would not be complete.
* The heuristic function must be consistent. This means that it must obey the triangle inequality theorem. That is, for three neighbouring points ( $x_{1}, x_{2}, x_{3}$ ), tthe heuristic value for $x_{1}$ to $x_{3}$ must be less than the sum of the heuristic values for $x_{1}$ to $x_{2}$ and $x_{2}$ to $x_{3}$.
* The heuristic function must be admissible. This means that h(n) must always be less than or equal to the true cost of reaching the goal from every node. In other words, h(n) must never overestimate the true path cost.
![alt text][image38]

As shown above, to understand where the admissibility clause comes from. Suppose you have two paths to a goal where one is optimal (the highlighted path), and one is not (the lower path). Both heuristics overestimate the path cost. From the start, you have four nodes on the frontier, but Node N would be expanded first because its h(n) is the lowest - it is equal to 62. From there, the goal node is added to the frontier - with a cost of 23 + 37 = 60. This node looks more promising than Node P, whose h(n) is equal to 63. In such a case, A* finds a path to the goal which is not optimal. If the heuristics never overestimated the true cost, this situation would not occur because Node P would look more promising than Node N and be explored first.

Admissibility is a requirement for A* to be optimal. For this reason, common heuristics include the Euclidean distance from a node to the goal or in some applications the Manhattan distance. When comparing two different types of values - for instance, if the path cost is measured in hours, but the heuristic function is estimating distance - then you would need to determine a scaling parameter to be able to sum the two in a useful manner.



## Probabilistic Path Planning
While the first two approaches looked at the path planning problem generically - with no understanding of who or what may be executing the actions - probabilistic path planning takes into account the uncertainty of the robot’s motion. It's used in reinforcement learning as well such as reward.


# Review
## Discrete Path Planning
* Continuous Representation
    * Create a configuration space.
* Discretization
    * Three different types of methods used to represent a configuration space with discrete segments.
        * ***Roadmap*** group of methods: Modeled the configuration space as a simple graph by either connecting the vertices of the obstacles or building a Voronoi diagram.
        * ***Cell Decomposition***: Broke the space into a finite number of cells, each of which was assessed to be empty, full, or mixed. The empty cells will linked together to create a graph.
        * ***Gradient field***: Method that models the configuration space using a 3D function that has the goal as global minimum and obstacles as tall structures.
* Graph Search
    * `A* Search`admissibility is a requirement for A* to be optimal. For this reason, common heuristics include the Euclidean distance from a node to the goal, or in some applications the Manhattan distance. When comparing two different types of values - for instance, if the path cost is measured in hours, but the heuristic function is estimating distance - then you would need to determine a scaling parameter to be able to sum the two in a useful manner. 
    * [A* search hueristic guide](http://theory.stanford.edu/~amitp/GameProgramming/Heuristics.html)
    * [Path Finding Visualization](https://qiao.github.io/PathFinding.js/visual/)
    * [MovingAI A* Variance](https://movingai.com/astar-var.html)
    * [Variants of A* - Stanford](http://theory.stanford.edu/~amitp/GameProgramming/Variations.html)
    
    
