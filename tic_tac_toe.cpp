#include <iostream>
using namespace std;
char matrix[3][3] = { '1','2','3','4','5','6' ,'7','8','9' };
char player = 'X';
void Draw()
{
	system("cls");
	cout << " _________________" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "|     |     |     |" << endl << "|";
		for (int j = 0; j < 3; j++)
		{
			cout << "  "<< matrix[i][j];
			cout << "  |";
		}

		cout << endl;
		cout << "|_____|_____|_____|";
		cout << endl;
	}
}
void Input()
{
	char a, count = 0;
	cout << "It's " << player << " turn" << endl;
	cout << "press the number of the field";
	cin >> a;
	if (a >= '0' && a <= '9')                           //check valid input or not
	{
		for (int i = 0; i < 3; i++)						
		{
			for (int j = 0; j < 3; j++)
			{
				count++;
				if (char(count+48) == a)
				{
					if (matrix[i][j] == a)
					{
						matrix[i][j] = player;
					}
					else
					{
						cout << "Feild is already in use try again! " << endl;
						Input();

					}
				}
			}
		}
	}
	else
	{
		cout << "not valid"<<endl;
		Input();
	}
	
}
void TogglePlayer()
{
	if (player == 'X')
		player = 'O';
	else
		player = 'X';
}
char Win()
{
	//for first player
	if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X')
		return 'X';
	else if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X')
		return 'X';
	else if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X')
		return 'X';

	else if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X')
		return 'X';
	else if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X')
		return 'X';
	else if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X')
		return 'X';

	else if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
		return 'X';
	else if (matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X')
		return 'X';

	//for second player

	if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O')
		return 'O';
	else if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O')
		return 'O';
	else if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O')
		return 'O';

	else if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O')
		return 'O';
	else if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O')
		return 'O';
	else if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O')
		return 'O';

	else if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
		return 'O';
	else if (matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O')
		return 'O';
	return '/';
}
int main()
{
	int count1=0;
	Draw();
	while (true)
	{
		count1++;
		Input();
		TogglePlayer();
		Draw();
		if (Win() == 'X')
		{
			cout << "X wins" << endl;
			break;
		}
		else if (Win() == 'O')
		{
			cout << "O wins" << endl;
			break;
		}
		if (count1 >= 9)
		{
			cout << "Draw" << endl;
			break;
		}
	}
	system("pause");
	return 0;

}
