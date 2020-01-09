#include <iostream>
using namespace std;

bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);

int main() {
    char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
    displayBoard(board);

    while (true) {
        // The first player makes a move
        makeAMove(board, 'X');
        displayBoard(board);
        if (isWon('X', board)) {
            cout << "X player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }

        // The second player makes a move
        makeAMove(board, 'O');
        displayBoard(board);

        if (isWon('O', board)) {
            cout << "O player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }
    }

    return 0;
}

bool isWon(char player, char board[][3]) {
    // Determine if said player has won by...
    // Three of their marks in a row vertically:
    if ((board[0][0] == player && board[0][1] == player && board[0][2] == player) ||
        (board[1][0] == player && board[1][1] == player && board [1][2] == player) ||
        (board[2][0] == player && board[2][1] == player && board [2][2] == player)) {
        return true;
    }

    // Three of their marks in a row horizontally:
    else if ((board[0][0] == player && board[1][0] == player && board[2][0]== player) ||
        (board[0][1] == player && board[1][1] == player && board [2][1] == player) ||
        (board[0][2] == player && board[1][2] == player && board [2][2] == player)) {
        return true;
    }

    // Three of their marks in a row diagonally:
    else if ((board[0][0] == player && board[1][1] == player && board[2][2] == player ) ||
        (board[2][0] == player && board[1][1] == player && board [0][2] == player )) {
        return true;
    }

    else {
        return false;
    }
}

bool isDraw(char board[][3]) {
    // Check to see if the board is full. If it is, return true.
    cout << "Entering isDraw bool" << endl;
    int counter = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != ' ') {
                counter++;
            }
        }
    }

    if (counter == 9) {
        return true;
    }

}

void displayBoard(char board[][3]) {
    // Displays the TicTacToe board using a 2D array as the parameter.
    // The nested for loops print each space in the 2D array.

    for (int i = 0; i < 3; i++) {
        cout << "-------------" << endl;
        for (int j = 0; j < 3; j++) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << "-------------" << endl;
}

void makeAMove(char board[][3], char player) {
    // Prompt player to enter a row and column to put their mark.
    int row, column;
    cout << "Enter a row (0, 1, 2) for player " << player << "   : ";
    cin >> row;
    cout << "Enter a column (0, 1, 2) for player " << player << ": ";
    cin >> column;

    // Place the player's mark in the specific row/column they requested, only if
    // there is vacant space.
    if (board[row][column] != ' ') {
        cout << "This cell is already occupied. Try a different cell" << endl;
        makeAMove(board, player);
    }
    else {
        board[row][column] = player;
    }
}