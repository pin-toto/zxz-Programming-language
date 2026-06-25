# ZXZ Programming Language Documentation

**Version:** 2.0  
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
6. [Comments](#comments)
7. [Examples](#examples)
8. [Error Handling](#error-handling)
9. [Command Line Interface](#command-line-interface)

---

## Introduction

ZXZ is a minimal, interpreted programming language designed for simplicity and ease of use. Built with C, it provides a clean syntax for output operations and mathematical expressions. The language is perfect for beginners learning programming concepts or for quick scripting tasks.

### Key Features
- Simple and readable syntax
- Built-in expression evaluation
- String and numeric output support
- Comment support for code documentation
- Lightweight and fast interpretation

---

## Installation

### Prerequisites
- C compiler (GCC recommended)
- Make (optional)

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
    zxz.cout/(15 + 5) / 4/;
    
    :. Exponentiation
    zxz.cout/2 ** 4/;
    zxz.cout/3 ** 2 + 4/;
zxz end;
```

### String Output
```
start zxz;
    zxz.cout/"Welcome to ZXZ!"/;
    zxz.cout/"Learning programming is fun!"/;
zxz end;
```

### Mixed Output
```
start zxz;
    zxz.cout/"The result is: "/;
    zxz.cout/42/;
    zxz.cout/"2 + 3 = "/;
    zxz.cout/2 + 3/;
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

### Error Messages
- `Error: No input file specified` - File not provided
- `Error: Cannot open file '<filename>'` - File doesn't exist or can't be read
- `Error at line X: Program must start with 'start zxz;'` - Incorrect program start
- `Error: Program must end with 'zxz end;'` - Missing program end
- `Error at line X: Invalid syntax` - Syntax error in code
- `Error: Division by zero` - Attempted division by zero

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
- The `#` symbol can be used as an alternative to `/` for division
- Comments are removed during parsing
- Whitespace is handled flexibly

### Limitations
- No variable assignment or storage
- No control flow (if statements, loops)
- No function definitions
- Single-file programs only
- No input capability

### Future Roadmap
Potential features for future versions:
- Variable support
- Control flow statements (if/else, loops)
- Function definitions
- Array support
- File I/O operations

---

## License

This project is open source. See the GitHub repository for licensing information.

---

## Support

For issues, questions, or contributions, please visit:
[https://github.com/pin-toto/zxz-Programming-language](https://github.com/pin-toto/zxz-Programming-language)

---

*ZXZ - Simple, Clean, Effective Programming Language*
