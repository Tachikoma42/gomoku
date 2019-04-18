#include<stdio.h>
#include<algorithm>
#define boardSize 9

typedef struct LOCATION {
	int x;
	int y;
}location;
typedef struct Gomoku {
	int size;//set board size
	char symobl[3];//set symbol for each other and void 
	int clientPiece;//record how many pieces the client has put
	int serverPiece;//record how many pieces the server has put
	location clientLocation[81];//record the exact location of the pieces
	location serverLocation[81];//record the exact location of the pieces
	char allPieces[boardSize * boardSize];
}gomoku;
bool findStone(location targetLocation, location stoneLocation[], int index, int stoneSize)
{
	bool discovered = false;
	for (int i = index; i < stoneSize; i++)
	{
		if ((stoneLocation[i].x == targetLocation.x) && (stoneLocation[i].y == targetLocation.y))
		{
			discovered = true;
			break;
		}
	}
	return discovered;
}
 int compare1(const void* a, const void* b)
 {

 	location* stone1 = (location*)a;
 	location* stone2 = (location*)b;

 	return (stone1->x - stone2->x);
 }
 int compare2(const void* a, const void* b)
 {

 	location* stone1 = (location*)a;
 	location* stone2 = (location*)b;

 	return (stone1->y - stone2->y);
 }
 void initGame(gomoku* current)
 {
 		//Discription:	initial a game board
 		//Input:			current the current gomoku board
 		//Output:			NULL
 	current->symobl[0] = '~';// no piece on this location
 	current->symobl[1] = 'x';// client piece on this location
 	current->symobl[2] = 'o';// server piece on this location
 	current->clientPiece = 0;
 	current->serverPiece = 0;

 	for (int i = 0; i < boardSize * boardSize; i++)
 		current->allPieces[i] = current->symobl[0];
 }
 bool pieceAvailability(location input, gomoku* current)
 {
 	char piece = current->allPieces[(input.x - 1) * boardSize + input.y - 1];
 	if (piece != current->symobl[0])
 		return false;
 	return true;
 }
 void addPiece(location input, gomoku* current, bool client)
 {	//	Discription:	add a piece to the current gomoku
	 //	Input:			input: location of the piece that need to be added
	 //					current: the current gokoku board
	 //					client: true for client/ false for server}
	 //	Output:			NULL
	 bool availability;
	 availability = pieceAvailability(input, current);
	 if (!availability)
	 {
		 printf("THIS PIECE IS TAKEN\n");
		 return;
	 }
	 if (client)
	 {
		 current->clientLocation[current->clientPiece] = input;
		 current->clientPiece++;
		 location stoneLoca[81];
		 for (int i = 0; i < current->clientPiece; i++)
			 stoneLoca[i] = current->clientLocation[i];
		 qsort(stoneLoca, current->clientPiece, sizeof(stoneLoca[0]), compare1);
		 qsort(stoneLoca, current->clientPiece, sizeof(stoneLoca[0]), compare2);
		 for (int i = 0; i < current->clientPiece; i++)
			 current->clientLocation[i] = stoneLoca[i];
		 current->allPieces[(input.x - 1) * boardSize + input.y - 1] = current->symobl[1] = current->symobl[1];

	 }
	 else
	 {
		 current->serverLocation[current->serverPiece] = input;
		 current->serverPiece++;
		 location stoneLoca[81];
		 for (int i = 0; i < current->serverPiece; i++)
			 stoneLoca[i] = current->serverLocation[i];
		 qsort(stoneLoca, current->serverPiece, sizeof(stoneLoca[0]), compare1);
		 qsort(stoneLoca, current->serverPiece, sizeof(stoneLoca[0]), compare2);
		 for (int i = 0; i < current->serverPiece; i++)
			 current->serverLocation[i] = stoneLoca[i];
		 current->allPieces[(input.x - 1) * boardSize + input.y - 1] = current->symobl[1] = current->symobl[2];
	 }

 }
int main()
{
 	gomoku current;
// 	location input;
 	initGame(&current);
 	addPiece({ 1,2 }, &current, true);
 	addPiece({ 2,4 }, &current, true);
 	addPiece({ 1,3 }, &current, true);
 	addPiece({ 3,7 }, &current, true);
	location stoneLocation[81];
	for (int i = 0; i < current.clientPiece; i++)
		stoneLocation[i] = current.clientLocation[i];
	bool yes = findStone({ 1,4 }, stoneLocation, 0, current.clientPiece);
 	return 0;
}