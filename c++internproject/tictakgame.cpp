#include <iostream>
using namespace std;

// Game board array
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char current_marker;
int current_player;

// Function to display the game board
void displayBoard() {
    cout << "Tic-Tac-Toe Board:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n---------\n";
    }
    cout << endl;
}

// Function to place marker on the board
bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    } else {
        cout << "Slot already taken! Try a different move." << endl;
        return false;
    }
}

// Function to check if there's a win
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

// Function to switch players
void switchPlayer() {
    current_marker = (current_marker == 'X') ? 'O' : 'X';
    current_player = (current_player == 1) ? 2 : 1;
}

// Main game function
void playGame() {
    cout << "Player 1, choose your marker (X or O): ";
    char marker;
    cin >> marker;

    current_player = 1;
    current_marker = marker;

    displayBoard();
    int slot;

    while (true) {
        cout << "Player " << current_player << "'s turn. Enter your slot: ";
        cin >> slot;

        // Validate slot and place marker
        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Please choose a slot between 1 and 9." << endl;
            continue;
        }

        if (!placeMarker(slot)) continue;

        displayBoard();

        // Check for win or draw
        if (checkWin()) {
            cout << "Player " << current_player << " wins!" << endl;
            break;
        }
        if (checkDraw()) {
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch player for next turn
        switchPlayer();
    }
}

// Function to reset the board
void resetBoard() {
    char initial = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = initial++;
        }
    }
}

// Main function to run the game loop
int main() {
    char playAgain;

    do {
        resetBoard();
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl;
    return 0;
}
