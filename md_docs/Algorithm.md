# About the project and code design

## Project structure

We understand that ease in reading and maintenance of code is vital, and as such decided it was best to split the various functions into different files, each containing code relating to a particular class or type of task, so that code pertaining to a particular function would be much easier to find and debug. In the end, we ended up with the following source code files:

- **main.cpp:** for invoking various functions/objects defined in different files. All these functions/objects collectively complete the task.
- **logicProof.cpp** for the LogicProof class, which is our implementation of a logic proof object
- **proofLine.cpp** for the ProofLine class, which is our implementation of a proof line object, also building block of LogicProof object.
- **stack.cpp:** for the Stack class, which is our implementation of the Stack data structure
- **utils.cpp:**  for miscellaneous utility functions that didn't fit in any other category

Moreover, we created a header file corresponding to each cpp source file in their own directory, so that our source code directory does not get cluttered.

We also decided to use another directory for the output namely the `./build` directory.

`./md_docs` is a directory for markdown docs which provides doxygen to generate html files on the fly.

`./tests` is a directory for examples we used to test our algorithm.

Tree view of the project:

```
.
├── build
│   ├── logicProof.o
│   ├── main
│   ├── main.o
│   ├── proofLine.o
│   ├── stack.o
│   └── utils.o
├── Doxyfile
├── file.txt
├── include
│   ├── logicProof.h
│   ├── main.h
│   ├── proofLine.h
│   ├── stack.h
│   └── utils.h
├── LICENSE
├── Makefile
├── md_docs
│   ├── Algorithm.md
│   ├── Code design.md
│   └── Main.md
├── runTests.sh
├── src
│   ├── logicProof.cpp
│   ├── main.cpp
│   ├── proofLine.cpp
│   ├── stack.cpp
│   └── utils.cpp
└── tests
    ├── test10VALID.txt
    ├── test1VALID.txt
    ├── test2VALID.txt
    ├── test3VALID.txt
    ├── test4VALID.txt
    ├── test5VALID.txt
    ├── test6INVALID.txt
    ├── test7INVALID.txt
    ├── test8VALID.txt
    └── test9INVALID.txt
```

## Code design

To make checking validity of logical proofs as simple as possible, we have defined two classes which hold and manage the data contained within the proof. These are:

1. The ProofLine class, which holds a particular line of the proof. It has different parameters for holding the formula on that line, the rule that was used to get this formula, and up to two line numbers referenced by that rule, such as the line number containing the formula to which an OR was introduced, for the OR Introduction rule.
2. The LogicProof class, which has an array of pointers to ProofLine objects that represent each line of the proof, as well as additional helpful properties like the length of the proof.

Our algorithm for figuring out the validity of a logic proof is quite straightforward. Given a proof, we iterate through every line in order, checking its validity. If any line is determined to be invalid, the iteration is halted there and "false" is returned; otherwise, if we reach the end of the proof and every line was valid, "true" is returned instead.

Checking the validity of each individual line, too, is quite simple. As instructed, the formula in each line is assumed to be valid and well parenthesized, so the only thing to check is for the correct usage of the rules of natural deduction. For any line, we start by checking the rule used for it, with a master `switch` statement (which we preferred over a chain of `if-else` statements as it is faster for matching one value from a set of values, and makes adding more rules down the line simpler as well). If the line is a premise, it is assumed to be valid by default; otherwise, for all other (known) rules we ensure the rule was utilized correctly. If the rule is unknown, it is assumed to be invalid.

For every rule we do some basic preliminary checks, such as:

- making sure the correct operator was added to the formula at the correct position for introduction rules
- making sure the correct operator was removed from the formula from the correct position for elimination rules
- making sure any line numbers referenced by the rule are positive and occur before the current line

and so on.

Once the preliminary checks are done, we check for the exact specifics of the given rule using `if` conditions, such as making sure both sides of an AND in an AND Introduction line exactly match the formulae on the line numbers given, making sure the left (right) side of the current line matches the line referenced for OR Introduction 1 (2), etc.

For the purposes of getting the left and right sides of a formula which are joined together by an AND or OR operator, we make use of conversion to and from the prefix mode of writing formulae, as it is much easier to check and remove the operator with the least priority of a prefix expression, since that operator is always the first character of the formula. We have implemented a Stack of Strings to aid with this conversion.

## Extending it for other rules

As we have made our code as modular as possible, extending it to include more rules shouldn't be extremely difficult, though some changes will need to be made to the structure of the ProofLine class.

In particular, the class would need to support referencing not just individual line numbers, but also ranges of lines (like [3-6]) which are needed by rules such as OR Elimination, as well as support for referencing up to three lines/line ranges instead of the current two.

Moreover, a way to identify every scope uniquely would be needed, to make sure formulae aren't used from lines that are out of the current scope. One way of achieving the same would be a new class member that's a hashmap from integers to integers, where the keys represent all the levels of nested scope the line is in, and the value they map to uniquely identifies this scope among all other scopes in the same parent. For example, if there is one level 1 scope in the proof, which has two level 2 scopes in it, the hashmaps of the two inner scopes would read `1:1, 2:1` and `1:1, 2:2` respectively (where the first element signifies that we're in the first level 1 scope of the proof, and the second element signifies the first and second level 2 scopes inside this scope, respectively)

Once these two additions have been made, adding support for more rules of natural deduction should be as simple as adding more cases to the `switch` statement that checks for which rule was used, and adding the necessary condition checks via `if` statements inside the respective rules.
