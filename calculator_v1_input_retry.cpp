#include <iostream>
#include <limits>

/*
    ============================
    Version: v1
    Focus:
    - Retry-until-valid input
    - std::cin state machine (fail / clear / ignore)
    - No templates / auto / lambda
    - int only
*/

// ---------- Operation functions ----------
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b; // Caller must guarantee b != 0
}

// ---------- UI printing ----------
void print_menu() {
    std::cout << R"(
=================================
        Simple Calculator
=================================
  1. Add        2. Subtract
  3. Multiply   4. Divide
=================================
)";
}

// ---------- Input helpers ----------

/*
    Read an integer with retry-until-valid behavior.

    Key idea:
    - If std::cin enters fail state, we must:
        1. clear() the failbit
        2. ignore() the remaining invalid input
        3. ask the user to re-enter
*/
void read_int_with_retry(const char* prompt, int& value) {
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (!std::cin.fail()) {
            return; // Valid integer read
        }

        // Invalid input handling
        std::cin.clear(); // Clear failbit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Invalid input. Please enter an integer value.\n";
    }
}

/*
    Read operation choice (1-4) with retry.
*/
void read_choice_with_retry(int& choice) {
    while (true) {
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        if (!std::cin.fail() && choice >= 1 && choice <= 4) {
            return;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
    }
}

/*
    Read continue flag (0 or 1) with retry.
*/
void read_continue_flag_with_retry(int& flag) {
    while (true) {
        std::cout << R"(
Do you want to continue?
1 for yes
0 for no
Enter 1 or 0: )";

        std::cin >> flag;

        if (!std::cin.fail() && (flag == 0 || flag == 1)) {
            return;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Invalid input. Please enter 1 or 0.\n";
    }
}

// ---------- Main control ----------
int main() {
    int continue_flag = 1;

    while (continue_flag == 1) {
        print_menu();

        int choice = 0;
        read_choice_with_retry(choice);

        int a = 0;
        int b = 0;

        read_int_with_retry("Enter the first integer: ", a);
        read_int_with_retry("Enter the second integer: ", b);

        int result = 0;
        bool valid_operation = true;

        // Function pointer
        int (*operation)(int, int) = nullptr;

        switch (choice) {
            case 1: operation = add; break;
            case 2: operation = subtract; break;
            case 3: operation = multiply; break;
            case 4:
                if (b == 0) {
                    std::cout << "Error: Division by zero is not allowed.\n";
                    valid_operation = false;
                } else {
                    operation = divide;
                }
                break;
        }

        if (valid_operation && operation != nullptr) {
            result = operation(a, b);
            std::cout << "Result: " << result << "\n";
        }

        read_continue_flag_with_retry(continue_flag);
        std::cout << "\n";
    }

    std::cout << "Program terminated.\n";
    return 0;
}

/*
    ---------- Common mistakes (for learning purpose only) ----------

    ❌ Mistake 1:
        if (std::cin.fail()) return;

    Explanation:
        Returning directly exits the current function or even main,
        which breaks interactive programs.
        In v1, we must retry instead of exiting.

    ❌ Mistake 2:
        std::cin >> value;
        std::cin >> value; // without clearing failbit

    Explanation:
        Once failbit is set, all subsequent input operations will fail
        until clear() is called.

    ❌ Mistake 3:
        Using vague prompts like "again?"

    Explanation:
        User prompts must strictly match accepted input rules.
*/
