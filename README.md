# C++ Calculator Learning Notes

This repository contains a series of small C++ programs written as **learning notes**.
The goal is not to build a full-featured calculator, but to practice and understand
core C++ concepts through **incremental versions** of a simple example.

The code evolves step by step, with each version focusing on a specific topic.

---

## Version Overview

### Version 0 — Function Pointers (Integer Only)

**File:**  
`calculator_v0_function_pointers.cpp`

**Focus:**
- Function pointer basics
- Passing functions as parameters
- Menu-driven control flow
- Sentinel-controlled loops
- Input validation using `std::cin`
- Separation of UI, logic, and control flow

**Key Concepts:**
- Function pointer syntax: `int (*op)(int, int)`
- Using `std::cin.fail()` for input validation
- Clearing input state with `cin.clear()` and `cin.ignore()`
- Simple user interaction design

This version intentionally supports **integers only** to keep the logic clear and focused.

---

## Planned Versions

Future versions will be added to this repository to document the learning progression:

- **v1**: Improved input validation and retry logic  
- **v2**: Function pointer table (removing `switch`)  
- **v3**: Template-based calculator (supporting `int` and `double`)  
- **v4**: Lambda and callable-based design  

Each version will be preserved as a separate `.cpp` file.

---

## Purpose of This Repository

This repository is intended as a **personal study record**, not as a production project
or a research demonstration.

It documents:
- How basic C++ programs grow in structure
- Common pitfalls in input handling
- The transition from simple syntax to clearer program design

---

## Notes

The emphasis is on **clarity and learning**, not on performance or advanced abstractions.
Comments and structure are kept explicit to make the reasoning easy to follow.
