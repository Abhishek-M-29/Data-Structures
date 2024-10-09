#include <iostream>  // This library is used for input and output

int main() {
    // Declare variables to store user input
    int num1, num2, sum;

    // Prompt the user for input
    std::cout << "Enter the first number: ";
    std::cin >> num1;  // Read the first number from the user

    std::cout << "Enter the second number: ";
    std::cin >> num2;  // Read the second number from the user

    // Calculate the sum of the two numbers
    sum = num1 + num2;

    // Display the result
    std::cout << "The sum of " << num1 << " and " << num2 << " is " << sum << std::endl;

    return 0;  // End of the program
}