#include <iostream>
#include <limits>

/*
============================================================
This file is a learning-oriented calculator example.

It demonstrates:
- Function pointers
- Input validation
- Control flow with sentinel values
- Early return in void functions
- Common beginner pitfalls (kept as comments with explanation)

All problematic code versions are preserved as comments
for comparison and learning purposes.
============================================================
*/


// ---------- UI printing ----------
void print_menu() {
    std::cout << R"(
=================================
        Simple Calculator
=================================
  1. Add        2. Subtract
  3. Multiply   4. Divide
  0. Exit
=================================
)";
}

// ---------- basic operations ----------
int my_add(int a, int b) {
    return a + b;
}

int my_sub(int a, int b) {
    return a - b;
}

int my_mul(int a, int b) {
    return a * b;
}

int my_divide(int a, int b) {
    if (b == 0) {
        std::cout << "Error: division by zero.\n";
        return 0;
    }
    return a / b;
}

/*
------------------------------------------------------------
❌ Common mistake (kept for learning purpose):

int my_divide(int a, int b){
    if (b == 0)
        std::cout << "b cannot be 0";
    else
        return a / b;
}

Problem:
- This function does NOT return a value when b == 0.
- Non-void functions must return a value in ALL control paths.
- This leads to undefined behavior and compiler warnings.
------------------------------------------------------------
*/


// ---------- calculator (function pointer) ----------
void calculate(int (*op)(int, int)) {
    int a = 0;
    int b = 0;

    std::cout << "Please enter two integers (a b): ";

    if (!(std::cin >> a >> b)) {
        std::cout << "Invalid input: integers only.\n";

        // Clear error flags
        std::cin.clear();

        // Discard remaining invalid input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Early return:
        // This immediately exits the function.
        // In a void function, `return;` does NOT return a value.
        // It only stops further execution of the function.
        return;
    }

    int result = op(a, b);
    std::cout << "Result: " << result << "\n";
}

/*
------------------------------------------------------------
❌ Earlier version with a logic bug:

void cal(int (*fp)(int,int)){
    int a = 0;
    int b = 0;
    std::cout << "enter two intergers";
    if(!(std::cin >> a >> b)) {
        std::cout << "false formats";
    }
    int result = fp(a,b);
    std::cout << result;
}

Problems:
1. Even when input fails, the function still calls fp(a, b).
2. a and b may contain invalid or unchanged values.
3. Input failure must stop further computation immediately.

Correct approach:
- Detect invalid input
- Clear input state
- Use early return to exit the void function
------------------------------------------------------------
*/


// ---------- ask whether to continue ----------
bool ask_continue() {
    int option = 0;

    std::cout << "\nDo you want to continue?\n";
    std::cout << "1. Yes\n";
    std::cout << "0. No\n";
    std::cout << "Your choice: ";

    if (!(std::cin >> option)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    return option == 1;
}

/*
------------------------------------------------------------
❌ Earlier version using bool input directly:

bool ask(){
    bool running = false;
    std::cin >> running;
    return running == 1;
}

Problems:
1. std::cin >> bool treats ANY non-zero value as true.
2. Input "2", "-1", or "99" will all be interpreted as true.
3. This breaks the intended rule: "1 means yes, 0 means no".

Correct approach:
- Use int to receive user choice
- Explicitly compare with expected values
------------------------------------------------------------
*/


// ---------- main ----------
int main() {
    bool running = true;

    while (running) {
        print_menu();

        int choice = -1;
        std::cout << "Please select an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                calculate(my_add);
                running = ask_continue();
                break;
            case 2:
                calculate(my_sub);
                running = ask_continue();
                break;
            case 3:
                calculate(my_mul);
                running = ask_continue();
                break;
            case 4:
                calculate(my_divide);
                running = ask_continue();
                break;
            case 0:
                running = false;
                std::cout << "Program exited. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
                running = ask_continue();
                break;
        }
    }

    return 0;
}
