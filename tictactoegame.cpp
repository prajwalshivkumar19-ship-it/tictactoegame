#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// Display the board
void displayBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

// Check for winner
bool checkWinner(char player) {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    // Diagonals
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

// Check if board is full
bool boardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

int main() {
    int choice;
    char player = 'X';

    cout << "===== TIC TAC TOE =====\n";

    while (true) {
        displayBoard();

        cout << "\nPlayer " << player << ", enter position (1-9): ";
        cin >> choice;

        // Convert position to row and column
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        // Check valid input
        if (choice < 1 || choice > 9 ||
            board[row][col] == 'X' ||
            board[row][col] == 'O') {

            cout << "Invalid move! Try again.\n";
            continue;
        }

        board[row][col] = player;

        // Check winner
        if (checkWinner(player)) {
            displayBoard();
            cout << "\nPlayer " << player << " wins! 🎉\n";
            break;
        }

        // Check draw
        if (boardFull()) {
            displayBoard();
            cout << "\nIt's a draw! 🤝\n";
            break;
        }

        // Change player
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    return 0;
}