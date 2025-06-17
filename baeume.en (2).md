---
title: Trees
short_title: Trees
kind: quiz
prefix: '021'
hidden: false
---

## Introduction

### q:{}

A node without a parent is called

- [ ] leaf
- [ ] internal node
- [X] root

### q:{}

A node without child nodes is called

- [X] leaf
- [ ] internal node
- [ ] root

### q:{}

A node with one or more children is called

- [ ] leaf
- [X] internal node
- [ ] root

### q:{}

The height $h$ of a *complete* binary tree with $n$ nodes is

- [ ] $2^n-1$
- [X] $\log _2 (n+1)$ :: Because $n$ can be represented as $n=2^h-1$ depending on the height $h$.
- [ ] $n^2$

### q:{}

A *path* is a sequence of nodes

- [ ] that are connected by edges.
- [X] that are connected by edges and in which no node appears more than once.
- [ ] that are connected to the root via edges.

### q:{}

For every node in the tree, there is a *unique* path to the root.

- [X] Yes
- [ ] No

### q:{}

A (e.g., linked) list is a tree.

- [X] Yes :: Here, `head` is the root, each node has exactly one child except the "last" node (the only leaf).
- [ ] No

### q:{}

A tree is a (e.g., linked) list.

- [ ] Yes
- [X] No

### q:{}

The $k$-th level (starting from 0) of an $n$-ary tree contains at most how many nodes?

- [ ] $n$
- [ ] $n\cdot{}k$
- [ ] $n \log k$
- [X] $n^k$

## Implementation: Example Binary Trees

You can learn more from the examples in the comments. Look at the code.

### q:{}

The class `aud.BinaryTree<T>` stores

- [X] one reference to the left and right child :: Access via `getLeft()` and `getRight()`
- [X] a reference to the parent node :: Access via `getParent()`; often the "backward reference" is **missing**, as it is not needed in many algorithms.
- [X] a reference to arbitrary data of type `T` :: We use this to distinguish nodes or represent operators and terminals in "computation trees." In the next chapter on *search trees*, this field holds the "payload." (That is, we continue using the `BinaryTree` class.)

### q:{}

The class `aud.BinaryTree<T>` represents

- [X] a single node.
- [X] a subtree. :: That is, the node and all children (and their children and their children’s children... using `getParent()` we can go back to the [fathers and their fa...][lob] you know what’s next ;-) ).

      This is actually important and *different* from lists: there we "hid" the `Node` class. For trees, this isn’t suitable because many algorithms directly work with nodes and subtrees. The same applies to the methods in `BinaryTree`: the second constructor composes a tree, `setLeft` and `setRight` modify it.

[lob]: http://montypython.50webs.com/scripts/Life_of_Brian/10.htm

### q:{}

The following expression tests whether

```java
BinaryTree<String> node=...;
// ... setup tree ...

node.getParent()!=null && node.getParent().getParent()==null
