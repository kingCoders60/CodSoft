#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Generate a random number between 1 and 100
    srand(time(0));
    int randomNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;

    std::cout << "Guess the number between 1 and 100!" << std::endl;

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess > randomNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else if (guess < randomNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts." << std::endl;
        }
    } while (guess != randomNumber);

    return 0;
}