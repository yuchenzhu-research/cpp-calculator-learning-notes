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

### Version 1 — Retry-Until-Valid Input (Current)

**File:**  
`calculator_v1_input_retry.cpp`

**Focus:**
- Retry-until-valid input handling
- Robust recovery from invalid user input
- Explicit management of the `std::cin` state machine
- Consistent multi-line UI output using raw string literals

**Key Concepts:**
- Treating `std::cin` as a state machine (`fail / clear / ignore`)
- Loop-based input recovery instead of early termination
- Using helper functions to encapsulate input logic
- Maintaining strict consistency between prompts and accepted input

This version improves interaction robustness while preserving all v0 constraints
(no templates, no `auto`, no lambda expressions, integer-only arithmetic).

---

## Purpose of This Repository

This repository is intended as a **personal study record**, not as a production project
or a research demonstration.

It documents:
- How basic C++ programs grow in structure
- Common pitfalls in input handling
- How control flow design affects program robustness

---

## Notes

The emphasis is on **clarity and learning**, not on performance or advanced abstractions.
Mistakes and rejected patterns are sometimes kept as commented examples to make the
learning process explicit and reviewable.