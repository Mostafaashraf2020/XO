#include <iostream>
using namespace std;

void drawBoard(char game[3][3]) {
    // Loop through rows
    for (int i = 0; i < 3; i++) {
        // Loop through columns within each row
        for (int j = 0; j < 3; j++) {
            // Print the cell value
            cout << game[i][j];

            // Add a vertical separator except for the last column
            if (j < 2) {
                cout << " | ";
            }
        }

        cout << endl;

        // Add a horizontal separator except for the last row
        if (i < 2) {
            cout << "---------" << endl;
        }
    }
}

char checkWinner(char game[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (game[i][0] == game[i][1] && game[i][1] == game[i][2] && game[i][0] != ' ') {
            return game[i][0];
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (game[0][j] == game[1][j] && game[1][j] == game[2][j] && game[0][j] != ' ') {
            return game[0][j];
        }
    }

    // Check diagonals
    if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && game[0][0] != ' ') {
        return game[0][0];
    }
    if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && game[0][2] != ' ') {
        return game[0][2];
    }

    // If no winner yet
    return 'N';
}

int main() {
    char game[3][3];

    // Initialize the game board with empty cells (' ')
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            game[i][j] = ' ';
        }
    }

    int count = 0;
    bool isX = true;
    while (count < 9) {
        int x, y;
        do {
            cout << "Enter X, Y" << endl;
            cin >> x >> y;

            if (x < 0 || x >= 3 || y < 0 || y >= 3 || game[x][y] != ' ') {
                cout << "Invalid move! Try again." << endl;
            }
        } while (x < 0 || x >= 3 || y < 0 || y >= 3 || game[x][y] != ' ');

        if (isX)
            game[x][y] = 'X';
        else
            game[x][y] = 'O';

        isX = !isX;
        drawBoard(game);
        char c = checkWinner(game);
        if (c == 'X') {
            cout << "Player X won!" << endl;
            break;
        }
        else if (c == 'O') {
            cout << "Player O won!" << endl;
            break;
        }
        else if (count == 8) {
            cout << "It's a draw!" << endl;
        }

        count++;
    }

    return 0;
}
