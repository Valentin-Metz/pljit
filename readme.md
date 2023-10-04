# PL/0 JIT-compiler

This is a C++ JIT-compiler for the [PL/0](https://en.wikipedia.org/wiki/PL/0) programming language.

### Includes:

- Lexer (with error checking)
- Parse tree for semantic analysis
- Abstract syntax tree with dead code elimination and constant folding

### Usage:

```bash
./pljit <source_file> <argument_0> <argument_1> ...
```

Example program:

```pl/0
PARAM width, height, depth;
VAR volume;
CONST density = 2400;
BEGIN
volume := width * height * depth;
RETURN density * volume
END.
```

Another example:

```pl/0
PARAM leet, notLeetButOk;
VAR leetAgain;
CONST alsoLeet = 1337;
BEGIN
leetAgain := leet + alsoLeet + 1337 + leet;
RETURN leetAgain * 1337 / leet / ( notLeetButOk - (2 - 3))
END.
```
