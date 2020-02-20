#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int floors[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
int chosenAmount = 0;
int currentFloor = 0;
size_t nofl = sizeof(floors)/sizeof(floors[0]);
char choice;
bool flag = false;
int temp = 0;
bool swap = true;

int inarray(int x, int array[], size_t asize)
{
    for (int i = 0; i < asize; i++)
    {
        if (array[i] == x)
        {
            return 1;
        }
    }
    return 0;
}

void elevator()
{
    printf("We're on floor %d, the top floor is 15. How many floors do you want to visit?\n",currentFloor);
    scanf("%d",&chosenAmount);
   
    int whereTo[chosenAmount];
    size_t wtsz = sizeof(whereTo)/sizeof(whereTo[0]);
   
    for (int i = 0; i < wtsz; i++)
    {
        printf("Floor number: ");
        scanf("%d",&whereTo[i]);
    }
   
    flag = true;
    for (int k = 0; k < wtsz; k++)
    {
        if(inarray(whereTo[k], floors, nofl) == 0)
        {
            flag = false;
        }  
    }
   
    if (flag == true)
    {
        //sorting
        while (swap == true)
            {
                swap = false;
                for (int i = 0; i < wtsz - 1; i++)
                {
                    if (whereTo[i] > whereTo[i+1])
                    {
                        temp = whereTo[i];
                        whereTo[i] = whereTo[i+1];
                        whereTo[i+1] = temp;
                        swap = true;
                    }
                }
            }
            printf("Mind the gate...\n");
            for (int i = 0; i < wtsz; i++)
            {
                while (currentFloor <= whereTo[i])
                {
                    if(inarray(currentFloor, whereTo, wtsz) == 1)
                    {
                        printf("DING! You are on floor %d.\n",currentFloor);
                    } else
                    {
                        printf("%d\n",currentFloor);
                    }
                    currentFloor = currentFloor + 1;
                }
            }
    } else if (flag == false)
    {
            printf("You input an invalid floor, mate.\n");
            elevator();
    }
   
}

int main()
{
    printf("Evening! I'm the lift attendant, and I'm here to take you where you want to go! ");
    elevator();
    return 0;
}

