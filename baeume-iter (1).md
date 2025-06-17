
---
title: Iterative Traversal of Trees
short_title: Iterative Traversal of Trees
kind: quiz
prefix: '022'
hidden: false
---

## Recursion and Iteration

We want to express *recursively* defined traversals (*preorder, inorder, postorder*) as **iterative** algorithms. We consider this problem as an example of how recursive algorithms can be transformed into iterative ones.

### q:{}

Why would we even *want* to do that?

- [ ] I don't want to, because the recursive algorithms are simpler. :: "Simpler" is true, but maybe you *have to*... (see below)
- [ ] I can't get along with recursion.
- [ ] Iterative algorithms are faster. :: That can be the case, but doesn't have to be. The difference is negligible for us!
- [X] Recursion can't always be applied. :: Unfortunately, that's true.
- [X] Java iterators for trees can't be implemented using recursive algorithms. :: This is an example of the statement above. At least, an *efficient* implementation (in the sense of *no overhead*) isn't possible with recursive functions.

      **Note:** Programming languages that support [coroutines] allow recursive implementations: from within a coroutine, return and re-entry is possible (enabled, of course, by a *stack*). But that's beyond the scope here.

[coroutines]: http://en.wikipedia.org/wiki/Coroutine

### q:{}

Great, now we can do iterators, but will we need this again?

- [X] Yes :: The algorithms for traversing graphs will look similar. In fact, many are similar to the *level-order* traversal. If you understand this chapter, things will be easier later.
- [ ] No

### q:{}

What does the following code snippet print?

```java
int n=6;
Stack<Integer> stack;
stack.push(n);
int x=1;
while (!stack.is_empty()) {
  int y=stack.pop();
  x*=y;
  if (y>1)
    stack.push(y-1);
}
System.out.println(x);
```

- [ ] `6`
- [ ] `12`
- [ ] `48`
- [ ] `612`
- [X] `720` :: The code calculates $n!=6!=720$.
- [ ] `3600`

### q:{}

What does the following code snippet print?

```java
int n=6;
int x=1;
while (n>0) {
  int y=n;
  x*=y;
  n=n-1;
}
System.out.println(x);
```

- [ ] `6`
- [ ] `12`
- [ ] `48`
- [ ] `612`
- [X] `720` :: This is also the factorial function: Here you can see what "tail recursion" means — the stack is unnecessary since only one entry is ever pushed and then immediately popped. Of course, you could simplify this code further.
- [ ] `3600`

## A Bit More

This chapter is not very suitable for quizzes: It's better if you look at the algorithms and walk through them with small examples. You can also find everything in the code examples. Then try, e.g., to write the *preorder traversal* yourself without looking at the code examples or the slides.

You can use the `VerboseStack` and `VerboseQueue` classes to see the state of the data structure after each operation.

### q:{}

The *postorder* traversal uses two stacks because

- [X] in addition to the next node ("What comes next?"), the state of the algorithm needs to be stored. :: This means: "Where do we continue?" in the sense of "from which of the recursive calls are we returning?"

      In practice, you would probably use *one* stack on which you store instances of a class with node and state as attributes. Since this is a bit verbose in Java, I opted for two stacks, which are used in "synchrony".
- [X] Two different recursive calls are needed. :: This leads to the situation described above (the "Where?" question).

### q:{}

This is not necessary for *preorder* traversal because

- [ ] the node is always printed before its children are processed.
- [X] there is effectively only one recursive call. :: The other is *tail-recursive* and either explicitly removed (version with two loops) or done via `push`/`pop` like in the factorial example above.

### q:{}

The *postorder* traversal can also be written using *one* stack, then

- [X] each entry must be a pair of node and a "label" (here an `int`). :: This would actually be more elegant but requires a separate class for the pair.
- [ ] node and "label" would have to be pushed and popped one after the other. :: Not entirely wrong, but that would mix two different types on the stack!

### q:{}

The *Towers of Hanoi* example uses recursion of the same type as the

- [ ] *preorder* traversal
- [X] *inorder* traversal :: If you've understood the recursive-to-iterative transformation for the example (i.e., the "type of recursion schema"), then you can easily transfer the algorithms.
- [ ] *postorder* traversal
- [ ] *level-order* traversal

### q:{}

The *level-order* traversal arises from...

- [X] the iterative implementation of the *preorder* traversal,
- [ ] the iterative implementation of the *inorder* traversal,
- [ ] the iterative implementation of the *postorder* traversal,
- [X] replacing `Stack` with `Queue`.
- [ ] reading the `Stack` in reverse. :: That’s nonsense.

## Outlook: A Bit Deeper and More Technical...

Function calls (and thus recursion) are actually implemented using a stack — for example, in the Java VM or in "machine language". We can illustrate this by reusing the *register machine* (from the *EinfInf* lecture) as a model.

Suppose we extend the machine with the following instructions: `LOADB` loads the accumulator into the instruction counter `b`. `LOADI` and `STOREI` behave like `LOAD` and `STORE` but read/write not register `i` directly, but the register whose index is in `i`. `PUSH` and `POP` place the accumulator on a stack or retrieve it from there.

**Note 1:** The register machine is not the ideal example and is a bit "clunky". But we already know it.

**Note 2:** The commands `PUSH`, `POP`, and `ST` operate on a stack that is "somehow" attached to the register machine. We could also assemble these commands from existing ones and store the stack in "regular" registers $C_i$. (This was done in an earlier version of the quiz. But it became quite messy. You're welcome to try it yourself!)

### q:{}

Which of the following statements is true?

- [X] `LOADB` is a jump instruction. :: Unlike `GOTO`, the jump target is not constant but read from the accumulator. (A better name for this instruction would be *JUMP* or *BRANCH*, but we stay consistent with `LOAD` and `STORE`.)
- [ ] `STOREI` and `LOADI` are defined only for convenience and are redundant. :: This functionality is actually missing. (It makes the register machine more similar to a "real" computer. *However*, the new instructions are not necessary in terms of *computability*, which is why we introduced the register machine!)
- [X] `STOREI` and `LOADI` allow *indirect addressing*. :: That is, *indirectly* via indices: you could say they allow addressing in a field or array.

### q:{}

What is happening here?

```basic
1 CLOAD 5
2 PUSH
3 CLOAD 100
4 LOADB
5 ...
...
100 ...
...
111 POP
112 LOADB
113 ...
```

- [ ] A function/subroutine starting at instruction `5` is called.
- [X] A function/subroutine starting at instruction `100` is called.
- [X] Upon finishing the function, it jumps to instruction `5`. :: That’s where it continues after the call.
- [ ] Upon finishing the function, it jumps to instruction `112`
- [X] Instruction at `113` is never reached. :: Because `112` is the return jump.

### q:{}

What is happening here?

```basic
 1 CLOAD 6
 2 STORE 1
 3 CLOAD 1
 4 STORE 2

 5 CLOAD 9
 6 PUSH
 7 CLOAD 10
 8 LOADB

 9 END

10 LOAD 1
11 IF c0=0 GOTO 21

12 MULT 2
13 STORE 2
14 LOAD 1
15 CSUB 1
16 STORE 1

17 CLOAD 21
18 PUSH
19 CLOAD 10
20 LOADB

21 POP
22 LOADB
```

- [X] The program computes $6!=720$ recursively and stores the result in register `2`.
- [X] The input is in register `1`, the output in register `2`.
- [X] Instructions 1–4 initialize the input (`c1`) and output (`c2`).
- [X] Instructions 5–8 call the factorial function.
- [X] The factorial function is implemented in instructions 10–22.
- [X] The recursive call occurs in instructions 17–20.

### q:{}

What is missing in the above program compared to a recursive Java implementation?

- [X] No local variables are used. :: This works here only because the factorial function is so simple!
- [X] Parameters (e.g., to the recursive call) are passed via a single "global" register. :: In fact, we can’t simulate argument passing and "declaring" local variables **on the stack** here. For that, we’d need to be able to address stack entries relative to the top. If you want to learn more about how function calls work on "real" computers, see [Wikipedia (EN/DE)][call stack].

[call stack]: http://en.wikipedia.org/wiki/Call_stack

{:comment
%%% Local Variables:
%%% ispell-local-dictionary: "de"
%%% coding: utf-8
%%% End:
}
