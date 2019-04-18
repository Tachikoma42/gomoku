#include<stdio.h>
#include<algorithm>
#define boardSize 9

typedef struct LOCATION {
	int x;
	int y;
}location;
typedef struct Gomoku {
	//int size;//set board size
	char symobl[3];//set symbol for each other and void 
	int clientPiece;//record how many pieces the client has put
	int serverPiece;//record how many pieces the server has put
	location clientLocation[81];//record the exact location of the pieces
	location serverLocation[81];//record the exact location of the pieces
	char allPieces[boardSize * boardSize];
}gomoku;
// int compare1(const void* a, const void* b)
// {

// 	location* stone1 = (location*)a;
// 	location* stone2 = (location*)b;

// 	return (stone1->x - stone2->x);
// }
// int compare2(const void* a, const void* b)
// {

// 	location* stone1 = (location*)a;
// 	location* stone2 = (location*)b;

// 	return (stone1->y - stone2->y);
// }
// void initGame(gomoku* current)
// {
// 	//	Discription:	initial a game board
// 	//	Input:			current the current gomoku board
// 	//	Output:			NULL
// 	current->symobl[0] = '~';// no piece on this location
// 	current->symobl[1] = 'x';// client piece on this location
// 	current->symobl[2] = 'o';// server piece on this location
// 	current->clientPiece = 0;
// 	current->serverPiece = 0;

// 	for (int i = 0; i < boardSize * boardSize; i++)
// 		current->allPieces[i] = current->symobl[0];
// }
// bool pieceAvailability(location input, gomoku* current)
// {
// 	char piece = current->allPieces[(input.x - 1) * boardSize + input.y - 1];
// 	if (piece != current->symobl[0])
// 		return false;
// 	return true;
// }
// void addPiece(location input, gomoku* current, bool client)
// {	//	Discription:	add a piece to the current gomoku
// 	//	Input:			input: location of the piece that need to be added
// 	//					current: the current gokoku board
// 	//					client: true for client/ false for server}
// 	//	Output:			NULL
// 	bool availability;
// 	availability = pieceAvailability(input, current);
// 	if (!availability)
// 	{
// 		printf("THIS PIECE IS TAKEN\n");
// 		return;
// 	}
// 	if (client)
// 	{
// 		current->clientLocation[current->clientPiece] = input;
// 		current->clientPiece++;
// 		///*int stoneSize = current->clientPiece;
// 		//location tempLocation[boardSize * boardSize];
// 		//for (int i = 0; i < stoneSize; i++)
// 		//	tempLocation[i] = current->clientLocation[i];
// 		//qsort(tempLocation,templocation+stoneSize, )
// 		//location  stoneLocation[81];*/
// 		//qsort(current->clientLocation, current->clientPiece, sizeof(current->clientLocation[0]), compare);
// 		current->allPieces[(input.x - 1) * boardSize + input.y - 1] = current->symobl[1] = current->symobl[1];

// 	}
// 	else
// 	{
// 		current->serverLocation[current->serverPiece] = input;
// 		current->serverPiece++;
// 		current->allPieces[(input.x - 1) * boardSize + input.y - 1] = current->symobl[1] = current->symobl[2];
// 	}

// }
// void display(gomoku* current)
// {
// 	//	Discription:	display the current gomoku board
// 	//	Input:			current the current gomoku board
// 	//	Output:			NULL
// 	system("cls");
// 	for (int i = 0; i < boardSize; i++)
// 	{
// 		printf("\n");
// 		for (int j = 0; j < boardSize; j++)
// 			printf(" %c ", current->allPieces[i * boardSize + j]);
// 	}
// }
// int main()
// {
// 	gomoku current;
// 	location input;
// 	initGame(&current);
// 	addPiece({ 1,2 }, &current, true);
// 	addPiece({ 2,4 }, &current, true);
// 	addPiece({ 1,3 }, &current, true);
// 	addPiece({ 3,7 }, &current, true);
// 	//display(&current);
// 	location stoneLoca[81];
// 	for (int i = 0; i < current.clientPiece; i++)
// 		stoneLoca[i] = current.clientLocation[i];
// 	qsort(stoneLoca, current.clientPiece, sizeof(stoneLoca[0]),compare1);
// 	qsort(stoneLoca, current.clientPiece, sizeof(stoneLoca[0]), compare2);

// 	printf("\n");

// 	return 0;
// }

bool checkWin(gomoku* current, bool client)
{
	//	Discription:	check after input did you win
	//	Input:			current: the current gomoku board
	//					client: true to check client win/ false to check server win
	//	Output:			bool win
	int stoneSize;
	location  stoneLocation[81];
	bool winStatus = false;
	if (client)
	{
		stoneSize = current->clientPiece;
		for (int i = 0; i < stoneSize; i++)
			stoneLocation[i] = current->clientLocation[i];
	}
	else
	{
		stoneSize = current->serverPiece;
		for (int i = 0; i < stoneSize; i++)
			stoneLocation[i] = current->serverLocation[i];
	}

	if (stoneSize < 5)
		return false;
	//check horizontial
	for(int i =0;i<stoneSize;i++)
	{
		location tempLoca = stoneLocation[i];
		if (stoneSize - i < 5)
			return winStatus;
		if(checkHorizontial(tempLoca,stoneLocation,i, stoneSize)||checkVertical(tempLoca,stoneLocation,i,stoneSize)||checkDiagonal(tempLoca,stoneLocation,i,stoneSize))
		{
			winStatus = true;
			return winStatus;
		}
	}

	return winStatus;
}
bool checkHorizontial(location tempLoca, location stoneLocation[],int i,int stoneSize)
{
	//check horizontial

	bool winStatus = false;
	if ((boardSize-tempLoca.y) < 4)
		return winStatus;
	else
	{
		int ylabel = tempLoca.y;
		for (int j = i+1; j < i+5; j++)
		{
			ylabel++;
			if (stoneLocation[j].y != ylabel)
			{
				winStatus = false;
				break;
			}
			if (j == i + 4)
				winStatus = true;
		}
	}
	return winStatus;
}
bool checkVertical(location tempLoca, location stoneLocation[],int i,int stoneSize)
{
	//check vertical

	bool winStatus = false;
	if ((boardSize-tempLoca.x) < 4)
		return winStatus;
	else
	{
		int xlabel = tempLoca.x;
		for (int j = i+1; j < i+5; j++)
		{
			xlabel++;
			if (stoneLocation[j*boardSize].x != xlabel)
			{
				winStatus = false;
				break;
			}
			if (j == i + 4)
				winStatus = true;
		}
	}
	return winStatus;
}
bool checkDiagonal(location tempLoca, location stoneLocation[],int i,int stoneSize)
{
	//check diagonal

	bool winStatus = false;
	//check left
	if(tempLoca.x <5)
		winStatus = false;
	else
	{
		if((boardSize-tempLoca.y) < 4)
			winStatus = false;
		else
		{
			/* code */
		}
		
	}
	//check right

	if(winStatus)
		return winStatus;
	else if((boardSize-tempLoca.x) < 4)
		winStatus = false;
	else
	{
		/* code */
	}
	
	return winStatus;

}
bool findStone(location targetLocation, location stoneLocation[], int index, int stoneSize)
{
	bool discovered = false;
	for (int i = index;i<stoneSize;i++)
	{
		if((stoneLocation[i].x == targetLocation.x)&&(stoneLocation[i].y == targetLocation.y))
		{
			discovered = true;
			break;
		}
	}
}