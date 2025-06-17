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

A node without children is called

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
- [X] that are connected by edges, and in which no node appears twice.
- [ ] that are connected to the root via edges.

### q:{}

There is a *unique* path to the root for every node in the tree.

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

You can learn more from the examples in the comments. Take a look at the code.

### q:{}

The class `aud.BinaryTree<T>` stores

- [X] a reference to the left and right child :: Access via `getLeft()` and `getRight()`
- [X] a reference to the parent node :: Access via `getParent()`; often the "backward reference" is **missing**, as it is not needed in many algorithms.
- [X] a reference to an arbitrary datum of type `T` :: We use this to distinguish nodes or to represent operators and terminals in "computation trees". In the next chapter on *search trees*, the "payload data" will be stored there. (That is, we continue using the `BinaryTree` class.)

### q:{}

The class `aud.BinaryTree<T>` represents

- [X] a single node.
- [X] a subtree. :: That is, the node and all children (and their children, and their children's children,... using `getParent()` we can get back to the [fathers and their fa...][lob] you know what's coming ;-) ).

      This is actually important and *different* from the list: there we "hid" the node class `Node`. For the tree, that's not appropriate, since many algorithms work directly with nodes and subtrees. That also applies to methods of `BinaryTree`: the second constructor composes a tree, `setLeft` and `setRight` modify the tree.

[lob]: http://montypython.50webs.com/scripts/Life_of_Brian/10.htm

### q:{}

The following expression tests whether

```java
BinaryTree<String> node=...;
// ... setup tree ...

node.getParent()!=null && node.getParent().getParent()==null
```

- [ ] `node` might be the root.
- [X] `node` is a node at level 1.
- [ ] `node` is an internal node.
- [ ] `node` is an external node.

### q:{}

The linking of nodes in `BinaryTree` is

- [ ] similar to `Vector` :: There's no linking there.
- [ ] similar to `SList` :: Not here, since we also store a reference to the parent node. (This is often not needed, but quite practical.)
- [X] similar to `DList` :: Because each node holds references to its children **and** its parent.

### q:{}

What holds after executing the code fragment?

```java
BinaryTree<String> node=...;
BinaryTree<String> y=...;

// ... setup trees ...

BinaryTree<String> x=node.setLeft(y);
```

- [X] `x` contains the (former) left subtree of `node`.
- [X] `x` is a root. :: The former left subtree of `node` was "detached", so there's no meaningful parent node for `x` anymore, i.e., `parent_` was set to `null` by `setLeft`.
- [ ] The left subtree of `node` is `x`.
- [X] The left subtree of `node` is `y`.
- [ ] `node` is the parent of `x`.
- [X] The right child of `node` remains unchanged.

### q:{}

What does `y.getParent()` return after the code fragment above is executed?

- [ ] `null`
- [ ] `x`
- [X] `node` :: Because `node.setLeft(y)` sets `parent_` in `y`, i.e., it changes the state of both `node` and `y`!
- [ ] That’s unclear and not evident from the code.

### q:{}

What holds after executing the code fragment? Does this work?

```java
BinaryTree<String> node=...;
// ... setup tree ...

BinaryTree<String> x=node.setLeft(null);
```

- [X] `x` contains the (former) left subtree of `node`.
- [X] `x` is a root. :: The former left subtree of `node` was "detached", so there's no meaningful parent node for `x` anymore, i.e., `parent_` was set to `null` by `setLeft`.
- [X] The left subtree of `node` is empty. :: Because we set it to `null`, and we always use this reference to indicate that a part does not exist.
- [ ] The code fails because `setLeft` cannot be called with `null`!
- [X] The right child of `node` remains unchanged.

### q:{}

What holds after executing the code fragment? Does this work?

```java
BinaryTree<String> node=...;
// ... setup tree ...

BinaryTree<String> x=node.getLeft();
x=node.setRight(x);
```

- [X] `node` no longer represents a binary tree. :: If you draw the result, you'll see it immediately. No node can appear multiple times in a tree — e.g., be both left and right child! That makes the result nonsensical. **Warning:** Such errors can occur and are often hard to find! (See also the note below.)
- [ ] The code crashes. :: Unfortunately not, at least not in the current implementation.

      One way to avoid this situation would be for `setLeft(x)` and `setRight(x)` to throw an exception if `x` is not a root — meaning I can only insert children that are not already part of another tree.

      The current implementation will automatically "detach" `x` from its tree if needed. This can be convenient but allows for the kind of error mentioned above.

## Insert: "Computation Trees"

We consider "computation trees" as an example. These are *syntax trees* for terms like sums and products. We can represent terms as trees, evaluate them recursively, and output the term again. Output can happen in various ways: standard *infix* notation or *prefix* or *postfix* notation. This will lead us to traversing trees. Finally, we will look at how the syntax tree for a term can be constructed algorithmically.

### q:{}

In *syntax trees* for terms

- [X] operators are in the *inner* nodes.
- [ ] operators are in the leaves.
- [ ] constants are in the *inner* nodes.
- [X] constants are in the leaves.

### q:{}

This means for the implementation:

- [X] We need a common *base class* for operators and constants. :: In the examples, this is the class `AtomicExpression`, and all nodes are of type `BinaryTree<AtomicExpression>` (at least subclasses, since we extend this class further in `ExpressionTree`, the actual node class).
- [ ] We have two different types of nodes.
- [X] Each operator is represented by its own class. :: This class overrides the method `getValue()`, which evaluates the operator — e.g., `Plus` computes "`left+right`", and `Times` computes "`left*right`".
