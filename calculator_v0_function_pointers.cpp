#include <iostream>
#include <limits>

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
        return;
    }

    int result = op(a, b);
    std::cout << "Result: " << result << "\n";
}

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
