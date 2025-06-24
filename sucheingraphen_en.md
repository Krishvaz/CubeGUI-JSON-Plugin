---
title: Search Trees
short_title: Search Trees
kind: quiz
prefix: '03'
hidden: false
---

## Introduction

An ideal quiz on search trees would include many sketches of trees
that you could then match to the correct answers... However, you can generate as many and (almost)
as complex trees yourself, search in them, insert, delete, and e.g., rotate. Just start the example
`aud.example.BinarySearchTreeExample` as shown in the lecture. *Have fun experimenting!*

### q:{}

I find the maximum value in a search tree by

- [X] descending as far right as possible. :: Conversely, for the minimum, go left.
- [ ] descending as far left as possible.

### q:{}

To output the entries in a binary search tree as a sorted sequence, I use

- [ ] a *Preorder* traversal.
- [X] an *Inorder* traversal.
- [ ] a *Postorder* traversal.
- [ ] a *Level-order* traversal.

### q:{}

We want to implement a *range iterator*. This is an
iterator that enumerates a specific value range ("from ... to") in a
search tree in sorted order. This range is defined by references `from` and `to` to nodes. :P: Is it possible to traverse the
range from `from` to `to` *inorder*, without using recursion
or a stack?

- [X] Yes :: In the *search tree*, we use the keys to decide which
      node to visit next. *Can you design an algorithm for this?* (You’ll find a solution as the method
      `next()` in the class `BinarySeachTree::Node`. This method is
      then called by `BinarySearchTree::RangeIterator::next()`.)

      **Hint:** At this point, we need the ability to move from
      a node to its parent. In the
      implementation, this is `getParent()` or a corresponding
      (additional) upward link.
- [ ] No :: In a general binary tree, this is not
      possible. In a binary *search tree*, however, we know more: we
      can use the keys to decide which
      node to visit next.

### q:{}

The method `BinarySeachTree::Node::next()` relies on a property of the implementation of `BinaryTree`. Which?

- [ ] Do I need to check the examples now? :: Of course not, you
      can also design your own examples. You should understand at least one of them.
- [X] It requires `getParent()`, i.e., the ability to move to
      the parent node. :: The class `BinaryTree` stores
      a reference to the parent node. Therefore, this simple
      implementation of `next()` is possible. Often this
      reference is omitted; then it becomes more complicated. (Then we need a stack for a `RangeIterator`.)
- [ ] It requires the already defined `InorderIterator`.
- [ ] It requires helper nodes (*dummy nodes*).

### q:{}

In the examples, methods for searching for a value, the
minimum, etc., return a so-called `Cursor`. What is the purpose of the `Cursor` class?

- [X] It helps to hide the implementation of nodes.
- [X] It refers to a node without exposing all methods
      of the node. :: Those are meant to remain "private".
      Read access to the key (which must not be changed), and
      read/write access to the data is enabled.

### q:{}

The class `BinarySearchTree` uses a helper node
`head`. What are the properties of `head`?

- [X] `head` is always the root. :: That’s what we want: this
      way there is always a root, we never insert into an "empty"
      (non-existent) tree, and the root is never deleted. So we avoid special cases.
- [X] The key in `head` is smaller than all possible
      keys. :: We achieve this by letting `head` be the
      *only* node with a `null` entry as key. This
      special case is handled in the helper method
      `BinarySearchTree::compareKeys`, *before* the general
      method `compareTo` from the `Comparable` interface
      is called.
- [ ] The key in `head` is greater than all possible keys.

## Balanced Search Trees

### q:{}

Which size determines the cost of a search?

- [ ] the number of entries in the tree
- [ ] the width of the tree
- [X] the height of the tree

### q:{}

Which size determines the cost of inserting an
entry?

- [ ] the number of entries in the tree
- [ ] the width of the tree
- [X] the height of the tree :: Because the insertion position
      must be found first.

### q:{}

What height can a binary search tree have after inserting $n$ entries at most?

- [ ] $\log_2 n$
- [ ] $\sqrt{n}$
- [X] $n$ :: In the worst case, the tree degenerates into a
      list.
- [ ] $n \log_2 n$
- [ ] $n^2$

### q:{}

What operations can locally "balance" a binary search tree?

- [ ] Translations
- [X] Rotations
- [ ] Reflections

### q:{}

How can the effect of these operations for nodes `a,b,c` be imagined (or remembered)? Here `b` is the parent of `c` and `a` the parent of `b`.

- [ ] Construct a new tree as a *preorder* traversal of `a,b,c` and
      "attach" it to the tree at the new root.
- [X] Construct a new tree as an *inorder* traversal of `a,b,c` and
      "attach" it to the tree at the new root. :: Because
      *inorder* ensures the key order remains sorted.
- [ ] Construct a new tree as a *postorder* traversal of `a,b,c` and
      "attach" it to the tree at the new root.
- [ ] Construct a new tree as a *level-order* traversal of `a,b,c`
      and "attach" it to the tree at the new root.

...

### q:{}

The AVL property states that the left and right subtrees
may differ in height by at most 1. This property holds

- [ ] only at the root
- [X] at every node :: That is, for every subtree.
- [ ] only at the leaves

### q:{}

How many entries does an AVL tree of height $h$ contain in asymptotic terms?

- [ ] $O(\log h)$
- [ ] $O(h^2)$
- [X] $O(2^h)$ :: That is, a tree with $n$ entries has a height
      of $O(\log n)$.

### q:{}

How many entries does a red-black tree of height $h$ contain in asymptotic terms?

- [ ] $O(\log h)$
- [ ] $O(h^2)$
- [X] $O(2^h)$ :: That is, a tree with $n$ entries has a height
      of $O(\log n)$.

### q:{}

The restructuring of an AVL tree is done

- [ ] *top-down*
- [X] *bottom-up* :: We must go from the insertion position ("bottom") back to the root and rotate
      if at any node along this path the AVL property
      is violated.
- [ ] either *top-down* or *bottom-up*

### q:{}

The restructuring of a red-black tree is done

- [ ] *top-down*
- [ ] *bottom-up*
- [X] either *top-down* or *bottom-up* :: In the
      lecture we only covered *bottom-up*. In practice,
      both work similarly to 2-3-4 trees. (For these
      we saw *top-down* and *bottom-up splits*.)

### q:{}

The restructuring of 2-3-4 trees is done

- [ ] by rotations
- [ ] by *tri-node restructuring*
- [X] by *splits* :: Splitting involves moving an entry
      up and merging with the parent node (*merge*).

### q:{}

Which trees "grow at the root"?

- [ ] AVL trees
- [ ] Red-black trees
- [X] 2-3-4 trees
- [X] B-trees

### q:{}

Red-black trees are isomorphic to

- [ ] AVL trees
- [X] 2-3-4 trees :: That is, one can be mapped to the other.
- [ ] B-trees

### q:{}

When inserting into a red-black tree, what color does the new
entry have (*before* any restructuring)?

- [X] red
- [ ] black

### q:{}

When does restructuring need to occur in a red-black tree?

- [X] when the parent of the new node is red :: Because we’ve inserted a
      red node. With a red parent, this creates a
      "forbidden" red-red configuration.
- [ ] when the parent of the new node is black
- [ ] when the "uncle" of the new node is red
- [ ] when the "uncle" of the new node is black

### q:{}

When is a rotation (single or double) done in a red-black tree?

- [ ] when the "uncle" of the new node is red
- [X] when the "uncle" of the new node is black

### q:{}

What if the "uncle" node doesn’t exist?

- [ ] Assume: red
- [X] Assume: black :: These are the black "helper nodes" as
      leaves. We imagine them and then assume
      they’re black.
- [ ] Then restructuring must always occur.
- [ ] Then restructuring is never needed.

### q:{}

Which restructuring operation in a red-black tree requires recursive ascent?

- [ ] Single rotation
- [ ] Double rotation
- [X] Recoloring :: When recoloring (since parent and uncle are both red), the
      grandparent is recolored red. This may cause a new red-red configuration
      higher up the tree (grandparent and great-grandparent).

### q:{}

How long do we need to ascend recursively during restructuring in a red-black tree?

- [ ] until the "uncle" node is red
- [ ] until the "uncle" node is black
- [X] until there is no more red-red situation

### q:{}

What additional rule must be followed during restructuring?

- [ ] All leaves are black. :: This is ensured by the (imaginary)
      helper nodes.
- [ ] The root is red.
- [X] The root is black. :: A red root due to recoloring
      is simply recolored black. This is important because otherwise
      unnecessary red-red configurations would arise.

### q:{}

AVL trees are better balanced, i.e., with the same number of entries usually (at least in the worst case) lower than
red-black trees.

- [X] Yes :: For $n$ entries, the height of a
      red-black tree is roughly $\leq 2 \log_2 n$, while that of an AVL tree
      is $\leq 1.44 \log_2 n$. So the red-black tree is over a
      third — i.e., a *constant* factor — taller.
- [ ] No

### q:{}

Operations on AVL trees can be executed "faster".

- [ ] Yes
- [X] No :: This is only true in practice for search, which benefits directly
      from the lower height.

      For insertion and deletion, better balance
      comes at the cost of a stricter balancing criterion
      compared to red-black trees. (In fact, every AVL tree
      is also a red-black tree, but not vice versa.) This means *more work*
      during rebalancing. More rotations or local restructurings
      are required, which of course also take time.

      The statement is therefore only valid if we build the AVL tree once
      and then change it very little, mainly searching in it.
      That may be valid for specific applications, but in general,
      we should not assume this.

      This is a major reason why red-black trees are preferred in practice.

### q:{}

Which are binary trees?

- [X] AVL tree
- [ ] 2-3-4 tree
- [X] Red-black tree
- [ ] 2-3 tree :: as a special case of B-trees
- [ ] B-tree

### q:{}

Why is a B-tree particularly suitable when the tree is stored
on external storage?

- [X] Reading and writing is done in large blocks :: Usually a
      block size that the OS also uses for external storage.
- [X] The number of read/write accesses is minimized.
- [X] There are relatively few nodes. :: Therefore fewer
      potential positions in external storage need to be addressed and
      "accessed". Each node holds more data.
- [ ] B-trees grow very slowly in height. :: That’s true, but
      not relevant here.

### q:{}

B-trees usually require more memory for the same data compared to
AVL or red-black trees.

- [X] Yes :: Because the nodes are chosen to be "large" (high branching factor),
      but only need to be half full. So we may reserve
      unused space for future operations.
- [ ] No

### q:{}

When inserting into a B-tree with up to $2m$ entries (keys)
per node, how many keys are moved on average?

- [ ] none
- [ ] $2$
- [ ] $m$
- [ ] $\frac{3}{2}m$
- [X] $\frac{3}{4}m$ :: The new key must be inserted into the existing
      sorted list of keys (an array). Each node (except the root) holds at least $m$
      keys, so on average $\frac{3}{2}m$ keys. On average, half
      of them must be moved during insertion.
- [ ] $2m$

### q:{}

This shifting during insertion (above) happens in

- [X] internal memory :: e.g., in RAM, even if the nodes are held on
      disk. That’s why it’s relatively fast. Entire blocks are read and written.
- [ ] external memory

### q:{}

For $m=32$, a B-tree of height 3 contains at least how many
entries?

- [X] $2,177$ :: The root has one entry and two children.
    Each of the two subtrees has at least $32$ entries and at least
    $33$ children each with at least $32$ entries.
    That is $1+2\cdot (32+33\cdot 32)=2,177$.
- [ ] $32,737$
- [ ] $2,147,483,648$
- [ ] $4,294,967,296$

### q:{}

What is the *maximum* height of a B-tree with $m=32$ if it contains
$1,000,000,000,000 = 10^{12}$ entries?

- [ ] 2
- [ ] 4
- [X] 8 :: Because $\log_{32} 10^{12} \approx 7.97$

      Estimate: $\log_2 10^{12} \approx 40$, since
      $2^9<1000<2^{10}$ so $\log_2 1000 \approx 10$ and
      $10^{12}=1000^4\approx{}2^{40}$. With $32=2^5$ this gives
      approximately $\tfrac{40}{5}=8$.
- [ ] 12
- [ ] 16

### q:{}

For which trees does a *cursor* (or *iterator*) remain valid
when a new node is inserted?

- [X] AVL tree :: A *cursor* must refer to a node since
      it stores, for example, the result of a search. (An *iterator*
      must also hold at least a reference to the current node.)

      An AVL tree is a binary tree, i.e., there is only one type
      of node with a key, and each key stays with
      "its" node. Even with rotations or balance bookkeeping, the reference remains valid. Also, the inorder order doesn’t change (iterator!).

      This may seem obvious, but it’s not!
      See 2-3-4 and B-trees.
- [ ] 2-3-4 tree :: A *cursor* must refer to a node (see above).
      It may also need to remember the index
      of the key in the node (especially for iterators).

      In 2-3-4 trees, the shape or type of
      nodes can change, and keys may not remain
      in their original node. So with *split & merge*, the reference may become invalid or point to the wrong
      node.

      This property is important: Inserting
      now causes a side effect! As a user, I must know this!
      As a developer of a 2-3-4 tree, I must document this!
      Note: If I use constructs like a *cursor*, I can no longer
      simply replace an AVL tree implementation of the ADT Set
      with a 2-3-4 tree one. The insertion semantics are different!
      Even if the difference is "just" subtle!

- [X] Red-black tree :: Same argument as for AVL tree.
- [ ] B-tree :: Same argument as for 2-3-4 tree.

### q:{}

A *splay tree* changes

- [ ] only on search
- [ ] only on insertion
- [X] on both insertion and search :: Because the searched entry is rotated to the root. Frequently accessed entries thus move closer to the root.

### q:{}

Which tree is also suitable for data compression?

- [ ] AVL tree
- [ ] 2-3-4 tree
- [ ] Red-black tree
- [ ] B-tree
- [ ] *splay tree*
- [X] *trie* :: An interesting example, also discussed in the
      *Image Processing* lecture, is [Huffman coding](http://en.wikipedia.org/wiki/Huffman_coding):
      The binary tree used is a *trie* over the binary alphabet {0,1}.
      During construction, the relative frequencies of characters
      are stored in the nodes so that the most common characters (from the "text alphabet")
      are reached via the shortest paths in the *trie*, i.e., encoded
      with as few bits {0,1} as possible.
