#include <iostream>
#include "tic_tac_toe.h"
using namespace std;
int main()
{
	int count=0;
	Draw();
	while (true)
	{
		count++;
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
		if (count >= 9)
		{
			cout << "Draw" << endl;
			break;
		}
	}
	system("pause");
	return 0;

}
