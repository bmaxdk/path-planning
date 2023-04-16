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



## Sample-Based Planning
Sample-based path planning probes the workspace to incrementally construct a graph. Instead of discretizing every segment of the workspace, sample-based planning takes a number of samples and uses them to build a discrete representation of the workspace. The resultant graph is not as precise as one created using discrete planning, but it is much quicker to construct because of the relatively small number of samples used. A path generated using sample-based planning may not be the best path, but in certain applications - it’s better to generate a feasible path quickly than to wait hours or even days to generate the optimal path.


## Probabilistic Path Planning
While the first two approaches looked at the path planning problem generically - with no understanding of who or what may be executing the actions - probabilistic path planning takes into account the uncertainty of the robot’s motion. It's used in reinforcement learning as well such as reward.

