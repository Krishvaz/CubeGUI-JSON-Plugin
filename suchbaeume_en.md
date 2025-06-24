---
title: "Again: Search in Graphs"
short_title: "Again: Search in Graphs"
kind: quiz
prefix: '072'
hidden: false
---

## Description

Given is the following weighted graph and also 12 different spanning trees of the graph.

The following questions each require classification into one of several types of spanning trees:

- *Shortest path tree* (SPT) from Dijkstra's algorithm,
- *Minimum spanning tree* (MST) from Prim’s algorithm,
- Spanning tree from a *depth-first search* (DFS),
- or from a *breadth-first search* (BFS) in the unweighted version of the graph.

To answer correctly, you need to understand and apply the corresponding graph traversal algorithms.

If you know the properties of the different algorithms, you can often rule out incorrect assignments quickly.
Note that the trees have different roots — i.e., the search algorithms started from different source nodes.

All images are screenshots from `aud.example.graph.TraversalExample` for the graph `another.graph`.
You can use that to create your own tasks and verify your solution.
(Be aware that trees are not necessarily unique.)

![image](/images/graph.png){: class="img-fluid mx-auto d-block" max-width: 33% }

Tree 1

![image](/images/spt_h.png){: class="img-fluid mx-auto d-block" max-width: 33% }

Tree 2

![image](/images/mst_a.png){: class="img-fluid mx-auto d-block" max-width: 33% }

Tree 3

![image](/images/spt_a.png){: class="img-fluid mx-auto d-block" max-width: 33% }

Tree 4

![image](/images/bfs_a.png){: class="img-fluid mx-auto d-block" max-width: 33% }

Tree 5

![image](/images/spt_d.png){: class="img-fluid mx-auto d-block" max-width: 33% }

Tree 6

![image](/images/mst_d.png){: class="img-fluid mx-auto d-block" max-width: 33% }

Tree 7

![image](/images/bfs_f.png){: class="img-fluid mx-auto d-block" max-width: 33% }

Tree 8

![image](/images/dfs_a.png){: class="img-fluid mx-auto d-block" max-width: 33% }

Tree 9

![image](/images/dfs_d.png){: class="img-fluid mx-auto d-block" max-width: 33% }

Tree 10

![image](/images/dfs_f.png){: class="img-fluid mx-auto d-block" max-width: 33% }

Tree 11

![image](/images/bfs_h.png){: class="img-fluid mx-auto d-block" max-width: 33% }

Tree 12

![image](/images/bfs_d.png){: class="img-fluid mx-auto d-block" max-width: 33% }

---

### q:{}

Which of the spanning trees are *shortest path trees (SPT)* from Dijkstra's algorithm?

- [X] Tree 1
- [ ] Tree 2
- [X] Tree 3
- [ ] Tree 4
- [X] Tree 5
- [ ] Tree 6
- [ ] Tree 7
- [ ] Tree 8
- [ ] Tree 9
- [ ] Tree 10
- [ ] Tree 11
- [ ] Tree 12

### q:{}

Which of the spanning trees are *minimum spanning trees (MST)* from Prim's algorithm?

- [ ] Tree 1
- [X] Tree 2
- [ ] Tree 3
- [ ] Tree 4
- [ ] Tree 5
- [X] Tree 6
- [ ] Tree 7
- [ ] Tree 8
- [ ] Tree 9
- [ ] Tree 10
- [ ] Tree 11
- [ ] Tree 12

### q:{}

Which are spanning trees from a *depth-first search (DFS)* in an unweighted graph?

- [ ] Tree 1
- [ ] Tree 2
- [ ] Tree 3
- [ ] Tree 4
- [ ] Tree 5
- [ ] Tree 6
- [ ] Tree 7
- [X] Tree 8
- [X] Tree 9
- [X] Tree 10
- [ ] Tree 11
- [ ] Tree 12

### q:{}

Which are spanning trees from a *breadth-first search (BFS)* in an unweighted graph?

- [ ] Tree 1
- [ ] Tree 2
- [ ] Tree 3
- [X] Tree 4
- [X] Tree 5 :: (This tree is also an SPT.)
- [X] Tree 6 :: (This tree is also an MST.)
- [X] Tree 7
- [ ] Tree 8
- [ ] Tree 9
- [ ] Tree 10
- [X] Tree 11
- [X] Tree 12

