#include <iostream>
#include <cstdlib>
#include <ctime>

int grid[10][10];

void randomShip(){
    int i = rand() % 10;
    int j = rand() % 10;
    if (grid[i][j] == 0){ //prevent assigning to the same square
    	grid[i][j] = 1; //square gets a ship
	} else {
		randomShip();
	}
}

int main()
{
    srand(time(0));
    for (int i = 0; i<10; i++)
    {
        for (int j = 0; j<10; j++)
        {
            grid[i][j] = 0;
        }
    }
   
    for (int k = 0; k<5; k++){
        randomShip();
    }
    
    return 0;
}
