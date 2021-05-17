#include <bits/stdc++.h>
using namespace std;

int board[3][3];

const int PLAYER1 = 5;
const int PLAYER2 = 10;

bool _end = false;
void win(int player) {
    int p = (player == PLAYER1) ? 1 : 2;
    cout << "Player " << p << " Won!" << endl;
    _end = true;
}

int check() {
    // check diagonal
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2])
	||
	(board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
	return board[1][1];
    }
    // check horizontal and vertical

    // check horizontal
    for (int i = 0; i < 3; i++) { // row
	int sample = board[i][0];
	for (int j = 1; j < 3; j++) { // column
	    if (board[i][j] != sample) {
		sample = 0;
		break;
	    }
	}
	if (sample != 0) {
	    return sample;
	}
    }
    for (int i = 0; i < 3; i++) { // column
	int sample = board[0][i];
	for (int j = 1; j < 3; j++) { // row
	    if (board[j][i] != sample) {
		sample = 0;
		break;
	    }
	}
	if (sample != 0) {
	    return sample;
	}
    }

    return 0;
}

void place(int player, int x, int y) {
    board[x][y] = player;
    int checker = check();
    if (checker != 0) {
	win(checker);
    }
}
void print_current() {
    for (int i = 0; i < 3; i++) {
	printf("+---+---+---+\n");
	for (int j = 0; j < 3; j++) {
	    //	    printf("| %c ", (board[i][j] == 1) ? 'O' : 'X');
	    if (board[i][j] == PLAYER1) {
		printf("| O ");
	    } else if (board[i][j] == PLAYER2) {
		printf("| X ");
	    } else {
		printf("|   ");
	    }
	}
	printf("|\n");
    }
    printf("+---+---+---+\n\n");
}
int main(int argc, const char *argv[]) {
    for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 3; j++) {
	    board[i][j] = 0;
	}
    }

    // player include 5 and 10

    int current_player = PLAYER1;
    while (!_end) {
	print_current();
	int i, j;
        printf("(Player %d) Please enter x and y: ", (current_player == PLAYER1) ? 1 : 2);
	cin >> i >> j;
	if (board[i][j] != 0) continue;
	place(current_player, i, j);
	//	print_current();
	if (current_player == PLAYER1) {
	    current_player = PLAYER2;
	} else {
	    current_player = PLAYER1;
	}
    }


    return 0;
}
