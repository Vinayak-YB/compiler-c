# COMPILER - C 

A compiler is a program that translates source code written in a high level language into low level language then can be executed by a computer,

### LEXER -> PARSER -> CODE GENERATOR 

- Lexer : A lexer breaks down input source code into tokens. Tokens are the smallest unit in a source code. 
    Tokens examples 
        > Keywords : if, for, return 
        > Identifiers : x, y, myfunction
        > Operators : +, -, *
        > Symbols : {,}, ;

    Example : 
                (Input) int a = 5; 
                (Output) Token 1 - int {keyword}
                         Token 2 - a {identifier}
                         Token 3 - = {operator}
                         Token 4 - 5 {literal}
                         Token 5 - ; {Symbol}

- Parser : (Syntax Analyser) The parser takes the tokens from the lexer and organizes them into a syntax tree (or parse tree) based on grammar of the programming language. 

    Example : 
                (Input) int a = 5;
                (Output) Declaration:
                            - Type: int
                            - Variable: a
                            - Value: 5
                If the input is invalid eg. int 10 = a; then the parser will raise a syntax error

- Code Generator : The code generator converts the syntax tree or intermediate representation (IR) into the target machine code or assembly code.

    Example : 
                (Input) Syntax tree 
                (Output) mov eax, 10;
                         mov [a], eax

There are other stages in a full compiler like Semantic Analyser, Intermediate Representation, Optimizer, Assembler and Linker.

## TEST 

In test file (test.unn) we start with a simple task of parsing a statement.

`exit(1);` *idea exiting with an error code*

So here we have a keyword "exit", separator "()", literal "1" and a separator ";".

