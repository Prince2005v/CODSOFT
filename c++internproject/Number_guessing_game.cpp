#include <iostream>
#include <cstdlib>  
#include <ctime>   

using namespace std;

void guessTheNumber() {
    // Seed the random number generator
    srand(time(0));
    
    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;
    int userGuess;
    
    cout << "I'm thinking of a number between 1 and 100." << endl;

    while (true) {
        cout << "Enter your guess: ";
        cin >> userGuess;

        if (userGuess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else if (userGuess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number " << randomNumber << " correctly." << endl;
            break;
        }
    }
}

int main() {
    guessTheNumber();
    return 0;
}
