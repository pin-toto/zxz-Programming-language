```markdown
# ZXZ Programming Language Documentation

**Version:** 3.0  
**Created:** 2026  
**Author:** pintoto  
**Language:** C  
**GitHub:** [https://github.com/pin-toto/zxz-Programming-language/tree/main](https://github.com/pin-toto/zxz-Programming-language/tree/main)

---

## Table of Contents
1. [Introduction](#introduction)
2. [Installation](#installation)
3. [Basic Syntax](#basic-syntax)
4. [Print Statements](#print-statements)
5. [Expressions and Operators](#expressions-and-operators)
6. [Matrix Operations](#matrix-operations)
7. [Trigonometric Functions](#trigonometric-functions)
8. [Comments](#comments)
9. [Examples](#examples)
10. [Error Handling](#error-handling)
11. [Command Line Interface](#command-line-interface)

---

## Introduction

ZXZ is a minimal, interpreted programming language designed for simplicity and ease of use. Built with C, it provides a clean syntax for output operations, mathematical expressions, matrix operations, and trigonometric functions. The language is perfect for beginners learning programming concepts, mathematical computations, or for quick scripting tasks.

### Key Features
- Simple and readable syntax
- Built-in expression evaluation with operator precedence
- Matrix operations (addition, subtraction, multiplication)
- Trigonometric functions (sin, cos, tan)
- String and numeric output support
- Comment support for code documentation
- Lightweight and fast interpretation

---

## Installation

### Prerequisites
- C compiler (GCC recommended)
- Make (optional)
- Math library (libm)

### Building from Source
```bash
git clone https://github.com/pin-toto/zxz-Programming-language.git
cd zxz-Programming-language
gcc -o zxzrun interpreter.c -lm
```

### Running Programs
```bash
./zxzrun <filename.zxz>
```

---

## Basic Syntax

### Program Structure
Every ZXZ program must follow this structure:
```
start zxz;
    // Your code here
zxz end;
```

### Example Program
```
start zxz;
    zxz.cout/"Hello, World!"/;
zxz end;
```

### Syntax Rules
- Statements end with a semicolon (`;`)
- The `start zxz;` and `zxz end;` keywords mark the program boundaries
- Whitespace is generally ignored (except in strings)
- The language is case-sensitive

---

## Print Statements

### Outputting Text
Use the `zxz.cout/` command followed by a string in double quotes:
```
zxz.cout/"Your text here"/;
```

### Outputting Numbers and Expressions
You can output mathematical expressions directly:
```
zxz.cout/2 + 3/;
zxz.cout/5 * 4 - 2/;
zxz.cout/(2 + 3) * 4/;
```

### Print Syntax Rules
- Format: `zxz.cout/<content>/;`
- For strings: content must be enclosed in double quotes (`"`)
- For expressions: content is evaluated before printing
- The ending `/;` is mandatory

---

## Expressions and Operators

### Supported Operators
| Operator | Description | Example |
|----------|-------------|---------|
| `+` | Addition | `5 + 3` |
| `-` | Subtraction | `10 - 4` |
| `*` | Multiplication | `6 * 7` |
| `/` | Division | `15 / 3` |
| `#` | Division (alternative) | `15 # 3` |
| `**` | Exponentiation | `2 ** 3` |

### Operator Precedence
1. Parentheses `()`
2. Exponentiation `**` (right-to-left)
3. Multiplication `*` and Division `/` (left-to-right)
4. Addition `+` and Subtraction `-` (left-to-right)

### Expression Examples
```
zxz.cout/2 + 3 * 4/;           // Outputs: 14
zxz.cout/(2 + 3) * 4/;         // Outputs: 20
zxz.cout/10 / 2 + 3/;          // Outputs: 8
zxz.cout/2 ** 3/;              // Outputs: 8
zxz.cout/2 ** 3 + 1/;          // Outputs: 9
zxz.cout/(2 + 3) ** 2/;        // Outputs: 25
zxz.cout/10 # 2/;              // Outputs: 5 (using # as division)
```

### Floating Point Support
ZXZ handles floating-point numbers and will output integers without decimal places:
```
zxz.cout/5.5 + 2.5/;           // Outputs: 8
zxz.cout/10 / 3/;              // Outputs: 3.3333333333
zxz.cout/2.5 * 4/;             // Outputs: 10
```

---

## Matrix Operations

ZXZ supports matrix operations including addition, subtraction, and multiplication.

### Matrix Syntax
Matrices are defined using nested square brackets:
- `[[1,2],[3,4]]` represents a 2x2 matrix
- `[[1,2,3],[4,5,6]]` represents a 2x3 matrix
- `[[1,2],[3,4],[5,6]]` represents a 3x2 matrix

### Matrix Operators
| Operator | Description | Example |
|----------|-------------|---------|
| `+` | Matrix Addition | `[[1,2],[3,4]] + [[5,6],[7,8]]` |
| `-` | Matrix Subtraction | `[[10,20],[30,40]] - [[5,5],[5,5]]` |
| `*` | Matrix Multiplication | `[[1,2],[3,4]] * [[5,6],[7,8]]` |

### Matrix Rules
- **Addition/Subtraction:** Matrices must have the same dimensions
- **Multiplication:** Number of columns in first matrix must equal number of rows in second matrix
- Results are automatically displayed as matrices

### Matrix Examples
```zxz
:. Matrix Addition (2x2 + 2x2)
zxz.cout/[[1,2],[3,4]] + [[5,6],[7,8]]/;
:. Output: [[6,8],[10,12]]

:. Matrix Subtraction (2x2 - 2x2)
zxz.cout/[[10,20],[30,40]] - [[5,5],[5,5]]/;
:. Output: [[5,15],[25,35]]

:. Matrix Multiplication (2x2 * 2x2)
zxz.cout/[[1,2],[3,4]] * [[5,6],[7,8]]/;
:. Output: [[19,22],[43,50]]

:. Matrix Multiplication (2x3 * 3x2)
zxz.cout/[[1,2,3],[4,5,6]] * [[7,8],[9,10],[11,12]]/;
:. Output: [[58,64],[139,154]]

:. Single Element Matrix
zxz.cout/[[42]]/;
:. Output: [[42]]
```

---

## Trigonometric Functions

ZXZ supports basic trigonometric functions using radians.

### Supported Functions
| Function | Description | Example |
|----------|-------------|---------|
| `sin(x)` | Sine of x (radians) | `sin(3.14159)` |
| `cos(x)` | Cosine of x (radians) | `cos(3.14159)` |
| `tan(x)` | Tangent of x (radians) | `tan(0.785398)` |

### Trigonometry Examples
```zxz
:. Basic trigonometric values
zxz.cout/sin(0)/;              // Outputs: 0
zxz.cout/cos(0)/;              // Outputs: 1
zxz.cout/sin(3.14159265359)/;  // Outputs: ~0
zxz.cout/cos(3.14159265359)/;  // Outputs: -1
zxz.cout/tan(0.78539816339)/;  // Outputs: 1

:. Trigonometry with degrees (converted to radians)
zxz.cout/sin(30 * 3.14159265359 # 180)/;  // Outputs: 0.5
zxz.cout/cos(45 * 3.14159265359 # 180)/;  // Outputs: 0.707107

:. Complex expressions with trigonometry
zxz.cout/((10 + 5) * (20 - 5) # 3) + sin(1.57)/;  // Outputs: 75.999999
```

---

## Comments

Comments in ZXZ start with `:.` and continue to the end of the line:

```
start zxz;
    :. This is a comment
    zxz.cout/"Hello"/; :. This is also a comment
zxz end;
```

### Comment Rules
- Comments begin with `:.`
- Everything after `:.` on that line is ignored
- Comments can be placed on their own line or after code
- No multi-line comments are supported

---

## Examples

### Hello World Program
```
start zxz;
    zxz.cout/"Hello, World!"/;
zxz end;
```

### Mathematical Calculations
```
start zxz;
    :. Simple arithmetic
    zxz.cout/5 + 3/;
    zxz.cout/10 * 2 - 4/;
    zxz.cout/(15 + 5) # 4/;
    
    :. Exponentiation
    zxz.cout/2 ** 4/;
    zxz.cout/3 ** 2 + 4/;
zxz end;
```

### Matrix Operations
```
start zxz;
    :. Matrix addition
    zxz.cout/[[1,2],[3,4]] + [[5,6],[7,8]]/;
    
    :. Matrix multiplication
    zxz.cout/[[2,0],[0,2]] * [[1,2],[3,4]]/;
    
    :. Complex matrix expression
    zxz.cout/[[1,2],[3,4]] * [[5,6],[7,8]] + [[1,1],[1,1]]/;
zxz end;
```

### Trigonometric Calculations
```
start zxz;
    :. Basic trig
    zxz.cout/sin(0)/;
    zxz.cout/cos(0)/;
    
    :. Trig with degrees
    zxz.cout/sin(30 * 3.14159 # 180)/;
    zxz.cout/cos(45 * 3.14159 # 180)/;
    
    :. Mixed expressions
    zxz.cout/sin(2 * 3.14159) + cos(3.14159)/;
zxz end;
```

### Full Feature Program
```
start zxz;
    :. ZXZ Complete Example
    
    zxz.cout/"=== ZXZ Calculator ==="/;
    zxz.cout/"Simple Math: "/;
    zxz.cout/10 + 20/;
    zxz.cout/2 ** 10/;
    
    zxz.cout/"Trigonometry: "/;
    zxz.cout/sin(0.5)/;
    zxz.cout/cos(0.5)/;
    
    zxz.cout/"Matrix Operations: "/;
    zxz.cout/[[1,2],[3,4]] + [[5,6],[7,8]]/;
    zxz.cout/[[1,2],[3,4]] * [[5,6],[7,8]]/;
    
    zxz.cout/"Complex Expression: "/;
    zxz.cout/((10 + 5) * (20 - 5) # 3) + sin(1.57)/;
zxz end;
```

---

## Error Handling

### Common Errors

#### Missing Program Markers
```
start zxz;
    zxz.cout/"Hello"/;
:: Missing "zxz end;" will cause an error
```
**Error:** `Error: Program must end with 'zxz end;'`

#### Invalid Print Syntax
```
start zxz;
    zxz.cout/"Hello";   :: Missing the final / 
zxz end;
```
**Error:** `Error at line 2: Invalid syntax`

#### Division by Zero
```
start zxz;
    zxz.cout/10 / 0/;
zxz end;
```
**Error:** `Error: Division by zero`

#### Unclosed Parentheses
```
start zxz;
    zxz.cout/(2 + 3 * 4/;   :: Missing closing parenthesis
zxz end;
```
**Error:** `Error at line 2: Invalid syntax`

#### Invalid Matrix Dimensions
```
start zxz;
    zxz.cout/[[1,2]] + [[3,4],[5,6]]/;  :: Different dimensions
zxz end;
```
**Error:** `Error: Matrix dimensions must match for addition`

#### Matrix Multiplication Mismatch
```
start zxz;
    zxz.cout/[[1,2]] * [[3,4],[5,6]]/;  :: 1x2 * 2x2 (invalid)
zxz end;
```
**Error:** `Error: Invalid matrix dimensions for multiplication`

### Error Messages
- `Error: No input file specified` - File not provided
- `Error: Cannot open file '<filename>'` - File doesn't exist or can't be read
- `Error at line X: Program must start with 'start zxz;'` - Incorrect program start
- `Error: Program must end with 'zxz end;'` - Missing program end
- `Error at line X: Invalid syntax` - Syntax error in code
- `Error: Division by zero` - Attempted division by zero
- `Error: Matrix dimensions must match for addition` - Matrix addition with mismatched dimensions
- `Error: Matrix dimensions must match for subtraction` - Matrix subtraction with mismatched dimensions
- `Error: Invalid matrix dimensions for multiplication` - Invalid matrix multiplication

---

## Command Line Interface

### Basic Usage
```bash
zxzrun [options] <filename.zxz>
```

### Options
| Option | Description |
|--------|-------------|
| `-h`, `--help` | Show help message |
| `-v`, `--version` | Show version information |

### Examples
```bash
# Run a program
./zxzrun program.zxz

# Show help
./zxzrun --help

# Show version
./zxzrun --version
```

---

## Technical Notes

### Implementation Details
- The interpreter is written in C and uses standard libraries
- Expression evaluation supports floating-point arithmetic
- Matrix operations are performed with dynamic stack management
- Trigonometric functions use the standard math library
- The `#` symbol can be used as an alternative to `/` for division to avoid syntax conflicts
- Comments are removed during parsing
- Whitespace is handled flexibly

### Limitations
- No variable assignment or storage
- No control flow (if statements, loops)
- No function definitions
- Single-file programs only
- No input capability
- Matrix size limited to 100x100
- Trigonometry functions only in radians

### Future Roadmap
Potential features for future versions:
- Variable support
- Control flow statements (if/else, loops)
- Function definitions
- File I/O operations
- Vector operations
- Linear algebra functions (determinant, inverse, transpose)
- User-defined functions
- String manipulation

---

## License

This project is open source. See the GitHub repository for licensing information.

---

## Support

For issues, questions, or contributions, please visit:
[https://github.com/pin-toto/zxz-Programming-language](https://github.com/pin-toto/zxz-Programming-language)

---

*ZXZ - Simple, Clean, Effective Programming Language*
```
by pintoto

```
