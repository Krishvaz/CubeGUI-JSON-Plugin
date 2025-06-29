---
title: Algorithms on Graphs
short_title: Algorithms on Graphs
kind: quiz
prefix: '071'
hidden: false
---

## Search in Graphs

### q:{}

The (iterative) *depth-first search* requires

- [X] a stack
- [ ] a queue
- [ ] a priority queue

### q:{}

The *breadth-first search* requires

- [ ] a stack
- [X] a queue
- [ ] a priority queue

### q:{}

Unlike searching in trees

- [ ] you can't search recursively in graphs. :: Actually, you can with DFS.
- [X] visited nodes must be marked. :: Since in graphs we don't just move "downward", we must remember where we've been.
- [ ] nodes may be listed multiple times.
- [X] we start at an arbitrary node.

### q:{}

The order in which BFS visits nodes is unique given a start node.

- [ ] Yes
- [X] No

### q:{}

Cyclic graphs cannot be searched.

- [ ] Yes
- [X] No

### q:{}

BFS will reach any node that is accessible from the start node via $k$ edges before it reaches any node accessible via $k+1$ edges.

- [X] Yes
- [ ] No

### q:{}

If we remember each node’s predecessor during DFS or BFS, we obtain

- [ ] a topological sort
- [X] a spanning tree :: Contains all nodes reachable from the start node.

## Topological Sorting

### q:{}

A topological sort produces an ordering of the nodes of a

- [ ] undirected graph
- [X] directed graph
- [ ] weighted graph

### q:{}

Additionally, this graph must be

- [ ] connected
- [X] acyclic :: A DAG (directed acyclic graph)
- [ ] have both incoming and outgoing edges for every node

### q:{}

A node is a *source* if

- [X] it has no incoming edges
- [ ] it has no outgoing edges

### q:{}

Which algorithm can perform topological sorting?

- [X] DFS :: Output after recursively finishing all neighbors.
- [ ] BFS
- [ ] Best-first search (priority-first search)

### q:{}

The output of a topological sort algorithm is

- [ ] unique
- [X] *not* unique :: Any order that respects the partial order is valid.

## Dijkstra’s Algorithm

### q:{}

Dijkstra’s algorithm works on

- [ ] directed graphs
- [X] weighted graphs
- [ ] unweighted graphs :: In unweighted graphs, BFS suffices.

### q:{}

Dijkstra’s algorithm works similarly to

- [ ] recursive DFS
- [ ] iterative DFS
- [X] BFS

### q:{}

The main data structure used by the algorithm is a

- [ ] stack
- [ ] queue
- [X] priority queue

### q:{}

Dijkstra’s algorithm computes, starting from a node:

- [X] the shortest paths to *all* other nodes
- [ ] the minimum spanning tree :: That’s Prim’s algorithm.

### q:{}

In each iteration, the node that is processed is the one with

- [X] the shortest distance to the start node
- [ ] the longest distance to the start node
- [ ] the smallest edge weight
- [ ] the largest edge weight

### q:{}

What is the purpose of the `lower` function in the pseudocode/Java example?

- [X] It adjusts the priority queue when a node's distance decreases.
- [ ] It adjusts the priority queue when a node's distance increases. :: We only care about shorter paths.
- [ ] It ensures an entry can sink down the heap.
- [X] It ensures an entry can bubble up in the heap.

### q:{}

For `lower` to work efficiently, the node must be found in the priority queue. Ideal lookup time is $O(1)$. How?

- [X] Use a balanced tree instead of a heap :: Delete and reinsert entries.
- [X] Store each node’s index in the heap and keep it consistent :: Efficient, but couples heap and node structure.
- [X] Use a heap plus a hash map to track positions :: Used in `aud.PriorityQueue`.

### q:{}

The class `PriorityQueue<T>` needs a comparison. How can we provide one independent of `T`?

- [X] Pass a `Comparator<T>` to the constructor
- [X] Let `T` implement `Comparable<T>`
- [X] Support both :: As in `aud.PriorityQueue`, falling back from comparator to `Comparable`.

### q:{}

Which algorithm is most similar to Dijkstra’s?

- [ ] Ford–Fulkerson :: Used for max flow.
- [X] Prim’s algorithm :: Finds a minimum spanning tree.
- [ ] Tarjan’s algorithm :: Used for topological sort.
- [ ] Kahn’s algorithm :: Also for topological sort.

### q:{}

Unlike Dijkstra, Prim’s algorithm uses as sorting key

- [X] the edge weight :: To minimize total weight in MST.
- [ ] the sum of edge weights :: That’s Dijkstra.
- [ ] the path length plus a heuristic :: That’s A*.

### q:{}

Dijkstra’s algorithm is a greedy algorithm. This means:

- [X] It picks the locally best option in each step.
- [ ] It may not find optimal paths :: False for Dijkstra.
- [ ] It picks the edge with smallest weight :: That’s Prim.

### q:{}

Greedy algorithms *do not always* produce optimal results.

- [X] Yes :: E.g. a hiker always going steepest uphill may get stuck in a local maximum.
- [ ] No

### q:{}

*Backtracking* refers to

- [ ] a sport
- [X] tracing the shortest path back to the start in Dijkstra’s algorithm
- [X] systematically solving from partial solutions :: Like using predecessors in shortest path or dynamic programming

### q:{}

Which statements are true?

- [X] Dijkstra works only with non-negative weights
- [X] Bellman–Ford works even with negative weights
- [X] Bellman–Ford must use *directed* graphs if weights are negative :: To avoid infinite cycles
- [X] Bellman–Ford is an example of *dynamic programming*

### q:{}

Bellman–Ford is always slower than Dijkstra?

- [ ] Yes
- [X] No :: With optimizations (queue-based variant from Sedgewick), it may be faster in practice.

### q:{}

What does *relaxing an edge* mean?

- [ ] The edge is relaxed and happy
- [ ] The edge is on vacation
- [X] A path is extended via this edge :: Used to check if a shorter path exists

## A* Algorithm

### q:{}

Which statements are true?

- [X] A* is a greedy algorithm
- [X] A* extends Dijkstra
- [ ] A* computes shortest paths to all nodes :: It stops when goal is reached
- [X] A* uses a heuristic
- [ ] A* is always faster than Dijkstra :: Not guaranteed

### q:{}

A* processes nodes with

- [ ] minimum distance from start :: Dijkstra
- [X] minimum (distance from start + estimated distance to goal) :: This is the priority
- [ ] minimum estimated distance to goal
- [ ] minimum estimated total distance from start to goal

### q:{}

The heuristic used

- [ ] must not *underestimate* the actual distance
- [X] must not *overestimate* the actual distance :: Or it might fail to find the shortest path
- [ ] must be Euclidean :: Not required

### q:{}

We compute shortest paths on a grid. Node positions are $(x,y)$. Which heuristics are valid?

- [ ] $h(t)=||x(t)||$ :: That’s distance to origin
- [X] $h(t)=||x(t)-x(s_1)||$ :: Euclidean distance
- [ ] $h(t)=||x(t)-x(s_1)||^2$ :: Overestimates
- [X] $h(t)=|x(t)-x(s_1)|$ :: Underestimates
- [ ] $h(t)=x(t)-x(s_1)$ :: May be negative
- [ ] $h(t)=|x(t)-y(s_1)|$ :: Nonsense
- [X] $h(t)=\max(|x(t)-x(s_1)|, |y(t)-y(s_1)|)$ :: Never overestimates
- [ ] $h(t)=|x(t)-x(s_1)| + |y(t)-y(s_1)|$ :: Manhattan distance can overestimate Euclidean
- [X] $h(t)=0$ :: Makes A* behave like Dijkstra

### q:{}

Are shortest paths computed by Dijkstra or A* always unique?

- [ ] Yes
- [X] No :: Multiple shortest paths may exist (e.g., on grids)

## More on Shortest Paths

You can find implementations of all algorithms for finding shortest paths in the code examples for the lecture. With them, you can also visually illustrate the differences between the various algorithms. The best setup is probably a search on a regular grid, as shown in the lecture. (To make this *colorful*, you’ll need a [terminal emulator] as is common under Unix-based systems!)

A similar, more visually refined and interactive representation can be found **[here]**, including explanations and code snippets in [Python]. This visualization focuses on the application of the A* algorithm for pathfinding in *games*.

[terminal emulator]: https://en.wikipedia.org/wiki/Terminal_emulator
[here]: http://www.redblobgames.com/pathfinding/a-star/introduction.html
[Python]: https://www.python.org/

---

## Flow in Graphs

### q:{}

What do edge weights represent in flow computation on a graph?

- [ ] Edge length
- [X] Capacities :: That is, the maximum flow through that edge. Imagine the edges as pipes through which a certain amount of fluid can be pumped per unit time.
- [ ] Resistance
- [ ] Inductance

### q:{}

We consider graphs with

- [ ] one source and multiple sinks
- [ ] one sink and multiple sources
- [X] exactly one source and one sink :: Any graph can be transformed into this form by consolidating all sources (or sinks) into one — by introducing a new node as source (or sink).

### q:{}

What conditions must a flow in a graph satisfy?

- [X] At every node (except source and sink), the sum of inflows and outflows must be zero.
- [ ] At every node (except source and sink), the sum of outflows must be zero.
- [ ] At every node (except source and sink), the sum of inflows must be zero.
- [X] The flow on each edge may not exceed its weight (capacity).
- [ ] The flow on each edge must be at least as large as the weight.
- [X] The flow along each edge is positive.
- [X] The backflow against the edge direction equals the negative of the flow on the edge. :: We use this *anti-symmetry* rule, ensuring that the total flow (including backflows) in any node is zero.
- [X] The value of a flow is the total (out-)flow from the source.
- [X] The value of a flow is the total (in-)flow into the sink.

### q:{}

A *cut* is a partitioning of the graph into two disjoint parts.

- [X] Yes
- [ ] No

### q:{}

A cut can be represented as

- [X] A subset of nodes and its complement
- [X] A subset of edges that are removed
- [ ] A path in the graph

### q:{}

The value of a cut is

- [X] The sum of the edge weights of the edges that are removed :: i.e., those "cut through"
- [ ] The sum of node values in one node set :: What would a "node value" even be?
- [ ] The quotient of the sums of node values in the two sets

### q:{}

In a weighted graph, the value of the maximum flow equals the value of the minimum cut.

- [X] Yes
- [ ] No


