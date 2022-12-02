# Code design/Project structure

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