[image1]: image/a1.png "img1"
[image2]: image/a2.png "img2"
[image3]: image/a3.png "img3"
[image4]: image/a4.png "img4"

[image1]: image/a5.png "img5"
[image2]: image/a6.png "img6"
[image3]: image/a7.png "img7"
[image4]: image/a8.png "img8"
[image3]: image/a9.png "img9"
[image4]: image/a10.png "img10"

[image11]: image/a11.png "img11"
[image22]: image/a12.png "img12"
[image33]: image/a13.png "img13"
[image44]: image/a14.png "img14"

# path-planning
Path Planning

## Approaches to Path Planning
Three different approaches:

* `Discrete (or combinatorial) path planning`
* `Sample-based path planning`
* `Probabilistic path planning`

## Discrete Planning
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

The Minkowski sum is a mathematical property that can be used to compute the configuration space given an obstacle geometry and robot geometry. To create the configuration space, the Minkowski sum is calculated in such a way for every obstacle in the workspace. The image below shows three configuration spaces created from a single workspace with three different sized robots.
![alt text][image5]
For convex polygons, computing the convolution is trivial and can be done in linear time - however for non-convex polygons (i.e. ones with gaps or holes present), the computation is much more expensive.


## Sample-Based Planning
Sample-based path planning probes the workspace to incrementally construct a graph. Instead of discretizing every segment of the workspace, sample-based planning takes a number of samples and uses them to build a discrete representation of the workspace. The resultant graph is not as precise as one created using discrete planning, but it is much quicker to construct because of the relatively small number of samples used. A path generated using sample-based planning may not be the best path, but in certain applications - it’s better to generate a feasible path quickly than to wait hours or even days to generate the optimal path.


## Probabilistic Path Planning
While the first two approaches looked at the path planning problem generically - with no understanding of who or what may be executing the actions - probabilistic path planning takes into account the uncertainty of the robot’s motion. It's used in reinforcement learning as well such as reward.

