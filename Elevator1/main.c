#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int floors[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
int currentFloor = 0;
int whereTo = 0;
size_t nofl = sizeof(floors)/sizeof(floors[0]);
char choice;
bool flag = false;

void elevator()
{
    flag = false;
    printf("We're on floor %d, the top floor is 15. Where to? ",currentFloor);
    scanf("%d",&whereTo);

    for (int i = 0; i < nofl; i++)
    {
        if(floors[i] == whereTo)
        {
            flag = true;
        }
    }
        if(flag == true)
        {
            printf("Mind the gate...\n");
            while (currentFloor < whereTo)
            {
                printf("%d\n",currentFloor);
                currentFloor = currentFloor + 1;
            }
            while (currentFloor > whereTo)
            {
                printf("%d\n",currentFloor);
                currentFloor = currentFloor - 1;
            }
            printf("DING! You are on floor %d.\n",currentFloor);
            printf("Would you like to go to a new floor? y/n ");
            scanf("%s",&choice);
            if(choice == 'y' || choice == 'Y')
            {
                elevator();
            } else {}
        } else if(flag == false)
        {
            printf("That's not a valid floor, mate.\n");
            elevator();
        }
}

int main()
{
    printf("Evening! I'm the lift attendant, and I'm here to take you where you want to go! ");
    elevator();
    return 0;
}