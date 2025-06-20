---
title: Graphs and Data Structures for Graphs
short_title: Graphs (Data Structures)
kind: quiz
prefix: '06'
hidden: false
---

## Introduction

Graphs play an important role in computer science and many other disciplines. They are used in various applications as theoretical models. Often, this involves mapping *physical* objects, such as road networks (with places as nodes and roads as edges), computer networks, or pipelines. Likewise, *abstract* scenarios can be represented using graphs, e.g., in project planning (with goals or states as nodes and actions as edges) or optimization. Such optimization problems arise in mathematics and computer science (from shortest paths to [image processing] and Google's [*PageRank*]), but especially in economics: [Operations Research]. Of course, graphs also play a major role in [Machine Learning], which is frequently discussed in the media (often loosely referred to as "*AI*" or simply "*algorithms*").

In the following, we focus on the definition of graphs and the implementation with appropriate data structures.

[Image processing]: http://www.cis.upenn.edu/~jshi/GraphTutorial/
[*PageRank*]: http://de.wikipedia.org/wiki/PageRank
[Operations Research]: http://de.wikipedia.org/wiki/Operations_Research
[Machine Learning]: https://en.wikipedia.org/wiki/Machine_learning

## Graphs

### q:{}

We distinguish between:

- [ ] heavy graphs  
- [X] weighted graphs  
- [ ] light graphs  
- [X] directed graphs  
- [X] undirected graphs  
- [ ] function graphs :: Not here...

### q:{}

Which of the following is true?

- [X] A list is a graph.  
- [ ] A graph is a list.  
- [X] A closed ring (as a linked list) is a graph.  
- [ ] A graph is a closed ring.  
- [X] A tree is a graph.  
- [ ] A graph is a tree.

### q:{}

A cycle is:

- [ ] a *path* in which no node appears more than once  
- [X] a *path* in which a node appears more than once :: That means we're "going in circles."  
- [ ] a *graph* forming a ring  
- [ ] a *directed graph* containing a ring

### q:{}

A *weighted* graph:

- [ ] is a graph in which each node has a weight  
- [X] is a graph in which each edge has a weight :: Usually weights are natural or positive real numbers and are often associated with costs.  
- [ ] is a graph where each node and each edge has a weight  
- [ ] is always directed  
- [ ] is always undirected  
- [X] can be either directed or undirected :: Exactly, "weighted" doesn't imply anything about direction.

  **Special case:** In some applications of directed graphs, the direction of edges may indicate the sign of the weight. Edges may then be traversed in both directions.
- [ ] is always cycle-free

### q:{}

The acronym *DAG* refers to:

- [ ] a path  
- [X] a graph :: **G** stands for *Graph*  
- [X] a directed graph :: **D** stands for *Directed*  
- [X] an acyclic graph :: **A** stands for *Acyclic*. This abbreviation for **Directed Acyclic Graph** is commonly found in literature.

### q:{}

An undirected graph *always* has a cycle.

- [ ] Yes :: Only if it has at least one edge  
- [X] No :: Only in the *special case* of a graph with no edges. In general, we can "walk in circles" in an undirected graph.

### q:{}

A node in a graph is also called:

- [ ] vortex  
- [X] vertex :: Plural *vertices*. This is why $V$ usually denotes the set of nodes.  
- [ ] loop

### q:{}

Let $G=(V,E)$ be a graph with nodes $V$ and edges $E=\left\{\,\{i,j\}\,|\,i,j\in{}V\,\right\}$. $G$ is a:

- [ ] directed graph  
- [X] undirected graph :: Because the edges are sets $\{i,j\}$, order doesn't matter. In contrast, in directed graphs edges are ordered pairs $(i,j)$.  
- [ ] weighted graph :: There's no weight function.  
- [ ] acyclic graph

### q:{}

A *loop*:

- [X] is a cycle :: Specifically a cycle of length 1.  
- [X] is an edge from a node to itself  
- [X] is a directed edge :: We only allow loops in directed graphs

## Data Structures for Graphs

Note that there is generally **no single** data structure suitable for all applications. Instead, we must decide which operations are frequently needed and make trade-offs. Many suggestions from the lecture build on simpler data structures. They can be adapted, combined, and tailored to specific applications.

We will consider *asymptotic costs*.

### q:{}

Which operations should a *graph data structure* support?

- [X] Enumerate all nodes  
- [X] Enumerate all edges  
- [ ] Enumerate all cycles :: Requires an algorithm like DFS  
- [X] Given $i,j$: decide whether edge $(i,j)$ exists  
- [X] Access attributes of node $i$ (e.g. its position)  
- [X] Access attributes of edge $(i,j)$ (e.g. weight)  
- [X] List all nodes adjacent to node $i$  
- [X] List all edges going out from node $i$  
- [X] Insert and delete nodes  
- [X] Insert and delete edges

### q:{}

Suppose we model a road network with a graph. Each node has a position attribute. We want to display this graph. Which operations are needed?

- [ ] Enumerate all nodes  
- [X] Enumerate all edges  
- [ ] Enumerate all cycles  
- [ ] Check if edge $(i,j)$ exists  
- [X] Access attributes of node $i$  
- [ ] Access attributes of edge $(i,j)$  
- [ ] List all neighbors of node $i$  
- [ ] List all edges of node $i$  
- [ ] Insert and delete nodes  
- [ ] Insert and delete edges

### q:{}

Suppose we model a maze as a graph, to be traversed using depth-first search[^dfs]. Which operations are needed?

[^dfs]: We'll cover DFS algorithms in the next chapter. For now, imagine simulating someone walking through the maze and marking each visited room (node).

- [X] Enumerate all nodes :: To reset marks at the beginning  
- [ ] Enumerate all edges  
- [ ] Enumerate all cycles  
- [ ] Check if edge $(i,j)$ exists  
- [X] Access attributes of node $i$ :: We need to *mark* visited nodes  
- [ ] Access attributes of edge $(i,j)$  
- [X] List all edges from node $i$  
- [ ] Insert and delete nodes  
- [ ] Insert and delete edges

### q:{}

Which operation becomes *more efficient* if we represent the *node list* using two arrays?

- [ ] Enumerate all nodes  
- [ ] Enumerate all edges  
- [ ] Enumerate all cycles  
- [ ] Check if edge $(i,j)$ exists  
- [ ] Access attributes of node $i$  
- [ ] Access attributes of edge $(i,j)$  
- [X] List all edges from node $i$ :: Can be done in $O(1)$ under the assumption of constant out-degree  
- [ ] Insert and delete nodes  
- [ ] Insert and delete edges

## Example: `aud.graph.GraphAM`

The `GraphAM` class uses a sparse adjacency matrix. What are the costs of the following operations in terms of number of nodes $n$ and edges $m$?

We assume the number of outgoing edges per node is bounded.

### q:{}

Enumerate all nodes

- [ ] $O(1)$  
- [ ] $O(\log n)$  
- [X] $O(n)$  
- [ ] $O(m)$  
- [ ] $O(\log m)$  
- [ ] $O(m+n)$

...

*(continued — ask if you'd like the rest or prefer split files)*

---

Let me know if you'd like the rest of this file output as a downloadable `.md`, or continue with `graphalgorithmen.md` and `hashes.md` translations now.
