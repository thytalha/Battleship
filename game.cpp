#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <cstring>
using namespace std;
const int SIZE = 11;
void attack_blue(char grid[SIZE][SIZE]) // To start board
{
	char alpha = 'A';
	grid[0][0] = 'O';

	for (int col = 1; col < SIZE; col++) // Column header
	{
		if (col == 10)
		{
			grid[0][col] = 'X';
		}
		else
		{
			grid[0][col] = '0' + col;
		}
	}

	for (int row = 1; row < SIZE; row++) // Row header
	{
		grid[row][0] = alpha++;
	}

	for (int row = 1; row < SIZE; row++)
	{
		for (int col = 1; col < SIZE; col++)
		{
			grid[row][col] = '-';
		}
	}
}

void blue_board(char grid[SIZE][SIZE]) // To start board
{
	char alpha = 'A';
	grid[0][0] = 'O';

	for (int col = 1; col < SIZE; col++) // Column header
	{
		if (col == 10)
		{
			grid[0][col] = 'X';
		}
		else
		{
			grid[0][col] = '0' + col;
		}
	}

	for (int row = 1; row < SIZE; row++) // Row header
	{
		grid[row][0] = alpha++;
	}

	for (int row = 1; row < SIZE; row++)
	{
		for (int col = 1; col < SIZE; col++)
		{
			grid[row][col] = '-';
		}
	}
}

void attack_red(char grid[SIZE][SIZE]) // To start board
{
	char alpha = 'A';
	grid[0][0] = 'O';

	for (int col = 1; col < SIZE; col++) // Column header
	{
		if (col == 10)
		{
			grid[0][col] = 'X';
		}
		else
		{
			grid[0][col] = '0' + col;
		}
	}

	for (int row = 1; row < SIZE; row++) // Row header
	{
		grid[row][0] = alpha++;
	}

	for (int row = 1; row < SIZE; row++)
	{
		for (int col = 1; col < SIZE; col++)
		{
			grid[row][col] = '-';
		}
	}
}

void red_board(char grid[SIZE][SIZE]) // To start board
{
	char alpha = 'A';
	grid[0][0] = 'O';

	for (int col = 1; col < SIZE; col++) // Column header
	{
		if (col == 10)
		{
			grid[0][col] = 'X';
		}
		else
		{
			grid[0][col] = '0' + col;
		}
	}

	for (int row = 1; row < SIZE; row++) // Row header
	{
		grid[row][0] = alpha++;
	}

	for (int row = 1; row < SIZE; row++)
	{
		for (int col = 1; col < SIZE; col++)
		{
			grid[row][col] = '-';
		}
	}
}

void print(char grid[SIZE][SIZE])
{
	cout << endl;
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			cout << grid[row][col] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

bool carrier(char grid[SIZE][SIZE], char dir, int col, int row)
{
	bool is_valid = true;
	if (col < SIZE&& col >= 1 && row < SIZE && row >= 1)
	{
		if (dir == 'u' || dir == 'U') // Carrier facing up
		{
			if (row > 4)
			{
				bool isValid = true;
				for (int i = row; i > row - 5; i--)
				{
					if (grid[i][col] != '-')
					{
						isValid = false;
						break;
					}
				}
				if (isValid)
				{
					for (int i = row; i > row - 5; i--)
					{
						grid[i][col] = 'C';
					}
				}
				else
				{
					cout << "Overlapping detected with another ship" << endl;
					is_valid = false;
				}
			}
			else
			{
				cout << "Ship goes out of bounds" << endl;
				is_valid = false;
			}
		}

		else if (dir == 'd' || dir == 'D') // Carrier facing down
		{
			if (row < 7)
			{
				bool isValid = true;
				for (int i = row; i < row + 5; i++)
				{
					if (grid[i][col] != '-')
					{
						isValid = false;
						break;
					}
				}
				if (isValid)
				{
					{
						for (int i = row; i < row + 5; i++)
						{
							grid[i][col] = 'C';
						}
					}
				}
				else
				{
					cout << "Overlapping detected with another ship" << endl;
					is_valid = false;
				}
			}
			else
			{
				cout << "Ship goes out of bounds" << endl;
				is_valid = false;
			}
		}
		else if (dir == 'r' || dir == 'R') // Carrier facing right
		{
			if (col < 7)
			{
				bool isValid = true;
				for (int i = col; i < col + 5; i++)
				{
					if (grid[row][i] != '-')
					{
						isValid = false;
						break;
					}
				}
				if (isValid)
				{
					for (int i = col; i < col + 5; i++)
					{
						grid[row][i] = 'C';
					}
				}
				else
				{
					cout << "Overlapping detected with another ship" << endl;
					is_valid = false;
				}
			}
			else
			{
				cout << "Ship goes out of bounds" << endl;
				is_valid = false;
			}
		}
		else if (dir == 'l' || dir == 'L')// Carrier facing left
		{
			if (col > 4)
			{
				bool isValid = true;
				for (int i = col; i > col - 5; i--)
				{
					if (grid[row][i] != '-')
					{
						isValid = false;
						break;
					}
				}
				if (isValid)
				{
					for (int i = col; i > col - 5; i--)
					{
						grid[row][i] = 'C';
					}
				}
				else
				{
					cout << "Overlapping detected with another ship" << endl;
					is_valid = false;
				}
			}
			else
			{
				cout << "Ship goes out of bounds" << endl;
				is_valid = false;
			}
		}
	}
	else
	{
		cout << "Invalid starting position" << endl;
		is_valid = false;
	}
	return is_valid;
}

bool battleship(char grid[SIZE][SIZE], char dir, int col, int row)
{
	bool is_valid = true;
	if (col < SIZE&& col >= 1 && row < SIZE && row >= 1)
	{
		if (dir == 'u' || dir == 'U')
		{
			if (row > 3)
			{
				bool isValid = true;
				for (int i = row; i > row - 4; i--)
				{
					if (grid[i][col] != '-')
					{
						isValid = false;
						break;
					}
				}
				if (isValid)
				{
					for (int i = row; i > row - 4; i--)
					{
						grid[i][col] = 'B';
					}
				}
				else
				{
					cout << "Overlapping detected with another ship" << endl;
					is_valid = false;
				}
			}
			else
			{
				cout << "Ship goes out of bounds" << endl;
				is_valid = false;
			}
		}
		else if (dir == 'd' || dir == 'D')
		{
			if (row < 8)
			{
				bool isValid = true;
				for (int i = row; i < row + 4; i++)
				{
					if (grid[i][col] != '-')
					{
						isValid = false;
						break;
					}
				}
				if (isValid)
				{
					for (int i = row; i < row + 4; i++)
					{
						grid[i][col] = 'B';
					}
				}
				else
				{
					cout << "Overlapping detected with another ship" << endl;
					is_valid = false;
				}
			}
			else
			{
				cout << "Ship goes out of bounds" << endl;
				is_valid = false;
			}
		}
		else if (dir == 'r' || dir == 'R')
		{
			if (col < 8)
			{
				bool isValid = true;
				for (int i = col; i < col + 4; i++)
				{
					if (grid[row][i] != '-')
					{
						isValid = false;
						break;
					}
				}
				if (isValid)
				{
					for (int i = col; i < col + 4; i++)
					{
						grid[row][i] = 'B';
					}
				}
				else
				{
					cout << "Overlapping detected with another ship" << endl;
					is_valid = false;
				}
			}
			else
			{
				cout << "Ship goes out of bounds" << endl;
				is_valid = false;
			}
		}
		else if (dir == 'l' || dir == 'L')
		{
			if (col > 3)
			{
				bool isValid = true;
				for (int i = col; i > col - 4; i--)
				{
					if (grid[row][i] != '-')
					{
						isValid = false;
						break;
					}
				}
				if (isValid)
				{
					for (int i = col; i > col - 4; i--)
					{
						grid[row][i] = 'B';
					}
				}
				else
				{
					cout << "overlapping detected with another ship" << endl;
					is_valid = false;
				}

			}
			else
			{
				cout << "Ship goes out of bounds" << endl;
				is_valid = false;
			}
		}
	}
	else
	{
		cout << "Invalid starting position" << endl;
		is_valid = false;
	}
	return is_valid;
}

bool cruiser(char grid[SIZE][SIZE], char dir, int col, int row)
{
	bool is_valid = true;
	if (col < SIZE&& col >= 1 && row < SIZE && row >= 1)
	{
		if (dir == 'u' || dir == 'U')
		{
			if (row > 2)
			{
				bool isValid = true;
				for (int i = row; i > row - 3; i--)
				{
					if (grid[i][col] != '-')
					{
						isValid = false;
						break;
					}
				}
				if (isValid)
				{
					for (int i = row; i > row - 3; i--)
					{
						grid[i][col] = 'K';
					}
				}
				else
				{
					cout << "Overlapping detected with another ship" << endl;
					is_valid = false;
				}
			}
			else
			{
				cout << "Ship goes out of bounds" << endl;
				is_valid = false;
			}
		}
		else if (dir == 'd' || dir == 'D')
		{
			if (row < 9)
			{
				bool isValid = true;
				for (int i = row; i < row + 3; i++)
				{
					if (grid[i][col] != '-')
					{
						isValid = false;
						break;
					}
				}
				if (isValid)
				{
					for (int i = row; i < row + 3; i++)
					{
						grid[i][col] = 'K';
					}
				}
				else
				{
					cout << "Overlapping detected with another ship" << endl;
					is_valid = false;
				}
			}
			else
			{
				cout << "Ship goes out of bounds" << endl;
				is_valid = false;
			}
		}
		else if (dir == 'r' || dir == 'R')
		{
			if (col < 9)
			{
				bool isValid = true;
				for (int i = col; i < col + 3; i++)
				{
					if (grid[row][i] != '-')
					{
						isValid = false;
						break;
					}
				}
				if (isValid)
				{
					for (int i = col; i < col + 3; i++)
					{
						grid[row][i] = 'K';
					}
				}
				else
				{
					cout << "Overlapping detected with another ship" << endl;
					is_valid = false;
				}
			}
			else
			{
				cout << "Ship goes out of bounds" << endl;
				is_valid = false;
			}
		}
		else if (dir == 'l' || dir == 'L')
		{
			if (col > 2)
			{
				bool isValid = true;
				for (int i = col; i > col - 3; i--)
				{
					if (grid[row][i] != '-')
					{
						isValid = false;
						break;
					}
				}
				if (isValid)
				{
					for (int i = col; i > col - 3; i--)
					{
						grid[row][i] = 'K';
					}
				}
				else
				{
					cout << "overlapping detected with another ship" << endl;
					is_valid = false;
				}

			}
			else
			{
				cout << "Ship goes out of bounds" << endl;
				is_valid = false;
			}
		}
	}
	else
	{
		cout << "Invalid starting position" << endl;
		is_valid = false;
	}
	return is_valid;
}

bool submarine(char grid[SIZE][SIZE], char dir, int col, int row)
{
	bool is_valid = true;
	if (col < SIZE&& col >= 1 && row < SIZE && row >= 1)
	{
		if (dir == 'u' || dir == 'U')
		{
			if (row > 2)
			{
				bool isValid = true;
				for (int i = row; i > row - 3; i--)
				{
					if (grid[i][col] != '-')
					{
						isValid = false;
						break;
					}
				}
				if (isValid)
				{
					for (int i = row; i > row - 3; i--)
					{
						grid[i][col] = 'S';
					}
				}
				else
				{
					cout << "Overlapping detected with another ship" << endl;
					is_valid = false;
				}
			}
			else
			{
				cout << "Ship goes out of bounds" << endl;
				is_valid = false;
			}
		}
		else if (dir == 'd' || dir == 'D')
		{
			if (row < 9)
			{
				bool isValid = true;
				for (int i = row; i < row + 3; i++)
				{
					if (grid[i][col] != '-')
					{
						isValid = false;
						break;
					}
				}
				if (isValid)
				{
					for (int i = row; i < row + 3; i++)
					{
						grid[i][col] = 'S';
					}
				}
				else
				{
					cout << "Overlapping detected with another ship" << endl;
					is_valid = false;
				}
			}
			else
			{
				cout << "Ship goes out of bounds" << endl;
				is_valid = false;
			}
		}
		else if (dir == 'r' || dir == 'R')
		{
			if (col < 9)
			{
				bool isValid = true;
				for (int i = col; i < col + 3; i++)
				{
					if (grid[row][i] != '-')
					{
						isValid = false;
						break;
					}
				}
				if (isValid)
				{
					for (int i = col; i < col + 3; i++)
					{
						grid[row][i] = 'S';
					}
				}
				else
				{
					cout << "Overlapping detected with another ship" << endl;
					is_valid = false;
				}
			}
			else
			{
				cout << "Ship goes out of bounds" << endl;
				is_valid = false;
			}
		}
		else if (dir == 'l' || dir == 'L')
		{
			if (col > 2)
			{
				bool isValid = true;
				for (int i = col; i > col - 3; i--)
				{
					if (grid[row][i] != '-')
					{
						isValid = false;
						break;
					}
				}
				if (isValid)
				{
					for (int i = col; i > col - 3; i--)
					{
						grid[row][i] = 'S';
					}
				}
				else
				{
					cout << "overlapping detected with another ship" << endl;
					is_valid = false;
				}

			}
			else
			{
				cout << "Ship goes out of bounds" << endl;
				is_valid = false;
			}
		}
	}
	else
	{
		cout << "Invalid starting position" << endl;
		is_valid = false;
	}
	return is_valid;
}

bool destroyer(char grid[SIZE][SIZE], char dir, int col, int row)
{
	bool is_valid = true;
	if (col < SIZE&& col >= 1 && row < SIZE && row >= 1)
	{
		if (dir == 'u' || dir == 'U')
		{
			if (row != 1)
			{
				bool isValid = true;
				for (int i = row; i > row - 2; i--)
				{
					if (grid[i][col] != '-')
					{
						isValid = false;
						break;
					}
				}
				if (isValid)
				{
					for (int i = row; i > row - 2; i--)
					{
						grid[i][col] = 'D';
					}
				}
				else
				{
					cout << "Overlapping detected with another ship" << endl;
					is_valid = false;

				}
			}
			else
			{
				cout << "Ship goes out of bounds" << endl;
				is_valid = false;
			}

		}

		else if (dir == 'd' || dir == 'D')
		{
			if (row != 10)
			{
				bool isValid = true;
				for (int i = row; i < row + 2; i++)
				{
					if (grid[i][col] != '-')
					{
						isValid = false;
						break;
					}
				}
				if (isValid)
				{
					for (int i = row; i < row + 2; i++)
					{
						grid[i][col] = 'D';
					}
				}
				else
				{
					cout << "Overlapping detected with another ship" << endl;
					is_valid = false;

				}
			}
			else
			{
				cout << "Ship goes out of bounds" << endl;
				is_valid = false;

			}
		}
		else if (dir == 'r' || dir == 'R')
		{
			if (col != 10)
			{
				bool isValid = true;
				for (int i = col; i < col + 2; i++)
				{
					if (grid[row][i] != '-')
					{
						isValid = false;
						break;
					}
				}
				if (isValid)
				{
					for (int i = col; i < col + 2; i++)
					{
						grid[row][i] = 'D';
					}
				}
				else
				{
					cout << "Overlapping detected with another ship" << endl;
					is_valid = false;

				}
			}
			else
			{
				cout << "Ship goes out of bounds" << endl;
				is_valid = false;
			}
		}
		else if (dir == 'l' || dir == 'L')
		{
			if (col != 1)
			{
				bool isValid = true;
				for (int i = col; i > col - 2; i--)
				{
					if (grid[row][i] != '-')
					{
						isValid = false;
						break;
					}
				}
				if (isValid)
				{

					for (int i = col; i > col - 2; i--)
					{
						grid[row][i] = 'D';
					}
				}
				else
				{
					cout << "Overlapping detected with another ship" << endl;
					is_valid = false;
				}
			}
			else
			{
				cout << "Ship goes out of bounds" << endl;
				is_valid = false;
			}
		}
	}
	else
	{
		cout << "Invalid starting position" << endl;
		is_valid = false;
	}
	return is_valid;
}

void clearScreen()
{
	system("cls");
}

int input_row(char ch)
{
	string ship;
	char row_value;

	if (ch == 'C')
	{
		ship = "Carrier";
	}
	else if (ch == 'B')
	{
		ship = "Battleship";
	}
	else if (ch == 'K')
	{
		ship = "Cruiser";
	}
	else if (ch == 'S')
	{
		ship = "Submarine";
	}
	else
	{
		ship = "Destroyer";
	}

	while (true)
	{
		cout << "Enter row value for " << ship << ". (Choose from A-J) " << endl;
		cin >> row_value;
		cout << endl;

		if ((row_value >= 'A' && row_value <= 'J') || (row_value >= 'a' && row_value <= 'j'))
		{
			if (row_value >= 'a' && row_value <= 'j')
			{
				row_value = row_value - 32;
				return (1 + (row_value - 'A'));
			}
			else
			{
				return (1 + (row_value - 'A'));

			}
		}
		else
		{
			cout << "Invalid input, try again!" << endl;
		}
	}
}

int input_col(char ch)
{
	string ship;
	int col_value;

	if (ch == 'C')
	{
		ship = "Carrier";
	}
	else if (ch == 'B')
	{
		ship = "Battleship";
	}
	else if (ch == 'K')
	{
		ship = "Cruiser";
	}
	else if (ch == 'S')
	{
		ship = "Submarine";
	}
	else
	{
		ship = "Destroyer";
	}

	while (true)
	{
		cout << "Enter column value for " << ship << ". (Choose from 1-10) " << endl;
		cin >> col_value;

		if (cin.fail()) // Input failed (IF non-integer entered)
		{
			cin.clear(); // Clear the fail state
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
			cout << "Invalid input, please enter a valid number between 1 and 10!" << endl;
		}
		else if (col_value >= 1 && col_value <= 10)
		{
			return col_value; // Valid input, return the column value
		}
		else
		{
			cout << "Invalid input, try again! Number must be between 1 and 10." << endl;
		}
	}
}

char input_dir(char ch)
{
	string ship;
	char direction;

	if (ch == 'C')
	{
		ship = "Carrier";
	}
	else if (ch == 'B')
	{
		ship = "Battleship";
	}
	else if (ch == 'K')
	{
		ship = "Cruiser";
	}
	else if (ch == 'S')
	{
		ship = "Submarine";
	}
	else
	{
		ship = "Destroyer";
	}

	while (true)
	{
		cout << "Enter direction for " << ship << ". " << endl;
		cout << "(Choose between: 'u'/'U' = Up, 'd'/'D' = Down, 'r'/'R' = Right and 'l'/'L' = Left)" << endl;
		cin >> direction;

		if (direction == 'u' || direction == 'd' || direction == 'l' || direction == 'r' || direction == 'U' || direction == 'D' || direction == 'L' || direction == 'R')
		{
			return direction;
		}
		else
		{
			cout << "Invalid input, please try again!" << endl;
		}
	}
}

void ship_placement(char blue[SIZE][SIZE], char red[SIZE][SIZE])
{
	bool valid = false;
	cout << "Player Blue's ship placement turn: " << endl << endl;

	blue_board(blue);

	print(blue);
	while (valid == false)
	{
		valid = carrier(blue, input_dir('C'), input_col('C'), input_row('C'));		    //	9	7	u
	}
	print(blue);
	valid = false;

	while (valid == false)
	{
		valid = battleship(blue, input_dir('B'), input_col('B'), input_row('B'));		    //	1	1	r
	}
	print(blue);
	valid = false;

	while (valid == false)
	{
		valid = cruiser(blue, input_dir('K'), input_col('K'), input_row('K'));		    //	9	2	r
	}
	print(blue);
	valid = false;

	while (valid == false)
	{
		valid = submarine(blue, input_dir('S'), input_col('S'), input_row('S'));		    //	7	5	d
	}
	print(blue);
	valid = false;

	while (valid == false)
	{
		valid = destroyer(blue, input_dir('D'), input_col('D'), input_row('D'));		    //	10	10	l
	}
	print(blue);
	valid = false;

	cout << "Press any key to end Player Blue's ship placement turn: ";
	int ignored = _getch();
	clearScreen();

	cout << "Player Blue's ship placement turn ends! " << endl << endl;
	cout << "Press any key to start Player Red's ship placement turn! ";
	ignored = _getch();
	clearScreen();

	cout << "Player Red's ship placement turn: " << endl << endl;

	red_board(red);

	print(red);
	while (valid == false)
	{
		valid = carrier(red, input_dir('C'), input_col('C'), input_row('C'));		    //	2	2	r
	}
	print(red);
	valid = false;

	while (valid == false)
	{
		valid = battleship(red, input_dir('B'), input_col('B'), input_row('B'));		    //	3	10	l
	}
	print(red);
	valid = false;

	while (valid == false)
	{
		valid = cruiser(red, input_dir('K'), input_col('K'), input_row('K'));		    //	9	2	u
	}
	print(red);
	valid = false;

	while (valid == false)
	{
		valid = submarine(red, input_dir('S'), input_col('S'), input_row('S'));		    //	7	5	u
	}
	print(red);
	valid = false;

	while (valid == false)
	{
		valid = destroyer(red, input_dir('D'), input_col('D'), input_row('D'));		    //	7	10	d
	}
	print(red);

	cout << "Press any key to end Player Red's ship placement turn: ";
	ignored = _getch();
	clearScreen();

	cout << "Player Red's ship placement turn ends! " << endl << endl;
}

int check_ships(char board[SIZE][SIZE])
{
	int check = 0;
	void check_carrier(char board[SIZE][SIZE]);
	{
		bool found = false;
		for (int row = 1; row < 11; row++)
		{
			for (int col = 1; col < 11; col++)
			{
				if (board[row][col] == 'C')
				{
					found = true;
				}
			}
		}
		if (found == false)
		{
			cout << "Carrier destroyed! " << endl;
			check++;
		}
	}

	void check_battleship(char board[SIZE][SIZE]);
	{
		bool found = false;
		for (int row = 1; row < 11; row++)
		{
			for (int col = 1; col < 11; col++)
			{
				if (board[row][col] == 'B')
				{
					found = true;
				}
			}
		}
		if (found == false)
		{
			cout << "Battleship destroyed! " << endl;
			check++;
		}
	}

	void check_cruiser(char board[SIZE][SIZE]);
	{
		bool found = false;
		for (int row = 1; row < 11; row++)
		{
			for (int col = 1; col < 11; col++)
			{
				if (board[row][col] == 'K')
				{
					found = true;
				}
			}
		}
		if (found == false)
		{
			cout << "Cruiser ship destroyed! " << endl;
			check++;
		}
	}

	void check_submarine(char board[SIZE][SIZE]);
	{
		bool found = false;
		for (int row = 1; row < 11; row++)
		{
			for (int col = 1; col < 11; col++)
			{
				if (board[row][col] == 'S')
				{
					found = true;
				}
			}
		}
		if (found == false)
		{
			cout << "Submarine destroyed! " << endl;
			check++;
		}
	}

	void check_destroyer(char board[SIZE][SIZE]);
	{
		bool found = false;
		for (int row = 1; row < 11; row++)
		{
			for (int col = 1; col < 11; col++)
			{
				if (board[row][col] == 'D')
				{
					found = true;
				}
			}
		}
		if (found == false)
		{
			cout << "Destroyer ship destroyed! " << endl;
			check++;
		}
	}
	return check;
}

void shoot(char attack[SIZE][SIZE], char board[SIZE][SIZE])
{
	char row;
	int col;

	while (true)
	{
		cout << endl << "Which coordinates would you like to attack? " << endl;

		while (true)
		{
			cout << "Enter row (Choose from A-J): ";
			cin >> row;

			if ((row >= 'a' && row <= 'j') || (row >= 'A' && row <= 'J'))
			{
				if (row >= 'a' && row <= 'j')
				{
					row = row - 32;
					break;
				}
				else if ((row >= 'A' && row <= 'J'))
				{
					break;
				}
			}
			else
			{
				cout << "Invalid row value, it should be a character from A-J" << endl;
			}
		}

		while (true)
		{
			cout << "Enter column (Choose from 1-10): ";
			cin >> col;

			if (cin.fail()) // Input failed (non-integer entered)
			{
				cin.clear(); // Clear the fail state
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
				cout << "Invalid input, please enter a valid number between 1 and 10!" << endl;
			}
			else if (col >= 1 && col <= 10)
			{
				break;
			}
			else
			{
				cout << "Invalid input, try again! Number must be between 1 and 10." << endl;
			}
		}

		if (board[1 + (row - 'A')][col] == '-')
		{
			attack[1 + (row - 'A')][col] = 'M';
			print(attack);
			cout << endl << "It's a miss :(" << endl;
			break;
		}
		else if (attack[1 + (row - 'A')][col] == 'M' || attack[1 + (row - 'A')][col] == 'H')
		{
			cout << "Invalid attack, can't attack the same area twice, try again!" << endl;
		}
		else
		{
			board[1 + (row - 'A')][col] = 'H';
			attack[1 + (row - 'A')][col] = 'H';
			print(attack);
			cout << endl << "It's a hit! :)" << endl;
			break;
		}
	}
}

bool blue_turn(char attack[SIZE][SIZE], char board[SIZE][SIZE], char enemy[SIZE][SIZE])
{
	cout << "Press any key to start Player Blue's turn! ";

	int ignored = _getch();
	clearScreen();

	cout << "Player Blue's ships chart: " << endl;
	print(board);

	cout << endl << "Player Blue's attacks chart: " << endl;
	print(attack);

	shoot(attack, enemy);
	int ships_destroyed = check_ships(enemy);

	if (ships_destroyed == 5)
	{
		return true;
	}
	else
	{
		cout << endl << "Press any key to end Player Blue's turn: ";
		ignored = _getch();
		clearScreen();

		cout << "Player Blue's turn ends! " << endl << endl;

		return false;
	}
}

bool red_turn(char attack[SIZE][SIZE], char board[SIZE][SIZE], char enemy[SIZE][SIZE])
{
	cout << "Press any key to start Player Red's turn! ";

	int ignored = _getch();
	clearScreen();

	cout << "Player Red's ships chart: " << endl;
	print(board);

	cout << endl << "Player Red's attacks chart: " << endl;
	print(attack);

	shoot(attack, enemy);
	int ships_destroyed = check_ships(enemy);

	if (ships_destroyed == 5)
	{
		return true;
	}
	else
	{
		cout << endl << "Press any key to end Player Red's turn: ";
		ignored = _getch();
		clearScreen();

		cout << "Player Red's turn ends! " << endl << endl;

		return false;
	}
}

int main()
{
	char blue_grid[SIZE][SIZE];
	char blue_attack[SIZE][SIZE];
	char red_grid[SIZE][SIZE];
	char red_attack[SIZE][SIZE];
	bool game_over = false;
	bool blue_wins = false;
	bool red_wins = false;

	ship_placement(blue_grid, red_grid);

	attack_blue(blue_attack);
	attack_red(red_attack);

	while (true)
	{
		if (game_over == true)
		{
			break;
		}
		else
		{
			game_over = blue_turn(blue_attack, blue_grid, red_grid);
			blue_wins = true;
		}
		if (game_over == true)
		{
			break;
		}
		else
		{
			game_over = red_turn(red_attack, red_grid, blue_grid);
			red_wins = true;
		}
	}

	cout << ((blue_wins == true) ? "Player Blue wins!" : "Player Red wins!") << endl;

	return 0;
}