#include "gameClient/gomoku.h"

int main()
{
	gomoku current;
//	location input;
	initGame(&current);
	//addPiece({ 1,1 }, &current, true);
	//addPiece({ 2,1 }, &current, true);
	//addPiece({ 1,3 }, &current, true);
	//addPiece({ 4,1 }, &current, true);
	//addPiece({ 5,1 }, &current, true);
	//addPiece({ 5,5 }, &current, true);

	for (int i = 9;i>1 ; i--)
		addPiece({ i,i }, &current, true);

	bool yes = checkWin(&current, true);
	printf("%d", yes);
	return 0;
}
