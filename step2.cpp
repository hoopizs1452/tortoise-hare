#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

const int RACE_END = 70;

void printCurrentPositions( const int * const snapperPtr, const int * const bunnyPtr );
void moveTortoise( int *const );


int main()
{
    int tortoise=1;
    int hare = 1;
    
    srand( time( 0 ) );
    
    while ( tortoise != RACE_END && hare != RACE_END ) 
   {
      Sleep( 500 );
      system("cls");   
      moveTortoise( &tortoise );
      printCurrentPositions( &tortoise, &hare );
   }
}

/*印出烏龜與兔子位置*/
void printCurrentPositions( const int * const snapperPtr, const int * const bunnyPtr )
{
	for(int i=0; i<7; i++)
		cout << "---------|";
	cout << endl;
	cout << setw(*bunnyPtr) << "H" << endl;
	cout << setw(*snapperPtr) << "T" << endl; 
}

/*移動烏龜*/
void moveTortoise( int * const turtlePtr )
{
	int r = rand()%10;
	*turtlePtr += (r>=0 && r<=4)?3:(r>=5 && r<=6)?-6:1;
	*turtlePtr = (*turtlePtr>70)?70:(*turtlePtr<1)?1:*turtlePtr;
	
}
