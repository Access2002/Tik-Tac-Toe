#include <iostream>

void board();
void GameLogic();

char squares[9] = {'1', '2','3','4','5','6','7','8','9'};

char X = 'X';
char O = 'O';
char Mark;

int choice;
int player = 1; //1 == X, 0 == O

int WinState = 0;

int main()
{
	while (WinState == 0) {
		if (WinState != 0) {
			break;
		}
		board();
		GameLogic();

		player = (player % 2);
		if (player == 1) {
			Mark = X;
		}

		if (player == 0) {
			Mark = O;
		}

		std::cout << "Pick a Number!\n";
		std::cout << "You are player: " << Mark << "\n";
		std::cout << "Current WinState: " << WinState << std::endl;
		std::cin >> choice;

		if (choice == 1 && squares[0] == '1') {
			squares[0] = Mark;
		}

		else if (choice == 2 && squares[1] == '2') {
			squares[1] = Mark;
		}

		else if (choice == 3 && squares[2] == '3') {
			squares[2] = Mark;
		}
		else if (choice == 4 && squares[3] == '4') {
			squares[3] = Mark;
		}
		else if (choice == 5 && squares[4] == '5') {
			squares[4] = Mark;
		}
		else if (choice == 6 && squares[5] == '6') {
			squares[5] = Mark;
		}
		else if (choice == 7 && squares[6] == '7') {
			squares[6] = Mark;
		}
		else if (choice == 8 && squares[7] == '8') {
			squares[7] = Mark;
		}
		else if (choice == 9 && squares[8] == '9') {
			squares[8] = Mark;
		}


		else {
			std::cout << "Invalid!" << std::endl;
			continue;
		}

		player++;
		GameLogic();
	}

	board();
	if (WinState == 10) {
		std::cout << "X Won!\n";
	}

	if (WinState == 20) {
		std::cout << "O Won!\n";
	}

	if (WinState == 2) {
		std::cout << "Draw!\n";
	}


	system("PAUSE");
	return 0;

}

// Calculates who has won or when the game is finished;
void GameLogic() {
	if (squares[0] == squares[1] && squares[1] == squares[2]) {
		WinState = 1;
	}
	else if (squares[3] == squares[4] && squares[4] == squares[5]) {
		WinState = 1;
	}
	else if (squares[6] == squares[7] && squares[7] == squares[8]) {
		WinState = 1;
	}
	else if (squares[0] == squares[3] && squares[3] == squares[6]) {
		WinState = 1;
	}
	else if (squares[1] == squares[4] && squares[4] == squares[7]) {
		WinState = 1;
	}
	else if (squares[2] == squares[5] && squares[5] == squares[8]) {
		WinState = 1;
	}
	else if (squares[0] == squares[4] && squares[4] == squares[8]) {
		WinState = 1;
	}
	else if (squares[2] == squares[4] && squares[4] == squares[6]) {
		WinState = 1;
	}
	else if (squares[0] != '1' && squares[1] != '2' && squares[2] != '3' && squares[3] != '4' && squares[4] != '5' && squares[5] != '6'
		&& squares[6] != '7' && squares[7] != '8' && squares[8] != '9') {
		WinState = 2;
	}

	if (WinState == 1 && Mark == X) {
		WinState = 10;
	}

	if (WinState == 1 && Mark == O) {
		WinState == 20;
	}
}


//Draws Board onto the screen
void board() {
	system("cls");
	std::cout << "     |     |  \n";
	std::cout << "  " << squares[0] << "  |  " << squares[1] << "  |  " << squares[2] << "  \n";
	std::cout << "_____|_____|____\n";
	std::cout << "     |     |    \n";
	std::cout << "  " << squares[3] << "  |  " << squares[4] << "  |  " << squares[5] << "  \n";
	std::cout << "_____|_____|____\n";
	std::cout << "     |     |    \n";
	std::cout << "  " << squares[6] << "  |  " << squares[7] << "  |  " << squares[8] << "  \n";
	std::cout << "     |     |    \n";
}
