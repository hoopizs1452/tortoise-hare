#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

const int RACE_END = 70;

void printCurrentPositions( const int * const snapperPtr, const int * const bunnyPtr );
void moveTortoise( int *const );
void moveHare( int * const );

int main()
{
    int tortoise=1;
    int hare = 1;
    clock_t start, end;
    srand( time( 0 ) );
    
    start = clock();
    while ( tortoise != RACE_END && hare != RACE_END ) 
   {
      Sleep( 100 );
      system("cls");
	      
      moveTortoise( &tortoise );
      moveHare(&hare);
      printCurrentPositions( &tortoise, &hare );
      
   }
   end = clock();
   
   if(tortoise==70)
   	cout << "TORTOISE WINS!!! YAY!!!" << endl;
   else if(hare==70)
   	cout << "Hae wins. Yuch." << endl;
   cout << "TIME ELAPSED = " << (end-start)/1000 << " seconds" << endl;

   	
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
	*turtlePtr += (r>=0 && r<=1)?0:(r>=2 && r<=3)?9:(r==4)?-12:(r>=5 && r<=7)?1:-2;
	*turtlePtr = (*turtlePtr>70)?70:(*turtlePtr<1)?1:*turtlePtr;
}

/*移動兔子*/
void moveHare( int * const rabbitPtr )
{
	int r = rand()%10;
	*rabbitPtr += (r>=0 && r<=4)?3:(r>=5 && r<=6)?-6:1;
	*rabbitPtr = (*rabbitPtr>70)?70:(*rabbitPtr<1)?1:*rabbitPtr;
}
