---
title: Dynamic Programming
short_title: Dynamic Programming
kind: quiz
prefix: '08'
hidden: false
---

## General

### q:{}

Dynamic programming refers to

- [ ] a form of memory management
- [ ] the description of dynamic systems :: The term [dynamic system] does exist, but it refers to something else.
- [ ] an extension of linear programming
- [X] a method for solving optimization problems
- [ ] a problem-solving method using a dynamic programming language :: There are languages sometimes called ["dynamic"]. Java is not one of them, and this has nothing to do with dynamic programming.

[dynamic system]: https://de.wikipedia.org/wiki/Dynamisches_System
["dynamic"]: https://de.wikipedia.org/wiki/Dynamische_Programmiersprache

### q:{}

The term *programming* in "dynamic programming" means

- [X] An optimization problem is being solved. :: The term is historical (from before computers existed!). Similar to [linear programming], it refers to a method of optimization.
- [ ] A recursive function is implemented as a loop ("programmed").

[linear programming]: https://de.wikipedia.org/wiki/Lineare_Optimierung

### q:{}

Which conditions must hold to apply dynamic programming?

- [ ] Divide-and-conquer is applicable. :: Here, sub-solutions do *not* overlap after "divide".
- [X] The solution consists of overlapping subproblems.
- [ ] The solution must be integer.
- [X] The optimal solution can be composed of optimal sub-solutions. :: This is the *principle of optimality*.
- [X] Subproblems must be enumerable. :: I.e., each subproblem can be characterized by a natural number or indices (tuples of natural numbers).
- [X] Subproblems must be efficiently solvable. :: That means simple decisions can be made — like choosing whether to pack an item in the *knapsack problem*.

### q:{}

What does it mean that a solution is *optimal*?

- [ ] There is a solution with lower cost.
- [X] There is no solution with lower cost. :: We assume costs are *minimized*. In other examples, e.g., profits are *maximized*.
- [ ] Every other solution has higher cost. :: The optimal solution does not have to be unique.

### q:{}

What are constraints in an optimization problem? Which statements are true?

- [ ] Constraints expand the search space.
- [X] Constraints limit the search space.
- [ ] Constraints must be integer. :: That’s nonsense.
- [ ] Constraints are complicated. :: Not necessarily: e.g., knapsack capacity is easy to imagine.
- [ ] Constraints are next to conditions.
- [X] Every feasible solution must satisfy the constraints. :: Otherwise, the knapsack breaks...

### q:{}

We can find an optimum by systematically enumerating *all* solutions. This is called

- [ ] Linear programming
- [ ] Quadratic programming :: That does [exist].
- [ ] Dynamic programming
- [ ] Exponential programming :: That doesn’t exist.
- [X] *brute force* method :: Or simply "search". It may not be elegant, but it can serve as a test to validate better implementations.

[exist]: https://de.wikipedia.org/wiki/Quadratisches_Programm

## Knapsack Problem

### q:{}

The knapsack problem is *not* solvable using dynamic programming if

- [ ] the profits are not integers
- [X] the weights are not integers :: We use a table indexed by all possible knapsack weights.

### q:{}

The *constraint* in the knapsack problem is

- [ ] the value of each item
- [ ] the weight of each item
- [ ] the maximum value of the knapsack
- [X] the maximum weight of the knapsack

### q:{}

Which function describes the recurrence for computing the max profit in the knapsack problem for the $k$-th item and total weight $g$?

- [X]  $egin{cases} p(k-1,g)&	ext{if } g_k>g\\
       \max\{p(k-1,g),\\phantom{\max\{}p(k-1,g-g_k)+w_k\}&	ext{otherwise}
       \end{cases}$
- [ ] Same with `p(k,g)` and `g_k<g`
- [ ] Same with `p(k+1,g)` and `g_k=g`

### q:{}

The number of possible solutions for the knapsack problem with $n$ items is

- [ ] $O(n)$
- [ ] $O(n^2)$
- [ ] $O(n^3)$
- [X] $O(2^n)$ :: The solution space grows *exponentially* with $n$.
- [ ] $O(n!)$

### q:{}

Using dynamic programming, the time complexity of solving the knapsack problem with $n$ items is

- [ ] $O(\log n)$
- [X] $O(n)$ :: If we include the capacity $C$, it's actually $O(C \cdot n)$.
- [ ] $O(n \log n)$
- [ ] $O(n^2)$
- [ ] $O(2^n)$

### q:{}

You're in a store with your backpack and your self-programmed instant app says “You could make a profit of €41.99.” What did you forget?

- [ ] 1 cent
- [ ] the store address (not a jeweler?)
- [X] Backtracking :: We want to remember *how* we achieved that solution — i.e., what to pack.
- [ ] Backpacking

### q:{}

The following problems are known from *Intro to CS*. They are not optimization problems, but dynamic programming can still be applied. Which one fits?

- [ ] Computing factorial $n!$
- [ ] Computing GCD $	ext{gcd}(m,n)$
- [X] Computing the $n$th Fibonacci number :: Recursive evaluation takes $O(2^n)$ — use iteration and memoization to get $O(n)$.
- [ ] Computing $m+n$
- [ ] Computing the digit sum of $n$

## An Interesting Example

Ever wondered how your *spell checker* suggests corrections for misspelled words? Look at the [Levenshtein distance]. It measures similarity by the minimal number of edits (insert, delete, substitute) needed. Dynamic programming can compute it.

[Levenshtein distance]: https://en.wikipedia.org/wiki/Levenshtein_distance

{:comment
%%% Local Variables:
%%% ispell-local-dictionary: "en"
%%% coding: utf-8
%%% End:
}
