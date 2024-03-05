#include <iostream>
using namespace std;

class TicTacToe {
public:
    char space[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
    int row, column;
    char token='x';
    bool tie=false;

    void board() {
        cout << "       |       |       " << endl;
        cout << "   " << space[0][0] << "   |   " << space[0][1] << "   |   " << space[0][2] << endl;
        cout << "_______|_______|_______" << endl;
        cout << "       |       |       " << endl;
        cout << "   " << space[1][0] << "   |   " << space[1][1] << "   |   " << space[1][2] << endl;
        cout << "_______|_______|_______" << endl;
        cout << "       |       |       " << endl;
        cout << "   " << space[2][0] << "   |   " << space[2][1] << "   |   " << space[2][2] << endl;
        cout << "       |       |       " << endl;
    }

    void fn2() {
        int digit;
        if (token == 'x') {
            cout << "Player 1: ";
        } else {
            cout << "Player 2: ";
        }
        cin >> digit;
        if (digit < 1 || digit > 9) {
            cout << "Invalid !!!" << endl;
            return;
        }
        row = (digit - 1) / 3;
        column = (digit - 1) % 3;

        if (space[row][column] != 'x' && space[row][column] != 'o') {
            space[row][column] = token;
            token = (token == 'x') ? 'o' : 'x';
        } else {
            cout << "There is no empty space!" << endl;
            fn2();
        }
    }

    bool check() {
        for (int i = 0; i < 3; i++) {
            if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) ||
                (space[0][i] == space[1][i] && space[0][i] == space[2][i])) {
                return true;
            }
        }
        if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
            (space[0][2] == space[1][1] && space[1][1] == space[2][0])) {
            return true;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (space[i][j] != 'x' && space[i][j] != 'o') {
                    return false;
                }
            }
        }
        tie = true;
        return true;
    }
};

int main() {
    TicTacToe game;
    while (!game.check()) {
        game.board();
        game.fn2();
    }
    if (game.tie) {
        cout << "It's a draw!" << endl;
    } else {
        if (game.token == 'x') {
            cout << "Player 2 wins!" << endl;
        } else {
            cout << "Player 1 wins!" << endl;
        }
    }
    return 0;
} 