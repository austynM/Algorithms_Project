# Algorithms_Project
Algorithms 

My BFS algorithm, will make a queue, and will have a Boolean signal to check when we get to a state that is equal the goal.
The algorithm will put nodes onto the queue in the order of moves left, up, right, down, until we find the solution. 
The graph will look like a tree, and we will traverse the graph from left to right.

The DFS algorithm is a stack-based algorithm. 
The algorithm will put moves onto a stack if they exist in the order left, up, right, down.
This algorithm is very inefficient and will almost always choose the left path.
This led to a stack overflow/ memory error most of the time.

The Dijkstra algorithm will take in a root node. 
It will then find its neighbors (left, right, up, down). 
It will then take it neighbors and sort the neighbors by cost, which is the number of the tile we move added with the number of tiles out of place from the solution. 
These neighbors will then be added onto a queue and repeat the steps. 
The graph in this problem will look like a tree so all the nodes on level 1 (roots children) will always have a smaller distance than the nodes on level 2(nodes on level 1 children).
Thus, making this algorithm correct.  

